#include "fractal.h"

void    paint_image(t_imgdata *img, int width, int height, int color)
{
    int	i;
	int	j;

	i = -1;
	while (++i < width)
	{
		j = -1;
		while (++j < height)
			my_mlx_pixel_put(img, i, j, color);
	}
}

t_base_point    create_base(double  posx, double posy, double coorx, double coory)
{
    t_base_point ret;

    ret.posx = posx;
    ret.posy = posy;
    ret.coorx = coorx;
    ret.coory = coory;
    return (ret);
}

double	calculate_coor(int pos, t_vars *vars, char sep)
{
	double	base;

	if (sep == 'r')
		base = (pos - vars->xy.posx) * vars->zo_rate + vars->xy.old_corx;
	else
		base = (vars->xy.posy - pos) * vars->zo_rate + vars->xy.old_cory;
	return (base);
}

void design_image(t_vars *data)
{
    int	i;
	int	j;
    double  coor_r;
    double  coor_i;
    t_imgdata   new_img;

    create_image(data, &new_img);
	i = -1;
	while (++i < WIDTH)
	{
        j = -1;
		while (++j < HEIGHT)
        {
            coor_r = calculate_coor(i, data, 'r');
            coor_i = calculate_coor(j, data, 'i')
            my_mlx_pixel_put(&(data->dimension), i, j, fract_hub(data, coor_r, coor_i));
        }
	}
    mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->imgblack, 0, 0);
    mlx_destroy_image(data->dimension);
    mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->imgblack, 0, 0);
}

int main(int argc, char **argv)
{
    //arg check hangi fractal geliyo çöz bu kadar.
    t_vars  data;
    data.mlx_ptr = mlx_init();
    data.win_ptr = mlx_new_window(data.mlx_ptr, WIDTH, HEIGHT, "Gorkem Fraktal yapanları destekliyor");

    create_image(&data, &(data.imgblack));
    create_image(&data, &(data.dimension));
    paint_image(&(data.imgblack), WIDTH, HEIGHT, BLACK);
    data.base = create_base(WIDTH/2, HEIGHT/2, 0, 0);
    data.zoom = 0.80;
    data.zo_rate = pow(2, data.zoom);

    design_image(&data);
    mlx_key_hook(data.win_ptr, &key_hook(), &data);
    
}