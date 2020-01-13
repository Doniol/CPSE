#include "intset.hpp"



void intset::add(int value){
    if (index < int(set.size()) && !contains(value)){
        set[index] = value;
        index++;
    }
}

void intset::remove(int value){
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

bool intset::contains(int value){
    for(unsigned int i = 0; i < set.size(); i++){
        if(set[i] == value){
            return true;
        }
    }
    return false;
}


std::ostream& operator<<(std::ostream& os, const intset& given_set){
    for (unsigned int i = 0; i < given_set.set.size() - 1; i++){
        os << "[" << given_set.set[i] << "], ";
    }
    os << "[" << given_set.set[-1] << "]";
    return os;
}