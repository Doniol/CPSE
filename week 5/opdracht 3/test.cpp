#define CATCH_CONFIG_MAIN
#include <catch.hpp>
#include "intset.hpp"


TEST_CASE("MAX HAS TO BE EQUAL TO 27"){
    intset<int, 10> set;
    set.add(20);
    set.add(22);
    set.add(27);
    set.add(25);

    REQUIRE(set.max() == 27);
}

