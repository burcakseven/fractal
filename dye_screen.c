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

void convert_to_xy(t_data	*img,float i , float j)
{
	float initial_x;
	float initial_y;
	initial_x = i/width_division;
	initial_y = j/height_division;

	initial_x -= 4;
	initial_y = 2 - initial_y;
	
	my_mlx_pixel_put(img, i,j, 0x00FF0000);
	printf("%f",initial_x);
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
	while (WIDTH != i++)
	{
		int j = 0;
		while (HEIGHT != j++)
		{
			// detect_function(name);
			// my_mlx_pixel_put(img, i,j, 0x00FF0000);
			convert_to_xy(img,(float) i, (float)j);
		}
		
	}
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