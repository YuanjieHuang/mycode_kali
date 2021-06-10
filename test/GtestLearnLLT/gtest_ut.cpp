extern "C" {
#include <stdio.h>
#include <stdlib.h>
#include "func.h"
#include "ex_func.h"
#include "sort.h"
}

#include <limits.h>
#include <mockcpp/mockcpp.hpp>
#include "gmock/gmock.h"
#include "gtest/gtest.h"
#include <string>

// using namespace std;
using namespace testing;

// void func(int var)
// {
// }
// void test()
// {
//     int var = 10;
//     func(var);
// }
// TEST(sample test)
// {
//     int var;
//     MOCKER(func)
//         .stubs()
//         .with(spy(var));
//         .with(eq(10));

//     test();
//     ASSERT_EQ(var, 10);    
// }

TEST(StringMothodTest, strcmp) {
    const char *cmp0 = "hello";
    const char *cmp1 = "hello";
    EXPECT_EQ(strcmp(cmp0, cmp1), 0);
}
TEST(sort, swap)
{
    int a = 1, b = 2;
    swap(&a, &b);
    EXPECT_EQ(a, 2);
}
// TEST(sample, addTest)
// {
//     MOCKER(add)
//         .expects(once())
//         .with(eq(1), eq(2))
//         .will(returnValue(100));

//     ASSERT_EQ(100, add(1, 2));
//     ASSERT_EQ(50, add(2, 3));
// }
class GtestUt : public testing::Test
{
protected:
    void SetUp() override
    {
        std::cout << "--------------------Gtest_Ut SetUP-------------------" << std::endl;
    }

    void TearDown() override
    {
        std::cout << "--------------------Gtest_Ut TearDown----------------" << std::endl;
        GlobalMockObject::verify();
    }
    
};

class Mock_FOO {
public:
    MOCK_METHOD1(mock_test_struct_func, int(struct test_t *test));
}mocker;


int mock_test_struct_func(struct test_t *test)
{
    return mocker.mock_test_struct_func(test);
}

TEST_F(GtestUt, ut_add_01)
{
    int ret;

    ret = add(1, 2);
    EXPECT_EQ(3, ret);
}

TEST_F(GtestUt, ut_add_02)
{
    int ret;
    struct test_t test;

    test.a = 1;
    test.b = 1;

    MOCKER(multi)
    .expects(atMost(20))
    .will(returnValue(100));
    ret = add_struct(&test);
    EXPECT_EQ(ret, 100);
}

TEST_F(GtestUt, ut_add_03)
{
    int ret;
    struct test_t test;

    test.a = 10;
    test.b = 11;

    MOCKER(multi)
    // .expects(atMost(20))
    .stubs()
    .will(returnValue(30));
    // .id(1);
    ret = add_struct(&test);
    EXPECT_EQ(ret, 30);

    // MOCKER(multi)
    // .expects(atMost(20))
    // .will(returnValue(100));
    // ret = add_struct(&test);
    // EXPECT_EQ(ret, 21);
}

TEST_F(GtestUt, ut_add_04)
{
    int ret;
    int a, b;
    struct test_t test;

    test.a = 10;
    test.b = 11;
    test.p_func = mock_test_struct_func;
    EXPECT_CALL(mocker, mock_test_struct_func(&test)).WillRepeatedly(Return(10));

    ret = test_struct_func(&test);
    EXPECT_EQ(ret, 10);
}

TEST_F(GtestUt, ut_add_05)
{
    int ret;
    int ex_value;
    MOCKER(ex_get_value)
    .stubs()
    .will(returnValue(1));
    ret = test_stub_func();
    EXPECT_EQ(ret, 1);
}
#if 0
TEST(mockcpp detail sample)
{
    MOCKER(function) / MOCK_METHOD(mocker, method)
        .stubs() / defaults() / expects(never() | once() | exactly(3) | atLeast(3) | atMost(3) )
        [.before("some-mocker-id")]
        [.with( any() | eq(3) | neq(3) | gt(3) | lt(3) | spy(var_out) | check(check_func)
                | outBound(var_out) | outBoundP(var_out_addr, var_size) | mirror(var_in_addr, var_size)
                | smirror(string) | contains(string) | startWith(string) | endWith(string) )]
        [.after("some-mocker-id")]
        .will( returnValue(1) | repeat(1, 20) | returnObjectList(r1, r2)
                | invoke(func_stub) | ignoreReturnValue()
                | increase(from, to) | increase(from) | throws(exception) | die(3))
        [.then(returnValue(2))]
        [.id("some-mocker-id")]
}
TEST_F(GtestUt, my_div)
{
    int ret;

    ret = test_my_div(6, 3);
    EXPECT_EQ(2, ret);
}

#endif