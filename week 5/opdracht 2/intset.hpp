#ifndef _INTSET_HPP
#define _INTSET_HPP

#include <array>
#include <ostream>

template <typename K, int T>
class intset { 

    std::array<K, T> set;
    int index = 0;

public:

    intset(){}

    //adds an item to the set
    void add(K value){

        if (index < T){
            set[index] = value;
            index++;
        }
    };

    //removes first encounter of given item inside of set
    void remove(K value){

        for (unsigned int i = 0; i < T; i++){
            if (set[i] == value){
                for (unsigned int j = i; j < (T - 1); j++){
                    set[j] = set[j + 1];
                }
                index--;
                return;
            }
        }
    }

    //returns if item is inside of set
    bool contains(K value){

        for(unsigned int i = 0; i < T; i++){
            if(set[i] == value){
                return true;
            }
        }
        return false;

    }

    //returns max value of item inside set
    K max() {
        K max = set[0];
        for (size_t i = 1; i < index; i++) {
            if (set[i] > max){
                max = set[i];
            } 
        }
        return max;
    }

    friend std::ostream& operator<<(std::ostream& os, const intset& set){
            
        for (unsigned int i = 0; i < set.index; i++){
            os << '[' << set.set[i] << ']';
        }
        return os;

    }
};






#endif //_INTSET_HPP