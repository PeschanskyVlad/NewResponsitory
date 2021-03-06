#include "Lab1_Header.h"
#include "matrix.h"
#include "vector.h"
#include <time.h>

struct matrix_s
{
    int **element;
    int n;
    int m;
};

static enum M_STATUS status = M_OK;

matrix_t * new_random_matrix()
{
    srand ( time(NULL) );
    int i,j;
    int a=rand()%9+1;
    int b=rand()%9+1;
    matrix_t * mt = malloc(sizeof(struct matrix_s));

    if(mt==NULL)
    {
        status=M_NULL;
        return NULL;
    }

    mt->element = (int **)malloc(a * sizeof(int *));
    for(i=0; i<a; i++)
    {
        mt->element[i] = malloc(sizeof(int)*b);
        memset(mt->element[i], 0, b * sizeof(int));
    }
    mt->n=a;
    mt->m=b;

    for(i=0; i<mt->n; i++)
    {
        for(j=0; j<mt->m; j++)
        {
            mt->element[i][j] = rand()%10;
        }
    }
    status=M_OK;
    return mt;
}

matrix_t * new_test_matrix()
{
    srand ( time(NULL) );
    int i,j;
    int a=6;
    int b=7;
    matrix_t * mt = malloc(sizeof(struct matrix_s));
    if(mt==NULL)
    {
        status=M_NULL;
        return NULL;
    }

    mt->element = (int **)malloc(a * sizeof(int *));
    for(i=0; i<a; i++)
    {
        mt->element[i] = malloc(sizeof(int)*b);
        memset(mt->element[i], 0, b * sizeof(int));
    }
    mt->n=a;
    mt->m=b;

    for(i=0; i<mt->n; i++)
    {
        for(j=0; j<mt->m; j++)
        {
            mt->element[i][j] = rand()%10;
        }
    }

    status=M_OK;
    return mt;
}



matrix_t * matrix_new_test(int n, int m, const int arr[n][m])
{
    int i;
    matrix_t * mt = malloc(sizeof(struct matrix_s));
    if(mt == NULL)
    {
        status = M_NULL;
        return NULL;
    }

    mt->n = n;
    mt->m = m;

     mt->element = (int **)malloc(n * sizeof(int *));
    for(i=0; i<n; i++)
    {
        mt->element[i] = malloc(sizeof(int)*m);
        memset(mt->element[i], 0, m * sizeof(int));
    }

    if(mt->element == NULL)
    {
        status = M_NULL;
        return NULL;
    }

    for(i=0; i<mt->n; i++)
    {
        for(int j=0; j<mt->m; j++)
        {
            mt->element[i][j] = arr[i][j];
        }
    }

    status = M_OK;
    return mt;
}








int matrix_free(matrix_t * self)
{
    free(self->element);
    free(self);
    return 1;
}



int matrix_print(const matrix_t * self)
{

     if(self==NULL){
        status=M_NULL;
        return 0;
    }

    int i,j,checkTrue=0;
    puts("");
    puts("Matrix:");
    for(i=0; i<self->n; i++)
    {
        for(j=0; j<self->m; j++)
        {
            printf("%i ",self->element[i][j]);
            checkTrue++;
        }
        puts("");
    }
    if(checkTrue==self->m*self->n)
    {
        status=M_OK;
        return 1;
    }
    else
    {

        status=M_ERROR_OPERATION;
        return 0;
    }
}

int matrix_return_element(const matrix_t * self,int n, int m){
 return self->element[n][m];
}

int matrix_multiplication_on_random_number(const matrix_t * self)

{

    if(self==NULL){
        status=M_NULL;
        return 0;
    }
    srand ( time(NULL) );
    int i,j,checkTrue=0;
    int randElement=rand()%5+1;
    for(i=0; i<self->n; i++)
    {
        for(j=0; j<self->m; j++)
        {
            self->element[i][j]*=randElement;
            checkTrue++;
        }
    }
    if(checkTrue==self->m*self->n)
    {
        status=M_OK;
        return 1;
    }
    else
    {
        status=M_ERROR_OPERATION;
        return 0;
    }
}

int matrix_test_multiplication(const matrix_t * mt)
{

    if(mt==NULL){
        status=M_NULL;
        return 0;
    }
    int i,j,checkTrue=0;
    srand ( time(NULL)+6);
    int n=2,m=2;
    int tempMatrix[2][2]={{2,2},{2,2}};
    puts("");/*
    puts("Random temp matrix:");
    for(i=0; i<n; i++)
    {
        for(j=0; j<m; j++)
        {
            tempMatrix[i][j] = rand()%10;
            printf("%i ", tempMatrix[i][j]);
        }
        puts("");
    }
*/
    if(mt->m!=n)
    {
        puts("");
        status=M_ERROR_OPERATION;
        puts("Error! Can't multiply matrix.");
        return 0;
    }

    puts("");
    puts("Multiply result:");

    for(i=0; i<mt->n; i++)
    {
        for(j=0; j<m; j++)
        {
            mt->element[i][j]*=tempMatrix[j][i];
            printf("%i ",mt->element[i][j]*tempMatrix[j][i]);
            checkTrue++;
        }
        puts("");
    }
    if(checkTrue==mt->n*m)
    {
        status=M_OK;
        return 1;
    }
    else
    {
        status=M_ERROR_OPERATION;
        return 0;
    }

}

int matrix_vector_multiplication(const matrix_t * mt,const vector_t * vc)
{

     if(mt==NULL){
        status=M_NULL;
        return 0;
    }

     if(vc==NULL){
        status=M_NULL;
        return 0;
    }

    int i,j,checkTrue=0;
    puts("");

    if(mt->m!=vector_return_size(vc))
    {
        puts("");
        status=M_ERROR_OPERATION;
        puts("Error! Can't multiply matrix and vector");
        return 0;
    }
    for(i=0; i<mt->n; i++)
    {
        for(j=0; j<mt->m; j++)
        {
            mt->element[i][j]*=vector_return_value_on_k_position(vc,j);
            //printf("%i ",return_vector_value_on_k_position(vc,j));
            checkTrue++;
        }
        puts("");
    }
    if(checkTrue==mt->m*mt->n)
    {
        status=M_OK;
        return 1;
    }
    else
    {
        status=M_ERROR_OPERATION;
        return 0;
    }
}


int matrix_transpose(const matrix_t * mt)

{

     if(mt==NULL){
        status=M_NULL;
        return 0;
    }
    int i,j,checkTrue=0;

    puts("Transpose matrix:");
    matrix_print(mt);

    int tempMatrix[mt->m][mt->n];

    for(i=0; i<mt->n; i++)
    {
        for(j=0; j<mt->m; j++)
        {
            tempMatrix[j][i]=mt->element[i][j];
            checkTrue++;
        }
    }
    puts("\nOutput matrix:");

    for(i=0; i<mt->m; i++)
    {
        for(j=0; j<mt->n; j++)
        {
            printf("%i ",tempMatrix[i][j]);
        }
        puts("");
    }

    for(i=0; i<mt->n; i++)
    {
        for(j=0; j<mt->m; j++)
        {
            mt->element[i][j]=tempMatrix[i][j];
        }
        }





    puts(" ");

    if(checkTrue==mt->m*mt->n)
    {
        status=M_OK;
        return 1;
    }
    else
    {
        status=M_ERROR_OPERATION;
        return 0;
    }
}

void matrix_multiplication(const matrix_t * mt,const matrix_t * mt1)
{

     if(mt==NULL){
        status=M_NULL;
        return 0;
    }

     if(mt1==NULL){
        status=M_NULL;
        return 0;
    }
    int i,j;

    if(mt->m!=mt1->n)
    {
        puts("");
        status=M_ERROR_OPERATION;
        puts("Error! Can't multiply matrix.");
        return 0;
    }

    puts("");
    puts("Multiply result:");

    for(i=0; i<mt->n; i++)
    {
        for(j=0; j<mt->m; j++)
        {
            printf("%i ",mt->element[i][j]*mt1->element[j][i]);

        }
        puts("");
    }
    status=M_OK;
}

M_STATUS return_M_status()
{
    return status;
}


