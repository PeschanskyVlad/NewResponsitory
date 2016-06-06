#ifndef SERVER_H_INCLUDED
#define SERVER_H_INCLUDED

#define BUFFER_LENGTH 100000
#define MSG_LENGTH 10000
#define WORD_LENGTH 100
#include <sqlite3.h>
#include "socket.h"
#include "list.h"
#include "freelanser.h"


typedef struct keyvalue_s keyvalue_t;
typedef struct http_request_s http_request_t;



char * xmlFreelancerToMessage(freelancer_t *self);
char * xmlFreelancersToMessage(List_t * list);

char *freelancerToHTML(freelancer_t *self, char *buff);
char *allFreelancersToHTML(List_t *list, char *buff);




http_request_t
getRequest(const char * const request);

const char *
getReqestArg(http_request_t * self, const char * key);

const char *
keyToString(keyvalue_t * self);

void serverStart(sqlite3 *db);


void serverChooseMethod(http_request_t req, socket_t * clientSocket, sqlite3 *db);


#endif // SERVER_H_INCLUDED
