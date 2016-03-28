#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include <windows.h>
#include "thread.h"
#include "mutex.h"
#include "threads.h"
void *  reader(string_t  *  st) {

    while(1){

            char *mstr=getCurrentString(6,st);
            if(strlen(mstr)<=5){

                 puts(mstr);
                }
              //  Sleep(100);

    }
     return NULL;

}
