#include "fractal.h"

void dye_screen(t_data	*img,void	*mlx,void	*mlx_win)
{
	int i = 500;
	int colour = 0;
 while (i)
    {
	colour = create_trgb(200,200,1,1);
    
	my_mlx_pixel_put(img, 1920/4, 1080/4-i, colour);
	i--;
       
    }
	my_mlx_pixel_put(img, 1920/4, 1080/4, colour);
	mlx_put_image_to_window(mlx, mlx_win, img->img, 0, 0);
}


void init_window(t_fractal *name)
{
	t_data	img;


	name->mlx = mlx_init();
    name->win = mlx_new_window(name->mlx, 1920/2, 1080/2, name->name);
	img.img = mlx_new_image(name->mlx, 1920/2, 1080/2);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								&img.endian);
	
	dye_screen( &img, name->mlx,name->win );
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