#include "fractal.h"

int	key_hook(int keycode, t_fractal *fractal)
{

    if (keycode == KEY_ESC)
        exit(EXIT_SUCCESS);
		
    else if (keycode == KEY_A)
        fractal->move_x += 0.5*(fractal->zoom_rate);
    else if (keycode == KEY_D)
        fractal->move_x -= 0.5*(fractal->zoom_rate);
    else if (keycode == KEY_W)
        fractal->move_y -= 0.5*(fractal->zoom_rate);
    else if (keycode == KEY_S)
        fractal->move_y += 0.5*(fractal->zoom_rate);

    navigate_on_screen(&fractal->dimension,fractal);
	return (1);
}

int mouse_hook(int keycode,int x, int y, t_fractal *fractal)
{
    x = 0;
    y = 0;
    if (keycode == SCROLL_UP)
    {
        fractal->zoom_rate *= 1.1;
    }
    if (keycode == SCROLL_DOWN)
    {
        fractal->zoom_rate /= 1.1;
    }
    
    navigate_on_screen(&fractal->dimension,fractal);
    return(1);
}