#include "ft_printf.h"
#include <stdio.h>
#include <stdlib.h>

int		main(int argc, char **av)
{
	char	*p = "pie";
	char	*s = "sam";
	int		 d = 66;		
	long long		 x = atoi(av[1]);

	ft_printf("my result = %# +32d\n", atoi(av[1]));
	printf("pf result = %# +32d\n", atoi(av[1]));
	ft_printf("my result = %# +32o\n", atoi(av[1]));
	printf("pf result = %# +32o\n", atoi(av[1]));
	ft_printf("my result = %# +32x\n", atoi(av[1]));
	printf("pf result = %# +32x\n", atoi(av[1]));
}
