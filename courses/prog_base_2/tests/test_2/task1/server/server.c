#include "server.h"
#include <stdio.h>
#include <stdlib.h>
#include <libxml/parser.h>
#include <libxml/tree.h>
#include <stddef.h>
#include <string.h>
#include <ctype.h>


struct http_request_s{
    char method[8];
    char uri[256];
    keyvalue_t * form;
    int formLength;
};

struct keyvalue_s{
    char key[256];
    char value[256];
};

int getRequest(const char * request){
    ptrdiff_t methodLen = strstr(request, " ") - request;  // find first whitespace

    char reqMetod[CHAR_LENGTH];
    char reqUri[CHAR_LENGTH];

    memcpy(reqMetod, request, methodLen);
    reqMetod[methodLen] = '\0';


    const char * uriStartPtr = request + strlen(reqMetod) + 1;
    const char * uriEndPtr = strstr(uriStartPtr, " ");  // find second whitespace
    ptrdiff_t uriLen = uriEndPtr - uriStartPtr;
    memcpy(reqUri, uriStartPtr, uriLen);
    reqUri[uriLen] = '\0';

    puts("GetURI:");
    puts(reqUri);
    if(strcmp(reqUri,"/info")==0){
        return 1;
        puts("true");
    }
    puts("false");
    return 0;
}



void serverNew(void){

    lib_init();
    socket_t * serverSocket = socket_new();
    socket_bind(serverSocket, 5000);
    socket_listen(serverSocket);

    while(1){
        puts("Waiting for connections.");
        socket_t * clientSocket = socket_accept(serverSocket);
        puts("New client connected.");

        char buff[BUFFER_LENGTH];
        int readLength = socket_read(clientSocket, buff, BUFFER_LENGTH);
        if(readLength == 0){
            socket_close(clientSocket);
            socket_free(clientSocket);
            puts("Empty request.");
            continue;
        }

        printf("Got Request:\n---------------\n%s\n----------------\n", buff);

        int getTrue = getRequest(buff) ;


        serverInfo(clientSocket,getTrue);


        socket_close(clientSocket);
        socket_free(clientSocket);
    }
    socket_close(serverSocket);
    socket_free(serverSocket);
    lib_free();
}

char * serverToXML(char * name, char * group, char * var)
{
	xmlDoc * doc = NULL;
	xmlNode * rootNode = NULL;
	doc = xmlNewDoc("1.0");
	rootNode = xmlNewNode(NULL, "persons");

	char * text = malloc(sizeof(char) * CHAR_LENGTH);
	for (int i = 0; i < CHAR_LENGTH; i++)
	{
		text[i] = '\0';
	}
	xmlDocSetRootElement(doc, rootNode);
	xmlNewChild(rootNode, NULL, "student", name);
	xmlNewChild(rootNode, NULL, "group", group);
	xmlNewChild(rootNode, NULL, "variant", var);
	xmlBuffer * bufferPtr = xmlBufferCreate();
	xmlNodeDump(bufferPtr, NULL, (xmlNode *)doc, 0, 1);
	strcat(text, bufferPtr->content);
	xmlBufferFree(bufferPtr);
	xmlFreeDoc(doc);
	xmlCleanupParser();
	puts(text);
	return text;
}


void serverInfo(socket_t * client, int get)
{
	char homeBuf[BUFFER_LENGTH];


	if(get==1){
    const char * name = "Vlad Peschansky";
	const char * group = "KP-52";
	const char * variant = "41";
	char * text = serverToXML(name, group, variant);
    sprintf(homeBuf,
        "HTTP/1.1 404 \n"
        "Content-Type: text/xml\n"
        "Content-Length: %u\n"
        "\n%s", strlen(text), text);
        free(text);
	}else{
	    char * text = "404 Page Not Found!";
	    sprintf(homeBuf,
        "HTTP/1.1 404 \n"
        "Content-Type: text\n"
        "Content-Length: %u\n"
        "\n%s", strlen(text),text);
	}


    socket_write_string(client, homeBuf);
    socket_close(client);

}




