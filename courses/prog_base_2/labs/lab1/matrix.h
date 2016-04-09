#ifndef MATRIX_H_INCLUDED
#define MATRIX_H_INCLUDED
typedef struct matrix_s matrix_t ;

typedef enum M_STATUS {M_OK, M_NULL, M_ERROR_OPERATION} M_STATUS;

matrix_t * new_random_matrix();
matrix_t * new_test_matrix();
matrix_t * matrix_new_test(int n, int m, const int arr[n][m]);








int matrix_print(const matrix_t * self);

int matrix_multiplication_on_random_number(const matrix_t * self);

int matrix_test_multiplication(const matrix_t * mt);

int matrix_vector_multiplication(const matrix_t * mt,const vector_t * vc);



int matrix_free(matrix_t * self);

int matrix_transpose(const matrix_t * mt);

void matrix_multiplication(const matrix_t * mt,const matrix_t * mt1);

M_STATUS return_M_status();



#endif // MATRIX_H_INCLUDED
