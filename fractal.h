
#ifndef FRACTAL_H
# define FRACTAL_H

# include "mlx/mlx.h"
# include <math.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

#define HEIGHT 360
#define WIDTH  480
#define BLACK  0x0

typedef struct s_base_point
{
	double	posx;
	double	posy;
	double	coorx;
	double	coory;
}				t_base_point;

typedef struct s_imgdata
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_imgdata;

typedef struct s_julia_set
{
    double  c_r;
    double  c_i;
}   t_julia_set;

typedef struct s_vars
{
	void				*mlx_ptr;
	void				*win_ptr;
	struct s_imgdata	dimension;
	struct s_imgdata	imgblack;
	struct s_base_point base;
	double				zoom;
	double				zo_rate;
	char				sep;
    int                 max_iter;
	int					pallette;
}				t_vars;


void	create_image(t_vars *s_vars, t_imgdata *s_img);
void	my_mlx_pixel_put(t_imgdata *data, int x, int y, int color);

#endif