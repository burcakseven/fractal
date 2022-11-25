#ifndef FRACTAL_H
#define FRACTAL_H

# include "mlx/mlx.h"
# include <math.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

int	create_trgb(int t, int r, int g, int b);
void init_window(char* fractal_name);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
char* read_arg(char* av);
void init_window(char* fractal_name);
int	ft_strcmp(char *s1, char *s2);
int	ft_strlen(char *str);
char	*ft_strdup(char *s1);

#endif