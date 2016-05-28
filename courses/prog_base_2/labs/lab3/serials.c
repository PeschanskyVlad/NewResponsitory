#include <stdlib.h>

#include "serials.h"
#include "time.h"
#include "user.h"

struct serial_s {
char name[256];
int number_of_series;
int **series_release_date;
event_t ** arr;
int count;
};

serial_t *
serial_new(char * nName) {
    serial_t * self = malloc(sizeof(struct serial_s));
    strcpy(self->name,nName);
    self->number_of_series=rand()%3+2;

    self->series_release_date = malloc(sizeof(int)*self->number_of_series);

    self->series_release_date[0]=rand()%4+1;

    for(int i=1;i<self->number_of_series;i++){

    self->series_release_date[i]=rand()%3+1+self->series_release_date[i-1];

    }
    self->arr = malloc(0);
    self->count = 0;
    return self;
}



void
printSerial(serial_t * self){

//printf("Series %s begin to appear %i of May.\n",self->name,self->date);
printf("Serial %s has %i series.\n",self->name,self->number_of_series);
for(int i = 0;i<self->number_of_series;i++){
    printf("Series %i comes %i.\n",i+1,self->series_release_date[i]);
}
puts("");
return;

}

char * serialGetName(serial_t * self){
return self->name;
}

int serialGetSeriesNum(serial_t * self){
return self->number_of_series;
}

int serialGetSerieDate(serial_t * self,int num){
return self->series_release_date[num];
}

bool seriaIisSeriesCome(serial_t * self,int date){
    for(int i = 0;i<self->number_of_series;i++){
            if(date==self->series_release_date[i]){
                return true;
            }

    }
    return false;
}



void
serial_free(serial_t * self) {
    free(self->arr);
    free(self->series_release_date);
    free(self);
}

void
event_push_back(serial_t * self, event_t * ptr) {
    self->count++;
    self->arr = realloc(self->arr, sizeof(void *) * self->count);
    self->arr[self->count - 1] = ptr;
}



int
event_getCount(serial_t * self) {
    return self->count;
}

event_t *
event_getEl(serial_t * self, int index) {
    return self->arr[index];
}







