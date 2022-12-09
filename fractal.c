#include "fractal.h"

void fill_data(t_fractal *name)
{
	name->move_x = 0;
	name->move_y = 0;
	name->zoom_rate = 1;
}

void init_window(t_fractal *name)
{
	t_data	img;
	name->mlx = mlx_init();
    name->win = mlx_new_window(name->mlx, WIDTH, HEIGHT, name->name);
	img.img = mlx_new_image(name->mlx, WIDTH, HEIGHT);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								&img.endian);
	name->dimension = img;
	navigate_on_screen(&img, name);
	mlx_mouse_hook(name->win, mouse_hook, name);
	mlx_key_hook(name->win, key_hook, name);
	mlx_loop(name->mlx);

}

int main(int ac, char** av)
{
	t_fractal name;
    if (ac == 2)
	{
	fill_data(&name);
	name.name = choose_function(av[1]);
    init_window(&name);
	}
	else
	{
		exit(1);
	}
    return(0);
}