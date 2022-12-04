#include "fractal.h" //16777215 = 2^2 × 3 × 11 × 31 × (41)

// // red	0x00FF0000
// // green	0x0000FF00
// // blue	0x000000FF
// // zn1 = z^2+(x +yi);
int mandelbrot_formula(float initial_x,float initial_y)
{
    // int z_0 = 0;
    float imagine = 0;
    float reel = 0;
    float hold_reel;
    int count = 0;
    while (imagine*imagine + reel*reel <=4 && count < 100)
    {
        hold_reel = reel;
        reel = (reel*reel - imagine*imagine) +initial_x;
        imagine = (2*imagine*hold_reel) + initial_y;
        // printf("int %f %f",initial_x,initial_y);
        count++;
    }
        // printf("%f reel,",reel);
        // printf("%f image,",imagine);
    return(count);
}