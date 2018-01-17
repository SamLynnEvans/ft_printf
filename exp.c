#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>
#include "ft_printf.h"

void print(char *str, ...)
{
	va_list ap;
	int		i;
	char	*d;
	int		add;

	i = 0;
	va_start(ap, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			d= va_arg(ap, char *);
			add = (int)d;
			ft_strdebug(d, "str");
		}
		i++;
	}
	va_end(ap);
}

int main()
{
	print("% %");
}
