#include <stdio.h>
#include <stdlib.h>
#include "freelanser.h"
#include "freelanser_db.h"
#include "list.h"



int main()
{



    dataBase * db = createNewDatabase(FILE_NAME);
/*
    //freelancerAdd(db,3,"Vlad","Tins",56.6,21,"12-05-1998");

    //freelancer_t * tmpL = freelancerGet(db,3);

    //freelancerPrint(tmpL);

    List_t list = List_new();

    freelancerGetAll(db,list);

    for(int i = 0;i<List_getSize(list);i++){
        freelancer_t * tmpL = List_get(list,i,NULL);
        //freelancerPrint(tmpL);
    }
*/


    List_t list2 = List_new();

    /*freelancerGetNeeded(db,list2,4,100,1);

      for(int i = 0;i<List_getSize(list2);i++){
        freelancer_t * tmpL1 = List_get(list2,i,NULL);
        freelancerPrint(tmpL1);
    }*/


    //printf("Size: %i",freelancersCount(db));



    serverStart(db);



/*

    printf("Freelansers count : %i\n", count_freeLansers(db));

    freeLanser_t * fl_get = get_freeLanser(db,5);
    freeLanser_print(fl_get);
    change_freeLanser(db,fl_get);

    fl_get = get_freeLanser(db,5);
    freeLanser_print(fl_get);
*/


/*
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


    return 0;*/
}
