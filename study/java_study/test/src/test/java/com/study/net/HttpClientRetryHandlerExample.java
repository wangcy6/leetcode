package com.study.net;

import org.apache.http.HttpEntityEnclosingRequest;
import org.apache.http.HttpRequest;
import org.apache.http.client.HttpRequestRetryHandler;
import org.apache.http.client.methods.HttpGet;
import org.apache.http.client.protocol.HttpClientContext;
import org.apache.http.impl.client.CloseableHttpClient;
import org.apache.http.impl.client.HttpClients;
import javax.net.ssl.SSLException;
import java.io.IOException;
import java.io.InterruptedIOException;
import java.net.UnknownHostException;

/**
 * This example demonstrates the use of {@link HttpRequestRetryHandler}.
 */
public class HttpClientRetryHandlerExample {

    public static void main(String... args) throws IOException {

        CloseableHttpClient httpclient = HttpClients.custom()
                .setRetryHandler(retryHandler())
                .build();

        try {
            HttpGet httpget = new HttpGet("http://localhost:1234");
            System.out.println("Executing request " + httpget.getRequestLine());
            httpclient.execute(httpget);
            System.out.println("----------------------------------------");
            System.out.println("Request finished");
        } finally {
            httpclient.close();
        }
    }

    private static HttpRequestRetryHandler retryHandler(){
        return (exception, executionCount, context) -> {

            System.out.println("try request: " + executionCount);

            if (executionCount >= 5) {
                // Do not retry if over max retry count
                return false;
            }
            if (exception instanceof InterruptedIOException) {
                // Timeout
                return false;
            }
            if (exception instanceof UnknownHostException) {
                // Unknown host
                return false;
            }
            if (exception instanceof SSLException) {
                // SSL handshake exception
                return false;
            }
            HttpClientContext clientContext = HttpClientContext.adapt(context);
            HttpRequest request = clientContext.getRequest();
            boolean idempotent = !(request instanceof HttpEntityEnclosingRequest);
            if (idempotent) {
                // Retry if the request is considered idempotent
                return true;
            }
            return false;
        };
    }
}