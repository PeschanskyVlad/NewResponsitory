#include "plural.h"
#include <time.h>

struct plural_s{
int *plural;
int size;
};


plural_t * plural_new(int size, int *totalPos) {
    int i;
    printf("Number elements of the set: 10");
    //scanf("%i",&size);
    size=10;
   (*totalPos)=size;
    plural_t * pl = malloc(sizeof(struct plural_s));
    pl->plural = malloc(sizeof(int) * size);
    pl->size = size;
     for (i = 0; i < pl->size; i++) {
        pl->plural[i] = 0;
    }
    (*totalPos)=0;
    return pl;
}


void plural_fill_range(plural_t * self, int *totalPos, int rangeStart, int rangeEnd) {
    int i;
    printf("Enter start of range: 2");
    rangeStart=2;
   // scanf("%i",&rangeStart);
     printf("Enter end of range: 5");
     rangeEnd=5;
    //scanf("%i",&rangeEnd);
    int rangeLenght=rangeEnd-rangeStart;
    int a,b=rangeStart;
    if (self->size-(*totalPos) < rangeLenght){
        a = self->size-(*totalPos);
    }else{
        a= rangeLenght+(*totalPos);
    }
    for (i = (*totalPos); i < a; i++) {
        self->plural[i] = b;
        b++;
    }
    if(i<self->size-1){
    (*totalPos)=i+1;}else{
    (*totalPos)=self->size;
    }
}

void plural_addElement(plural_t * self, int *totalPos){
     int newElement;
     printf("New element: 10");
    // scanf("%i",&newElement);
    newElement=10;
    self->plural[(*totalPos)]=newElement;
    (*totalPos)++;
}

void plural_deleteElement(plural_t * self, int *totalPos){

    int deletedElementPos;
    int i;
    puts(" ");
     printf("Position of deleted element: 0");
    // scanf("%i",&deletedElementPos);
    deletedElementPos=0;
     for(i=deletedElementPos;i<(*totalPos);i++){
        self->plural[i]=self->plural[i+1];
     }
     (*totalPos)--;


}
void plural_random(plural_t * self, int *totalPos){
 int i;
 srand ( time(NULL) );
    for (i = 0; i < self->size; i++) {
        self->plural[i] = rand()%100;
    }
    (*totalPos)=self->size;
}


int plural_print(const plural_t * self, int *totalPos) {
    int i;
    for (i = 0; i < self->size; i++) {
        printf("%i ", self->plural[i]);
    }
    return 1;
}

void plural_free(plural_t * self) {
    free(self->plural);
    free(self);
}

int plural_intersection(plural_t * self, int plur[10]){
int i,j,rp=0;
int check=0;
int checkTrue=0;
int resultPlural[self->size];
for(i=0;i<self->size;i++){
   for(j=0;j<10;j++){
        checkTrue++;
        if(self->plural[i]==plur[j]){
            check++;
        }

   }

   if(check!=0){
    resultPlural[rp]=self->plural[i];
    rp++;
   }
   check=0;
}
puts(" ");
/*
puts("Result of intersection:");
  for(i=0;i<rp;i++){
            printf("%i ",resultPlural[i]);
        }
*/
if(checkTrue==self->size*10){
return 1;}else{return 0;}
}


int plural_association(plural_t * self, int plur[10]){
    int checkTrue=0;
    int i,j,rp=0;
    int check=0;
    int resultPlural[self->size+10];
        for(i=0;i<self->size;i++){
           resultPlural[rp]=self->plural[i];
            rp++;
        }

        for(j=0;j<10;j++){
            for(i=0;i<self->size;i++){
                    checkTrue++;
              if(self->plural[i]==plur[j]){
            check++;
               }
            }

             if(check==0){
            resultPlural[rp]=plur[j];
            rp++;
       }

        }



        puts(" ");
        /*
        puts("Result of association:");
        for(i=0;i<rp;i++){
            printf("%i ",resultPlural[i]);
        }
        */
      if(checkTrue==self->size*10){
return 1;}else{return 0;}
}


int plural_symmetric_difference(plural_t * self, int plur[10]){
    int checkTrue=0;
int i,j,rp=0;
    int check=0;
    int resultPlural[self->size+10];

    for(j=0;j<10;j++){
            for(i=0;i<self->size;i++){
                    checkTrue++;
              if(self->plural[i]==plur[j]){
            check++;
               }
            }

             if(check==0){
            resultPlural[rp]=plur[j];
            rp++;
       }

        }


        for(i=0;i<self->size;i++){
   for(j=0;j<10;j++){
        if(self->plural[i]==plur[j]){
            check++;
        }

   }

   if(check==0){
    resultPlural[rp]=self->plural[i];
    rp++;
   }
   check=0;
}

 puts(" ");
 /*
        puts("Result of symmetric difference:");
        for(i=0;i<rp;i++){
            printf("%i ",resultPlural[i]);
        }
        */
        if(checkTrue==self->size*10){
return 1;}else{return 0;}


}

