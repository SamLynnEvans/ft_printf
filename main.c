#include "ft_printf.h"
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int		main(int argc, char **av)
{
	char	*p = "pie";
	char	*s = "sam";
	long long		 d = 66234123;		
	long long		 e = 66324;		
	long long		 f = -663452356;		
	long long		 g = 661232;		
	long long		 h = -922337203685477580;		
	long long		 i = -6645646;		

//	ft_printf("my result = %#llu  %llu %llu %llu %llu % 10lld %llu \n", atoi(av[1]), d, e, f, g, h, i);
//	printf("pf result = %#llu  %llu %llu %llu %llu % 10lld %llu \n", atoi(av[1]), d, e, f, g, h, i);
//	ft_printf("my result = %30hx\n", atoi(av[1]));
	printf("pf result = %30hhd\n", atoi(av[1]));
	printf("pf result = %30hd\n", atoi(av[1]));
	ft_printf("my result = %30hhd\n", atoi(av[1]));
	ft_printf("my result = %30hd\n", atoi(av[1]));
	//	printf("pf result = %# +32d\n", atoi(av[1]));
/*	ft_printf("my result = %# +32llu\n", atoi(av[1]));
	printf("pf result = %# +32llu\n", atoi(av[1]));
	ft_printf("my result = %# +32llX\n", atoi(av[1]));
	printf("pf result = %# +32llX\n", atoi(av[1]));
	ft_printf("my result = %- +32llo\n", atoi(av[1]));
	printf("pf result = %- +32llo\n", atoi(av[1]));*/
}
