#ifndef USER_H_INCLUDED
#define USER_H_INCLUDED

typedef struct user_s {
    char name[100];
    int number_of_interesting_serials;
    char **interesting_serial;
    int current_serials;
} user_t;

user_t * userNew(const char * uName,int number_of_interesting_serials);
int userAddSerial(user_t * self,const char * sName);
int userPrint(user_t * self);
int userFree(user_t * self);
int userGetNumSerials(user_t * self);
char * userGetSerial(user_t * self,int i);

#endif // USER_H_INCLUDED
