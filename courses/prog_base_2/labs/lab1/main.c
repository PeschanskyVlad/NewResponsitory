#include <stdio.h>
#include <stdlib.h>  // !
#include <stdarg.h>  // !
#include <stddef.h>  // !
#include <setjmp.h>  // !

#include <cmocka.h>

#include "Lab1_Header.h"




int main(){


    test();


    puts("\nWork in main:\n");
    matrix_t * mt =new_random_matrix();
    matrix_t * mt1 =new_random_matrix();
    matrix_print(mt);
    matrix_multiplication_on_random_number(mt);
    matrix_print(mt);

    matrix_multiplication(mt,mt1);



}
