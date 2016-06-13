#include <stdlib.h>
#include <stdio.h>
#include "lib.h"
#include "list.h"
#define CHARLEN 100

struct library{
    List_t book;
    int booksCount;

};

struct book{
  List_t users;
  int status;
  char name[CHARLEN];
  int curDaysUsed;
  char  curDate[CHARLEN];
};

struct user{
char name[CHARLEN];
};

library_t * newLibrary(void){
library_t * self = malloc(sizeof(library_t));
self->book = List_new();
return self;
}

user_t * newUser(const char * name){
user_t * self = malloc(sizeof(user_t));
strcpy(self->name,name);
return self;
}



book_t * newBook(const char * name){
book_t * self = malloc(sizeof(book_t));
strcpy(self->name,name);
self->status = 0;
self->curDaysUsed = 0;
strcpy(self->curDate,"");
self->users = List_new();
return self;
}

book_t * newBookchangeParam(const char * name,int status, int curDaysUsed, const char * curDate, List_t * users){
book_t * self = malloc(sizeof(book_t));
strcpy(self->name,name);
self->status = status;
self->curDaysUsed = curDaysUsed;
strcpy(self->curDate,curDate);
self->users = users;
return self;

}

void addBook(library_t * self,const char * name){
book_t * nB = newBook(name);
List_add(self->book,List_getSize(self->book),nB);
}

void deleteBook(library_t * self,const char * name){
for(int i = 0;i<List_getSize(self->book);i++){
            book_t * tmpBook = List_get(self->book,i,NULL);
            if(strcmp(tmpBook->name,name)==0){
                List_remove(self->book,i,NULL);
                return;
            }
    }
}

List_t * getBooksList(library_t * self){
return self->book;
}

void printBooks(library_t * self){
printList(self->book);
}

void printList(List_t * self){

    for(int i = 0;i<List_getSize(self);i++){
            book_t * tmpBook = List_get(self,i,NULL);
            printf("\nBook number: %i\nBook name: %s",i+1,tmpBook->name);
            if(tmpBook->status == 1){
                user_t * tmpUser = List_get(tmpBook->users,List_getSize(tmpBook->users),NULL);
                printf("\nUser: %s",tmpUser->name);
            }
    }
    puts("");
}

void bookAddReader(library_t * self,const char * name,const char * readerName){
    for(int i = 0;i<List_getSize(self);i++){
            book_t * tmpBook = List_get(self,i,NULL);
            if(strcmp(tmpBook->name,name)==0 && tmpBook->status == 0){

                user_t * tmpUser = newUser(readerName);
                List_add(tmpBook->users,List_getSize(tmpBook->users),tmpUser);

                book_t * nB = newBookchangeParam(name,1,tmpBook->curDaysUsed+1,"day",tmpBook->users);
                List_remove(self->book,i,NULL);

                List_add(self->book,i,nB);
                return;
            }
    }
}



void bookDeleteReader(library_t * self,const char * name){

        for(int i = 0;i<List_getSize(self);i++){
            book_t * tmpBook = List_get(self,i,NULL);
            if(strcmp(tmpBook->name,name)==0){

                    if(tmpBook->status == 1){
                            book_t * nB = newBookchangeParam(name,0,tmpBook->curDaysUsed," ",tmpBook->users);
                            List_remove(self->book,i,NULL);
                            List_add(self->book,i,nB);
                            return;

                    }else{
                            return;
                    }
            }
    }

}

List_t * getNeededBooks(library_t * self,int status){
    List_t neededList = List_new();
     for(int i = 0;i<List_getSize(self);i++){
            book_t * tmpBook = List_get(self,i,NULL);
            if(tmpBook->status == status){
                List_add(neededList,List_getSize(neededList),tmpBook);
            }
    }
    return getNeededBooks;
}

List_t * getOldBooks(library_t * self,int days){
    List_t neededList = List_new();
     for(int i = 0;i<List_getSize(self);i++){
            book_t * tmpBook = List_get(self,i,NULL);
            if(tmpBook->curDaysUsed >= days){
                List_add(neededList,List_getSize(neededList),tmpBook);
            }
    }
    return getNeededBooks;
}








/*
int SampleAddInt(int i1, int i2)
{
    printf("SampleAddInt called!");
    return i1 + i2;
}

void SampleFunction1(void)
{
    printf("SampleFunction1 called!");
}

int SampleFunction2(void)
{
    printf("SampleFunction2 called!");
    return 0;
}*/
