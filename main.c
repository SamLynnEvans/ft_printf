#include "ft_printf.h"

int		main()
{
	char	*p = "pie";
	char	*s = "sam";
	int		 d = 66;		
	
	ft_printf("sam is %#####s and pie is %s and he likes %d", p, s, d);
}
