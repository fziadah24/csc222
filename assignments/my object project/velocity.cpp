#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest.h>
#include "velocity.h"
using namespace std;

TEST_CASE("Test can create and render velocity") {
    velocity vel(1, 1, 1);
    CHECK(vel.toString() == "1.000000 mph, 1.000000 mphps, 1 degrees");
    vel.increment(1);
    CHECK(vel.toString() == "2.000000 mph, 1.000000 mphps, 1 degrees");
    vel.increment(1., 1.);
    CHECK(vel.toString() == "3.000000 mph, 0.000000 mphps, 1 degrees");
    vel.increment(2, -1, 1);
    CHECK(vel.toString() == "4.000000 mph, 2.000000 mphps, 3 degrees");
}

