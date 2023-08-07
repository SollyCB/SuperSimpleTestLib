#include "SomeClassTest.hpp"
#include "SomeClass.hpp"
#include "../test.hpp"

void test1() {
    SomeClass some_class = {};
    TEST_EQ("add_method", some_class.add(), 0, false);
}

void SomeClassTest::run() {
    TEST_MODULE_BEGIN("SomeClassTest", false, false);
    test1();
    TEST_MODULE_END();
}
