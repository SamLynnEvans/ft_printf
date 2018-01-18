/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slynn-ev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 22:16:21 by slynn-ev          #+#    #+#             */
/*   Updated: 2018/01/18 19:21:19 by slynn-ev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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

void	get_modval(va_list ap, char *flags, int *mod, int *mod2)
{
	mod[0] = 0;
	mod[1] = 0;
	while (*flags != '.' && *flags)
	{
		*mod = (*flags == '*') ? va_arg(ap, int) : *mod;
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
		*mod = (*flags == '*') ? va_arg(ap, int) : *mod;
		if (*flags <= '9' && *flags >= '0')
		{
			*mod2 = ft_atoi(flags);
			while (*(flags + 1) <= '9' && *(flags + 1) >= '0')
				flags++;
		}
		flags++;
	}
}

int		print_chars(va_list ap, char *flags, char *c, int mod[2])
{
	if (*c == '%')
		return (print_char('%', flags, mod[0]));
	else if ((*c == 's' || *c == 'S') && ft_strrchr(flags, '.') && mod[1] == 0)
	{
		print_spaces(mod[0]);
		return (mod[0]);
	}
	else if ((*c == 'c' || *c == 'C') && ft_strrchr(flags, '.') && mod[1] == 0)
	{
		print_spaces(mod[0]);
		return (1);
	}
	else if (*c == 'S' || (*c == 's' && ft_strrchr(flags, 'l')))
		return (ft_putstr_unicode(va_arg(ap, int *), flags, mod[0]));
	else if (*c == 'C' || (*c == 'c' && ft_strrchr(flags, 'l')))
		return (ft_putchar_unicode(va_arg(ap, int), flags, mod[0]));
	else if (*c == 's' && ft_strrchr(flags, '.') && mod[1] >= 0)
		return (dt_print_str(va_arg(ap, char *), flags, mod));
	else if (*c == 's')
		return (print_string(va_arg(ap, char *), flags, mod[0]));
	else if (*c == 'c')
		return (print_char((char)(va_arg(ap, int)), flags, mod[0]));
	else if (*c == 'p')
		return (print_pointer(va_arg(ap, long long *), flags, mod[0]));
	return (0);
}

int		print_variable(va_list ap, int *skip, char *str)
{
	char	*flags;
	int		mod[2];
	int		count;

	count = 0;
	flags = get_flags(str + 1, skip);
	get_modval(ap, flags, &mod[0], &mod[1]);
	if (mod[0] < 0)
		flags = ft_strjoin_free(flags, "-");
	mod[0] = (mod[0] < 0) ? mod[0] * -1 : mod[0];
	if (*(str + *skip) == '\0')
		*skip = 0;
	if (ft_strrchr("dDuUixXoOb", *(str + *skip)))
		count += print_number(ap, flags, str + *skip, mod);
	else if (ft_strrchr("cCsSp%", *(str + *skip)))
		count += print_chars(ap, flags, str + *skip, mod);
	else if (str[*skip])
	{
		print_spaces(mod[0] - 1);
		*skip = *skip - 1;
		count = mod[0] - 1;
	}
	free(flags);
	return (count);
}

int		ft_printf(char *str, ...)
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
		else
		{
			count++;
			ft_putchar(*str);
		}
		str += skip;
		str++;
	}
	va_end(ap);
	return (count);
}
