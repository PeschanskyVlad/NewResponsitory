#include "client.h"
#include <stdio.h>
#include <stdlib.h>
#include "client.h"
#include<winsock2.h>
#pragma comment(lib,"ws2_32.lib")

#pragma comment(lib, "ws2_32.lib")

#define NO_FLAGS_SET 0
#define PORT 80
#define MAXBUFLEN 20480 // How much is printed out to the screen

int connectClient(){

    WSADATA Data;
    SOCKADDR_IN recvSockAddr;
    SOCKET recvSocket;
    int status,i;
    int pos=0,count=0,min;
    char * bufferPos=(char*)malloc(400);
    //char * bufferPos1=(char*)malloc(400);;

    char tempBuffer[100];
    int numrcv = 0;
    struct hostent * remoteHost;
    char * ip;
    char * baseAddress=(char*)malloc(400);
    char * receivedAddress;
    const char bA2[]=" HTTP/1.1\r\nHost:%s\r\n\r\n";
   // char  tempAddress[100]="temp";
    //const char * host_name = "example.com";
    const char * host_name ="pb-homework.appspot.com";
    char buffer[MAXBUFLEN];
    char buffer2[MAXBUFLEN];
    char buffer3[MAXBUFLEN];
    memset(buffer,0,MAXBUFLEN);
    memset(buffer2,0,MAXBUFLEN);
    memset(buffer3,0,MAXBUFLEN);
    memset(tempBuffer,0,100);
    // Initialize Windows Socket DLL
    status = WSAStartup(MAKEWORD(2, 2), &Data);

    if(status != 0)
    {
        printf("ERROR: WSAStartup unsuccessful\r\n");
        return 0;
    }

    // Get IP address from host name
    remoteHost = gethostbyname(host_name);
    ip = inet_ntoa(*(struct in_addr *)*remoteHost->h_addr_list);
    printf("IP address is: %s.\n", ip);
    memset(&recvSockAddr, 0, sizeof(recvSockAddr)); // zero the sockaddr_in structure
    recvSockAddr.sin_port=htons(PORT); // specify the port portion of the address
    recvSockAddr.sin_family=AF_INET; // specify the address family as Internet
    recvSockAddr.sin_addr.s_addr= inet_addr(ip); // specify ip address
    // Create socket
    recvSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if(recvSocket == INVALID_SOCKET)
    {
        printf("ERROR: socket unsuccessful\r\n");
        system("pause");
        return 0;
    }
    // Connect
    if(connect(recvSocket,(SOCKADDR*)&recvSockAddr,sizeof(SOCKADDR_IN)) == SOCKET_ERROR)
    {
        printf("ERROR: socket could not connect\r\n");
        closesocket(recvSocket);
        WSACleanup();
        return 0;
    }
    // Send request
    char request[2000];



    sprintf(request,"GET /var/8 HTTP/1.1\r\nHost:%s\r\n\r\n", host_name); // add Host header with host_name value
    send(recvSocket, request, strlen(request), 0);

    // Receieve
    numrcv = recv(recvSocket, buffer, MAXBUFLEN, NO_FLAGS_SET);
    if (numrcv == SOCKET_ERROR)
    {
        printf("ERROR: recvfrom unsuccessful\r\n");
        status = closesocket(recvSocket);
        if(status == SOCKET_ERROR)
            printf("ERROR: closesocket unsuccessful\r\n");
        status = WSACleanup();
        if (status == SOCKET_ERROR)
            printf("ERROR: WSACleanup unsuccessful\r\n");
        system("pause");
        return(1);
    }

    printf("%s\r\n", buffer);

    // Print out receieved socket data


    //printf("Length: %i\n",printf("%s %i\r\n", buffer,strlen(buffer)));

    bufferPos=strstr(buffer,"\r\n\r\n");


    strcpy(tempBuffer,"");
    for(i=0;i<strlen(bufferPos)-4;i++){

        tempBuffer[i]=bufferPos[i+4];
    }

    printf("BufferPos: %s",tempBuffer);

    strcpy(baseAddress,"GET /var/8?");

    baseAddress=strcat(baseAddress,tempBuffer);

    baseAddress=strcat(baseAddress," HTTP/1.1\r\nHost:%s\r\n\r\n");


    puts("");
    puts("");
    printf("\nAddress2.0: %s\n", baseAddress);


    sprintf(request, baseAddress, host_name);
    send(recvSocket, request, strlen(request), 0);


    numrcv = recv(recvSocket, buffer2, MAXBUFLEN, NO_FLAGS_SET);
    if (numrcv == SOCKET_ERROR)
    {
        printf("ERROR: recvfrom unsuccessful\r\n");
        status = closesocket(recvSocket);
        if(status == SOCKET_ERROR)
            printf("ERROR: closesocket unsuccessful\r\n");
        status = WSACleanup();
        if (status == SOCKET_ERROR)
            printf("ERROR: WSACleanup unsuccessful\r\n");
        system("pause");
        return(1);
    }



    printf("%s Strlen: %i\r\n", buffer2,strlen(buffer2));

    bufferPos=strstr(buffer2,"\r\n\r\n");


    strcpy(tempBuffer,"");

    for(i=0;i<strlen(bufferPos)-4;i++){

        tempBuffer[i]=bufferPos[i+4];
    }
    puts("");
    printf("String: %s Strlen: %i",tempBuffer,strlen(tempBuffer));
    puts("");


    min=strlen(tempBuffer);
  for(i=0;i<strlen(tempBuffer);i++){
            if(tempBuffer[i]==' '){
               // puts("!");
                if(count<min){
                    min=count;

                    pos=i-count;
                }
                count=-1;

            }

            if(i==strlen(tempBuffer)-1){
               if(count<min){
                    min=count;

                    pos=i-count;
                }
            }

        count++;

    }

    printf("Min: %i PosMin: %i",min,pos);

    char message[min];
    for(i=0;i<min;i++){
        message[i]=tempBuffer[i+pos];
    }
    puts("");
    printf("String: %s Strlen: %i",message,strlen(message));
    puts("");




    /*strcpy(baseAddress,"POST /var/8 HTTP/1.1\r\nHost:%s\r\n result=");
    baseAddress=strcat(baseAddress,message);
    baseAddress=strcat(baseAddress,"\r\n");
*/
    strcpy(baseAddress,"result=");
    baseAddress=strcat(baseAddress,message);

    printf("\nAddress3.0: %s  END\n",baseAddress);





    sprintf(request, "POST /var/8 HTTP/1.1\r\n"
               "Host: %s\r\n"
               "Content-type: application/x-www-form-urlencoded\r\n"
               "Content-length: %d\r\n\r\n"
               "%s\r\n", host_name, strlen(baseAddress), baseAddress);
   // puts(request);
    send(recvSocket, request, strlen(request), 0);

    numrcv = recv(recvSocket,buffer3, MAXBUFLEN, NO_FLAGS_SET);
    if (numrcv == SOCKET_ERROR)
    {
        printf("ERROR: recvfrom unsuccessful\r\n");
        status = closesocket(recvSocket);
        if(status == SOCKET_ERROR)
            printf("ERROR: closesocket unsuccessful\r\n");
        status = WSACleanup();
        if (status == SOCKET_ERROR)
            printf("ERROR: WSACleanup unsuccessful\r\n");
        system("pause");
        return(1);
    }

 printf("%s\r\n", buffer3);







    system("pause");

    return 0;



}
