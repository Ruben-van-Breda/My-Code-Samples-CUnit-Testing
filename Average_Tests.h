//
// Created by Ruben van Breda on 2020/05/02.
//

#ifndef UNITTESTING_AVERAGE_TESTS_H

#include <stdio.h>
#include "CUnit.h"
#include "Basic.h"
#include "stdbool.h"
#include "avg_and_max.h"

#define UNITTESTING_AVERAGE_TESTS_H

#endif //UNITTESTING_AVERAGE_TESTS_H

void test_avg(void);
void test_avg_increasing_size_by_one(void);
void test_avg_zero(void);
void test_avg_ones(void);
void test_avg_all_same(void);
void test_avg_negative(void);
void test_avg_positive(void);
double average_solution(double array[], int size);
void UseSolution(bool use);

CU_pSuite* CreateSuite(char* strName,bool useSolution);

