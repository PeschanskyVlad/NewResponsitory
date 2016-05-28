#include <stdio.h>
#include <stdlib.h>
#include "WatchMe.h"
#include "serials.h"
#include "user.h"

void userNotification(void * receiver, watch_me_t * sender, const char * message,const char * serial) {
    user_t * user = (user_t *)receiver;

    const char * serviseName = seriviceGetName(sender);

    printf("User '%s' received:\n\tMessage:\t'%s'\n\t   Serial:\t'%s'\n%s - best serial service!\n\n",
           user->name,
           message,
           serial,
           serviseName);
}


int main()
{



    int i;
    srand(time(NULL));
     watch_me_t * watchMe = serviseNew("WatchMeNow.com");
     servicePrintSerials(watchMe);
//
     user_t * user[3];
     user[0]=userNew("Dima",1);
     userAddSerial(user[0],"Game of Thrones");

     user[1]=userNew("Tom",2);
     userAddSerial(user[1],"Game of Thrones");
     userAddSerial(user[1],"Walking Dead");

     user[2]=userNew("Vlad",3);
     userAddSerial(user[2],"Walking Dead");
     userAddSerial(user[2],"Session approaching");
     userAddSerial(user[2],"Hi army!");


     //puts(getUserSerial(user[0],0));


     puts("");
     puts("Users:");
     userPrint(user[0]);
     userPrint(user[1]);
     userPrint(user[2]);

     for ( i = 0; i < 3; i++) {
        serviceSubscribeNotification(watchMe, user[i], userNotification);
    }

    for( i = 1;i<32;i++){
         serviceScheduleForToday(watchMe,i,"New series coming out today!");
    }

    serviseDelete(watchMe);
    for(i=0;i<3;i++){
        userFree(user[i]);
    }

       test();

}
