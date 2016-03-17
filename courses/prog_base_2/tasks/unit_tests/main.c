#include <stdio.h>
#include <stdlib.h>  // !
#include <stdarg.h>  // !
#include <stddef.h>  // !
#include <setjmp.h>  // !

#include <cmocka.h>
#include "plural.h"

// unit-test function
static void new_random_plural_check_cursor_pos_by_cursor_comparison(void **state)
{
    int tPos;
    plural_t * plural = plural_new(10,&tPos);
    plural_random(plural,&tPos);
    assert_int_equal(tPos,10);
    plural_free(plural);
    puts("");
}

static void new_random_plural_check_print_by_cursor_comparison(void **state)
{
    int tPos;
    plural_t * plural = plural_new(10,&tPos);
    plural_random(plural,&tPos);
    assert_int_equal(plural_print(plural,&tPos),1);
    plural_free(plural);
    puts("");
}

static void new_plural_add_one_element_check_correct_add_by_cursor_comparison(void **state)
{
    int tPos;
    plural_t * plural = plural_new(10,&tPos);
    plural_addElement(plural,&tPos);
    assert_int_equal(tPos,1);
    plural_free(plural);
    puts("");
}

static void new_plural_add_delete_one_element_check_correct_deletedby_cursor_comparison(void **state)
{
    int tPos;
      puts("");
   // puts("Enter added number, and enter position of deleted element(in this case - 0)");
    plural_t * plural = plural_new(10,&tPos);
    plural_addElement(plural,&tPos);
    plural_deleteElement(plural,&tPos);
    assert_int_equal(tPos,0);
    plural_free(plural);
    puts("");
}

static void new_plural_add_range_of_elements_correct_add_by_cursor_comparison(void **state)
{
    int tPos;
    int a,b,c;
    puts("");

    c=3;
    plural_t * plural = plural_new(10,&tPos);
    plural_fill_range(plural,&tPos, a, b);
    assert_int_equal(tPos-1,c);
    plural_free(plural);
    puts("");
}

static void check_new_plural_intersection_by_return_value(void **state)
{
    int tPos;
    int plur[10]={2,3,4,7,1,8,4,4,9,7};
    plural_t * plural = plural_new(10,&tPos);
    plural_random(plural,&tPos);
    assert_int_equal(plural_intersection(plural,plur),1);
    plural_free(plural);
    puts("");

}

static void check_new_plural_association_by_return_value(void **state)
{
    int tPos;
    int plur[10]={2,3,4,7,1,8,4,4,9,7};
    plural_t * plural = plural_new(10,&tPos);
     plural_random(plural,&tPos);
    assert_int_equal(plural_association(plural,plur),1);
    plural_free(plural);
    puts("");

}

static void check_new_plural_symmetric_difference_by_return_value(void **state)
{
    int tPos;
    int plur[10]={2,3,4,7,1,8,4,4,9,7};
    plural_t * plural = plural_new(10,&tPos);
     plural_random(plural,&tPos);
    assert_int_equal(plural_symmetric_difference(plural,plur),1);
    plural_free(plural);
    puts("");

}





int main()
{
    puts("Always enter 10 for this query - 'Enter the number elements of the set:'");
    puts("And read tips.");
    puts("");
    const struct CMUnitTest tests[] =
    {
        cmocka_unit_test(new_random_plural_check_pos),
        cmocka_unit_test(new_random_plural_print),
        cmocka_unit_test(new_plural_add_one_element_check_pos),
        cmocka_unit_test(new_plural_add_delete_one_element_check_pos),
        cmocka_unit_test(new_plural_add_range_of_elements_check_pos),
        cmocka_unit_test(new_plural_intersection),
        cmocka_unit_test(new_plural_association),
        cmocka_unit_test(new_plural_symmetric_difference),
    };
    return cmocka_run_group_tests(tests, NULL, NULL);
    /*
    int size;
    int a1=0;
    int *totalPos;
    int rangeStart;
    int rangeEnd;
    int plur[10]={2,3,4,7,1,8,4,4,9,7};

    plural_t * pl;
    //pl = plural_new_random(size,&a1);
    pl = plural_new(size,&a1);

   // plural_addElement(pl,&a1);
   // plural_addElement(pl,&a1);
    plural_fill_range(pl,&a1,  rangeStart,  rangeEnd);
    //plural_random(pl,&a1);
   // plural_print(pl,&a1);
   // plural_deleteElement(pl,&a1);
    plural_print(pl,&a1);

    plural_intersection(pl,plur);
    plural_association(pl,plur);
    plural_symmetric_difference(pl,plur);
    //puts(" ");
    //plural_print(pl,&a1);
    plural_free(pl);
    */
}
