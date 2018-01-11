#include "ft_printf.h"

char	is_char_type(char *c)
{
	if (*c == 's' || *c == 'c')
		return (1);
	else
		return (0);
}

char	*get_flags(char *str, int *skip, int *mod)
{
	int		i;
	int		j;
	char	*flags;
	
	i = 0;
	*mod = 0;
	while (FLAG_CHARACTERS)	
		i++;
	*skip = i + 1;
	flags = malloc(sizeof(char) * (i + 1));
	i = 0;
	j = 0;
	while (FLAG_CHARACTERS)
	{
		if (str[i] >= '1' && str[i] <= '9')
		{
			*mod = ft_atoi(str + i);
			while (str[i] <= '9' && str[i] >= '0')
				flags[j++] = str[i++];
		}
		if (str[i] == '*')
			*mod = STAR;
		flags[j++] = str[i++];
	}
	flags[j] = '\0';
	return (flags);
}


void read_stars(va_list ap, char *flags, int *mod)
{
	int	star_count;
	int	i;

	i = 0;
	star_count = 0;
	while (*flags)
	{
		if (*flags == '*')
			star_count++;
		flags++;
	}
	while (i < star_count)
	{
		if (i + 1 == star_count && *mod == STAR)
			*mod = va_arg(ap, int);
		else
			va_arg(ap, int);
		i++;
	}
}	

int	ft_printf(char *str, ...)
{
	va_list	ap;
	int		skip;
	char	*flags;
	int		mod;
	int		count;

	count = 0;
	va_start(ap, str);
	while (*str)
	{
		if (*str == '%')
		{
			flags = get_flags(str + 1, &skip, &mod);
			read_stars(ap, flags, &mod);
			if (!(is_char_type(str + skip)))
				count += print_number(ap, flags, str + skip, mod);
			else 
				print_chars(va_arg(ap, char *), flags, str + skip, mod);
			str += skip;
			free(flags);
		}
		else
		{
			count++; 
			ft_putchar(*str);
		}
		str++;
	}
	va_end(ap);
//	ft_intdebug(count, "char count");
	return (count);
}
