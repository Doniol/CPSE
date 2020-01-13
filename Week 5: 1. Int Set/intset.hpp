#ifndef _INTSET_HPP
#define _INTSET_HPP


#include <iostream>
#include <array>
#include <ostream>
#include <sstream>

// Class for a set of 10 integers
class intset { 
    std::array<int, 10> set;
    int index = 0;

public:
    // Constructor for class
    intset(){}

    // Function for adding an integer to the set
    void add(int value);

    // Function for removing an integer from the set
    void remove(int value);

    // Returns whether the set contains a certain integer
    bool contains(int value);
 
    // Turns the array into a string
    friend std::ostream& operator<<(std::ostream& os, const intset& set);
};


#endif //_INTSET_HPP