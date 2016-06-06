#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#include "server.h"

typedef enum resp_s {HTML, XML} resp_t;

struct keyvalue_s
{
    char key[256];
    char value[256];
};

struct http_request_s
{
    char method[8];
    char uri[256];
    keyvalue_t * form;
    int formLength;
};

int date_check(char *date);

http_request_t
getRequest(const char * const request)
{
    http_request_t req;
    req.form = NULL;
    req.formLength = 0;
    // get method
    ptrdiff_t methodLen = strstr(request, " ") - request;  // find first whitespace
    memcpy(req.method, request, methodLen);
    req.method[methodLen] = '\0';
    // get uri
    const char * uriStartPtr = request + strlen(req.method) + 1;
    const char * uriEndPtr = strstr(uriStartPtr, " ");  // find second whitespace
    ptrdiff_t uriLen = uriEndPtr - uriStartPtr;
    memcpy(req.uri, uriStartPtr, uriLen);
    req.uri[uriLen] = '\0';
    // parse form data
    const char * bodyStartPtr = strstr(request, "\r\n\r\n") + strlen("\r\n\r\n");
    const char * cur = bodyStartPtr;
    const char * pairEndPtr = cur;
    const char * eqPtr = cur;
    while (strlen(cur) > 0)
    {
        pairEndPtr = strchr(cur, '&');
        if (NULL == pairEndPtr)
        {
            pairEndPtr = cur + strlen(cur);
        }
        keyvalue_t kv;
        // get key
        eqPtr = strchr(cur, '=');
        ptrdiff_t keyLen = eqPtr - cur;
        memcpy(kv.key, cur, keyLen);
        kv.key[keyLen] = '\0';
        // get value
        eqPtr++;
        ptrdiff_t valueLen = pairEndPtr - eqPtr;
        memcpy(kv.value, eqPtr, valueLen);
        kv.value[valueLen] = '\0';
        // insert key-value pair into request form list
        req.formLength += 1;
        req.form = realloc(req.form, sizeof(keyvalue_t) * req.formLength);
        req.form[req.formLength - 1] = kv;
        cur = pairEndPtr + ((strlen(pairEndPtr) > 0) ? 1 : 0);
    }
    return req;
}

const char *
getReqestArg(http_request_t * self, const char * key)
{
    for (int i = 0; i < self->formLength; i++)
    {
        if (strcmp(self->form[i].key, key) == 0)
        {
            return self->form[i].value;
        }
    }
    return NULL;
}

const char * keyToString(keyvalue_t * self)
{
    char * str = malloc(sizeof(char) * (strlen(self->key) + strlen(self->value) + 2));
    sprintf(str, "%s=%s\0", self->key, self->value);
    return str;
}

void serverStart(sqlite3 *db)
{
    lib_init();
  //  sqlite3 *db;
 //   int rc = 0;
   // rc = sqlite3_open("teachers.db", &db);
   // if(SQLITE_OK != rc)
   // {
   //     return;
   // }
    socket_t * serverSocket = socket_new();
    socket_bind(serverSocket, 5000);
    socket_listen(serverSocket);

    while(1)
    {
        puts("Waiting for connections");
        socket_t * clientSocket = socket_accept(serverSocket);
        puts("New client");
        char buff[BUFFER_LENGTH];
        int readLength = socket_read(clientSocket, buff, BUFFER_LENGTH);
        if(readLength == 0)
        {
            socket_close(clientSocket);
            socket_free(clientSocket);
            puts("Skipping empty request");
            continue;
        }

        printf("Got Request:\n---------------\n%s\n----------------\n", buff);

        http_request_t req = getRequest(buff);

        printf("Method: %s\nURI: %s\n", req.method, req.uri);
        puts("Data:");
        for(int i = 0; i < req.formLength; i++)
        {
            char * kvStr = keyToString(&req.form[i]);
            printf("\t%s\n", kvStr);
            free(kvStr);
        }
        serverChooseMethod(req, clientSocket, db);

        socket_close(clientSocket);
        socket_free(clientSocket);
    }
    socket_close(serverSocket);
    socket_free(serverSocket);
    sqlite3_close(db);
    free(db);
    lib_free();
}

char *getMessage(int type, const char *usermsg, int code, char *buffer)
{
    char msg[MSG_LENGTH];
    //XML
    if(type == 0)
    {
        switch(code)
        {
        case 200:
        {
            sprintf(buffer,
                    "HTTP/1.1 200 OK\n"
                    "Content-length: %zu\n"
                    "Content-type: application/xml\n"
                    "\n"
                    "%s\0", strlen(usermsg), usermsg);
            break;
        }
        case 403:
        {
            sprintf(msg, "<message>\n"
                    "\t<status>ERROR</status>\n"
                    "<text>Error 403: forbidden</text>"
                    "</message>");
            sprintf(buffer,
                    "HTTP/1.1 403 Error\n"
                    "Content-length: %zu\n"
                    "Content-type: application/xml\n"
                    "\n"
                    "%s\0", strlen(msg), msg);
            break;
        }
        case 404:
        {
            sprintf(msg, "<message>\n"
                    "\t<status>ERROR</status>\n"
                    "<text>Error 404: not found</text>"
                    "</message>");
            sprintf(buffer,
                    "HTTP/1.1 403 Error\n"
                    "Content-length: %zu\n"
                    "Content-type: application/xml\n"
                    "\n"
                    "%s\0", strlen(msg), msg);
            break;
        }
        default:
        {
            sprintf(msg, "<message>\n"
                    "\t<status>ERROR</status>\n"
                    "<text>Error 502: bad gateway</text>"
                    "</message>");
            sprintf(buffer,
                    "HTTP/1.1 502 Error\n"
                    "Content-length: %zu\n"
                    "Content-type: application/xml\n"
                    "\n"
                    "%s\0", strlen(msg), msg);
            break;
        }
        }
    }
    //HTML
    else if (type == 1)
    {
        switch(code)
        {
        case 200:
            sprintf(buffer,
                    "HTTP/1.1 200 OK\n"
                    "Content-length: %zu\n"
                    "Content-type: text/html\n"
                    "\n"
                    "%s\0", strlen(msg), msg);
            break;
        case 403:
            sprintf(msg, "<!DOCTYPE html>"
                    "<html>"
                    "<head>"
                    "<title>403 forbidden</title>"
                    "</title>"
                    "</head>"
                    "<body>"
                    "<h3>Error 403: forbidden</h3>"
                    "</body>"
                    "</html>");
            sprintf(buffer,
                    "HTTP/1.1 403 Error\n"
                    "Content-length: %zu\n"
                    "Content-type: text/html\n"
                    "\n"
                    "%s\0", strlen(msg), msg);
            break;
        case 404:
            sprintf(msg, "<!DOCTYPE html>"
                    "<html>"
                    "<head>"
                    "<title>404 not found</title>"
                    "</title>"
                    "</head>"
                    "<body>"
                    "<h3>Error 404: not found</h3>"
                    "</body>"
                    "</html>");
            sprintf(buffer,
                    "HTTP/1.1 404 Error\n"
                    "Content-length: %zu\n"
                    "Content-type: text/html\n"
                    "\n"
                    "%s\0", strlen(msg), msg);
            break;
        default:
            sprintf(msg, "<!DOCTYPE html>"
                    "<html>"
                    "<head>"
                    "<title>502 bad gateway</title>"
                    "</title>"
                    "</head>"
                    "<body>"
                    "<h3>Error 502: bad gateway</h3>"
                    "</body>"
                    "</html>");
            sprintf(buffer,
                    "HTTP/1.1 502 Error\n"
                    "Content-length: %zu\n"
                    "Content-type: text/html\n"
                    "\n"
                    "%s\0", strlen(msg), msg);
            break;
        }
    }
    return buffer;
}

void serverChooseMethod(http_request_t req, socket_t * clientSocket, sqlite3 *db)
{

    if(!strcmp(req.method, "GET"))
        {
            if(!strcmp(req.uri, "/"))
            {
                char smallMSG[1000];
                sprintf(smallMSG, "<!DOCTYPE html>"
                        "<html>"
                        "<head>"
                        "<title>Freelancers database</title>"
                        "</head>"
                        "<body>"

                        "<h1>Freelancers database</h1>"
                        "<p>Main page.</p>"
                        "<a href=\"/freelancers\">Show freelancers</a>"

                        "</body>"
                        "</html>");

                socket_write_string(clientSocket, smallMSG);
            }
            else if(!strcmp(req.uri, "/freelancers"))
            {
                char result_msg[MSG_LENGTH];

                List_t list = List_new();
                freelancerGetAll(db,list);

                allFreelancersToHTML(list,result_msg);
                List_delete(list);

                socket_write_string(clientSocket, result_msg);;
            }
            else if(!strcmp(req.uri, "/freelancers/new"))
            {
                char result_msg[MSG_LENGTH];
                sprintf(result_msg, "<!DOCTYPE html>"
                        "<html>"
                        "<head>"
                        "<title>Freelancers database</title>"
                        "</head>"
                        "<body>"
                        "<h3>New freelancer</h3>"
                        "<form action=\"/freelancers/\" method=\"POST\">"
                        "Id:<br>"
                        "<input type=\"text\" name=\"id\"><br>"
                        "Name:<br>"
                        "<input type=\"text\" name=\"name\"><br>"
                        "Surname:<br>"
                        "<input type=\"text\" name=\"surname\">"
                        "<br>"
                        "Birthdate:<br>"
                        "<input type=\"text\" name=\"birthdate\">"
                        "<br>"
                        "Salary:<br>"
                        "<input type=\"text\" name=\"salary\">"
                        "<br>"
                        "Completed projects:<br>"
                        "<input type=\"text\" name=\"cProjects\">"
                        "<br>"
                        "<input type=\"submit\" value=\"Submit\">"
                        "</form>"

                        "<br>"
                        "<a href=\"/\">Home</a>"

                        "</body>"
                        "</html>");
                socket_write_string(clientSocket, result_msg);
            }
            else if(strcmp(req.uri, "/freelancers")>0)
            {
                char result_msg[MSG_LENGTH];



                List_t list = List_new();
                freelancerGetAll(db,list);


               /* printf("\n\nI: %i\n\n",strnicmp(req.uri,"/api/",5));
                if(strnicmp(req.uri,"/api/",5)==0){
                printf("\n\nHere\n\n");

                return;
                }*/


                int id = atoi(strtok(req.uri, "/freelancers/"));



                if(isContaint(list, id) == -1)
                {
                    getMessage(XML, NULL, 404, result_msg);

                    socket_write_string(clientSocket, result_msg);
                    return;
                }

                freelancer_t * tmpL = freelancerGet(db,id);
                //read_teacher(db, pass, t1, s);

                char user_msg[MSG_LENGTH];
                freelancerToHTML(tmpL,user_msg);
                socket_write_string(clientSocket, user_msg);



            } else if(strcmp(req.uri, "/api/freelancers") > 0)
            {
                //this

                char * tmpC = strtok(req.uri, "/api/freelancers/");

                int id = atoi(tmpC);

                List_t list = List_new();
                freelancerGetAll(db,list);

                char result_msg[MSG_LENGTH];


                if(isContaint(list, id)!=-1)
                {
                freelancer_t * tmpL = freelancerGet(db,&id);
                //read_teacher(db, pass, t1, s);

                char user_msg[MSG_LENGTH];

                xmlFreelancerToMessage(tmpL);
                strcpy(user_msg,xmlFreelancerToMessage(tmpL));

                getMessage(0, user_msg, 200, result_msg);
               // socket_write_string(clientSocket, result_msg);

                socket_write_string(clientSocket, user_msg);
                    return;
                }





                //this

      //  char result_msg[MSG_LENGTH];

        char requestToParse[1000] = "\0";


        sscanf(req.uri, "/api/freelancers?%s", requestToParse);

        // Get request values.
        int arg1 = 0;
        float arg2 = 0;



        int checkCode = sscanf(requestToParse, "count=%i&salary=%f",&arg1,&arg2);





        if (checkCode != 2)
        {
                char result_msg[MSG_LENGTH];
                getMessage(0, NULL, 403, result_msg);
                socket_write_string(clientSocket, result_msg);
                return;


        }


            int state = 1;

            printf("Arg1: %i Arg2: %.2f\n",arg1,arg2);

            //printf("\n\nHere\n\n");
            List_t list2 = List_new();

            freelancerGetNeeded(db,list2,&arg1,&arg2,&state);


            char user_msg[MSG_LENGTH];
            strcpy(user_msg,xmlFreelancersToMessage(list2));

            getMessage(0, user_msg, 200, result_msg);
            socket_write_string(clientSocket, result_msg);




            return;

    }else if(!strcmp(req.uri, "/api/freelancers"))
            {
                char result_msg[MSG_LENGTH];

                List_t list = List_new();
                freelancerGetAll(db,list);


              //  read_all_teachers(db, list, s);

                char SomeMsg[MSG_LENGTH];
                strcpy(SomeMsg,xmlFreelancersToMessage(list));


               //puts(SomeMsg);

               getMessage(0, SomeMsg, 200, result_msg);

               //puts(result_msg);

               socket_write_string(clientSocket, result_msg);


            }/*else if(atoi(req.uri)>0){
                printf("\n\nHere\n\n");

                char result_msg[MSG_LENGTH];

                int tmpI = atoi(req.uri);

                List_t list = List_new();
                freelancerGetAll(db,list);
                if(isContaint(list,tmpI)){

                 freelancer_t * tmpLancer =   freelancerGet(db,tmpI);
                 char user_msg[MSG_LENGTH];
                 strcpy(user_msg,xmlFreelancerToMessage(tmpLancer));
                 getMessage(0, user_msg, 200, result_msg);
                 socket_write_string(clientSocket, result_msg);

                }





            }*/
            else {
                char result_msg[MSG_LENGTH];
                getMessage(0, NULL, 404, result_msg);
                socket_write_string(clientSocket, result_msg);
                return;
        }
    }

        else if(!strcmp(req.method, "DELETE"))
        {
            if(strcmp(req.uri, "/freelancers/") > 0)
            {
                char result_msg[MSG_LENGTH];


                List_t list = List_new();
                freelancerGetAll(db,list);



                int id = atoi(strtok(req.uri, "/freelancers/"));



                int c = isContaint(list, id);
                if(c == -1)
                {
                    getMessage(XML, NULL, 404, result_msg);
                    socket_write_string(clientSocket, result_msg);
                    return;
                }



                freelancerDelete(db,id);

                getMessage(XML, "<message>"
                          "<text>Deletion succesfull!</text>"
                          "</message>", 200, result_msg);
                socket_write_string(clientSocket, result_msg);
            }
            else
            {
                char result_msg[MSG_LENGTH];
                getMessage(XML, NULL, 404, result_msg);
                socket_write_string(clientSocket, result_msg);
                return;
            }
        }

        else if(!strcmp(req.method, "POST"))
        {

            if(!strcmp(req.uri, "/freelancers/"))
            {

                char result_msg[MSG_LENGTH];


                int id = atoi(getReqestArg(&req, "id"));
                const char * name = getReqestArg(&req,"name");
                const char * surname = getReqestArg(&req,"surname");
                const char * birthdate = getReqestArg(&req,"birthdate");
                float salary = atof(getReqestArg(&req, "salary"));
                int completedProjects = atoi(getReqestArg(&req, "cProjects"));


                if(!id || !name || !surname || !birthdate || !salary || !completedProjects)
                {
                    char result_msg[MSG_LENGTH];
                    getMessage(0, NULL, 403, result_msg);
                    socket_write_string(clientSocket, result_msg);
                    return;
                }
                if(completedProjects < 0 || salary < 0|| !checkDate(birthdate))
                {
                    char result_msg[MSG_LENGTH];
                    getMessage(0, NULL, 403, result_msg);
                    socket_write_string(clientSocket, result_msg);
                    return;
                }

                freelancerAdd(db,id,name,surname,salary,completedProjects,birthdate);

                List_t list = List_new();
                freelancerGetAll(db,list);

                allFreelancersToHTML(list,result_msg);


                socket_write_string(clientSocket, result_msg);
            }
            else
            {
                char result_msg[MSG_LENGTH];
                getMessage(0, NULL, 403, result_msg);
                socket_write_string(clientSocket, result_msg);
                return;
            }
        }
     //  else if(1){

              /*  int id = atoi(strtok(req.uri, "/freelancers/"));

                List_t list = List_new();
                freelancerGetAll(db,list);
                char result_msg[MSG_LENGTH];
                if(isContaint(list, id) == -1)
                {
                    getMessage(0, NULL, 404, result_msg);

                    socket_write_string(clientSocket, result_msg);
                    return;
                }

                freelancer_t * tmpL = freelancerGet(db,id);
                //read_teacher(db, pass, t1, s);

                char user_msg[MSG_LENGTH];

                xmlFreelancerToMessage(tmpL);
                strcpy(user_msg,xmlFreelancerToMessage(tmpL));

                getMessage(0, user_msg, 200, result_msg);
               // socket_write_string(clientSocket, result_msg);

                socket_write_string(clientSocket, user_msg);

                return;*/

      //  }

        //this
    else{
        char result_msg[MSG_LENGTH];
        getMessage(0, NULL, 404, result_msg);
        socket_write_string(clientSocket, result_msg);
        return;
    }
}


int checkDate(char *date){
    if(strlen(date) != 10){
        return 0;
    }
    for(int i = 0; i < 10; i++){
        if(i == 2 || i == 5){
            if(date[i] != '-'){
                return 0;
            }
        } else {
            if(!isdigit(date[i]))
                return 0;
        }
    }
    return 1;
}

