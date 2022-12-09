#include "fractal.h"

char	*choose_function(char *arg)
{
	char	*name_list[3] = { "mandelbrot","julia"};

	int i = 0;
	while (i<2)
	{
		if (ft_strcmp(arg,name_list[i])==0)
		{
			return (name_list[i]);
		}
		i++;
	}
	write(1,"arg couldn't find.",19);
	exit(1);
	
	
}

int charcompare(char arg, char referance)
{
	if (arg == referance)
	{
		return(1);
	}
	else if('A'<= arg && arg <= 'Z' && arg+('a'-'A') == referance)
	{
		return(1);
	}
	return(0);

}

int	ft_strcmp(char *arg, char *referance)
{
	int	i;

	i = 0;
	while (charcompare(arg[i],referance[i]) && arg[i] != '\0' && referance[i] != '\0')
		i++;
	return (arg[i] - referance[i]);
}
