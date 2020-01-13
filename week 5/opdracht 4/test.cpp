#define CATCH_CONFIG_MAIN
#include <catch.hpp>
#include "intset.hpp"


TEST_CASE("MAX HAS TO BE EQUAL TO 27"){
    intset<char, 3> set;
    set.add('a');
    set.add('b');
    set.add('z');
    set.add('d');

    REQUIRE(set.max() == 'z');
}
