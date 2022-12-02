#include "fractal.h"

// void detect_function(char name)
// {
// 	if(name == 'm')
// 	{
// 		dye_screen_m();
// 	}
// 	else
// 		dye_screen_j();

// }

void navigate_on_screen(t_data	*img,void	*mlx,void	*mlx_win, char name)
{
	int i = 0;
	name = '0';
	while (HEIGHT != i++)
	{
		int j = 0;
		while (WIDTH != j++)
		{
			// detect_function(name);
			my_mlx_pixel_put(img, i, j, 0x00FF0000);
		}
		
	}
			mlx_put_image_to_window(mlx, mlx_win, img->img, 0, 0);
}


void init_window(t_fractal *name)
{
	t_data	img;


	name->mlx = mlx_init();
    name->win = mlx_new_window(name->mlx, HEIGHT, WIDTH, name->name);
	img.img = mlx_new_image(name->mlx, HEIGHT, WIDTH);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								&img.endian);

	navigate_on_screen(&img, name->mlx,name->win, name->name[0]);
	// dye_screen( &img, name->mlx,name->win, name->name[0]);
	mlx_loop(name->mlx);

}

int main(int ac, char** av)
{
	t_fractal name;
    if (ac == 2)
	{
	name.name = choose_function(av[1]);
    init_window(&name);
	}
	else
	{
		exit(1);
	}
    return(0);
}