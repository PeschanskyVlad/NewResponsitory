#include <stdlib.h>
#include <stdio.h>

#include "freelanser.h"

void freelancerPrint(freelancer_t * fl) {
    printf("\nName: %s\nSurname: %s\nSalary: %0.2f\nCompletedProjects: %i\nBirth date: %s\n\n",
        fl->name, fl->surname, fl->salary, fl->completedProjects,fl->birthDate);
}

freelancer_t * freelanserNew(){

    freelancer_t * self = malloc(sizeof(struct freelancer_s));

    /*self->name =  malloc(sizeof(char)*STRL);
    self->surname =  malloc(sizeof(char)*STRL);
    self->birthDate =  malloc(sizeof(char)*STRL);*/
    return self;
}

void freelancerFree(freelancer_t * self){
free(self);
}




