#ifndef MATRIX_H_INCLUDED
#define MATRIX_H_INCLUDED

typedef enum M_STATUS {M_OK, M_NULL, M_ERROR_OPERATION} M_STATUS;

matrix_t * new_random_matrix();
matrix_t * new_test_matrix();








int matrix_print(const matrix_t * self);

int matrix_multiplication_on_random_number(const matrix_t * self);

int matrix_test_multiplication(const matrix_t * mt);

int matrix_vector_multiplication(const matrix_t * mt,const vector_t * vc);



int matrix_free(matrix_t * self);

int transpose_matrix(const matrix_t * mt);

void matrix_multiplication(const matrix_t * mt,const matrix_t * mt1);



#endif // MATRIX_H_INCLUDED