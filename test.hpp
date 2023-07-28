#pragma once
#include <iostream>

#define GLOBAL_TEST_KILL false
#define GLOBAL_TEST_NO_KILL true

static const char* RED = "\033[0;31m";
static const char* NC = "\033[0m";
static const char* GREEN = "\033[0;33m";
static const char* YELLOW = "\033[1;33m";

#define TEST_PRINT_BEGIN() \
    std::cout << "Beginning Test Suite " << __FILE__ << ":\n"
#define TEST_PRINT_PASS() \
    std::cout << GREEN << "OK\n" << NC;
#define TEST_PRINT_SKIP() \
    std::cout << YELLOW << "SKIPPED\n" << NC;
#define TEST_PRINT_FAIL_EQ(print_arg1__, print_arg2__) \
    std::cout << RED << "FAIL: " << NC << print_arg1__ << " != " << print_arg2__ << '\n';

namespace Test {

template<typename T>
bool match_eq(T arg1, T arg2, bool skip) {
    if (skip) {
        TEST_PRINT_SKIP();
        return true;
    }
    if (arg1 != arg2) {
        return false;
    }
    TEST_PRINT_PASS();
    return true;
}
}

#define KILL_TEST(mod_kill__) \
    if (GLOBAL_TEST_KILL) { \
        __builtin_trap(); \
    } \
    else if (!GLOBAL_TEST_NO_KILL && mod_kill__) { \
        __builtin_trap(); \
    }

#define EQ(eq_arg1__, eq_arg2__, mod_kill__, skip__) \
    std::cout << "Test " << __FUNCTION__ << '\n'; \
    if (!Test::match_eq(eq_arg1__, eq_arg2__, skip__)) { \
        TEST_PRINT_FAIL_EQ(#eq_arg1__, #eq_arg2__); \
    } \
    KILL_TEST(mod_kill__)

