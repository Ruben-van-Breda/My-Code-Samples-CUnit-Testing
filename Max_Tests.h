//
// Created by Ruben van Breda on 2020/05/02.
//

#ifndef UNITTESTING_MAX_TESTS_H
#define UNITTESTING_MAX_TESTS_H

#include <stdio.h>

#include "CUnit.h"
#include "Basic.h"
#endif //UNITTESTING_MAX_TESTS_H

void test_max(void);
void test_max_zero(void);
void test_max_positive(void);
void test_max_negative(void);
void test_max_all_same(void);
CU_pSuite* CreateSuite2(char* strName,bool useSolution);

