#include "str.h"
#include <stdlib.h>  // !
#include <stdarg.h>  // !
#include <stddef.h>  // !
#include <setjmp.h>  // !

#include <cmocka.h>



static void Test_str_module___put_str_started_and_finished_by_number___return_int_180(void **state)
{
   int tmpInt = getNumber("100-30word70+50y-10");
    assert_int_equal(tmpInt, 180);
}


static void Test_str_module___put_str_started_and_finished_by_word___return_int_90(void **state)
{
   int tmpInt = getNumber("word-30word70+50y-word");
    assert_int_equal(tmpInt, 90);
}


static void Test_str_module___put_str_with_only_negative_numbers___return_negative_int_210(void **state)
{
   int tmpInt = getNumber("-100-30word-70-10");
    assert_int_equal(tmpInt, -210);
}

static void Test_str_module___put_str_random_str___return_int_0(void **state)
{
   int tmpInt = getNumber("-100-30word70-10+70");
    assert_int_equal(tmpInt, 0);
}

static void Test_str_module___put_null_str___return_int_0(void **state)
{
   int tmpInt = getNumber("");
    assert_int_equal(tmpInt, 0);
}

static void Test_str_module___put_random_str___return_int_0(void **state)
{
   int tmpInt = getNumber("waetsrdtfy");
    assert_int_equal(tmpInt, 0);
}



void test(void) {

    const struct CMUnitTest tests[] =
    {
        cmocka_unit_test(Test_str_module___put_str_started_and_finished_by_number___return_int_180),
        cmocka_unit_test(Test_str_module___put_str_started_and_finished_by_word___return_int_90),
        cmocka_unit_test(Test_str_module___put_str_with_only_negative_numbers___return_negative_int_210),
        cmocka_unit_test(Test_str_module___put_str_random_str___return_int_0),
        cmocka_unit_test(Test_str_module___put_null_str___return_int_0),
        cmocka_unit_test(Test_str_module___put_random_str___return_int_0),
    };
    return cmocka_run_group_tests(tests, NULL, NULL);
}
