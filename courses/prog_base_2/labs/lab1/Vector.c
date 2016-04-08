#include <time.h>
#include "Lab1_Header.h"

struct vector_s{
int *element;
int size;
};

vector_t * new_random_vector() {
    srand ( time(NULL)+1);
    int i,size;
    size=rand()%9+1;


    vector_t * vc = malloc(sizeof(struct vector_s));
    vc->element = malloc(sizeof(int) * size);
    vc->size = size;
     for (i = 0; i < vc->size; i++) {
        vc->element[i] =  rand()%10;
    }

    return vc;
}

vector_t * new_test_vector() {
    srand ( time(NULL)+1);
    int i,size;
    size=7;


    vector_t * vc = malloc(sizeof(struct vector_s));
    vc->element = malloc(sizeof(int) * size);
    vc->size = size;
     for (i = 0; i < vc->size; i++) {
        vc->element[i] =  rand()%10;
    }

    return vc;
}

int vector_print(const vector_t * self) {
    int i;
    int checkPrint=0;
    puts("");
    puts("Vector:");
    printf("(");
    for (i = 0; i < self->size; i++) {
        printf("%i ", self->element[i]);
        checkPrint++;
    }
    printf(")");
    if(checkPrint==self->size){
    return 1;
    }
    else{
     return 0;
    }
}

int vector_free(vector_t * self) {
    free(self->element);
    free(self);
    return 1;
}

int vector_multiplication_on_random_number(vector_t * self) {
    srand ( time(NULL)+4);
    int i,checkTrue=0;
    for (i = 0; i < self->size; i++) {
        self->element[i]*=rand()%8;
        checkTrue++;
    }
     if(checkTrue==self->size){
    return 1;
    }
    else{
     return 0;
    }
}

int return_vector_value_on_k_position(const vector_t * self,int k){
    return self->element[k];
}

int return_vector_size(const vector_t * self){
    return self->size;
}
