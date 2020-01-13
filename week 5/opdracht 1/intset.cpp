#include "intset.hpp"



void intset::add(int value){

    if (index < 10){
        set[index] = value;
        index++;
    }

}

void intset::remove(int value){

    for (unsigned int i = 0; i < 10; i++){
        if (set[i] == value){
            for (unsigned int j = i; j < 9; j++){
                set[j] = set[j + 1];
            }
            index--;
            return;
        }
    }

}

bool intset::contains(int value){

    for(unsigned int i = 0; i < 10; i++){
        if(set[i] == value){
            return true;
        }
    }
    return false;

}


std::ostream& operator<<(std::ostream& os, const intset& p_set){
        
    for (unsigned int i = 0; i < 10; i++){
        os << '[' << p_set.set[i] << ']';
    }
    return os;

};