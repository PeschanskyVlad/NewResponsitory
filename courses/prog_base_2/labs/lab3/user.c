#include <stdio.h>
#include <stdlib.h>
#include "WatchMe.h"
#include "serials.h"
#include "user.h"

user_t * userNew(const char * uName,int number_of_interesting_serials){
    user_t * self = malloc(sizeof(struct user_s));
    strcpy(self->name,uName);
    self->number_of_interesting_serials=number_of_interesting_serials;
    self->interesting_serial=malloc(sizeof(char)*number_of_interesting_serials);

    for(int i=0;i<number_of_interesting_serials;i++){
    self->interesting_serial[i]=malloc(100);
    }

    self->current_serials=0;
    return self;
}



int userAddSerial(user_t * self,const char * sName){
if(self->current_serials < self->number_of_interesting_serials){
    strcpy(self->interesting_serial[self->current_serials],sName);
    self->current_serials++;
}
return self->current_serials;
}

int userPrint(user_t * self){
int i ;
printf("User name: %s\n",self->name);
for( i = 0;i<self->number_of_interesting_serials;i++){
    printf("Serial %i: %s\n",i+1,self->interesting_serial[i]);
}
puts("");
return i;
}

char * userGetSerial(user_t * self,int i){
return self->interesting_serial[i];
}



int userFree(user_t * self){
/*for(int i=0;i<self->number_of_interesting_serials;i++){
    free(self->interesting_serial[i]);
    }*/
    //free(self->interesting_serial);
    free(self);
    return 1;

}

int userGetNumSerials(user_t * self){
return self->number_of_interesting_serials;
}


