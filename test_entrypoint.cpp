#include "test.hpp"

using namespace Sol;

int main() {
    Test::Suite::instance()->init(false);

    // Run Tests

    Test::Suite::instance()->kill();
    return 0;
}
