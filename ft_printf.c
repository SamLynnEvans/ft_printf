#include "ft_printf.h"

t_print_chars		g_pf_char_tab[] =
{
	{"s", &ft_pf_string},
	{"%", &ft_pf_percent},
};


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
	char	*flags;
	
	i = 0;
	*mod = 0;
	while (FLAG_CHARACTERS)	
		i++;
	*skip = i + 1;
	flags = malloc(sizeof(char) * (i + 1));
	i = 0;
	while (FLAG_CHARACTERS)
	{
		flags[i] = str[i];
		if (str[i] >= '1' && str[i] <= '9')
		{
			*mod = ft_atoi(str + i);
			i += get_num_length(*mod, DECIMAL) - 1;
		}
		if (str[i] == '*')
			*mod = STAR;
		i++;
	}
	flags[i] = '\0';
	return (flags);
}

void	print_chars(char *prnt_str, char *flags, char *c, int star)
{
	int		j;

	star = 0;
	j = 0;
	while (j < 3)
	{
		if (*c == *g_pf_char_tab[j].c)
		{
			g_pf_char_tab[j].print(prnt_str, flags);
			break ;
		}
		j++;
	}
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

void	ft_printf(char *str, ...)
{
	va_list	ap;
	int		skip;
	char	*flags;
	int		mod;

	va_start(ap, str);
	while (*str)
	{
		if (*str == '%')
		{
			flags = get_flags(str + 1, &skip, &mod);
			read_stars(ap, flags, &mod);
			if (!(is_char_type(str + skip)))
				print_number(va_arg(ap, long long), flags, str + skip, mod);
			else
				print_chars(va_arg(ap, char *), flags, str + skip, mod);
			str += skip;
			free(flags);
		}
		else
			ft_putchar(*str);
		str++;
	}
	va_end(ap);
}
