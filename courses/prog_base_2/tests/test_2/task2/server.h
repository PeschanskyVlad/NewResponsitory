#ifndef SERVER_H_INCLUDED
#define SERVER_H_INCLUDED
#include "socket.h"
#include <libxml/parser.h>
#include <libxml/tree.h>
#include <time.h>
#define CHAR_LENGTH 1000
#define BUFFER_LENGTH 100000

typedef struct gdata gdata_t;

void serverNew(void);


#endif // SERVER_H_INCLUDED
