#include "plural.h"
#include <time.h>

struct plural_s{
int *plural;
int size;
};


plural_t * plural_new(int size, int *totalPos) {
    int i;
    printf("Enter the number elements of the set:");
    scanf("%i",&size);
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
    printf("Enter start of range:");
    scanf("%i",&rangeStart);
     printf("Enter end of range:");
    scanf("%i",&rangeEnd);
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
     printf("Enter new element:");
     scanf("%i",&newElement);
    self->plural[(*totalPos)]=newElement;
    (*totalPos)++;
}

void plural_deleteElement(plural_t * self, int *totalPos){

    int deletedElementPos;
    int i;
    puts(" ");
     printf("Enter position of deleted element:");
     scanf("%i",&deletedElementPos);
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

void plural_print(const plural_t * self, int *totalPos) {
    int i;
    for (i = 0; i < self->size; i++) {
        printf("%i ", self->plural[i]);
    }
}
void plural_free(plural_t * self) {
    free(self->plural);
    free(self);
}
void plural_intersection(plural_t * self, int plur[10]){
int i,j,rp=0;
int check=0;
int resultPlural[self->size];
for(i=0;i<self->size;i++){
   for(j=0;j<10;j++){
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
puts("Result of intersection:");
  for(i=0;i<rp;i++){
            printf("%i ",resultPlural[i]);
        }

}

void plural_association(plural_t * self, int plur[10]){
    int i,j,rp=0;
    int check=0;
    int resultPlural[self->size+10];
        for(i=0;i<self->size;i++){
           resultPlural[rp]=self->plural[i];
            rp++;
        }

        for(j=0;j<10;j++){
            for(i=0;i<self->size;i++){
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
        puts("Result of association:");
        for(i=0;i<rp;i++){
            printf("%i ",resultPlural[i]);
        }
}


void plural_symmetric_difference(plural_t * self, int plur[10]){
int i,j,rp=0;
    int check=0;
    int resultPlural[self->size+10];

    for(j=0;j<10;j++){
            for(i=0;i<self->size;i++){
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
        puts("Result of symmetric difference:");
        for(i=0;i<rp;i++){
            printf("%i ",resultPlural[i]);
        }


}

