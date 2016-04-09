#include <stdio.h>
#include <stdlib.h>  // !


#include "Lab1_Header.h"
#include "matrix.h"
#include "vector.h"




int main(){
    static enum M_STATUS status;


    test();


    puts("\nWork in main:\n");
    matrix_t * mt =new_random_matrix();
    matrix_t * mt1 =new_random_matrix();
    matrix_print(mt);
    matrix_multiplication_on_random_number(mt);
    matrix_print(mt);
    matrix_multiplication(mt,mt1);

    vector_t * vc1 =new_random_vector();
     vector_print(vc1);
    vector_t * vc2 =new_random_vector();

    vectors_multiplication(vc1,vc2);
    vector_print(vc1);

    status=return_M_status();





}
