#include <stdio.h>
#include <stdlib.h>
#include "freelanser.h"
#include "freelanser_db.h"



int main()
{


    freeLanser_t freeLansersList[100];
    dataBase * db = createNewDatabase(FILE_NAME);
    freeLanser_t fl1 = {.id = 5, .name = "Vlad", .surname = "Pes", .birthDate = "1996-02-21", .salary = 1100.10, .completedProjects = 50};
    add_freeLanser(db, &fl1);
    strcpy(fl1.surname,"Cena");
    change_freeLanser(db,&fl1);




    printf("Freelansers count : %i\n", count_freeLansers(db));

    freeLanser_t * fl_get = get_freeLanser(db,5);
    freeLanser_print(fl_get);
    change_freeLanser(db,fl_get);

    fl_get = get_freeLanser(db,5);
    freeLanser_print(fl_get);




   int count = 0;


   freeLanser_t * freeLansers = get_neededFreeLanser(db,1000,&count);

   if(count > 0)
    {
        printf("Printing %i needed freelansers\n",count);
        for(int i = 0; i < count; i++)
        {
            freeLanser_print(freeLansers + i);
        }
    }else{puts("count==0");}


    return 0;
}
