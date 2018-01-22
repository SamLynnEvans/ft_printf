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
	
	ret1 =	ft_printf("%#12.23o\n", INT_MAX);
	ret2 =	printf("%#12.23o\n", INT_MAX);
	ft_printf("my return value = %#x\n", ret1);
	ft_printf("pf return value = %#x\n", ret2);
	ret1 =	ft_printf("%#-10.5o\n", 2500);
	ret2 =	printf("%#-10.5o\n", 2500);
	ft_printf("my return value = %#x\n", ret1);
	ft_printf("pf return value = %#x\n", ret2);
	ret1 =	ft_printf("%#10.5o\n", 2500);
	ret2 =	printf("%#10.5o\n", 2500);
	ft_printf("my return value = %#x\n", ret1);
	ft_printf("pf return value = %#x\n", ret2);
	ret1 =	ft_printf("%#b\n", 1234234);
	ret2 =	ft_printf("%#b\n", -2134234);
	ft_printf("my return value = %#X\n", ret1);
	ft_printf("pf return value = %#X\n", ret2);
	ret1 =	ft_printf("%18.19X\n", -1234213);
	ret2 =	printf("%18.19X\n", -1234213);
	ft_printf("my return value = %#d\n", ret1);
	ft_printf("pf return value = %#d\n", ret2);

}
