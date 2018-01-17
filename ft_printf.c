#include "ft_printf.h"

t_print_colour g_colour_tab[] = {
	{"RED", "\x1b[31m"},
	{"GREEN", "\x1b[32m"},
	{"YELLOW", "\x1b[33m"},
	{"BLUE", "\x1b[34m"},
	{"MAGENTA", "\x1b[35m"},
	{"CYAN", "\x1b[36m"},
	{"EOC", "\x1b[0m"},
};

char	*get_flags(char *str, int *skip, int *mod)
{
	int		i;
	int		j;
	char	*flags;

	i = 0;
	*mod = 0;
	while (FLAG_CHARACTERS && str[i])	
		i++;
	*skip = i + 1;
	flags = malloc(sizeof(char) * (i + 1));
	i = 0;
	j = 0;
	while (FLAG_CHARACTERS && str[i])
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

void get_modval(va_list ap, char *flags, int *mod, int *mod2)
{
	while (*flags != '.' && *flags)
	{
		if (*flags == '*')
			*mod = va_arg(ap, int);
		if (*flags >= '0' && *flags <= '9')
		{
			*mod = ft_atoi(flags);
			while (*(flags + 1) <= '9' && *(flags + 1) >= '0')
				flags++;
		}
		flags++;
	}
	while (*flags)
	{
		if (*flags == '*')
			*mod2 = va_arg(ap, int);
		if (*flags <= '9' && *flags >= '0')
		{
			*mod2 = ft_atoi(flags);
			while (*(flags + 1) <= '9' && *(flags + 1) >= '0')
				flags++;
		}
		flags++;;
	}
}

int	print_chars(va_list ap, char *flags, char *c, int mod[2])
{
	if (*c == 's' || *c == 'S' || *c == 'C')
		return (print_string(va_arg(ap, char *), flags, mod));
	else if (*c == 'c')
		return (print_char(va_arg(ap, int), flags, mod));
	else if (*c == '%')
		return (print_char('%', flags, mod));
	else if (*c == 'p')
		return (print_pointer(va_arg(ap, long long *), flags, mod[0]));
	return (0);
}

int	print_variable(va_list ap, int *skip, char *str)
{
	char	*flags;
	int		mod[2];
	int		count;

	count = 0;
	mod[1] = 0;
	flags = get_flags(str + 1, skip, &mod[0]);
	if (strrchr(flags, '.'))
	{
		mod[0] = 0;
		get_modval(ap, flags, &mod[0], &mod[1]);
	}
	else
		read_stars(ap, flags, &mod[0]);
	if (ft_strrchr("dDuUixXoO", *(str + *skip)))
		count += print_number(ap, flags, str + *skip, mod[0]);
	else if (ft_strrchr("cCsSp%", *(str + *skip)))
		count += print_chars(ap, flags, str + *skip, mod);
	else if (str[*skip])
		*skip = *skip - 1;
	free(flags);
	return (count);
}

int	print_colour(char *str, int *skip)
{
	char	*colour;
	int		i;
	int		j;

	j = -1;
	i = 0;
	colour = malloc(sizeof(char) * 11);
	while(str[i + 1] != '}' && i < 10)
	{
		colour[i] = str[i + 1];
		i++;
	}
	colour[i] = '\0';
	while(++j < 7)
		if(!(ft_strcmp(colour, g_colour_tab[j].colour)))
		{
			ft_putstr(g_colour_tab[j].print_c);
			break ;
		}
	if (j == 7)
		ft_putchar(*str);
	*skip = (j == 7) ? 0: i + 1;
	free(colour);
	return (j == 7) ? 1 : 0;
}

int	ft_printf(char *str, ...)
{
	va_list	ap;
	int		skip;
	int		count;

	count = 0;
	va_start(ap, str);
	while (*str)
	{
		if (*str == '{')
		{
			count += print_colour(str, &skip);
			str += skip;
		}
		else if (*str == '%')
		{
			count += print_variable(ap, &skip, str);
			str += skip;
		}
		else
		{
			count++; 
			ft_putchar(*str);
		}
		str++;
	}
	va_end(ap);
	return (count);
}
