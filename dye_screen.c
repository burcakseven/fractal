#include "fractal.h"

// void dye_screen(t_data	*img,void	*mlx,void	*mlx_win, char name)
// {
// 	int i = 500;
// 	int colour = 0;
//  while (i)
//     {
// 	colour = create_trgb(200,200,1,1);
    
// 	my_mlx_pixel_put(img, 1920/4, 1080/4-i, colour);
// 	i--;
       
//     }
// 	mlx_put_image_to_window(mlx, mlx_win, img->img, 0, 0);
// }

void convert_to_xy(t_data	*img,int i , int j)//hata var ???
{
	// img->temp_i = i;
	// img->temp_j = j;
	int colour;
	int w_division =  width_division;
	int h_division = height_division;
	float initial_x;
	float initial_y;
	initial_x = (float)i/(float)w_division;
	initial_y = (float)j/(float)h_division;
	printf("x-y %d %d --",x_orjin_coordinate,y_orjin_coordinate);
	printf("x-y %f %d --",initial_x,y_orjin_coordinate/height_division);
	initial_x -= 4;
	initial_y = 3 - initial_y;
	printf("x-y %f %f\n",initial_x,initial_y);
	
	// red	0x00FF0000
// green	0x0000FF00
// blue	0x000000FF
	// colour = mandelbrot_formula(initial_x,initial_y);
	// if (colour < 50)
	// {
	// my_mlx_pixel_put(img, i,j, 0x00FF0000);
	// }
	// else if(colour < 90)
	// {
	// 	my_mlx_pixel_put(img, i,j, 0x0000FF00);
	// }
	// else
	// {
	// 	my_mlx_pixel_put(img, i,j, 0x000000FF);
	// }
	
	// printf("%f",initial_x);
	// // int zn,zn1,i;

	// // zn = 0;
	// // zn1 = 0; //z0
	
	// while (i++!=200)
	// {
	// 	// zn1 = zn^2 + c;
	// 	// if (zn1 >2)
	// 	// {
	// 	// 	printf
	// 	// }

		 
	// }
	
}

void navigate_on_screen(t_data	*img,void	*mlx,void	*mlx_win, char name)
{
	int i = 0;
	name = '0';
	// while (WIDTH != i++)
	// {
		int j = 0;
	// 	while (HEIGHT != j++)
	// 	{
			i = x_orjin_coordinate;
			j = y_orjin_coordinate;
			// detect_function(name);
			// my_mlx_pixel_put(img, i,j, 0x00FF0000);
			convert_to_xy(img, i, j);
		// }
		
	// }
			mlx_put_image_to_window(mlx, mlx_win, img->img, 0, 0);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}