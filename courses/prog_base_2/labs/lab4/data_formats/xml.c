#include "xml.h"
#include "freelancer.h"
#include <libxml/parser.h>
#include <libxml/tree.h>
#define MSG_LENGTH 10000

char * xmlFreelancerToMessage(freelanser_t *self, int id){
    if(!self)
        return NULL;
    char buff[MSG_LENGTH];
    xmlDoc * doc = NULL;
	xmlNode * rootNode = NULL;
	xmlNode * freelancerNode = NULL;
	xmlNode * personalData = NULL;
	xmlNode * position = NULL;
    doc = xmlNewDoc("1.0");
	rootNode = xmlNewNode(NULL, "freelancers");
	xmlDocSetRootElement(doc, rootNode);
	char strBuf[100];
	freelancerNode = xmlNewChild(rootNode, NULL, "freelancer", NULL);
	xmlNewChild(freelancerNode, NULL, "name", self->name);
	xmlNewChild(freelancerNode, NULL, "surname", self->surname);


	personalData = xmlNewChild(freelancerNode, NULL, "personalData", NULL);
	sprintf(strBuf, "%i", self->pD->age);
    xmlNewChild(personalData, NULL, "age", strBuf);

    sprintf(strBuf, "%f", self->pD->workExperience);
    xmlNewChild(personalData, NULL, "workExperience", strBuf);

    xmlNewChild(personalData, NULL, "birthdate", self->pD->birthdate);


    position = xmlNewChild(freelancerNode, NULL, "position", self->pos->name);
    xmlNewProp(position, "company", self->pos->company);



	xmlBuffer * bufferPtr = xmlBufferCreate();
	xmlNodeDump(bufferPtr, NULL, (xmlNode *)doc, 0, 1);
	sprintf(buff, "%s", (const char*)bufferPtr->content);
    xmlFreeDoc(doc);
	xmlCleanupParser();
	xmlBufferFree(bufferPtr);
    return buff;
}


char * xmlFreelancersToMessage(List_t * list){
    if(List_getSize(list) == 0){
        return NULL;
    }
    char buff[MSG_LENGTH];

    xmlDoc * doc = NULL;
	xmlNode * rootNode = NULL;
    doc = xmlNewDoc("1.0");

    rootNode = xmlNewNode(NULL, "freelancers");
	xmlDocSetRootElement(doc, rootNode);

	char strBuf[100];

    for(int i = 0; i  < List_getSize(list); i++){

        freelanser_t *self = List_get(list, i,NULL);

        xmlNode * freelancerNode = NULL;
        xmlNode * personalData = NULL;
        xmlNode * position = NULL;
        freelancerNode = xmlNewChild(rootNode, NULL, "freelancer", NULL);
        xmlNewChild(freelancerNode, NULL, "name", self->name);
        xmlNewChild(freelancerNode, NULL, "surname", self->surname);


        personalData = xmlNewChild(freelancerNode, NULL, "personalData", NULL);
        sprintf(strBuf, "%i", self->pD->age);
        xmlNewChild(personalData, NULL, "age", strBuf);

        sprintf(strBuf, "%f", self->pD->workExperience);
        xmlNewChild(personalData, NULL, "workExperience", strBuf);

        xmlNewChild(personalData, NULL, "birthdate", self->pD->birthdate);


        position = xmlNewChild(freelancerNode, NULL, "position", self->pos->name);
        xmlNewProp(position, "company", self->pos->company);
    }

	xmlBuffer * bufferPtr = xmlBufferCreate();
	xmlNodeDump(bufferPtr, NULL, (xmlNode *)doc, 0, 1);
	sprintf(buff, "%s", (const char*)bufferPtr->content);
    return buff;
}
