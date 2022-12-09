#ifndef FRACTAL_H
#define FRACTAL_H

# include "mlx/mlx.h"
# include <math.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

# define WIDTH		1080
# define HEIGHT		720
# define x_orjin_coordinate WIDTH/2
# define y_orjin_coordinate HEIGHT/2
# define width_division WIDTH/8
# define height_division HEIGHT/6
# define KEY_ESC 53
# define KEY_W 13
# define KEY_S 1
# define KEY_A 0
# define KEY_D 2
# define KEY_ESC 53
# define SCROLL_UP	4
# define SCROLL_DOWN	5

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct s_fractal
{
	char	*name;
	void				*mlx;
	void				*win;
	struct s_data	dimension;
	float	zoom_rate;
	float		move_x;
	float		move_y;

}				t_fractal;

int mouse_hook(int keycode,int x, int y, t_fractal fractal);
int	key_hook(int keycode, t_fractal *s_vars);
int julia_formula(float initial_x,float initial_y);
int mandelbrot_formula(float initial_x,float initial_y);
void convert_to_xy(t_data	*img,t_fractal *fractal,int i , int j);
void navigate_on_screen(t_data	*img,t_fractal *fractal);
void dye_screen(t_data	*img,void	*mlx,void	*mlx_win,char	name);
int charcompare(char arg, char referance);
char *choose_function(char *arg);
int	create_trgb(int t, int r, int g, int b);
void init_window(t_fractal *name);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
char* read_arg(char* av);
void init_window(t_fractal *name);
int	ft_strcmp(char *arg, char *referance);
int	ft_strlen(char *str);
char	*ft_strdup(char *s1);

#endif