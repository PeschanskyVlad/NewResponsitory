#ifndef FREELANCER_H_INCLUDED
#define FREELANCER_H_INCLUDED

#include <stdlib.h>
#include <time.h>
struct personalData{
   int age;
   time_t birthdate;
   float workExperience;
};

struct position{
char company[100];
char name[100];
};


typedef struct freelanser{
    char name[100];
    char surname[100];
    struct position pos;
    struct personalData pD;
} freelanser;

void find_freelansers(freelanser * freelansers, size_t required_quantity);


#endif // FREELANCER_H_INCLUDED
