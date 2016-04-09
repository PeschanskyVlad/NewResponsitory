#include <stdio.h>
#include <stdlib.h>  // !
#include <stdarg.h>  // !
#include <stddef.h>  // !
#include <setjmp.h>  // !

#include <cmocka.h>

#include "Lab1_Header.h"

static void check_print_and_free_new_random_matrix______returned_1(void **state){
matrix_t * mt =new_random_matrix();
assert_int_equal(matrix_print(mt),1);
assert_int_equal(matrix_free(mt),1);
}

static void check_new_test_matrix_print_and_free____sent_n_m_matrix_array____returned_1(void **state){
const int test_arr[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
matrix_t * mt =matrix_new_test(3, 3,test_arr);
//assert_int_equal(matrix_print(mt),1);
assert_int_equal(matrix_print(mt),1);
assert_int_equal(matrix_free(mt),1);
}


static void check_matrix_multiplication_on_random_number______sent_n_m_matrix_array____returned_1(void **state){
matrix_t * mt =new_random_matrix();
assert_int_equal(matrix_multiplication_on_random_number(mt),1);
matrix_free(mt);

}

static void check_matrix_transpose______sent_n_m_matrix_array____returned_1(void **state){
matrix_t * mt =new_random_matrix();
assert_int_equal(matrix_transpose(mt),1);
matrix_free(mt);
}

static void check_matrix_multiplication______sent_n_m_matrix_array____returned_1(void **state){


const int test_arr[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};

matrix_t * mt =matrix_new_test(3, 3,test_arr);
//puts("test print:");
matrix_print(mt);


assert_int_equal(matrix_test_multiplication(mt),1);
matrix_free(mt);
}

static void check_print_and_free_new_random_vector_______sent_size_vector_array_____returned_1(void **state){
vector_t * vc =vector_random();
assert_int_equal(vector_print(vc),1);
assert_int_equal(vector_free(vc),1);
}

static void check_vector_multiplication_on_random_number______sent_size_vector_array_____returned_1(void **state){
vector_t * vc =vector_random();
assert_int_equal(vector_multiplication_on_random_number(vc),1);
vector_free(vc);
}


static void check_matrix_vector_multiplication______sent_n_m_matrix_array_size_vector_array_____returned_1(void **state){
//matrix_t * mt =new_test_matrix();
//vector_t * vc =new_test_vector();

const int test_arr[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
const int test_arr1[3] = {1, 2, 3};

matrix_t * mt =matrix_new_test(3, 3,test_arr);
vector_t * vc = vector_new_test(3,test_arr1);


assert_int_equal(matrix_vector_multiplication(mt,vc),1);
matrix_free(mt);
}
void test(){
    const struct CMUnitTest tests[] =
    {
        cmocka_unit_test(check_new_test_matrix_print_and_free____sent_n_m_matrix_array____returned_1),
        cmocka_unit_test(check_matrix_multiplication_on_random_number______sent_n_m_matrix_array____returned_1),
        cmocka_unit_test(check_matrix_transpose______sent_n_m_matrix_array____returned_1),

        cmocka_unit_test(check_matrix_multiplication______sent_n_m_matrix_array____returned_1),
        cmocka_unit_test(check_print_and_free_new_random_vector_______sent_size_vector_array_____returned_1),
        cmocka_unit_test(check_vector_multiplication_on_random_number______sent_size_vector_array_____returned_1),
        cmocka_unit_test(check_matrix_vector_multiplication______sent_n_m_matrix_array_size_vector_array_____returned_1),
    };
    return cmocka_run_group_tests(tests, NULL, NULL);
}
