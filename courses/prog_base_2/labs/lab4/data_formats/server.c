#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "freelancer.h"
#include "list.h"
#include "server.h"


#include <stddef.h>

#include <ctype.h>


int id=-1;

struct keyvalue_s{
    char key[256];
    char value[256];
};

struct http_request_s{
    char method[8];
    char uri[256];
    keyvalue_t * form;
    int formLength;
};

int checkDate(char *date){
    if(strlen(date) != 10){
        return 0;
    }
    for(int i = 0; i < 10; i++){
        if(i == 2 || i == 5){
            if(date[i] != '.'){
                return 0;
            }
        } else {
            if(!isdigit(date[i]))
                return 0;
        }
    }
    return 1;
}

http_request_t
http_request_parse(const char * const request) {
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
    while (strlen(cur) > 0) {
        pairEndPtr = strchr(cur, '&');
        if (NULL == pairEndPtr) {
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
http_request_getArg(http_request_t * self, const char * key) {
    for (int i = 0; i < self->formLength; i++) {
        if (strcmp(self->form[i].key, key) == 0) {
            return self->form[i].value;
        }
    }
    return NULL;
}

const char * keyvalue_toString(keyvalue_t * self) {
    char * str = malloc(sizeof(char) * (strlen(self->key) + strlen(self->value) + 2));
    sprintf(str, "%s=%s\0", self->key, self->value);
    return str;
}

void serverStart(List_t * freelansers){
    lib_init();
    socket_t * serverSocket = socket_new();
    socket_bind(serverSocket, 5000);
    socket_listen(serverSocket);



    while(1){




        puts("Waiting for connections");
        socket_t * clientSocket = socket_accept(serverSocket);
        puts("New client");
        char buff[BUFFER_LENGTH];
        int readLength = socket_read(clientSocket, buff, BUFFER_LENGTH);
        if(readLength == 0){
            socket_close(clientSocket);
            socket_free(clientSocket);
            puts("Skipping empty request");
            continue;
        }

        printf("Got Request:\n---------------\n%s\n----------------\n", buff);

        http_request_t req = http_request_parse(buff);

        printf("Method: %s\nURI: %s\n", req.method, req.uri);
        puts("Data:");
        for(int i = 0; i < req.formLength; i++){
            char * kvStr = keyvalue_toString(&req.form[i]);
            printf("\t%s\n", kvStr);
            free(kvStr);
        }

        http_request_chooseMethod(req, clientSocket, freelansers);
        socket_close(clientSocket);
        socket_free(clientSocket);
    }
    socket_close(serverSocket);
    socket_free(serverSocket);
    lib_free();
}

void http_request_chooseMethod(http_request_t req, socket_t * clientSocket, List_t *freelancers){
    if(!strcmp(req.uri, "/"))
        {
        char msg[MSG_LENGTH];
        sprintf(msg,
                    "<!DOCTYPE html>"
"<html>"
    "<head>"
        "<title>Freelancers database</title>"
    "</head>"
    "<body>"

            "<h1>FREELANCERS DATABASE</h1>"


            "<a href=\"/freelancers\">Show freelancers.</a>"

    "</body>"
"</html>"
);
        socket_write_string(clientSocket, msg);
        }


    else
        if (strcmp(req.uri, "/freelancers") == 0)
        {


            if(strcmp(req.method, "GET") == 0){
                char tempBuff[MSG_LENGTH];
                sprintf(tempBuff, "<table>"
                        "<caption>FREELANCERS:</caption>"
        "<tr>"
            "<th>Id</th>"
            "<th>Name</th>"
            "<th>Surname</th>"
	"</tr>");
                for(int i = 0; i < List_getSize(freelancers); i++){
                        freelanser_t * tmpLancer = List_get(freelancers,i,NULL);

                    sprintf(tempBuff, "%s"
    "<tr>"
		"<th><a href=\"/freelancers/%d\">%d</a></th>"
		"<th>%s</th>"
		"<th>%s</th>"
	"</tr>", tempBuff, i+1, i+1, tmpLancer->name, tmpLancer ->surname);

                }



                    char result[10000];
                    sprintf(result,
                        "<!DOCTYPE html>"
"<html>"
    "<head>"
     "<title>Freelancers database</title>"
    "</head>"
    "<body>"

            "<h3>All freelancers</h3>"
            "%s"
            "</table>"
            "<br>"
            "<a href=\"/freelancers/new\">Add freelancer.</a>"


    "</body>"
"</html>"
                        , tempBuff);
                    socket_write_string(clientSocket, result);
                }
            else {
                char result_msg[MSG_LENGTH];
            char res[MSG_LENGTH];
            sprintf(res,
                    "<!DOCTYPE html>"
"<html>"
    "<head>"
        "<title>Freelancers database</title>"
    "</head>"
    "<body>"
        "<p>Error!</p>"
    "</body>"
"</html>"
                          );
                sprintf(result_msg,
                                "HTTP/1.1 403 ERROR\n"
                                "Content-length: %zu\n"
                                "Content-type: text/html\n"
                                "\n"
                                "%s\0",
                                strlen(res), res);
                socket_write_string(clientSocket, result_msg);
            }
        }

    else if (strcmp(req.uri, "/freelancers") > 0)
        {
            if(strcmp(req.method, "POST") == 0)
                {
                    char result[MSG_LENGTH];
                    const char * name = http_request_getArg(&req, "Name");
                    const char * sName = http_request_getArg(&req, "Surname");
                    int  age = atoi(http_request_getArg(&req, "Age"));
                    const char * birthdate = http_request_getArg(&req, "Birthdate");

                    float workExperience = atof(http_request_getArg(&req, "WorkExperience"));
                    const char * company = http_request_getArg(&req, "Company");
                    const char * companyposition = http_request_getArg(&req, "CompanyPosition");

                    if(!name || !sName || !age ||
                       !birthdate || !workExperience || !company || !companyposition){
                        char res[MSG_LENGTH];
            sprintf(res,
                    "<!DOCTYPE html>"
"<html>"
    "<head>"
       "<title>Freelancers database</title>"
    "</head>"
    "<body>"
        "<p>Error: empty field</p>"
    "</body>"
"</html>"
                           );
                sprintf(result,
                                "HTTP/1.1 403 ERROR\n"
                                "Content-length: %zu\n"
                                "Content-type: text/html\n"
                                "\n"
                                "%s\0",
                                strlen(res), res);
                            socket_write_string(clientSocket, result);
                            return 1;
                       }

                    else if(strlen(name) == 0 || strlen(name) > WORD_LENGTH || strlen(sName) == 0 || strlen(sName) > WORD_LENGTH){
                            char res[MSG_LENGTH];
            sprintf(res,
                    "<!DOCTYPE html>"
"<html>"
    "<head>"
        "<title>Freelancers database</title>"
    "</head>"
    "<body>"
        "<p>Error: invalid name/surname</p>"
    "</body>"
"</html>");

                sprintf(result,
                                "HTTP/1.1 403 ERROR\n"
                                "Content-length: %zu\n"
                                "Content-type: text/html\n"
                                "\n"
                                "%s\0",
                                strlen(res), res);
                            socket_write_string(clientSocket, result);
                            return 1;
                    } else if(!checkDate(birthdate)){
                        char res[MSG_LENGTH];
            sprintf(res,
                    "<!DOCTYPE html>"
"<html>"
    "<head>"
     "<title>Freelancers database</title>"
    "</head>"
    "<body>"
        "<p>Error: invalid birth date</p>"
    "</body>"
"</html>"
                           );
                sprintf(result,
                                "HTTP/1.1 403 ERROR\n"
                                "Content-length: %zu\n"
                                "Content-type: text/html\n"
                                "\n"
                                "%s\0",
                                strlen(res), res);
                            socket_write_string(clientSocket, result);
                            return 1;

                    } else if(strlen(company) == 0 || strlen(company) > WORD_LENGTH){
                        char res[MSG_LENGTH];
            sprintf(res,
                    "<!DOCTYPE html>"
"<html>"
    "<head>"
      "<title>Freelancers database</title>"
    "</head>"
    "<body>"
        "<p>Error: invalid company</p>"
    "</body>"
"</html>"
        );
                sprintf(result,
                                "HTTP/1.1 403 ERROR\n"
                                "Content-length: %zu\n"
                                "Content-type: text/html\n"
                                "\n"
                                "%s\0",
                                strlen(res), res);
                            socket_write_string(clientSocket, result);
                            return 1;
                    } else if(strlen(companyposition) == 0 || strlen(companyposition) > WORD_LENGTH){
                        char res[MSG_LENGTH];
            sprintf(res,
                    "<!DOCTYPE html>"
"<html>"
    "<head>"
        "<title>Freelancers database</title>"
    "</head>"
    "<body>"
        "<p>Error: invalid company Position</p>"
    "</body>"
"</html>"
                      );
                sprintf(result,
                                "HTTP/1.1 403 ERROR\n"
                                "Content-length: %zu\n"
                                "Content-type: text/html\n"
                                "\n"
                                "%s\0",
                                strlen(res), res);
                    }else {
                         freelancerAddParam(freelancers, name, sName, birthdate, age, workExperience, company, companyposition);




                        sprintf(result,"<!DOCTYPE html>"
"<html>"
    "<head>"
        "<title>KPI FPM TDB</title>"
    "</head>"
    "<body>"
        "<p>Freelancer successfully added</p>"
        "<a href=\"/\">Home</a>"
    "</body>"
"</html>"

                                );
                        socket_write_string(clientSocket, result);
                        return 1;


                        }


                    }
        else if(!strcmp(req.uri, "/freelancers/new")){

            if(!strcmp(req.method, "GET")){
                    char result_msg[MSG_LENGTH];
                    sprintf(result_msg, "<!DOCTYPE html>"
"<html>"
    "<head>"
        "<title>Freelancers database</title>"
    "</head>"
    "<body>"
        "<h3>New freelancer</h3>"
        "<form action=\"/freelancers/\" method=\"POST\">"
  "Name:<br>"
  "<input type=\"text\" name=\"Name\"><br>"
  "Surname:<br>"
  "<input type=\"text\" name=\"Surname\">"
  "<br>"

  "Age:<br>"
  "<input type=\"text\" name=\"Age\">"
  "<br>"


  "Birth date:<br>"
  "<input type=\"text\" name=\"Birthdate\">"
  "<br>"
  "Salary:<br>"
  "<input type=\"text\" name=\"WorkExperience\">"
  "<br>"
  "Company:<br>"
  "<input type=\"text\" name=\"Company\">"
  "<br>"
  "Company position:<br>"
  "<input type=\"text\" name=\"CompanyPosition\">"
  "<br>"

  "<input type=\"submit\" value=\"Confirm\">"
"</form>"

    "<br>"
    "<a href=\"/\">Home</a>"

    "</body>"
"</html>");
                    socket_write_string(clientSocket, result_msg);
                }else {
                    char result_msg[MSG_LENGTH];
            char res[MSG_LENGTH];
            sprintf(res,
                    "<!DOCTYPE html>"
"<html>"
    "<head>"
      "<title>Freelancers database</title>"
    "</head>"
    "<body>"
        "<p>Error!</p>"
    "</body>"
"</html>"
                          );
                sprintf(result_msg,
                                "HTTP/1.1 403 ERROR\n"
                                "Content-length: %zu\n"
                                "Content-type: text/html\n"
                                "\n"
                                "%s\0",
                                strlen(res), res);
                    socket_write_string(clientSocket, result_msg);
                    return 1;
                }
        }else{

         //id = atoi(strtok(req.uri, "/freelancers"))-1;


       if(atoi(strtok(req.uri, "/freelancers"))>0&&atoi(strtok(req.uri, "/freelancers"))<=List_getSize(freelancers)||strcmp(req.method, "DELETE") == 0)
      // if(1)
            {

            if(strcmp(req.method, "GET") == 0)
                {
                     id = atoi(strtok(req.uri, "/freelancers"))-1;

                        char result[BUFFER_LENGTH];

                        freelanser_t * temp = List_get(freelancers,id,NULL);

                        sprintf(result, "<!DOCTYPE html>"
"<html>"
    "<head>"
         "<title>Freelancers database</title>"
    "</head>"
    "<body>"
        "<h3>%s %s</h3>"
        "<table>"
            "<tr>"
                "<th>ID:</th>"
                "<th>Age:</th>"
                "<th>Birth date:</th>"
                "<th>Salary:</th>"
                "<th>Company</th>"
                "<th>Company position:</th>"

            "</tr>"
            "<tr>"
                "<th>%i</th>"
                "<th>%i</th>"
                "<th>%s</th>"
                "<th>%.2f</th>"
                "<th>%s</th>"
                "<th>%s</th>"

            "</tr>"
        "</table>"
        "<a href=\"#\" onclick=\"doDelete()\">Delete</a>"
        "<br>"
        "<a href=\"/\">Home</a>"
        "<script>"
            "function doDelete() {"
                "var xhttp = new XMLHttpRequest();"
                "xhttp.open(\"DELETE\", \"http://127.0.0.1:5000/teachers/%d\", true);"
                "xhttp.send();"
            "}"
        "</script>"
    "</body>"
"</html>"

                            , temp->name, temp->surname, id+1, temp->pD->age,  temp->pD->birthdate, temp->pD->workExperience, temp->pos->company, temp->pos->name);


                        socket_write_string(clientSocket, result);
                        return 1;
                   // }
                }
                else if(strcmp(req.method, "DELETE") == 0)
                {

                    List_remove(freelancers,id,NULL);

                    char result_msg[MSG_LENGTH];
                    sprintf(result_msg,
                            "<!DOCTYPE html>"
    "<html>"
    "<head>"
      "<title>Freelancers database</title>"
    "</head>"
    "<body>"
        "<p>%d Deleted!</p>"
        "<a href=\"/\">Home</a>"
    "</body>"
"</html>", id);
                    socket_write_string(clientSocket, result_msg);


                    return 1;


                }else {
                    char result_msg[MSG_LENGTH];
            char res[MSG_LENGTH];
            sprintf(res,
                    "<!DOCTYPE html>"
"<html>"
    "<head>"
      "<title>Freelancers database</title>"
    "</head>"
    "<body>"
        "<p>Error!</p>"
    "</body>"
"</html>"
                           );
                sprintf(result_msg,
                                "HTTP/1.1 403 ERROR\n"
                                "Content-length: %zu\n"
                                "Content-type: text/html\n"
                                "\n"
                                "%s\0",
                                strlen(res), res);
                    socket_write_string(clientSocket, result_msg);
                    return 1;
                }
            }
            else {
                char result_msg[MSG_LENGTH];
                char res[MSG_LENGTH];
                sprintf(res,
                        "<!DOCTYPE html>"
"<html>"
    "<head>"
        "<title>Freelancers database</title>"
    "</head>"
    "<body>"
        "<p>Error: freelancer not found</p>"
    "</body>"
"</html>", id);
                sprintf(result_msg,
                                "HTTP/1.1 404 ERROR\n"
                                "Content-length: %zu\n"
                                "Content-type: text/html\n"
                                "\n"
                                "%s\0",
                                strlen(res), res);
                socket_write_string(clientSocket, result_msg);
                return 1;
            }

            }
        }

    else if(strcmp(req.uri, "/api")>0){
            if(!strcmp(req.uri, "/api/"))
        {
        char msg[MSG_LENGTH];
        sprintf(msg,

                    "<message>\n"
                    "\t<status>XML OK</status>\n"
                    "\t<text>START XML MODULE!</text>\n"
                    "</message>\n");

        socket_write_string(clientSocket, msg);
        }

    else
        if (strcmp(req.uri, "/api/freelancers") == 0)
        {
           // puts("in /api/freelancers");
            if(strcmp(req.method, "GET") == 0){

 //To Do
                    char result[10000];
                    sprintf(result,
                        "HTTP/1.1 200 OK\n"
                        "Content-length: %zu\n"
                        "Content-type: application/xml\n"
                        "\n"
                        "%s\0",
                        strlen(xmlFreelancersToMessage(freelancers)), xmlFreelancersToMessage(freelancers));//, tempBuff);
                        puts("result:");
                        puts(result);
                    socket_write_string(clientSocket, result);
                }
          /*  else {
                char result_msg[MSG_LENGTH];
            char res[MSG_LENGTH];
            sprintf(res,

                            "<message>\n"
                            "\t<status>Error!</status>\n"
                            "\t<text>Not Allowed</text>\n"
                            "</message>\n");
                sprintf(result_msg,
                                "HTTP/1.1 403 ERROR\n"
                                "Content-length: %zu\n"
                                "Content-type: application/xml\n"
                                "\n"
                                "%s\0",
                                strlen(res), res);
                socket_write_string(clientSocket, result_msg);
            }*/
        }
  //  else
        if (strcmp(req.uri, "/api/freelancers") > 0)
        {
            if(strcmp(req.method, "POST") == 0)
                {



                    char result[MSG_LENGTH];
                    const char * name = http_request_getArg(&req, "Name");
                    const char * sName = http_request_getArg(&req, "Surname");
                    int  age = atoi(http_request_getArg(&req, "Age"));
                    const char * birthdate = http_request_getArg(&req, "Birthdate");

                    float workExperience = atof(http_request_getArg(&req, "WorkExperience"));
                    const char * company = http_request_getArg(&req, "Company");
                    const char * companyposition = http_request_getArg(&req, "CompanyPosition");

                    if(!name || !sName || !age ||
                       !birthdate || !workExperience || !company || !companyposition){


                              char res[MSG_LENGTH];
            sprintf(res,
                    "<!DOCTYPE html>"
"<html>"
    "<head>"
       "<title>Freelancers database</title>"
    "</head>"
    "<body>"
        "<p>Error: empty field</p>"
    "</body>"
"</html>"
                           );
                sprintf(result,
                                "HTTP/1.1 403 ERROR\n"
                                "Content-length: %zu\n"
                                "Content-type: text/html\n"
                                "\n"
                                "%s\0",
                                strlen(res), res);
                            socket_write_string(clientSocket, result);
                            return 1;
                       }

                    else if(strlen(name) == 0 || strlen(name) > WORD_LENGTH || strlen(sName) == 0 || strlen(sName) > WORD_LENGTH){
                            char res[MSG_LENGTH];
            sprintf(res,
                    "<!DOCTYPE html>"
"<html>"
    "<head>"
        "<title>Freelancers database</title>"
    "</head>"
    "<body>"
        "<p>Error: invalid name/surname</p>"
    "</body>"
"</html>");

                sprintf(result,
                                "HTTP/1.1 403 ERROR\n"
                                "Content-length: %zu\n"
                                "Content-type: text/html\n"
                                "\n"
                                "%s\0",
                                strlen(res), res);
                            socket_write_string(clientSocket, result);
                            return 1;
                    } else if(!checkDate(birthdate)){
                        char res[MSG_LENGTH];
            sprintf(res,
                    "<!DOCTYPE html>"
"<html>"
    "<head>"
     "<title>Freelancers database</title>"
    "</head>"
    "<body>"
        "<p>Error: invalid birth date</p>"
    "</body>"
"</html>"
                           );
                sprintf(result,
                                "HTTP/1.1 403 ERROR\n"
                                "Content-length: %zu\n"
                                "Content-type: text/html\n"
                                "\n"
                                "%s\0",
                                strlen(res), res);
                            socket_write_string(clientSocket, result);
                            return 1;

                    } else if(strlen(company) == 0 || strlen(company) > WORD_LENGTH){
                        char res[MSG_LENGTH];
            sprintf(res,
                    "<!DOCTYPE html>"
"<html>"
    "<head>"
      "<title>Freelancers database</title>"
    "</head>"
    "<body>"
        "<p>Error: invalid company</p>"
    "</body>"
"</html>"
        );
                sprintf(result,
                                "HTTP/1.1 403 ERROR\n"
                                "Content-length: %zu\n"
                                "Content-type: text/html\n"
                                "\n"
                                "%s\0",
                                strlen(res), res);
                            socket_write_string(clientSocket, result);
                            return 1;
                    } else if(strlen(companyposition) == 0 || strlen(companyposition) > WORD_LENGTH){
                        char res[MSG_LENGTH];
            sprintf(res,
                    "<!DOCTYPE html>"
"<html>"
    "<head>"
        "<title>Freelancers database</title>"
    "</head>"
    "<body>"
        "<p>Error: invalid company Position</p>"
    "</body>"
"</html>"
                      );
                sprintf(result,
                                "HTTP/1.1 403 ERROR\n"
                                "Content-length: %zu\n"
                                "Content-type: text/html\n"
                                "\n"
                                "%s\0",
                                strlen(res), res);
                    }

                     // to this
                     else {



                    freelancerAddParam(freelancers, name, sName, birthdate, age, workExperience, company, companyposition);

                    printf("New:\n"
                          "<freelancer>"
                          "\t<name>%s</name>\n"
                          "\t<surname>%s</surname>\n"
                          "\t<personalData>\n"
                          "\t\t<birthdate>%s</birthdate>\n"
                          "\t\t<age>%i</age>\n"
                          "\t\t<workExperience>%.2f</workExperience>\n"
                          "\t</personalData>\n"
                          "\t<position company = %s>%s</position>\n"
                          "</freelancer>",
                            name, sName, birthdate, age, workExperience, company, companyposition);

                        char res[MSG_LENGTH];
                        sprintf(res, "New:\n"
                          "<freelancer>"
                          "\t<name>%s</name>\n"
                          "\t<surname>%s</surname>\n"
                          "\t<personalData>\n"
                          "\t\t<birthdate>%s</birthdate>\n"
                          "\t\t<age>%i</age>\n"
                          "\t\t<workExperience>%.2f</workExperience>\n"
                          "\t</personalData>\n"
                          "\t<position company = %s>%s</position>\n"
                          "</freelancer>",
                            name, sName, birthdate, age, workExperience, company, companyposition);
                        sprintf(result,



                                "HTTP/1.1 200 OK\n"
                                "Content-length: %zu\n"
                                "Content-type: application/xml\n"
                                "\n"
                                "%s\0",
                                strlen(res), res);
                        socket_write_string(clientSocket, result);
                        return 1;
                        }

        }
        // else {
        }

        if(atoi(strtok(req.uri,  "/api/freelancers"))>0&&atoi(strtok(req.uri,  "/api/freelancers"))<=List_getSize(freelancers)||strcmp(req.method, "DELETE") == 0)
            {
            if(strcmp(req.method, "GET") == 0)
                {
                     id = atoi(strtok(req.uri, "/api/freelancers")) - 1;

                if(xmlFreelancerToMessage(List_get(freelancers, id,NULL), id) != NULL)
                    {
                        char result[BUFFER_LENGTH];
                        freelanser_t *t = List_get(freelancers, id,NULL);
                        sprintf(result,


                            "HTTP/1.1 200 OK\n"
                            "Content-length: %zu\n"
                            "Content-type: application/xml\n"
                            "\n"
                            "%s\0",
                            strlen(xmlFreelancerToMessage(t, id)), xmlFreelancerToMessage(t, id));


                        socket_write_string(clientSocket, result);
                        return 1;
                    }
                }

                else if(strcmp(req.method, "DELETE") == 0)
                {
                    List_remove(freelancers,id,NULL);
                    char result_msg[MSG_LENGTH];
                    sprintf(result_msg,

                            "<message>\n"
                            "\t<status>ok</status>\n"
                            "\t<text>Freelancer deleted</text>\n"
                            "</message>\n");//, id);
                    socket_write_string(clientSocket, result_msg);
                    return 1;
                }
                else {
                    char result_msg[MSG_LENGTH];
            char res[MSG_LENGTH];
            sprintf(res,

                            "<message>\n"
                            "\t<status>Error!</status>\n"
                            "\t<text>Not Allowed</text>\n"
                            "</message>\n");
                sprintf(result_msg,
                                "HTTP/1.1 403 ERROR\n"
                                "Content-length: %zu\n"
                                "Content-type: application/xml\n"
                                "\n"
                                "%s\0",
                                strlen(res), res);
                    socket_write_string(clientSocket, result_msg);
                    return 1;
                }
           } else {
                char result_msg[MSG_LENGTH];
                char res[MSG_LENGTH];
                sprintf(res,

                        "<message>\n"
                        "\t<status>error</status>\n"
                        "\t<text>Freelancer missed</text>\n"
                        "</message>\n", id);
                sprintf(result_msg,
                                "HTTP/1.1 404 ERROR\n"
                                "Content-length: %zu\n"
                                "Content-type: application/xml\n"
                                "\n"
                                "%s\0",
                                strlen(res), res);
                socket_write_string(clientSocket, result_msg);
                return 1;
            }

        //}

       // }
         //else
           if(1) {
                    char result_msg[MSG_LENGTH];
            char res[MSG_LENGTH];
            sprintf(res,

                            "<message>\n"
                            "\t<status>error</status>\n"
                            "\t<text>Not Found.</text>\n"
                            "</message>\n");
                sprintf(result_msg,
                                "HTTP/1.1 403 ERROR\n"
                                "Content-length: %zu\n"
                                "Content-type: application/xml\n"
                                "\n"
                                "%s\0",
                                strlen(res), res);
                    socket_write_string(clientSocket, result_msg);
                    return 1;
                }
        }
        else {
            char result_msg[MSG_LENGTH];
            char res[MSG_LENGTH];
            sprintf(res,

                            "<message>\n"
                            "\t<status>Error!</status>\n"
                            "\t<text>Not Found.</text>\n"
                            "</message>\n");
                sprintf(result_msg,
                                "HTTP/1.1 404 ERROR\n"
                                "Content-length: %zu\n"
                                "Content-type: application/xml\n"
                                "\n"
                                "%s\0",
                                strlen(res), res);
            socket_write_string(clientSocket, result_msg);
            return 1;
    }
}



