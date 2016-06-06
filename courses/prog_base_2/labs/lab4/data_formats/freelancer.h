#ifndef FREELANCER_H_INCLUDED
#define FREELANCER_H_INCLUDED

#include <stdlib.h>
#include <time.h>
#include "list.h"
#include "socket.h"

typedef struct personalData{
   int age;
   char * birthdate;
   float workExperience;
}personalData_t;

typedef struct position{
char *company;
char *name;
}position_t;


typedef struct freelanser{
    char name[100];
    char surname[100];
    position_t * pos;
    personalData_t * pD;
} freelanser_t;




void freelansersAdd(List_t * freelansers, const char * fileName);
void freelansersPrint(freelanser_t * freelanser);
void freelancerAddParam(List_t * self,const char * name,const char * surname,const char * birthdate,int age, float salary,const char * company,const char * companyPosition);


#endif // FREELANCER_H_INCLUDED
