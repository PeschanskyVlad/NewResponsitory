#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include <windows.h>
#include "thread.h"
#include "mutex.h"
#include "threads.h"

struct string_s {
    char *myString;
    char str_array[5][15];
    mutex_t * mu;
};


void * writer(void  *  args) {

string_t * st = (string_t *)args;
    while(1){
            int i;
            for(i=0;i<5;i++){
                st->myString=st->str_array[i];
                Sleep(30);
            }
    }

    return NULL;


}

void *  reader(void * args) {

string_t * st = (string_t *)args;
    while(1){
            if(strlen(st->myString)<=5){
                printf("String: %s\n",st->myString);
                }
                Sleep(30);

    }
     return NULL;

}



int main()
{
    string_t st;
    st.mu = mutex_new();
    scanf("%s",st.str_array[0]);
    scanf("%s",st.str_array[1]);
    scanf("%s",st.str_array[2]);
    scanf("%s",st.str_array[3]);
    scanf("%s",st.str_array[4]);


    thread_t * st1 = thread_create_args(writer, &st);
    thread_t * st2 = thread_create_args(reader, &st);
    thread_t * st3 = thread_create_args(reader, &st);





    getch();

    thread_free(st1);
    thread_free(st2);
    thread_free(st3);

    mutex_free(st.mu);
    return 0;


}


