package com.study.concurrency;

import java.util.concurrent.CountDownLatch;

//https://juejin.im/post/6844903869340712974
public class CountDownLatchTest {
    public static void main(String[] args) throws InterruptedException {
        CountDownLatch startSignal = new CountDownLatch(1);
        CountDownLatch doneSignal = new CountDownLatch(5);

        for (int i = 0; i < 5; i++) {
            new Thread(()->{
                try {
                    System.out.println("Aid thread is waiting for starting.");
                    startSignal.await();
                    // do sth
                    System.out.println("Aid thread is doing something.");
                    doneSignal.countDown();
                } catch (InterruptedException e) {
                    e.printStackTrace();
                }
            }).start();
        }

        // main thread do sth
        Thread.sleep(2000);
        System.out.println("Main thread is doing something.");
        startSignal.countDown();

        // main thread do sth else
        System.out.println("Main thread is waiting for aid threads finishing.");
        doneSignal.await();

        System.out.println("Main thread is doing something after all threads have finished.");

    }
}
