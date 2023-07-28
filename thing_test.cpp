#include "test.hpp"
#include "thing.hpp"

namespace Test {
namespace ThingTest {
    void test1(bool skip) {
        Thing thing = Thing::build();
        EQ(thing.x, 3, true, skip);
    }

    void run() {
        TEST_PRINT_BEGIN();
        test1(false);
    }
} // namespace Thing
} // namespace Test
