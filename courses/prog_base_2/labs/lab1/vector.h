#ifndef VECTOR_H_INCLUDED
#define VECTOR_H_INCLUDED

typedef enum V_STATUS {V_OK, V_NULL, V_ERROR_OPERATION} V_STATUS;

vector_t * new_random_vector();
vector_t * new_test_vector();

int vector_print(const vector_t * self);

int vector_free(vector_t * self);

int vector_multiplication_on_random_number(vector_t * self);

int return_vector_value_on_k_position(const vector_t * self,int k);

int return_vector_size(const vector_t * self);

void vectors_multiplication(const vector_t * v1,const vector_t * v2);



#endif // VECTOR_H_INCLUDED
