#include <time.h>
#include "Lab1_Header.h"
#include "vector.h"

struct vector_s{
int *element;
int size;
};

static enum V_STATUS status = V_OK;

vector_t * new_random_vector() {
    srand ( time(NULL)+1);
    int i,size;
    size=rand()%9+1;


    vector_t * vc = malloc(sizeof(struct vector_s));

    if(vc==NULL){
        status=V_NULL;
        return NULL;
    }
    vc->element = malloc(sizeof(int) * size);
    vc->size = size;
     for (i = 0; i < vc->size; i++) {
        vc->element[i] =  rand()%10;
    }
    status=V_OK;
    return vc;
}

vector_t * new_test_vector() {
    srand ( time(NULL)+1);
    int i,size;
    size=7;


    vector_t * vc = malloc(sizeof(struct vector_s));
    if(vc==NULL){
        status=V_NULL;
        return NULL;
    }
    vc->element = malloc(sizeof(int) * size);
    vc->size = size;
     for (i = 0; i < vc->size; i++) {
        vc->element[i] =  rand()%10;
    }
    status=V_OK;
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
            status=V_OK;
    return 1;
    }
    else{
      status=V_ERROR_OPERATION;
     return 0;
    }
}

int vector_free(vector_t * self) {
    free(self->element);
    free(self);
    return 1;
}

void vectors_multiplication(const vector_t * v1,const vector_t * v2){
int i;

    if(v1->size!=v2->size){
    puts("Error multiplication vectors!");
    return;
}

    for (i = 0; i < v1->size; i++) {
        v1->element[i]*=v2->element[i];
    }
    status=V_OK;
    return;

}

int vector_multiplication_on_random_number(vector_t * self) {
    srand ( time(NULL)+4);
    int i,checkTrue=0;
    int randNum=rand()%8;
    for (i = 0; i < self->size; i++) {
        self->element[i]*=randNum;
        checkTrue++;
    }
     if(checkTrue==self->size){
            status=V_OK;
    return 1;
    }
    else{
            status=V_ERROR_OPERATION;
     return 0;
    }
}

int return_vector_value_on_k_position(const vector_t * self,int k){
    return self->element[k];
}

int return_vector_size(const vector_t * self){
    return self->size;
}
