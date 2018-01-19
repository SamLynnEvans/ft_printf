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

	ret1 =	ft_printf("%lo\n", ULONG_MAX);
	ret2 =	printf("%lo\n", ULONG_MAX);
	ft_printf("my return value = %d\n", ret1);
	ft_printf("pf return value = %d\n", ret2);
	ret1 =	ft_printf("%llo\n", ULLONG_MAX);
	ret2 =	printf("%llo\n", ULLONG_MAX);
	ft_printf("my return value = %d\n", ret1);
	ft_printf("pf return value = %d\n", ret2);
	ret1 =	ft_printf("%hho\n", -1);
	ret2 =	printf("%hho\n", -1);
	ft_printf("my return value = %d\n", ret1);
	ft_printf("pf return value = %d\n", ret2);

}
