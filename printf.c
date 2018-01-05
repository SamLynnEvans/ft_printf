#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>

int	ft_printf(char *str, ...)
{
	int		n_args;
	va_list ap;
	int		i;
	int 	*data;

	i = 0;
	n_args = 0;
	while (str[i])
	{
		if (str[i] == '%')
			n_args++;
	}
	data = malloc(sizeof(int) * (n_args + 1));
	i = 0;
	va_start(ap, n_args);
	while (i < n_args)
	{
		data[i] = va_arg
	}
}
