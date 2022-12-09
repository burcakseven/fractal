#include "fractal.h" //16777215 = 2^2 × 3 × 11 × 31 × (41)

int mandelbrot_formula(float initial_x,float initial_y)
{
    float imagine = 0;
    float reel = 0;
    float hold_reel;
    int count = 0;
    while (imagine*imagine + reel*reel <=4 && count < 70)
    {
        hold_reel = reel;
        reel = (reel*reel - imagine*imagine) +initial_x;
        imagine = (2*imagine*hold_reel) + initial_y;
        count++;
    }
    return((count*3*11*90));
}

int julia_formula(float initial_x,float initial_y)
{
    float imagine = initial_x;
    float reel = initial_y;
    float hold_reel;
    int count = 0;
    while (imagine*imagine + reel*reel <=4 && count < 70)
    {
        hold_reel = reel;
        reel = (reel*reel - imagine*imagine) -0.624;
        imagine = (2*imagine*hold_reel) + 0.435;
        count++;
    }
    return((count*1040));
}