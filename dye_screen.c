#include "fractal.h"

void convert_to_xy(t_data	*img,t_fractal *fractal,int i , int j)
{
	int colour = 0;
	int w_division;
	w_division = width_division;
	int h_division;
	h_division = height_division;
	float initial_x;
	float initial_y;
	initial_x = (float)i/(float)w_division*fractal->zoom_rate;
	initial_y = (float)j/(float)h_division*fractal->zoom_rate;
	initial_x -= 4+fractal->move_x;
	initial_y = (3-fractal->move_y) - initial_y;

	if (fractal->name[0] == 'm')
	colour = mandelbrot_formula(initial_x,initial_y);
	else if (fractal->name[0] == 'j')
	colour = julia_formula(initial_x,initial_y);
	
	my_mlx_pixel_put(img, i,j, colour);
}

void navigate_on_screen(t_data	*img,t_fractal *fractal)
{
	int i = 0;
	while (WIDTH != i++)
	{
		int j = 0;
		while (HEIGHT != j++)
		{
			convert_to_xy(img,fractal,i, j);
		}
		
	}
		mlx_put_image_to_window(fractal->mlx, fractal->win, img->img, 0, 0);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}