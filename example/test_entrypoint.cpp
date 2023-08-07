#include "../test.hpp"
#include "SomeClassTest.hpp"

using namespace Sol;

int main() {
    Test::Suite::instance()->init(false);

    SomeClassTest some_class = {};
    some_class.run();

    Test::Suite::instance()->kill();
    return 0;
}
