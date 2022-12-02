#include "fractal.h"

// int	ft_strlen(char *str)
// {
// 	int	i;

// 	i = -1;
// 	while (str[++i])
// 		;
// 	return (i);
// }

// char	*ft_strdup(char *s1)
// {
// 	char	*str;
// 	size_t	i;

// 	if (!s1)
// 		return (NULL);
// 	str = (char *)malloc(sizeof(char) * (ft_strlen(s1) + 1));
// 	if (!str)
// 		return (NULL);
// 	i = 0;
// 	while (s1[i])
// 	{
// 		str[i] = s1[i];
// 		i++;
// 	}
// 	str[i] = 0;
// 	return (str);
// }

char	*choose_function(char *arg)
{
	char	*name_list[3] = { "mandelbrot","julia"}; // değişecek

	int i = 0;
	while (i<2)
	{
		if (ft_strcmp(arg,name_list[i])==0)
		{
			return (name_list[i]);
		}
		i++;
	}
	printf("arg couldn't find.");
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
