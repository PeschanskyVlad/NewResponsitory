#ifndef WATCHMENOW_H_INCLUDED
#define WATCHMENOW_H_INCLUDED

typedef struct watch_me_s watch_me_t;

typedef
    void
    (*watchMe_notification_fn)
    (void * receiver, watch_me_t * sender, const char * message,const char * serial);

const char *
seriviceGetName(watch_me_t * self);

void servicePrintSerials(watch_me_t * self);

void serviceScheduleForToday(watch_me_t * self, int date,const char * message);

void
serviceSubscribeNotification(watch_me_t * self, void * receiver, watchMe_notification_fn callback);

void serviseDelete(watch_me_t * self);

watch_me_t *
serviseNew(const char * aName);

#endif // WATCHMENOW_H_INCLUDED
