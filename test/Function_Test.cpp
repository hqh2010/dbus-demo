#include <gtest/gtest.h>

// #include "../src/utils/Function.h"
#include "Function.h"

TEST(FuncTest, test01)
{
    int a = 5;
    int b = 3;
    int ret = Function::add(a, b);
    EXPECT_EQ(ret, 8);
}

TEST(FuncTest, test02)
{
    int a = 5;
    int b = 3;
    int ret = Function::minus(a, b);
    EXPECT_EQ(ret, 2);
}