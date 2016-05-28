#include <stdio.h>
#include <stdlib.h>
#include "freelanser.h"
#include "freelanser_db.h"
#include "list.h"

int main()
{    freeLanser_t freeLansersList[100];
    dataBase * db = createNewDatabase(FILE_NAME);

    freeLanser_t fl1 = {.id = 1, .name = "Vlad", .surname = "Pes", .birthDate = "1996-02-21", .salary = 1100.10, .completedProjects = 50};

    freeLanser_t fl2 = {.id = 2, .name = "Tom", .surname = "Wins", .birthDate = "1996-02-22", .salary = 1100.10, .completedProjects = 45};

    freeLanser_t fl3 = {.id = 0, .name = "Tom", .surname = "Wins", .birthDate = "1996-02-22", .salary = 1100.10, .completedProjects = 45};
     delete_freeLanser(db,0);
    delete_freeLanser(db,2);
    delete_freeLanser(db,1);
    delete_freeLanser(db,3);
    delete_freeLanser(db,4);
    delete_freeLanser(db,5);
    delete_freeLanser(db,6);

    add_freeLanser(db, &fl1);
   add_freeLanser(db, &fl2);
    add_freeLanser(db, &fl3);

        //freeLanser_print(get_freeLanser(db,1));


    printf("Freelansers count : %i\n", count_freeLansers(db));

    List_t freeLansers = List_new();

    for(int i = 0;i<3;i++){
    List_add(freeLansers,i,get_freeLanser(db,i));
    }

      /*  for(int i = 0;i<List_getSize(freeLansers);i++){
     freeLanser_t * tmpLanser = List_get(freeLansers,0,NULL);
     freeLanser_print(tmpLanser);
        }*/


    serverNew(freeLansers);


    return 0;
}
