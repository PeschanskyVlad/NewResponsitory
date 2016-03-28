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


char * getCurrentString(int i,string_t  *  st){
char *mstr1;

if(i==6){
 mstr1=st->myString;
 return mstr1;
}

mstr1=st->str_array[i];
Sleep(30);
return mstr1;
}

void giveString(char  *  st1,string_t  *  st){
st->myString=st1;
}






int main()
{
    string_t st;
    st.mu = mutex_new();
    strcpy(st.str_array[0],"Test");
    strcpy(st.str_array[1],"Slogna");
    strcpy(st.str_array[2],"hello");
    strcpy(st.str_array[3],"why");
    strcpy(st.str_array[4],"1256");
    strcpy(st.myString,st.str_array[4]);




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


