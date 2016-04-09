#ifndef VECTOR_H_INCLUDED
#define VECTOR_H_INCLUDED

typedef struct vector_s vector_t;

typedef enum V_STATUS {V_OK, V_NULL, V_ERROR_OPERATION} V_STATUS;

vector_t * vector_random();
vector_t * new_test_vector();

vector_t * vector_new_test(int size , int arr[size]);

int vector_print(const vector_t * self);

int vector_free(vector_t * self);

int vector_multiplication_on_random_number(vector_t * self);

int vector_return_value_on_k_position(const vector_t * self,int k);

int vector_return__size(const vector_t * self);

void vectors_multiplication(const vector_t * v1,const vector_t * v2);

V_STATUS return_V_status();



#endif // VECTOR_H_INCLUDED
