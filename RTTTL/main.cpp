#include "hwlib.hpp"

extern "C" void print_asciz(const char * s);
extern "C" void application();
extern "C" char convert(char character);

extern "C" void uart_put_char(char c){
    hwlib::cout << convert(c);
}

int main(){
    hwlib::wait_ms(2000);
    application();
}