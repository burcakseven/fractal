#include "fractal.h"


void init_window(char* fractal_name)
{
    void	*mlx;
	t_data	img;
    void	*mlx_win;

	mlx = mlx_init();
    mlx_win = mlx_new_window(mlx, 1920/2, 1080/2, fractal_name);
	img.img = mlx_new_image(mlx, 1920/2, 1080/2);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								&img.endian); 
     int i = 100;
	int colour;
	
    while (i)
    {
	colour = create_trgb(200,200,1,1);
    
	my_mlx_pixel_put(&img, 1920/4, 1080/4-i, colour);
	i--;
       
    }
	my_mlx_pixel_put(&img, 1920/4, 1080/4, colour);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);

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

int main(int ac, char** av)
{
    ac = 1;
    init_window(av[1]);
    return(0);
}