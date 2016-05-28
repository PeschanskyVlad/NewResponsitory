#include <stdio.h>
#include <stdlib.h>
#include "server.h"


struct gdata{
char * name;
char * year;
time_t gettime;
};

gdata_t * newgData(){
gdata_t * self = malloc(sizeof(struct gdata));
self->name = malloc(sizeof(char)*100);
self->year = malloc(sizeof(char)*100);
return self;

}


gdata_t getStruct(const char * message){


    gdata_t * film = newgData();
    xmlDoc * xDoc;
    xDoc = xmlReadMemory(message, strlen(message), NULL, NULL, 0);
    if(NULL == xDoc){
        printf("FATAL ERROR");
        return;
    }


}

void serverNew(){
    lib_init();
    socket_t * serverSocket = socket_new();
    socket_bind(serverSocket, 5000);
    socket_listen(serverSocket);

    //
    socket_t* thisClientSoc = socket_new ();
    socket_connect(thisClientSoc, "216.58.209.49", 80);

    char uri [256];

    strcpy (uri, "http://pb-homework.appspot.com/test/var/41?format=xml");

    char req [1024];


    static const char * const requestFormat =
        "%s %s HTTP/1.1\r\n"
        "Content-Type: text\r\n"
        "Content-Length: %zu\r\n\r\n"
        "%s";



    sprintf (req, requestFormat, "GET", uri, NULL, NULL, NULL);

    socket_write(thisClientSoc, req, strlen (req));
    char responce [1024];
    socket_read (thisClientSoc, responce, 1024);

    int contentLength = 0;
    sscanf (strstr(responce, "Content-Length: ") + strlen ("Content-Length: "), "%d", &contentLength);
    char* data = strstr (responce, "\r\n\r\n") + 4;

    puts(data);


    socket_free(thisClientSoc);


    //

}
