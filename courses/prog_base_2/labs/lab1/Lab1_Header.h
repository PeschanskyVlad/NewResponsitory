#ifndef LAB1_HEADER_H_INCLUDED
#define LAB1_HEADER_H_INCLUDED

 typedef struct matrix_s matrix_t ;
 typedef struct vector_s vector_t;

matrix_t * new_random_matrix();
matrix_t * new_test_matrix();
vector_t * new_random_vector();
vector_t * new_test_vector();
void test();
int matrix_print(const matrix_t * self);
int vector_free(vector_t * self);
int matrix_multiplication_on_random_number(const matrix_t * self);
int return_vector_value_on_k_position(const vector_t * self,int k);
int return_vector_size(const vector_t * self);
int matrix_vector_multiplication(const matrix_t * mt,const vector_t * vc);
int matrix_test_multiplication(const matrix_t * mt);
void matrix_multiplication(const matrix_t * mt,const matrix_t * mt1);
int vector_multiplication_on_random_number(vector_t * self);
int transpose_matrix(const matrix_t * mt);

#endif // LAB1_HEADER_H_INCLUDED
