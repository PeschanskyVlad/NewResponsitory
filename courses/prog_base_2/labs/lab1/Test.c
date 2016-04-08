#include <stdio.h>
#include <stdlib.h>  // !
#include <stdarg.h>  // !
#include <stddef.h>  // !
#include <setjmp.h>  // !

#include <cmocka.h>

#include "Lab1_Header.h"

static void check_print_and_free_new_random_matrix_by_returned_value(void **state){
matrix_t * mt =new_random_matrix();
assert_int_equal(matrix_print(mt),1);
assert_int_equal(matrix_free(mt),1);
}

static void check_matrix_multiplication_on_random_number_by_returned_value(void **state){
matrix_t * mt =new_random_matrix();
assert_int_equal(matrix_multiplication_on_random_number(mt),1);
matrix_free(mt);

}

static void check_matrix_transpose_by_returned_value(void **state){
matrix_t * mt =new_random_matrix();
assert_int_equal(transpose_matrix(mt),1);
matrix_free(mt);
}

static void check_matrix_multiplication_by_returned_value(void **state){
matrix_t * mt =new_test_matrix();
assert_int_equal(matrix_test_multiplication(mt),1);
matrix_free(mt);
}

static void check_print_and_free_new_random_vector_by_returned_value(void **state){
vector_t * vc =new_random_vector();
assert_int_equal(vector_print(vc),1);
assert_int_equal(vector_free(vc),1);
}

static void check_vector_multiplication_on_random_number_by_returned_value(void **state){
vector_t * vc =new_random_vector();
assert_int_equal(vector_multiplication_on_random_number(vc),1);
vector_free(vc);
}


static void check_matrix_vector_multiplication_by_returned_value(void **state){
matrix_t * mt =new_test_matrix();
vector_t * vc =new_test_vector();
assert_int_equal(matrix_vector_multiplication(mt,vc),1);
matrix_free(mt);
}
void test(){
    const struct CMUnitTest tests[] =
    {
        cmocka_unit_test(check_print_and_free_new_random_matrix_by_returned_value),
        cmocka_unit_test(check_matrix_multiplication_on_random_number_by_returned_value),
        cmocka_unit_test(check_matrix_transpose_by_returned_value),

        cmocka_unit_test(check_matrix_multiplication_by_returned_value),
        cmocka_unit_test(check_print_and_free_new_random_vector_by_returned_value),
        cmocka_unit_test(check_vector_multiplication_on_random_number_by_returned_value),
        cmocka_unit_test(check_matrix_vector_multiplication_by_returned_value),
    };
    return cmocka_run_group_tests(tests, NULL, NULL);
}
