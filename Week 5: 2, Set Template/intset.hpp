#ifndef _INTSET_HPP
#define _INTSET_HPP


#include <iostream>
#include <array>
#include <sstream>

template<typename T, int N>
// Class for a set of N number of T
class intset { 
    std::array<T, N> set{};
    int index = 0;

public:
    // Constructor for class
    intset(){}

    // Function for adding an integer to the set
    void add(T value){
        if (index < int(set.size()) && !contains(value)){
            set[index] = value;
            index++;
        }
    }

    // Function for removing an integer from the set
    void remove(T value){
        for (unsigned int i = 0; i < set.size(); i++){
            if (set[i] == value){
                for (unsigned int j = i; j < set.size() - 1; j++){
                    set[j] = set[j + 1];
                }
                index--;
                return;
            }
        }
    }

    // Returns whether the set contains a certain integer
    bool contains(T value){
        for(unsigned int i = 0; i < set.size(); i++){
            if(set[i] == value){
                return true;
            }
        }
        return false;
    }
 
    // Turns the array into a string
    friend std::ostream& operator<<(std::ostream& os, const intset<T, N>& given_set){
        for (unsigned int i = 0; i < given_set.set.size() - 1; i++){
            os << "[" << given_set.set[i] << "], ";
        }
        os << "[" << given_set.set[given_set.set.size() - 1] << "]";
        return os;
    }
};


#endif //_INTSET_HPP