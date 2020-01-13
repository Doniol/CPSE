#include "intset.hpp"
#include <iostream>

int main(void){

    intset setje;


    setje.add(5);
    setje.add(1000);
    setje.add(6);    
    setje.add(22);
    setje.add(7);
    setje.add(88);
    setje.remove(5);
    setje.remove(0);

    std::cout << setje;
    




}