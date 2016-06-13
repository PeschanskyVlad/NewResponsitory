#ifndef LIB_H_INCLUDED
#define LIB_H_INCLUDED
#include "list.h"

typedef struct book book_t;
typedef struct library library_t;
typedef struct user user_t;


library_t * newLibrary(void);
void addBook(library_t * self,const char * name);

void printBooks(library_t * self);
void printList(List_t * self);
void deleteBook(library_t * self,const char * name);

List_t * getBooksList(library_t * self);

book_t * newBookchangeParam(const char * name,int status, int curDaysUsed, const char * curDate, List_t * users);
void addBookReader(library_t * self,const char * name,const char * readerName);
void bookDeleteReader(library_t * self,const char * name);
List_t * getNeededBooks(library_t * self,int status);
List_t * getOldBooks(library_t * self,int days);
void freeLibrary(library_t * self);

#endif // LIB_H_INCLUDED
