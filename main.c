#include "ft_printf.h"
#include <stdio.h>
#include <stdlib.h>

int		main(int argc, char **av)
{
	char	*p = "pie";
	char	*s = "sam";
	int		 d = 66234123;		
	int		 e = 66324;		
	int		 f = -663452356;		
	int		 g = 661232;		
	int		 h = 1234567893;		
	int		 i = -6645646;		
	long long		 x = atoi(av[1]);

	ft_printf("my result = %#u  %u %u %u %u % 10d %u \n", atoi(av[1]), d, e, f, g, h, i);
	printf("pf result = %#u  %u %u %u %u % 10d %u \n", atoi(av[1]), d, e, f, g, h, i);
	ft_printf("my result = % 10d\n", h);
	printf("my result = % 10d\n", h);
	//	printf("pf result = %# +32d\n", atoi(av[1]));
//	ft_printf("my result = %# +32u\n", atoi(av[1]));
//	printf("pf result = %# +32u\n", atoi(av[1]));
//	ft_printf("my result = %# +32x\n", atoi(av[1]));
//	printf("pf result = %# +32x\n", atoi(av[1]));
}
