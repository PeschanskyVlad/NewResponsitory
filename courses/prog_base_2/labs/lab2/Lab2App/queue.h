#ifndef QUEUE_H_INCLUDED
#define QUEUE_H_INCLUDED

#include<stdbool.h>

typedef struct Queue * Queue_t;

Queue_t Queue_new();
void Queue_delete(Queue_t self);
void Queue_enqueue(Queue_t self, int val);
int Queue_dequeue(Queue_t self);
int Queue_head(Queue_t self);
void Queue_print(Queue_t self);
int Queue_tail(Queue_t self);
bool Queue_isEmpty(Queue_t self);
unsigned int Queue_getSize(Queue_t self);
int Queue_getSum(Queue_t self);


#endif // QUEUE_H_INCLUDED
