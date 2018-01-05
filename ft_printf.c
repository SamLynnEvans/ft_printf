#include "ft_printf.h"

t_print_num			g_pf_num_tab[] =
{
	{"d", &ft_pf_decimal},
};

t_print_chars		g_pf_char_tab[] =
{
	{"s", &ft_pf_string},
	{"%", &ft_pf_percent},
};


char	is_int_type(char *c)
{
	if (*c == 'u' || *c == 'd')
		return (1);
	else
		return (0);
}

char	*get_flags(char *str, int *skip, int *star)
{
	int		i;
	char	*flags;
	
	i = 0;
	*star = 0;
	while (str[i] == '#' || str[i] == '+' || str[i] == '-' 
	|| str[i] == ' ' || str[i] == '0' || str[i] == 'j' || str[i] == 'l'
	|| str[i] == 'z' || str[i] == 'h')
		i++;
	*skip = i + 1;
	flags = malloc(sizeof(char) * (i + 1));
	i = 0;
	while (str[i] == '#' || str[i] == '+' || str[i] == '-' 
	|| str[i] == ' ' || str[i] == '0' || str[i] == 'j' || str[i] == 'l'
	|| str[i] == 'z' || str[i] == 'h')
	{
		flags[i] = str[i];
		if (str[i] == '*')
			*star = 1;
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

void	print_number(int num, char *flags, char *c, int star)
{
	int		j;

	star = 0;
	j = 0;
	while (j < 3)
	{
		if (*c == *g_pf_num_tab[j].c)
		{
			g_pf_num_tab[j].print(num, flags);
			break ;
		}
		j++;
	}
}

void	ft_printf(char *str, ...)
{
	va_list	ap;
	int		skip;
	int		star;
	char	*flags;

	va_start(ap, str);
	while (*str)
	{
		if (*str == '%')
		{
			flags = get_flags(str + 1, &skip, &star);
			if ((is_int_type(str + skip)))
				print_number(va_arg(ap, long long), flags, str + skip, star);
			else
				print_chars(va_arg(ap, char *), flags, str + skip, star);
			str += skip;
		}
		else
			ft_putchar(*str);
		str++;
	}
	va_end(ap);
}
