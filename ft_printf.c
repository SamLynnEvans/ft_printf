/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slynn-ev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 22:16:21 by slynn-ev          #+#    #+#             */
/*   Updated: 2018/01/17 22:22:47 by slynn-ev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

char	*get_flags(char *str, int *skip)
{
	int		i;
	char	*flags;

	i = 0;
	while (FLAG_CHARACTERS && str[i])	
		i++;
	*skip = i + 1;
	flags = malloc(sizeof(char) * (i + 1));
	i = 0;
	while (FLAG_CHARACTERS && str[i])
	{
		flags[i] = str[i];
		i++;
	}
	flags[i] = '\0';
	return (flags);
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
	if (*c == 'S')
		return (ft_putstr_unicode(va_arg(ap, int *), flags, mod[0]));
	else if (*c == 'C')
		return (ft_putchar_unicode(va_arg(ap, int), flags, mod[0]));
	else if (*c == 's')
		return (print_string(va_arg(ap, char *), flags, mod[0]));
	else if (*c == 's' && ft_strrchr(flags, '.'))
		return (dt_print_str(va_arg(ap, char *), flags, mod));
	else if (*c == 'c')
		return (print_char((char)(va_arg(ap, int)), flags, mod[0]));
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
	mod[0] = 0;
	mod[1] = 0;
	flags = get_flags(str + 1, skip);
		get_modval(ap, flags, &mod[0], &mod[1]);
	if (mod[0] < 0)
	{
		flags = ft_strjoin_free(flags, "-");
		mod[0] *= -1;
	}	
	if (ft_strrchr("dDuUixXoO", *(str + *skip)))
		count += print_number(ap, flags, str + *skip, mod);
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
		skip = 0;
		if (*str == '{')
			count += print_colour(str, &skip);
		else if (*str == '%')
			count += print_variable(ap, &skip, str);
		str += skip;
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
