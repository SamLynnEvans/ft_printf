#include "ft_printf.h"
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

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

//	ret1 = ft_printf("%");
//	printf("|\n"); 
//	ret2 = printf("%");
//	printf("|\n");
	ft_printf("{RED}this text is{MAGENTA} red{EOC}, now it is not,{GREEN} and now it's green!{EOC}"); 
	ret1 = ft_printf("%ls\n", "💩çççççç👹");
	ret2 = printf("%s\n", str);
	ft_printf("\nmy return value = %d\npf return value = %d\n", ret1, ret2);
	ret1 = ft_printf("%C\n", "💩");
	ret2 = printf("%lc\n", a);
	ft_printf("\nmy return value = %d\npf return value = %d\n", ret1, ret2);
	ret1 = ft_printf("my value = %20s\n", NULL); 
	ret2 = printf("pf value = %20s\n", NULL);
	ft_printf("my return value = %d\npf return value = %d\n", ret1, ret2);
	ret1 = ft_printf("my value = %-20p %11p %-18p\n", p, p2, NULL); 
	ret2 = printf("pf value = %-20p %11p %-18p\n", p, p2, NULL);
	ft_printf("my return value = %d\npf return value = %d\n", ret1, ret2);
	ret1 = ft_printf("my value = %l yo %s\n", p2, p1); 
	ret2 = printf("pf value = %l yo %s\n", p2, p1);
	ft_printf("my return value = %d\npf return value = %d\n", ret1, ret2);
}
