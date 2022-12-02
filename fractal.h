#ifndef FRACTAL_H
#define FRACTAL_H

# include "mlx/mlx.h"
# include <math.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

# define WIDTH		1080
# define HEIGHT		720

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
}				t_fractal;

void navigate_on_screen(t_data	*img,void	*mlx,void	*mlx_win, char name);
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