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
    if(strcmp(reqUri,"/external")==0){
        return 1;
        puts("true");
    }
    puts("false");
    return 0;
}

static void copy_xmlcontents_to_buffer(char * buffer, xmlNodePtr data)
{
    char * content = xmlNodeGetContent(data);
    strcpy(buffer, content);

}


void getGDATA(gdata_t * film,xmlNodePtr fl){
    xmlNodePtr fl_child = fl;
    do
    {
        if(fl_child->type != XML_ELEMENT_NODE)
            continue;
        if(xmlStrEqual(fl_child->name, "movie"))
        {
            copy_xmlcontents_to_buffer(film->name, fl_child);
        }
        else if(xmlStrEqual(fl_child->name, "year"))
        {
            copy_xmlcontents_to_buffer(film->year, fl_child);
        }
    }while((fl_child = fl_child->next)!=NULL);
    film->gettime = time(NULL);
}


gdata_t * getStruct(const char * message){
    gdata_t * film = newgData();

    xmlDoc * xDoc;
    xDoc = xmlReadMemory(message, strlen(message), NULL, NULL, 0);


    if(NULL == xDoc){
        printf("FATAL ERROR");
        return;
    }
        xmlNodePtr cur;
        cur = xmlDocGetRootElement(xDoc);
        xmlNodePtr fl = cur->children->next;
        getGDATA(film, fl);

film->gettime = time(NULL);
return  film;
}

void serverNew(){
    lib_init();
    socket_t * serverSocket = socket_new();
    socket_bind(serverSocket, 5000);
    socket_listen(serverSocket);

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

    gdata_t * film = getStruct(data);
    socket_free(thisClientSoc);

    //puts(film->name);
    //puts(film->year);

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


        serverInfo(clientSocket,getTrue,film);


        socket_close(clientSocket);
        socket_free(clientSocket);
    }
    socket_close(serverSocket);
    socket_free(serverSocket);
    lib_free();
}

char * serverToXML(char * name, char * year, char * time)
{
	xmlDoc * doc = NULL;
	xmlNode * rootNode = NULL;
	doc = xmlNewDoc("1.0");
	rootNode = xmlNewNode(NULL, "object");

	char * text = malloc(sizeof(char) * CHAR_LENGTH);
	for (int i = 0; i < CHAR_LENGTH; i++)
	{
		text[i] = '\0';
	}
	xmlDocSetRootElement(doc, rootNode);
	xmlNewChild(rootNode, NULL, "movie", name);
	xmlNewChild(rootNode, NULL, "year", year);
	xmlNewChild(rootNode, NULL, "getTime", time);
	xmlBuffer * bufferPtr = xmlBufferCreate();
	xmlNodeDump(bufferPtr, NULL, (xmlNode *)doc, 0, 1);
	strcat(text, bufferPtr->content);
	xmlBufferFree(bufferPtr);
	xmlFreeDoc(doc);
	xmlCleanupParser();
	puts(text);
	return text;
}


void serverInfo(socket_t * client, int get, gdata_t * film)
{
	char homeBuf[BUFFER_LENGTH];


	if(get==1){
    const char * name = film->name;
	const char * year = film->year;
    puts("Info\n");
	puts(name);
	puts(year);

    struct tm *m_time;

    //long int s_time = time (NULL);

	m_time = localtime (&film->gettime);
    const char * time = malloc(sizeof(char)*100);
   strftime(time, 32, "%a, %d.%m.%Y %H:%M:%S", m_time);


	char * text = serverToXML(name, year, time);

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
