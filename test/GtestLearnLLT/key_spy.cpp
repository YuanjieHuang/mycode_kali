#include <mockcpp/mockcpp.hpp>
#include "gmock/gmock.h"
#include "gtest/gtest.h"

void func(int var)
{
}
void test()
{
    int var = 10;
    func(var);
}
TEST(spy test)
{
    int var;
    MOCKER(func)
        .stubs()
        .with(spy(var));
        .with(eq(10));

    test();
    ASSERT_EQ(var, 10);    
}