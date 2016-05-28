#ifndef LIST_H_INCLUDED
#define LIST_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>



typedef struct serial_s serial_t;

typedef struct event_s {
    void * receiver;
    void * callback;
} event_t;


serial_t *
serial_new(char * nName);


char * serialGetName(serial_t * self);
int serialGetSeriesNum(serial_t * self);
int serialGetSerieDate(serial_t * self,int num);
bool seriaIisSeriesCome(serial_t * self,int date);

void
serialFree(serial_t * self);
void
serialPrint(serial_t * self);

void
serialEventPushBack(serial_t * self, event_t * ptr);


int
serialEventGetCount(serial_t * self);

event_t *
serialEventGetEl(serial_t * self, int index);


#endif // LIST_H_INCLUDED

