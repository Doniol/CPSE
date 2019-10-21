#define CATCH_CONFIG_MAIN 
#include "catch.hpp"
#include "set.hpp"
#include <sstream>

template<typename T, int N>
std::string toString(const set<T, N> &test){
    std::stringstream str;
    str << test;

    std::ostringstream ss;
    ss << str.rdbuf();
    return ss.str();
};

// INT
TEST_CASE("add int, operator<<"){
    set<int, 10> test;
    test.add(1);
    test.add(1);
    test.add(2);

    std::string converted = toString(test);

    REQUIRE(converted == "1 2 \n");
}

TEST_CASE("too many ints, operator<<"){
    set<int, 10> test;
    test.add(1);
    test.add(2);
    test.add(3);
    test.add(4);
    test.add(5);
    test.add(6);
    test.add(7);
    test.add(8);
    test.add(9);
    test.add(10);
    test.add(11);

    std::string converted = toString(test);

    REQUIRE(converted == "1 2 3 4 5 6 7 8 9 10 \n");
}

TEST_CASE("remove int, operator<<"){
    set<int, 10> test;
    test.add(1);
    test.add(2);
    test.add(3);
    test.remove(2);
    test.remove(3);

    std::string converted = toString(test);

    REQUIRE(converted == "1 \n");
}

TEST_CASE("contains int, operator<<"){
    set<int, 10> test;
    test.add(1);
    test.add(9);
    test.add(10);

    REQUIRE(test.contains(1) == true);
}

TEST_CASE("does not contain int, operator<<"){
    set<int, 10> test;
    test.add(1);
    test.add(9);
    test.add(10);

    REQUIRE(test.contains(4) == false);
}

TEST_CASE("max int, operator<<"){
    set<int, 10> test;
    test.add(1);
    test.add(9);
    test.add(10);

    REQUIRE(test.max() == 10);
}


//STRING
TEST_CASE("add string, operator<<"){
    set<std::string, 10> test;
    test.add("hai");
    test.add("ik");
    test.add("ik");
    test.add("ben");

    std::string converted = toString(test);

    REQUIRE(converted == "hai ik ben \n");
}

TEST_CASE("too many strings, operator<<"){
    set<std::string, 10> test;
    test.add("hai");
    test.add("ik");
    test.add("ben");
    test.add("Daniel");
    test.add("van");
    test.add("Eijk");
    test.add("-");
    test.add("Bos");
    test.add("Bulkowski");
    test.add("boi");
    test.add("iii");

    std::string converted = toString(test);

    REQUIRE(converted == "hai ik ben Daniel van Eijk - Bos Bulkowski boi \n");
}

TEST_CASE("remove string, operator<<"){
    set<std::string, 10> test;
    test.add("hai");
    test.add("hia");
    test.add("hoi");
    test.remove("hia");
    test.remove("hoi");

    std::string converted = toString(test);

    REQUIRE(converted == "hai \n");
}

TEST_CASE("contains string, operator<<"){
    set<std::string, 10> test;
    test.add("hi");
    test.add("hoi");
    test.add("hai");

    REQUIRE(test.contains("hi") == true);
}

TEST_CASE("does not contain string, operator<<"){
    set<std::string, 10> test;
    test.add("hi");
    test.add("hoi");
    test.add("hai");

    REQUIRE(test.contains("hio") == false);
}

TEST_CASE("max string, operator<<"){
    set<std::string, 10> test;
    test.add("hi");
    test.add("hai");
    test.add("hello");

    std::string s = test.max();
    REQUIRE(s == "hello");
}


//std::array<char, 3>
TEST_CASE("add std::array<char, 3>, operator<<"){
    set<std::array<char, 3>, 10> test;
    test.add({'a', 'b', 'c'});
    test.add({'d', 'e', 'f'});
    test.add({'g', 'h', 'i'});
    test.add({'j', 'k', 'l'});

    std::string converted = toString(test);

    REQUIRE(converted == "{a, b, c, }, {d, e, f, }, {g, h, i, }, {j, k, l, }, \n");
}

TEST_CASE("too many std::array<char, 3>, operator<<"){
    set<std::array<char, 3>, 10> test;
    test.add({'a', 'b', 'c'});
    test.add({'d', 'e', 'f'});
    test.add({'g', 'h', 'i'});
    test.add({'j', 'k', 'l'});
    test.add({'m', 'n', 'o'});
    test.add({'p', 'q', 'r'});
    test.add({'s', 't', 'u'});
    test.add({'v', 'w', 'x'});
    test.add({'y', 'z', 'a'});
    test.add({'b', 'c', 'd'});
    test.add({'e', 'f', 'g'});

    std::string converted = toString(test);

    REQUIRE(converted == "{a, b, c, }, {d, e, f, }, {g, h, i, }, {j, k, l, }, {m, n, o, }, {p, q, r, }, {s, t, u, }, {v, w, x, }, {y, z, a, }, {b, c, d, }, \n");
}

TEST_CASE("remove std::array<char, 3>, operator<<"){
    set<std::array<char, 3>, 10> test;
    test.add({'a', 'b', 'c'});
    test.add({'d', 'e', 'f'});
    test.add({'g', 'h', 'i'});
    test.remove({'a', 'b', 'c'});
    test.remove({'d', 'e', 'f'});

    std::string converted = toString(test);

    REQUIRE(converted == "{g, h, i, }, \n");
}

TEST_CASE("contains std::array<char, 3>, operator<<"){
    set<std::array<char, 3>, 10> test;
    test.add({'a', 'b', 'c'});
    test.add({'d', 'e', 'f'});
    test.add({'g', 'h', 'i'});

    REQUIRE(test.contains({'g', 'h', 'i'}) == true);
}

TEST_CASE("does not contain std::array<char, 3>, operator<<"){
    set<std::array<char, 3>, 10> test;
    test.add({'a', 'b', 'c'});
    test.add({'d', 'e', 'f'});
    test.add({'g', 'h', 'i'});

    REQUIRE(test.contains({'g', 'h', 'j'}) == false);
}

TEST_CASE("max std::array<char, 3>, operator<<"){
    set<std::array<char, 3>, 10> test;
    test.add({'a', 'b', 'c'});
    test.add({'d', 'e', 'f'});
    test.add({'g', 'h', 'i'});

    std::array<char, 3> s = test.max();
    char compare[3] = {'g', 'h', 'i'};
    bool check = (s[0] == compare[0]) && (s[1] == compare[1]) && (s[2] == compare[2]);
    REQUIRE(check == true);
}