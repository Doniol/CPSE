#include "intset.hpp"
#include <iostream>

int main(void){

    intset<int, 10> set;


    set.add(5);
    set.add(1000);
    set.add(6);    
    set.add(22);
    set.add(7);
    set.add(88);
    set.remove(5);
    set.remove(0);
    std::cout << set.max();

    // std::cout << set;
    




}