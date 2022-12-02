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
// 	my_mlx_pixel_put(img, 1920/4, 1080/4, colour);
// 	mlx_put_image_to_window(mlx, mlx_win, img->img, 0, 0);
// }

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