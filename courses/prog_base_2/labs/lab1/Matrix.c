#include "Lab1_Header.h"
#include <time.h>

struct matrix_s{
int **element;
int n;
int m;
};

matrix_t * new_random_matrix(){
srand ( time(NULL) );
int i,j;
int a=rand()%9+1;
int b=rand()%9+1;
matrix_t * mt = malloc(sizeof(struct matrix_s));

mt->element = (int **)malloc(a * sizeof(int *));
for(i=0;i<a;i++){
mt->element[i] = malloc(sizeof(int)*b);
memset(mt->element[i], 0, b * sizeof(int));
}
mt->n=a;
mt->m=b;

 for(i=0;i<mt->n;i++){
    for(j=0;j<mt->m;j++){
     mt->element[i][j] = rand()%10;
}
 }
return mt;
}

matrix_t * new_test_matrix(){
srand ( time(NULL) );
int i,j;
int a=6;
int b=7;
matrix_t * mt = malloc(sizeof(struct matrix_s));

mt->element = (int **)malloc(a * sizeof(int *));
for(i=0;i<a;i++){
mt->element[i] = malloc(sizeof(int)*b);
memset(mt->element[i], 0, b * sizeof(int));
}
mt->n=a;
mt->m=b;

 for(i=0;i<mt->n;i++){
    for(j=0;j<mt->m;j++){
     mt->element[i][j] = rand()%10;
}
 }
return mt;
}






int matrix_free(matrix_t * self) {
    free(self->element);
    free(self);
    return 1;
}



int matrix_print(const matrix_t * self){
 int i,j,checkTrue=0;
 puts("");
puts("Matrix:");
for(i=0;i<self->n;i++){
    for(j=0;j<self->m;j++){
     printf("%i ",self->element[i][j]);
     checkTrue++;
    }
    puts("");
}
if(checkTrue==self->m*self->n){
    return 1;
}
else{
    return 0;
}
}

int matrix_multiplication_on_random_number(const matrix_t * self){
 srand ( time(NULL) );
 int i,j,checkTrue=0;
 int randElement=rand()%5;
 for(i=0;i<self->n;i++){
    for(j=0;j<self->m;j++){
     self->element[i][j]*=randElement;
     checkTrue++;
    }
}
if(checkTrue==self->m*self->n){
    return 1;
}
else{
    return 0;
}
}

int matrix_test_multiplication(const matrix_t * mt){
    int i,j,checkTrue=0;
    srand ( time(NULL)+6);
    int n=7,m=4;
    int tempMatrix[n][m];
    puts("");
    puts("Random temp matrix:");
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            tempMatrix[i][j] = rand()%10;
            printf("%i ", tempMatrix[i][j]);
        }
        puts("");
    }
    if(mt->m!=n){
        puts("");
        puts("Error! Can't multiply matrix.");
        return 0;
    }

     puts("");
     puts("Multiply result:");

     for(i=0;i<mt->n;i++){
        for(j=0;j<m;j++){
            printf("%i ",mt->element[i][j]*tempMatrix[j][i]);
            checkTrue++;
        }
        puts("");
    }
if(checkTrue==mt->n*m){
    return 1;
}
else{
    return 0;
}

}

int matrix_vector_multiplication(const matrix_t * mt,const vector_t * vc){
    int i,j,checkTrue=0;
    puts("");
    //printf("%i %i",mt->,return_vector_size(vc));
    if(mt->m!=return_vector_size(vc)){
        puts("");
        puts("Error! Can't multiply matrix and vector");
        return 0;
    }
 for(i=0;i<mt->n;i++){
    for(j=0;j<mt->m;j++){
     mt->element[i][j]*=return_vector_value_on_k_position(vc,j);
     //printf("%i ",return_vector_value_on_k_position(vc,j));
     checkTrue++;
    }
    puts("");
}
if(checkTrue==mt->m*mt->n){
    return 1;
}
else{
    return 0;
}
}


int transpose_matrix(const matrix_t * mt){
        int i,j,checkTrue=0;

        puts("Transpose matrix:");
        matrix_print(mt);

        int tempMatrix[mt->m][mt->n];

    for(i=0;i<mt->n;i++){
        for(j=0;j<mt->m;j++){
            tempMatrix[j][i]=mt->element[i][j];
            checkTrue++;
        }
    }
    puts("\nOutput matrix:");

for(i=0;i<mt->m;i++){
    for(j=0;j<mt->n;j++){
     printf("%i ",tempMatrix[i][j]);
    }
    puts("");
}

puts(" ");

if(checkTrue==mt->m*mt->n){
    return 1;
}
else{
    return 0;
}
}

void matrix_multiplication(const matrix_t * mt,const matrix_t * mt1){
    int i,j;

    if(mt->m!=mt1->n){
        puts("");
        puts("Error! Can't multiply matrix.");
        return 0;
    }

     puts("");
     puts("Multiply result:");

     for(i=0;i<mt->n;i++){
        for(j=0;j<mt->m;j++){
            printf("%i ",mt->element[i][j]*mt1->element[j][i]);

        }
        puts("");
    }
}
