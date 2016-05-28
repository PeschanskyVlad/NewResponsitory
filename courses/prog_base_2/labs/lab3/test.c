#include <stdlib.h>  // !
#include <stdarg.h>  // !
#include <stddef.h>  // !
#include <setjmp.h>  // !

#include <cmocka.h>

#include "user.h"

// unit-test function
static void testUserAddSerial___user_Str___returned1(void **state)
{

     user_t * user;
     user=userNew("Dima",2);
     assert_int_equal(userAddSerial(user,"Game of Thrones"), 1);
     userFree(user);

}

static void testUserPrint___user___returned1(void **state)
{

     user_t * user;
     user=userNew("Dima",1);
     userAddSerial(user,"Game of Thrones");
     assert_int_equal( userPrint(user),1);
     userFree(user);

}

static void testUserGetNumSerials___user___returned1(void **state)
{
     user_t * user;
     user=userNew("Dima",1);
     assert_int_equal(userGetNumSerials(user), 1);
     userFree(user);
}

static void testUserFree___user___returned1(void **state)
{
     user_t * user;
     user=userNew("Dima",1);
     assert_int_equal(userFree(user),1);
}

static void testUserGetSerial___user_Str___returned_Game_of_Thrones(void **state)
{

     user_t * user;
     user=userNew("Dima",1);
     userAddSerial(user,"Game of Thrones");

     assert_string_equal(userGetSerial(user,0), "Game of Thrones");

     userFree(user);

}



void test() {
    const struct CMUnitTest tests[] =
    {
        cmocka_unit_test(testUserAddSerial___user_Str___returned1),
        cmocka_unit_test(testUserPrint___user___returned1),
        cmocka_unit_test(testUserGetNumSerials___user___returned1),
          cmocka_unit_test(testUserFree___user___returned1),
        cmocka_unit_test(testUserGetSerial___user_Str___returned_Game_of_Thrones),
    };
    return cmocka_run_group_tests(tests, NULL, NULL);
}
