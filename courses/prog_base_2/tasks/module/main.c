#include <stdio.h>
#include <stdlib.h>
#include "plural.h"

int main()
{
    int size;
    int a1=0;
    int *totalPos;
    int rangeStart;
    int rangeEnd;
    int plur[10]={2,3,4,7,1,8,4,4,9,7};

    plural_t * pl;
    //pl = plural_new_random(size,&a1);
    pl = plural_new(size,&a1);

   // plural_addElement(pl,&a1);
   // plural_addElement(pl,&a1);
    plural_fill_range(pl,&a1,  rangeStart,  rangeEnd);
    //plural_random(pl,&a1);
   // plural_print(pl,&a1);
   // plural_deleteElement(pl,&a1);
    plural_print(pl,&a1);

    plural_intersection(pl,plur);
    plural_association(pl,plur);
    plural_symmetric_difference(pl,plur);
    //puts(" ");
    //plural_print(pl,&a1);
    plural_free(pl);
}
