#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "freelancer.h"
#include <libxml/parser.h>
#include <libxml/tree.h>
int main() {

    puts("Start working.\n");
    freelanser freelancers[3];
    find_freelansers(freelancers, 3);
    for(int i = 0; i < 3; i++)
    {
        printf("name : %s\n", freelancers[i].name);
        printf("surname : %s\n", freelancers[i].surname);
        printf("position(company : %s) : %s\n", freelancers[i].pos.company, freelancers[i].pos.name);
        puts("statistics : ");
        printf("age : %i\n",freelancers[i].pD.age);
        printf("workExperience : %.2f\n",freelancers[i].pD.workExperience);
        printf("birthdate : %s\n",freelancers[i].pD.birthdate);
        puts("\n");
    }
	return 0;
}



