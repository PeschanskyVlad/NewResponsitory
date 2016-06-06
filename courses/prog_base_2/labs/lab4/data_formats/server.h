#ifndef SERVER_H_INCLUDED
#define SERVER_H_INCLUDED
#define BUFFER_LENGTH 100000
#define MSG_LENGTH 10000
#define WORD_LENGTH 100
#include "xml.h"


typedef struct keyvalue_s keyvalue_t;
typedef struct http_request_s http_request_t;

void serverStart(List_t * freelansers);

#endif // SERVER_H_INCLUDED
