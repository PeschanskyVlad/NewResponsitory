#include "freelanser.h"
#include "freelanser_db.h"
#include "list.h"
#include "server.h"

#include <libxml/parser.h>
#include <libxml/tree.h>

char * xmlFreelancerToMessage(freelancer_t *self){
    if(!self)
        return NULL;

    char buff[10000];
    xmlDoc * doc = NULL;
	xmlNode * rootNode = NULL;
	xmlNode * freelancerNode = NULL;


    doc = xmlNewDoc("1.0");
	rootNode = xmlNewNode(NULL, "freelancers");
	xmlDocSetRootElement(doc, rootNode);
	char strBuf[100];

	sprintf(strBuf, "%i", self->id);
	freelancerNode = xmlNewChild(rootNode, NULL, "freelancer", NULL);
	xmlNewChild(freelancerNode, NULL, "Id", strBuf);
	xmlNewChild(freelancerNode, NULL, "name", self->name);
	xmlNewChild(freelancerNode, NULL, "surname", self->surname);

	sprintf(strBuf, "%f", self->salary);
	xmlNewChild(freelancerNode, NULL, "salary", strBuf);
	sprintf(strBuf, "%i", self->id);
	xmlNewChild(freelancerNode, NULL, "completedProjects", strBuf);
	xmlNewChild(freelancerNode, NULL, "birthDate", self->birthDate);



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
    char buff[10000];

    xmlDoc * doc = NULL;
	xmlNode * rootNode = NULL;
    doc = xmlNewDoc("1.0");

    rootNode = xmlNewNode(NULL, "freelancers");
	xmlDocSetRootElement(doc, rootNode);

	char strBuf[100];

    for(int i = 0; i  < List_getSize(list); i++){

        freelancer_t *self = List_get(list, i,NULL);

        xmlNode * freelancerNode = NULL;
        sprintf(strBuf, "%i", self->id);
        freelancerNode = xmlNewChild(rootNode, NULL, "freelancer", NULL);
        xmlNewChild(freelancerNode, NULL, "Id", strBuf);
        xmlNewChild(freelancerNode, NULL, "name", self->name);
        xmlNewChild(freelancerNode, NULL, "surname", self->surname);

        sprintf(strBuf, "%f", self->salary);
        xmlNewChild(freelancerNode, NULL, "salary", strBuf);
        sprintf(strBuf, "%i", self->id);
        xmlNewChild(freelancerNode, NULL, "completedProjects", strBuf);
        xmlNewChild(freelancerNode, NULL, "birthDate", self->birthDate);


    }

	xmlBuffer * bufferPtr = xmlBufferCreate();
	xmlNodeDump(bufferPtr, NULL, (xmlNode *)doc, 0, 1);
	sprintf(buff, "%s", (const char*)bufferPtr->content);
    return buff;
}



char *freelancerToHTML(freelancer_t *self, char *buff){
    sprintf(buff, "<!DOCTYPE html>"
"<html>"
    "<head>"
        "<title>Freelancers database</title>"
    "</head>"
    "<body>"
        "<h3>%s %s</h3>"
        "<table>"
            "<tr>"
                "<th>ID:</th>"
                "<th>Completed projects:</th>"
                "<th>Salary:</th>"
                "<th>Birthdate:</th>"
            "</tr>"
            "<tr>"
                "<th>%i</th>"
                "<th>%i</th>"
                "<th>%.2f</th>"
                "<th>%s</th>"
            "</tr>"
        "</table>"
        "<a href=\"#\" onclick=\"doDelete()\">Delete</a>"
        "<br>"
        "<a href=\"/\">Home</a>"
        "<script>"
            "function doDelete() {"
                "var xhttp = new XMLHttpRequest();"
                "xhttp.open(\"DELETE\", \"http://127.0.0.1:5000/freelancers/%i\", true);"
                "xhttp.send();"
            "}"
        "</script>"
    "</body>"
"</html>", self->name, self->surname, self->id, self->completedProjects, self->salary, self->birthDate, self->id);
}



char *allFreelancersToHTML(List_t *list, char *buff){
    char tmpBuff[10000];

    sprintf(tmpBuff, "<table>"
                       // "<caption>Freelancers</caption>"
        "<tr>"
            "<th>Id</th>"
            "<th>Name</th>"
            "<th>Surname</th>"
	"</tr>");
                for(int i = 0; i < List_getSize(list); i++){
                    freelancer_t *tmpL = List_get(list, i,NULL);
                    sprintf(tmpBuff, "%s"
    "<tr>"
		"<th><a href=\"/freelancers/%d\">%d</a></th>"
		"<th>%s</th>"
		"<th>%s</th>"
	"</tr>", tmpBuff, tmpL->id, tmpL->id, tmpL->name, tmpL->surname);
                }



                    sprintf(buff,
                        "<!DOCTYPE html>"
"<html>"
    "<head>"
        "<title>All freelancers</title>"
    "</head>"
    "<body>"

            "<h3>All freelancers</h3>"
            "%s"
            "</table>"
            "<br>"
            "<br>"
            "<a href=\"/freelancers/new\">Add freelancer</a>"


    "</body>"
"</html>"
            , tmpBuff);
}


