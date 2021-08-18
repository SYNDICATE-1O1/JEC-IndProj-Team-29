#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<sys/socket.h>
#include<unistd.h>
#include<string.h>
#include<arpa/inet.h>
#define PORT 5536
int main() {
                //some usefull extra stuff
        char syndicate_ryply[707];
                // create a client socket
        int c;
        if ((c = socket(AF_INET,SOCK_STREAM,0)) < 0)
        printf("socket creation error");
        else{
        printf("welcome agent\n");}
                // create a address family
        struct sockaddr_in server;
        server.sin_family = AF_INET;
        server.sin_port   = htons(PORT);
        if(inet_pton(AF_INET,"127.0.0.1",&server.sin_addr)<=0)
        printf("\ninvalid address\n");
//      server.sin_addr.s_addr = htonl(INADDR_ANY);  //inet_addr("127.0.0.1");
                // connect to server

        if(connect(c ,(struct sockaddr *)&server,sizeof(server))<0)
        printf("SYNDICATE has REVOKED your AUTHORIATION\n");
        else{
        printf("connection estabilished : SYNDICATE is listning\n");
        printf("...\n");
        printf("...\n");
        printf("verify your IDENTITY - Agent:");
        }
        // send data to server
        int i;
        char code[15];
        for(i=0;i<4;i++){
        scanf("%s",&code);
        if(send(c,code,strlen(code),0)<0)
        puts("failed to verify: try again");
        //}
        // recv data from server
        //for(i=0;i<4;i++){         
        if(recv(c,syndicate_ryply,707,0)<0){
        printf("UNSECURE LINE : YOU ARE IN DANGER  ");
        printf("...");
        printf("CONNECTION TERMINATED");}
        else{
        puts(syndicate_ryply);}
        
        }
        close(c);
        return 0 ;
        }
