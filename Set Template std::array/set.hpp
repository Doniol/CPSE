#ifndef SET_HPP
#define SET_HPP

#include "hwlib.hpp"
#include <vector>
#include <iostream>

template<typename T, int N>
class set{
private:
    std::vector<T> stuff;
public:
    set():
        stuff{}
    {}

    void add(T thing){
        if(stuff.size() < N){
            for(unsigned int i = 0; i < stuff.size(); i++){
                if(stuff[i] == thing){
                    return;
                }
            }
            stuff.push_back(thing);
        }
    }

    void remove(T thing){
        for(unsigned int i = 0; i < stuff.size(); i++){
            if(stuff[i] == thing){
                stuff.erase(stuff.begin() + i);
            }
        }
    }

    bool contains(T thing){
        for(unsigned int i = 0; i < stuff.size(); i++){
            if(stuff[i] == thing){
                return true;
            }
        }
        return false;
    }

    friend std::ostream& operator<<(std::ostream & stream, const set<T, N>& set){
        for(unsigned int i = 0; i < set.stuff.size(); i++){
            stream << set.stuff[i] << " ";
        }
        stream << "\n";
        return stream;
    }

    T max(){
    T temp = stuff[0];
    for(unsigned int i = 1; i < stuff.size(); i++){
        if(stuff[i] > temp){
            temp = stuff[i];
        }
    }
    return temp;
}
};

template<int N>
class set<std::string, N>{
private:
    std::vector<std::string> stuff;
public:
    set():
        stuff{}
    {}

    void add(std::string thing){
        if(stuff.size() < N){
            for(unsigned int i = 0; i < stuff.size(); i++){
                if(stuff[i] == thing){
                    return;
                }
            }
            stuff.push_back(thing);
        }
    }

    void remove(std::string thing){
        for(unsigned int i = 0; i < stuff.size(); i++){
            if(stuff[i] == thing){
                stuff.erase(stuff.begin() + i);
            }
        }
    }

    bool contains(std::string thing){
        for(unsigned int i = 0; i < stuff.size(); i++){
            if(stuff[i] == thing){
                return true;
            }
        }
        return false;
    }

    friend std::ostream& operator<<(std::ostream & stream, const set<std::string, N>& set){
        for(unsigned int i = 0; i < set.stuff.size(); i++){
            stream << set.stuff[i] << " ";
        }
        stream << "\n";
        return stream;
    }

    std::string max(){
        std::string temp = stuff[0];
        for(unsigned int i = 1; i < stuff.size(); i++){
            if(stuff[i].length() > temp.length()){
                temp = stuff[i];
            }
        }
        return temp;
    }
};

template<int N>
class set<std::array<char, 3>, N>{
private:
    std::vector<std::array<char, 3>> stuff;
public:
    set():
        stuff{}
    {}

    void add(std::array<char, 3> thing){
        if(stuff.size() < N){
            for(unsigned int i = 0; i < stuff.size(); i++){
                if(stuff[i] == thing){
                    return;
                }
            }
            stuff.push_back(thing);
        }
    }

    void remove(std::array<char, 3> thing){
        for(unsigned int i = 0; i < stuff.size(); i++){
            if(stuff[i] == thing){
                stuff.erase(stuff.begin() + i);
            }
        }
    }

    bool contains(std::array<char, 3> thing){
        for(unsigned int i = 0; i < stuff.size(); i++){
            if(stuff[i] == thing){
                return true;
            }
        }
        return false;
    }

    friend std::ostream& operator<<(std::ostream & stream, const set<std::array<char, 3>, N>& set){
        for(unsigned int i = 0; i < set.stuff.size(); i++){
            stream << "{";
            for(unsigned int j = 0; j < 3; j++){
                stream << set.stuff[i][j] << ", ";
            }
            stream << "}, ";
        }
        stream << "\n";
        return stream;
    }

    std::array<char, 3> max(){
        std::array<char, 3> temp = stuff[0];
        for(unsigned int i = 1; i < stuff.size(); i++){
            if((stuff[i][0] + stuff[i][1] + stuff[i][2]) > (temp[0] + temp[1] + temp[2])){
                temp = stuff[i];
            }
        }
        return temp;
    }
};

#endif