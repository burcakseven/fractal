#include "fractal.h"

void init_window(char* fractal_name)
{
    void	*mlx;
	void	*mlx_win;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, fractal_name);
	mlx_loop(mlx);
 

}

int main(int ac, char** av)
{
    ac = 1;
    init_window(av[1]);
    return(0);
}