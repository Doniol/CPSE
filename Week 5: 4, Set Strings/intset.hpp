#ifndef _INTSET_HPP
#define _INTSET_HPP


#include <iostream>
#include <array>
#include <sstream>
#include <algorithm>

template<typename T, int N>
// Class for a set of N number of T
class intset { 
private:
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

    // Returns the set
    std::array<T, N> get_set(){
        return set;
    }
};

// Returns max value in set if applicable, otherwise returns first value
template<typename T, int N>
T max(intset<T, N> input){
    auto set = input.get_set();
    return set[0];
}

template<int N>
int max(intset<int, N> input){
    std::array<int, N> set = input.get_set();
    return *std::max_element(set.begin(), set.end());
}

template<int N>
float max(intset<float, N> input){
    std::array<float, N> set = input.get_set();
    return *std::max_element(set.begin(), set.end());
}

template<int N>
char max(intset<char, N> input){
    std::array<char, N> set = input.get_set();
    return *std::max_element(set.begin(), set.end());
}

template<int N>
std::string max(intset<std::string, N> input){
    std::array<std::string, N> set = input.get_set();
    std::string highest = set[0];
    for(auto entry : set){
        if(entry.size() > highest.size()){
            highest = entry;
        }
    }
    return highest;
}


#endif //_INTSET_HPP