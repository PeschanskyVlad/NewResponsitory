#include "WatchMe.h"
#include "serials.h"
#include "user.h"
#define serialsNumber 5

struct watch_me_s {
    char       name[256];
    serial_t **   serials;
    int seriesNumber;

};

watch_me_t *
serviseNew(const char * aName) {
    watch_me_t * self = malloc(sizeof(struct watch_me_s));
    self->serials = malloc(0);
    strcpy(self->name, aName);
    self->seriesNumber=5;


    self->serials[0] = serial_new("Walking Dead");
    self->serials[1] = serial_new("Hi army!");
    self->serials[2] = serial_new("Game of Thrones");
    self->serials[3] = serial_new("Santa barbara");
    self->serials[4] = serial_new("Session approaching");
    return self;
}

void serviseDelete(watch_me_t * self){
for(int i=1;i<serialsNumber;i++){
        serial_free(self->serials[i]);
}
free(self);
}

const char *
seriviceGetName(watch_me_t * self) {
    return self->name;
}

void servicePrintSerials(watch_me_t * self){
for(int i=0;i<5;i++){
  printSerial(self->serials[i]);
}
}




void
serviceSubscribeNotification(watch_me_t * self, void * receiver, watchMe_notification_fn callback){

    user_t * user = (user_t*)receiver;
    event_t * sb = malloc(sizeof(struct event_s));

    for(int i = 0;i<user->number_of_interesting_serials;i++){
            for(int j = 0; j< self->seriesNumber; j++){


                char * tmp1 = user->interesting_serial[i];

                char * tmp2 = serialGetName(self->serials[j]);

                if(strcmp(tmp1,tmp2)==0){
                        sb->receiver = receiver;
                        sb->callback = callback;
                        event_push_back(self->serials[j], sb);
                }
            }
    }

}

void serviceScheduleForToday(watch_me_t * self, int date,const char * message){


    char * tmpChar;
    for( int i = 0;i<self->seriesNumber;i++){
        if(seriaIisSeriesCome(self->serials[i],date)){
                int count = event_getCount(self->serials[i]);

                for (int j = 0; j < count; j++) {
                event_t * tmpEv = event_getEl(self->serials[i], j);

                if (NULL != tmpEv->callback)
                    {
                        watchMe_notification_fn fn = tmpEv->callback;

                        tmpChar=serialGetName(self->serials[i]);

                        fn(tmpEv->receiver, self, message, tmpChar);
                    }
                }
        }
    }
}

