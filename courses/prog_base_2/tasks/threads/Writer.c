#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include <windows.h>
#include "thread.h"
#include "mutex.h"
#include "threads.h"
void * writer(string_t  *  st) {




    int i;
    while(1){

            for(i=0;i<5;i++){
                giveString(getCurrentString(i,st),st);
            }
    }

    return NULL;


}
