//
// Created by Ruben van Breda on 2020/05/02.
//

#include "Average_Tests.h"
#include "stdio.h"

bool usingSolution = 0;
double average_solution(double array[], int size){
    double sum = 0;

    for(int i = 0; i < size; i++){
        sum += array[i];

    }
    return sum/size;

}
CU_pSuite* CreateSuite(char* strName, bool n_useSolution){
    usingSolution = n_useSolution;
    CU_Suite *suite = CU_add_suite(strName,0,0);
    CU_add_test(suite,"average_fun_test",test_avg);
    CU_add_test(suite,"avg_positive",test_avg_positive);
    CU_add_test(suite,"avg_negative",test_avg_negative);
    CU_add_test(suite,"avg_zero",test_avg_zero);
    CU_add_test(suite,"avg_all_same",test_avg_all_same);
    CU_add_test(suite,"test_avg_increasing_size_by_one",test_avg_increasing_size_by_one);
    return suite;
}

void test_avg(void){
    double arr[] = {1,2,3};
    double arr2[] = {1,0,3};
    double arr3[] = {1,0,3,4};
    double arr4[] = {-91,129,1003,49};


    if(usingSolution == false){
        CU_ASSERT_EQUAL(average(arr,3), 2);
        CU_ASSERT_EQUAL(average(arr2,3), (4.0/3.0));
        CU_ASSERT_EQUAL(average(arr3,4),1.6);
        CU_ASSERT_EQUAL(average(arr4,4),545/2.0);

    }
    else if(usingSolution == true){
        CU_ASSERT_EQUAL(average_solution(arr,3), 2);
        CU_ASSERT_EQUAL(average_solution(arr2,3), (4.0/3.0));
        CU_ASSERT_EQUAL(average_solution(arr3,4),2);
        CU_ASSERT_EQUAL(average_solution(arr4,4),545/2.0);

    }

}

void test_avg_increasing_size_by_one(void){
    //increasing by 0 cuz it not counting last number so 0 to have no effect hence should work for size -1
    double arr[] = {1,2,3,4,5};
    double arr2[] = {1,2,3,4};
    double arr3[] = {1,2,3,4,1};

    if(usingSolution == 0){
        CU_ASSERT_DOUBLE_EQUAL(average(arr,5), 2.5,0);
        CU_ASSERT_DOUBLE_EQUAL(average(arr2,5),3,0);
        CU_ASSERT_DOUBLE_EQUAL(average(arr3,5),2.2,0);
    }
    else if(usingSolution == 1){
        CU_ASSERT_DOUBLE_EQUAL(average_solution(arr,4), 2.5,0);
        CU_ASSERT_DOUBLE_EQUAL(average_solution(arr2,4),2.5,0);
        CU_ASSERT_DOUBLE_EQUAL(average_solution(arr3,5),2.2,0);
    }

}

void test_avg_zero(void){
    /*This works because the sum is always 0 and 0/any integer is zero,
     * So, this test works for the average and average_solution functions
     * 0/4 is equivalent to 0/5
     * */
    double arr[] = {0};
    double arr2[] = {0,0,0,0};

    CU_ASSERT(average(arr,1) == 0);
    CU_ASSERT(average(arr2,4) == 0);
}

void test_avg_all_same(void){
    double arr[] = {1,1,1,1,1,1};
    double arr2[] = {2,2,2,2,2,2};
    double arr3[] = {100,100,100,100,100,100};
    double arr4[] = {-1,-1,-1,-1,-1,-1};

    if(usingSolution == 0){
        CU_ASSERT_EQUAL(average(arr,6),1);
        CU_ASSERT_EQUAL(average(arr2,6),2);
        CU_ASSERT_EQUAL(average(arr3,6),100);
        CU_ASSERT_EQUAL(average(arr4,6),-1);
    }
    else if(usingSolution == 1){
        CU_ASSERT_EQUAL(average_solution(arr,6),1);
        CU_ASSERT_EQUAL(average_solution(arr2,6),2);
        CU_ASSERT_EQUAL(average_solution(arr3,6),100);
        CU_ASSERT_EQUAL(average_solution(arr4,6),-1);
    }
}
void test_avg_negative(void){
    double arr[] = {-1,-2,-3};
    double arr2[] = {-1.9,-99,-0,-100};
    double arr3[] = {-1,0,-3,-4};

    if(usingSolution == 0){
        CU_ASSERT_EQUAL(average(arr,3) ,-2.0);
        CU_ASSERT_EQUAL(average(arr2,4),(-2009.0/40));
        CU_ASSERT_EQUAL(average(arr3,4),-2);
    }
    else if(usingSolution == 1){
        CU_ASSERT_EQUAL(average_solution(arr,3) ,-2.0);
        CU_ASSERT_EQUAL(average_solution(arr2,4),(-2009.0/40));
        CU_ASSERT_EQUAL(average_solution(arr3,4),-2);
    }

}
void test_avg_positive(void){
    double arr[] = {1,2,3};
    double arr2[] = {1.9,99,0,100};
    double arr3[] = {1,0,3,4};

    if(usingSolution == 0){
        CU_ASSERT_EQUAL(average(arr,3), 2.0);
        CU_ASSERT_EQUAL(average(arr2,4) ,(2009.0/40));
        CU_ASSERT_EQUAL(average(arr3,4), 2);
    }
    if(usingSolution == 1){
        CU_ASSERT_EQUAL(average_solution(arr,3), 2.0);
        CU_ASSERT_EQUAL(average_solution(arr2,4) ,(2009.0/40));
        CU_ASSERT_EQUAL(average_solution(arr3,4), 2);
    }

}

