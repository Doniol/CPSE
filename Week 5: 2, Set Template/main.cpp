#define CATCH_CONFIG_MAIN


#include "intset.hpp"
#include "catch.hpp"

TEST_CASE("add int to set, add()"){
    intset<int, 10> set;
    set.add(1);
    set.add(10);

    std::stringstream test;
    test << set;
    
    REQUIRE(test.str() == "[1], [10], [0], [0], [0], [0], [0], [0], [0], [0]");
}

TEST_CASE("add string to set, add()"){
    intset<std::string, 3> set;
    set.add("hai");
    set.add("boi");

    std::stringstream test;
    test << set;

    REQUIRE(test.str() == "[hai], [boi], []");
}

TEST_CASE("remove int from set, remove()"){
    intset<int, 10> set;
    set.add(1);
    set.add(10);
    set.remove(1);

    std::stringstream test;
    test << set;
    
    REQUIRE(test.str() == "[10], [0], [0], [0], [0], [0], [0], [0], [0], [0]");
}

TEST_CASE("remove string from set, remove()"){
    intset<std::string, 3> set;
    set.add("hai");
    set.add("boi");
    set.remove("hai");

    std::stringstream test;
    test << set;

    REQUIRE(test.str() == "[boi], [], []");
}

TEST_CASE("set contains int, contains()"){
    intset<int, 10> set;
    set.add(1);
    set.add(10);

    bool ans = set.contains(10) && !set.contains(11);

    REQUIRE(ans);
}

TEST_CASE("set contains string, contains()"){
    intset<std::string, 3> set;
    set.add("hai");
    set.add("boi");

    bool ans = set.contains("boi") && !set.contains("boii");

    REQUIRE(ans);
}