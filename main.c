#include "ft_printf.h"
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <locale.h>

int		main(int argc, char **av)
{
	char	*s = "sam";
	char	t = 't';
	int *p;
	int a = 128169;
	p = &a;
	char *p1 = "hey";
	char *p2 = "ahsfkasej";
	long long *p3;
	char *str = "💩çççççç👹";
	long long		 d = 66234123;		
	long long		 e = 66324;		
	long long		 f = -663452356;		
	long long		 g = 661232;		
	long long		 h = -922337203685477580;		
	long long		 i = -6645646;		
	int ret1;
	int	ret2;
	p3 = &d;
	setlocale(LC_CTYPE, "");

	ft_printf("\nmy return value = %d\npf return value = %d\n", ret1, ret2);
	ret1 = ft_printf("%4.S\n", L"人名用漢字");
	ret2 = printf("%4.S\n", L"人名用漢字");
	ft_printf("\nmy return value = %d\npf return value = %d\n", ret1, ret2);
}
