#include<stdio.h>
#include<string.h>      //strlen
#include<sys/socket.h>
#include<arpa/inet.h>   //inet_addr
#include<unistd.h>      //write
#include<sys/types.h>
#include<netinet/in.h>
#include<stdlib.h>
#define PORT 5536
int main()
{
        int syndicate , agent , c;
        struct sockaddr_in server , client;
        char *msg;
        
        //Create socket
        syndicate = socket(AF_INET , SOCK_STREAM , 0);
        if (syndicate == -1)
        {
                printf("SATELLITE IS OFFLINE: TRY ANOTHER SATELLITE");
        }
        else{
        printf("SATELLITE HACKED\n");
        printf("UPLOADING SERVER ON SATELLITE\n");
        printf("...\n");
        printf("SERVER UPLOADED\n");
             }

        //creating the  structure
        server.sin_family = AF_INET;
        server.sin_addr.s_addr = INADDR_ANY;
        server.sin_port = htons(PORT);
        
        //Bind 
        if( bind(syndicate,(struct sockaddr *)&server , sizeof(server)) < 0)
        {
                puts("UNSECURE LINE: NEED TO SHIFT SERVER ON ANOTHER SATELLITE");
                return 1;
        }
        puts("SATELLITE HACKED : SECURE CONNECTION");
        
        //Listen
        if((listen(syndicate , 7))<0){
        puts("ERROR : POWER CUTTOFF\n");
        puts("NOT ABLE TO LISTEN\n");}
        //Accept the incoming connection
        else{
        puts("SYNDICATE IS ONLINE");}
        c = sizeof(struct sockaddr_in);
        while( (agent = accept(syndicate, (struct sockaddr *)&client, (socklen_t*)&c)) )
        {
        if (agent<0)
        {
                puts("Agent is offline");
        }
        
        //Reply to the client
        msg = "mission completed ... Next mission : assignment-2... Mission Details will be given in afganistan";
        write(agent , msg , strlen(msg));
        }
        return 0;
}
 
