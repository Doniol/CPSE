#include "clock.hpp"

int main( void ){	  
   namespace target = hwlib::target;
   
   auto scl = target::pin_oc( target::pins::scl );
   auto sda = target::pin_oc( target::pins::sda );
   auto i2c_bus = hwlib::i2c_bus_bit_banged_scl_sda( scl,sda );
   auto display = hwlib::glcd_oled( i2c_bus, 0x3c );

   constexpr auto drawing = clock(65, 31, 30);

   auto buttonh = hwlib::target::pin_in_out(hwlib::target::pins::d6);
   auto buttonm = hwlib::target::pin_in_out(hwlib::target::pins::d7);

   for(;;){
      drawing.draw(buttonh, buttonm, display);
   }
}