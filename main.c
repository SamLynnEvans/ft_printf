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
	
	ret1 = ft_printf("my value = %#x|\n", atoi(av[1])); 
	ret2 = printf("pf value = %#x|\n", atoi(av[1])); 
	ft_printf("my length = %d\npf length = %d\n", ret1, ret2);
	ret1 = ft_printf("my value = %#.0o|\n", atoi(av[1])); 
	ret2 = printf("pf value = %#.0o|\n", atoi(av[1])); 
	ft_printf("my length = %d\npf length = %d\n", ret1, ret2);
	ret1 = ft_printf("my value = %+ud\n", atoi(av[1])); 
	ret2 = printf("pf value = %+ud\n", atoi(av[1])); 
	ft_printf("my length = %d\npf length = %d\n", ret1, ret2);
	ret1 = ft_printf("my value = %0.11llo\n", atoi(av[1])); 
	ret2 = printf("pf value = %0.11llo\n", atoi(av[1])); 
	ft_printf("my length = %d\npf length = %d\n", ret1, ret2);
	ret1 = ft_printf("my value = %11.2llo\n", atoi(av[1])); 
	ret2 = printf("pf value = %11.2llo\n", atoi(av[1])); 
	ft_printf("my length = %d\npf length = %d\n", ret1, ret2);
	ret1 = ft_printf("my value = %#12.4llo\n", atoi(av[1])); 
	ret2 = printf("pf value = %#12.4llo\n", atoi(av[1])); 
	ft_printf("my length = %d\npf length = %d\n", ret1, ret2);
	ret1 = ft_printf("my value = %#7.4llo\n", atoi(av[1])); 
	ret2 = printf("pf value = %#7.4llo\n", atoi(av[1])); 
	ft_printf("my length = %d\npf length = %d\n", ret1, ret2);
}
