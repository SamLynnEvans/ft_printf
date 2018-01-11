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
	wchar_t b = 5;
	int ret1;
	int	ret2;

//	printf("%S\n", b);

//	ft_printf("print the string %ls", "hello");
//	printf("print the character %lc", 'c');
//	ft_printf("my result = %#llu  %llu %llu %llu %llu % 10lld %llu \n", atoi(av[1]), d, e, f, g, h, i);
//	printf("pf result = %#llu  %llu %llu %llu %llu % 10lld %llu \n", atoi(av[1]), d, e, f, g, h, i);
	ret1 = ft_printf("%+10.12d\n", atoi(av[1]));
	ret2 = printf("%+10.12d\n", atoi(av[1]));
	printf("my return value = %d\npf return value = %d\n", ret1, ret2);
	ret1 = ft_printf("%+10.6d\n", atoi(av[1]));
	ret2 = printf("%+10.6d\n", atoi(av[1]));
	printf("my return value = %d\npf return value = %d\n", ret1, ret2);
	ret1 = ft_printf("%+10.d\n", atoi(av[1]));
	ret2 = printf("%+10.d\n", atoi(av[1]));
	printf("my return value = %d\npf return value = %d\n", ret1, ret2);
	ret1 = ft_printf("%+10.1d\n", atoi(av[1]));
	ret2 = printf("%+10.1d\n", atoi(av[1]));
	printf("my return value = %d\npf return value = %d\n", ret1, ret2);
	ret1 = ft_printf("%+-10.4d\n", atoi(av[1]));
	ret2 = printf("%+-10.4d\n", atoi(av[1]));
	printf("my return value = %d\npf return value = %d\n", ret1, ret2);
/*	ret1 = ft_printf("%05.2d\n", atoi(av[1]));
	ret2 = printf("%05.2d\n", atoi(av[1]));
	printf("my return value = %d\npf return value = %d\n", ret1, ret2);
	ret1 = ft_printf("%.5x\n", atoi(av[1]));
	ret2 = printf("%.5x\n", atoi(av[1]));
	printf("my return value = %d\npf return value = %d\n", ret1, ret2);
	
	ret1 = ft_printf("%-5.10x\n", atoi(av[1]));
	ret2 = printf("%-5.10x\n", atoi(av[1]));
	printf("my return value = %d\npf return value = %d\n", ret1, ret2);
	
	ret1 = ft_printf("%.d\n", atoi(av[1]));
	ret2 = printf("%.d\n", atoi(av[1]));
	printf("my return value = %d\npf return value = %d\n", ret1, ret2);
*/	
//	printf("pf result = %30hd\n", atoi(av[1]));
//	ft_printf("my result = %30hhd\n", atoi(av[1]));
//	ft_printf("my result = %30hd\n", atoi(av[1]));
	//	printf("pf result = %# +32d\n", atoi(av[1]));
/*	ft_printf("my result = %# +32llu\n", atoi(av[1]));
	printf("pf result = %# +32llu\n", atoi(av[1]));
	ft_printf("my result = %# +32llX\n", atoi(av[1]));
	printf("pf result = %# +32llX\n", atoi(av[1]));
	ft_printf("my result = %- +32llo\n", atoi(av[1]));
	printf("pf result = %- +32llo\n", atoi(av[1]));*/
}
