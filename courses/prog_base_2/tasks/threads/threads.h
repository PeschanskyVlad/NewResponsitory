#ifndef PLURAL_H_INCLUDED
#define PLURAL_H_INCLUDED
typedef struct string_s string_t;

void * writer(string_t  *  st);
void * reader(string_t  *  st);
char * getCurrentString(int i,string_t  *  st);
void giveString(char  *  st1,string_t  *  st);
#endif // PLURAL_H_INCLUDED
