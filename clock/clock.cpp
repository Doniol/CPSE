#include "clock.hpp"

void clock::draw(hwlib::target::pin_in_out buttonh, hwlib::target::pin_in_out buttonm, hwlib::glcd_oled &display) const{
    buttonh.direction_set_input();
    buttonh.flush();
    buttonm.direction_set_input();
    buttonm.flush();

    auto c1 = hwlib::circle(hwlib::xy(coordsHours[30].x + 1, coordsHours[30].y - 1), 2);
    auto c2 = hwlib::circle(hwlib::xy(coordsHours[60].x + 1, coordsHours[60].y), 2);
    auto c3 = hwlib::circle(hwlib::xy(coordsHours[90].x + 3, coordsHours[90].y), 2);
    auto c4 = hwlib::circle(hwlib::xy(coordsHours[120].x + 2, coordsHours[120].y + 1), 2);
    auto c5 = hwlib::circle(hwlib::xy(coordsHours[150].x + 1, coordsHours[150].y + 1), 2);
    auto c6 = hwlib::circle(hwlib::xy(coordsHours[180].x + 0, coordsHours[180].y + 3), 2);

    auto c7 = hwlib::circle(hwlib::xy(coordsHours[210].x - 2, coordsHours[210].y + 1), 2);
    auto c8 = hwlib::circle(hwlib::xy(coordsHours[240].x - 1, coordsHours[240].y + 1), 2);
    auto c9 = hwlib::circle(hwlib::xy(coordsHours[270].x - 2, coordsHours[270].y), 2);
    auto c10 = hwlib::circle(hwlib::xy(coordsHours[300].x - 1, coordsHours[300].y), 2);
    auto c11 = hwlib::circle(hwlib::xy(coordsHours[330].x - 1, coordsHours[330].y), 2);
    auto c12 = hwlib::circle(hwlib::xy(coordsHours[359].x + 1, coordsHours[359].y - 2), 2);

    auto c = hwlib::circle(hwlib::xy(startx, starty), radius);
    for(unsigned int i = 0; i < 360; i+=30){
        for(unsigned int j = 0; j < 360; j+=6){
            display.clear();
            auto minutes = hwlib::line(hwlib::xy(startx, starty), coordsMinutes[j]);
            auto hours = hwlib::line(hwlib::xy(startx, starty), coordsHours[i + (j / 12)]);

            c.draw(display);
            c1.draw(display);
            c2.draw(display);
            c3.draw(display);
            c4.draw(display);
            c5.draw(display);
            c6.draw(display);
            c7.draw(display);
            c8.draw(display);
            c9.draw(display);
            c10.draw(display);
            c11.draw(display);
            c12.draw(display);
            minutes.draw(display);
            hours.draw(display);
            display.flush();

            if(!buttonh.read()){
                i += 30;
            } else if(!buttonm.read()){
                j += 6;
            }

            hwlib::wait_ms(1000);
        }
    }
}