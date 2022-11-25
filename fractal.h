#ifndef FRACTAL_H
#define FRACTAL_H

# include "mlx/mlx.h"
# include <math.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

struct t_image
{
    int image;

}  s_image;


char* read_arg(char* av);
void init_window(char* fractal_name);
int	ft_strcmp(char *s1, char *s2);
int	ft_strlen(char *str);
char	*ft_strdup(char *s1);

#endif