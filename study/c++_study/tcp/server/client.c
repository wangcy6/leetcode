//http://www.cs.tau.ac.il/~eddiea/samples/IOMultiplexing/TCP-client.c.html

/***************************************************************************/
/*                                                                         */    
/* Client program which gets as parameter the server name or               */    
/*     address and tries to send the data into non-blocking server.        */    
/*                                                                         */    
/* The message is sent after 5 seconds of wait                             */    
/*                                                                         */    
/*                                                                         */    
/* based on Beej's program - look in the simple TCp client for further doc.*/    
/*                                                                         */    
/*                                                                         */    
/***************************************************************************/
#include <stdio.h> 
#include <stdlib.h> 
#include <errno.h> 
#include <string.h> 
#include <netdb.h> 
#include <sys/types.h> 
#include <netinet/in.h> 
#include <sys/socket.h> 
#include <unistd.h>
#include <fcntl.h> /* Added for the nonblocking socket */

#define PORT 3490    /* the port client will be connecting to */
#define MAXDATASIZE 1024 /* max number of bytes we can get at once */

    //./client 127.0.0.1
    int main(int argc, char *argv[])
    {
        int sockfd, numbytes;  
        char buf[MAXDATASIZE];
        struct hostent *he;
        struct sockaddr_in their_addr; /* connector's address information */

        if (argc != 2) {
            fprintf(stderr,"usage: client hostname\n");
            exit(1);
        }

        if ((he=gethostbyname(argv[1])) == NULL) {  /* get the host info */
            herror("gethostbyname");
            exit(1);
        }

        if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
            perror("socket");
            exit(1);
        }

        their_addr.sin_family = AF_INET;      /* host byte order */
        their_addr.sin_port = htons(PORT);    /* short, network byte order */
        their_addr.sin_addr = *((struct in_addr *)he->h_addr);
        bzero(&(their_addr.sin_zero), 8);     /* zero the rest of the struct */

        if (connect(sockfd, (struct sockaddr *)&their_addr, \
                                              sizeof(struct sockaddr)) == -1) {
            perror("connect");
            exit(1);
        }

	while (1) 
    {   
        char sendBuffer[] = "Hello, world!";
        int sendSize =send(sockfd, sendBuffer, sizeof(sendBuffer), 0);
		if (sendSize == -1)
        {    
              printf(" send failed \n");
              perror("send");
		      exit (1);
		}
		printf("sockfd =%d, send sendSize=%d ,data=%s\n",sockfd,sendSize,sendBuffer);
        sleep(2);
        
        //对方一直不发数据，阻塞等待,这程序完蛋了
        //recvv将会阻塞，直到缓冲区里有至少一个字节才返回，当没有数据到来时，recv会一直阻塞或者直到超时，不会返回
        //fcntl(sockfd, F_SETFL, O_NONBLOCK); /* Change the socket into non-blocking state	*/
        if ((numbytes=recv(sockfd, buf, MAXDATASIZE, 0)) == -1) {
            
            printf(" recv failed \n");
            perror("recv");
            exit(1);
        }	

	    buf[numbytes] = '\0';
        printf("Received in pid=%d, text=: %s \n",getpid(), buf);
		sleep(1);

        printf("----------- \n");

	}

        close(sockfd);

        return 0;
    }

    //https://www.geeksforgeeks.org/tcp-server-client-implementation-in-c/

