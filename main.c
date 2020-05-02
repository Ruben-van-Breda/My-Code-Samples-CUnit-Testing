#include <stdio.h>


#include "maxFunction.h"
#include "avg_and_max.h"
#include "Average_Tests.h"
#include "Max_Tests.h"

void Debug(){
    int n = 4;
    double arr[] = {1,2,3};
    printf("10/4 avg = %.2lf should be 2\n",average(arr,3)); // = 1.5 should be 2.5
    double arr2[] = {1,2,3,4,0};
    printf("avg = %.2lf should be 4\n",average(arr2,n+1)); // = 2 should be 4

    double arr3[] = {1,2,3,4,5};
    printf("\navg = %.2lf\n",average(arr3,5)); // = 2 should be 3
    double arr4[] = {1,2,3,4,5};
    printf("avg = %.2lf\n",average(arr4,6)); // = 2.5 should be 3.5

}

int main() {
    Debug();
    //AVERAGE TEST
    CU_initialize_registry();
    CU_pSuite suite = CreateSuite("AVERAGE_TEST",false);
    CU_basic_set_mode(CU_BRM_VERBOSE);
    CU_basic_run_tests();
    CU_cleanup_registry();

    //AVERAGE TESTS WITH SOLUTION
    CU_initialize_registry();
    CU_pSuite suite_sol = CreateSuite("AVERAGE_TEST_SOLUTION",true);
    CU_basic_set_mode(CU_BRM_VERBOSE);
    CU_basic_run_tests();
    CU_cleanup_registry();

    //MAX_TEST
    CU_initialize_registry();
    CU_pSuite suite_max = CreateSuite2("MAX_TEST",false);
    CU_basic_set_mode(CU_BRM_VERBOSE);
    CU_basic_run_tests();
    CU_cleanup_registry();

    //MAX_TEST WITH SOLUTION
    CU_initialize_registry();
    CU_pSuite suite_max_sol = CreateSuite2("MAX_TEST_SOLUTION",true);
    CU_basic_set_mode(CU_BRM_VERBOSE);
    CU_basic_run_tests();
    CU_cleanup_registry();


    return 0;

}




void DebugMax(){
    double arr2[] = {-1,-2,-3};
    printf("max = %.2lf",(max(arr2,3) == -1));
}





