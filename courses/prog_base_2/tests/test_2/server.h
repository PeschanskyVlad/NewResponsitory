#ifndef SERVER_H_INCLUDED
#define SERVER_H_INCLUDED
#include "socket.h"
#define BUFFER_LENGTH 100000



typedef struct http_request_s http_request_t;

http_request_t
http_request_parse(const char * const request);
typedef struct keyvalue_s keyvalue_t;

void serverNew(void);

#endif // SERVER_H_INCLUDED
