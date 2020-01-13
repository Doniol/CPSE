#ifndef _INTSET_HPP
#define _INTSET_HPP


#include <iostream>
using namespace std;

class intset { 

    int set[10] = {0};
    int index = 0;

public:

    intset(){}

    void add(int value);

    void remove(int value);

    bool contains(int value);
 
    friend ostream& operator<<(ostream& os, const intset& p_set);


};



#endif //_INTSET_HPP