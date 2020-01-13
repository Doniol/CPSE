#define CATCH_CONFIG_MAIN


#include "intset.hpp"
#include "catch.hpp"

TEST_CASE("add int to set, add()"){
    intset set{};
    set.add(1);
    set.add(10);

    std::stringstream test;
    test << set;
    
    REQUIRE(test.str() == "[1], [10], [0], [0], [0], [0], [0], [0], [0], [0]");
}

TEST_CASE("remove int from set, remove()"){
    intset set{};
    set.add(1);
    set.add(10);
    set.remove(1);

    std::stringstream test;
    test << set;
    
    REQUIRE(test.str() == "[10], [0], [0], [0], [0], [0], [0], [0], [0], [0]");
}

TEST_CASE("set contains int, contains()"){
    intset set{};
    set.add(1);
    set.add(10);

    REQUIRE(set.contains(10));
}