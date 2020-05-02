//
// Created by Ruben van Breda on 2020/05/02.
//

#include <stdbool.h>
#include "avg_and_max.h"
#include "Max_Tests.h"
bool useSolution = 0;
double max_solution(double array[], int size){
    double max = array[0];
    for(int i =0; i < size ; i++){
        if(max < array[i])
            max = array[i];
    }
    return max;

}

CU_pSuite* CreateSuite2(char* strName,bool n_useSolution){
    useSolution = n_useSolution;
    CU_Suite *suite2 = CU_add_suite(strName,0,0);
    CU_add_test(suite2,"max_fun",test_max);
    CU_add_test(suite2,"max_positive",test_max_positive);
    CU_add_test(suite2,"max_negative",test_max_negative);
    CU_add_test(suite2,"max_zero",test_max_zero);
    CU_add_test(suite2,"max_all_same",test_max_all_same);
    return suite2;
}


void test_max(void){
    double arr[] = {1,2,3};
    double arr2[] = {-1,-2,-3};
    double arr3[] = {-0,-2};
    double arr4[] = {-99,10,1,0.5};


    if(useSolution == false){
        CU_ASSERT_EQUAL(max(arr,3),3);
        CU_ASSERT_EQUAL(max(arr2,3), -1);
        CU_ASSERT_EQUAL(max(arr3,2), 0);
        CU_ASSERT_EQUAL(max(arr4,4),10);
    }
    if(useSolution == true){
        CU_ASSERT_EQUAL(max_solution(arr,3),3);
        CU_ASSERT_EQUAL(max_solution(arr2,3), -1);
        CU_ASSERT_EQUAL(max_solution(arr3,2), 0);
        CU_ASSERT_EQUAL(max_solution(arr4,4),10);
    }


}
void test_max_zero(void){
    double arr[] = {0};
    double arr2[] = {0,0,0,0};

    if(useSolution == false){
        CU_ASSERT_EQUAL(max(arr,1) ,0);
        CU_ASSERT_EQUAL(max(arr2,4) ,0);
    }
    if(useSolution == true){
        CU_ASSERT_EQUAL(max_solution(arr,1) ,0);
        CU_ASSERT_EQUAL(max_solution(arr2,4) ,0);
    }

}
void test_max_positive(void){
    double arr[] = {1,2,3};
    double arr2[] = {10,21,10};
    double arr3[] = {1,2,9,3};
    double arr4[] = {1,2,10,3};
    double arr5[] = {1,2,3,10,11};
    double arr6[] = {1.1,7.5,8.6,19,10,20.9,100.1,110};


    if(useSolution == false) {
        CU_ASSERT_EQUAL(max(arr, 3), 3);
        CU_ASSERT_EQUAL(max(arr2, 3), 21);
        CU_ASSERT_EQUAL(max(arr3, 4), 9);
        CU_ASSERT_EQUAL(max(arr4, 4), 10);
        CU_ASSERT_EQUAL(max(arr4, 5), 10);
        CU_ASSERT_EQUAL(max(arr6, 8), 110);
    }
    if(useSolution == true) {
        CU_ASSERT_EQUAL(max_solution(arr, 3), 3);
        CU_ASSERT_EQUAL(max_solution(arr2, 3), 21);
        CU_ASSERT_EQUAL(max_solution(arr3, 4), 9);
        CU_ASSERT_EQUAL(max_solution(arr4, 4), 10);
        CU_ASSERT_EQUAL(max_solution(arr4, 5), 10);
        CU_ASSERT_EQUAL(max_solution(arr6, 8), 110);
    }

}
void test_max_negative(void){
    double arr[] = {-1,-2,-3};
    double arr2[] = {-10,-21,-10};
    double arr3[] = {0,-2};
    double arr4[] = {-1.1,-7.5,-8.6,-19,-10,-20.9,-100.1,-110};
    if(useSolution == false) {
        CU_ASSERT_EQUAL(max(arr,3) ,0);
        CU_ASSERT_EQUAL(max(arr2,3),-10);
        CU_ASSERT_EQUAL(max(arr3,2),0);
        CU_ASSERT_EQUAL(max(arr4,8),-1.1);
    }
    if(useSolution == true) {
        CU_ASSERT_EQUAL(max_solution(arr,3) ,-1);
        CU_ASSERT_EQUAL(max_solution(arr2,3),-10);
        CU_ASSERT_EQUAL(max_solution(arr3,2),0);
        CU_ASSERT_EQUAL(max_solution(arr4,8),-1.1);
    }

}
void test_max_all_same(void){
    double arr[] = {1,1,1,1,1,1};
    double arr2[] = {2,2,2,2,2,2};
    double arr3[] = {100,100,100,100,100,100};
    double arr4[] = {-1,-1,-1,-1,-1,-1};
    if(useSolution == false) {
        CU_ASSERT_EQUAL(max(arr,6),1);
        CU_ASSERT_EQUAL(max(arr2,6), 2);
        CU_ASSERT_EQUAL(max(arr3,6),100);
        CU_ASSERT_EQUAL(max(arr4,6),-1);
    }
    if(useSolution == true) {
        CU_ASSERT_EQUAL(max_solution(arr,6),1);
        CU_ASSERT_EQUAL(max_solution(arr2,6), 2);
        CU_ASSERT_EQUAL(max_solution(arr3,6),100);
        CU_ASSERT_EQUAL(max_solution(arr4,6),-1);
    }

}

