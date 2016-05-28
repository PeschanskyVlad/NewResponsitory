#include <stdio.h>
#include <stdlib.h>
#include "server.h"
#include "freelanser.h"
#include "freelanser_db.h"


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
    if(strcmp(reqUri,"/database")==0){
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

void serverNew(List_t * freeLansers){
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

        int getTrue = getRequest(buff);


        serverInfo(clientSocket,getTrue,freeLansers);


        socket_close(clientSocket);
        socket_free(clientSocket);
    }
    socket_close(serverSocket);
    socket_free(serverSocket);
    lib_free();
}

char * serverToXML(List_t * freeLanser)
{
	xmlDoc * doc = NULL;
	xmlNode * rootNode = NULL;
	doc = xmlNewDoc("1.0");
	rootNode = xmlNewNode(NULL, "freelancers");

	char * text = malloc(sizeof(char) * CHAR_LENGTH);
	for (int i = 0; i < CHAR_LENGTH; i++)
	{
		text[i] = '\0';
	}
	xmlDocSetRootElement(doc, rootNode);

	// for(int i = 0;i<List_getSize(freeLanser);i++){
    // freeLanser_t * tmpLanser = List_get(freeLanser,0,NULL);
    // freeLanser_print(tmpLanser);
    //    }

    char tmpstr[100];


	//for(int i = 0;i<List_getSize(freeLanser);i++){ цыкл ложит прогу
            freeLanser_t * tmpLanser = List_get(freeLanser,0,NULL);  // i -> 0
            xmlNewChild(rootNode, NULL, "name", tmpLanser->name);
            xmlNewChild(rootNode, NULL, "surname", tmpLanser->surname);
            xmlNewChild(rootNode, NULL, "id", tmpLanser->id);
            xmlNewChild(rootNode, NULL, "birthDate", tmpLanser->birthDate);

            sprintf(tmpstr,"%i",tmpLanser->completedProjects);
            xmlNewChild(rootNode, NULL, "completedProject", tmpstr);



//	}


	xmlBuffer * bufferPtr = xmlBufferCreate();
	xmlNodeDump(bufferPtr, NULL, (xmlNode *)doc, 0, 1);
	strcat(text, bufferPtr->content);
	xmlBufferFree(bufferPtr);
	xmlFreeDoc(doc);
	xmlCleanupParser();
	puts(text);
	return text;
}


void serverInfo(socket_t * client, int get, List_t * freeLanser)
{
	char homeBuf[BUFFER_LENGTH];


	if(get==1){



	char * text = serverToXML(freeLanser);

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
