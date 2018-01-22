#include "Includes/ft_printf.h"
#include "Includes/libft.h"
#include <stdio.h>
#include <limits.h>

int main(int ac, char **av)
{
	int ret1;
	int ret2;
	long	d = LONG_MAX;
	int		e = -4;
	int	f = -2123242;
	int	i;
	
	ret1 =	ft_printf("%#.o\n", 0);
	ret2 =	printf("%#.o\n", 0);
	ft_printf("my return value = %d\n", ret1);
	ft_printf("pf return value = %d\n", ret2);
}
