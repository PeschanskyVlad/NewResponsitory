#include <stdlib.h>
#include <stdio.h>

#include "freelanser.h"

void freeLanser_print(freeLanser_t * fl) {
    printf("\nName: %s\nSurname: %s\nSalary: %0.2f\nCompletedProjects: %i\nBirth date: %s\n\n",
        fl->name, fl->surname, fl->salary, fl->completedProjects,fl->birthDate);
}


