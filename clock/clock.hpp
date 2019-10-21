#include <math.h>
#include "hwlib.hpp"

class clock{
private:
    int startx;
    int starty;
    int radius;
    hwlib::xy coordsHours [360];
    hwlib::xy coordsMinutes [360];
public:
    constexpr clock(int startx, int starty, int radius):
        startx(startx),
        starty(starty),
        radius(radius)
    {
        calculate();
    };

    constexpr void calculate(){
        double hoekA = 0.0;
        while(hoekA < 360.0){
            double radhoekA = hoekA / 180.0 * 3.14159;
            double aanliggend = cos(radhoekA) * (radius - 2);
            double overstaand = sin(radhoekA) * (radius - 2);

            coordsHours[int(hoekA)] = hwlib::xy(startx + overstaand, starty - aanliggend);

            hoekA += 1;
        }

        double hoekB = 0.0;
        while(hoekB < 360.0){
            double radhoekB = hoekB / 180.0 * 3.14159;
            double aanliggend = cos(radhoekB) * (radius - 8);
            double overstaand = sin(radhoekB) * (radius - 8);

            coordsMinutes[int(hoekB)] = hwlib::xy(startx + overstaand, starty - aanliggend);

            hoekB += 1;
        }
    }

    void draw(hwlib::target::pin_in_out buttonh, hwlib::target::pin_in_out buttonm, hwlib::glcd_oled &display) const;
};