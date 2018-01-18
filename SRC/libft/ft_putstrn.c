#include "libft.h"

void ft_putstrn(char *str, int n)
{
	int	i;

	i = 0;
	while (str[i] && i < n)
		ft_putchar(str[i++]);
}
