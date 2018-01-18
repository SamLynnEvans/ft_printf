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
	
	ret1 =	ft_printf("%lo, %lo\n", 0, ULONG_MAX);
	ret2 =	printf("%lo, %lo\n", 0, ULONG_MAX);
	ft_printf("my return value = %d\n", ret1);
	ft_printf("pf return value = %d\n", ret2);
	ret1 =	ft_printf("%hhO, %hhO, %d\n", 0, USHRT_MAX, USHRT_MAX);
	ret2 =	printf("%hhO, %hhO\n", 0, USHRT_MAX);
	ft_printf("my return value = %d\n", ret1);
	ft_printf("pf return value = %d\n", ret2);
}
