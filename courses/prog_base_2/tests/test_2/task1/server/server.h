#ifndef SERVER_H_INCLUDED
#define SERVER_H_INCLUDED
#include "socket.h"
#define BUFFER_LENGTH 100000
#define CHAR_LENGTH 1000



typedef struct keyvalue_s keyvalue_t;
typedef struct http_request_s http_request_t;

http_request_t
http_request_parse(const char * const request);

typedef struct keyvalue_s keyvalue_t;

void serverInfo(socket_t * client, int get);

void serverNew(void);

#endif // SERVER_H_INCLUDED
