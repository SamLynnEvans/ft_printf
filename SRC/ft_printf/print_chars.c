/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_chars.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slynn-ev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/16 19:25:15 by slynn-ev          #+#    #+#             */
/*   Updated: 2018/01/21 22:54:23 by slynn-ev         ###   ########.fr       */
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

int	print_colour(char *str, int *skip)
{
	char	*colour;
	int		i;
	int		j;

	j = -1;
	i = 0;
	colour = malloc(sizeof(char) * 11);
	while (str[i + 1] != '}' && i < 10)
	{
		colour[i] = str[i + 1];
		i++;
	}
	colour[i] = '\0';
	while (++j < 7)
		if (!(ft_strcmp(colour, g_colour_tab[j].colour)))
		{
			ft_putstr(g_colour_tab[j].print_c);
			break ;
		}
	if (j == 7)
		ft_putchar(*str);
	*skip = (j == 7) ? 0 : i + 1;
	free(colour);
	return (j == 7) ? 1 : 0;
}

int	dt_print_str(char *str, char *flags, int mod[2])
{
	char	space_type;
	int		o_mod;
	int		len;
	int		null;

	null = (str == NULL) ? 1 : 0;
	if (null)
		str = ft_strdup("(null)");
	len = ft_strlen(str);
	len = (mod[1] < len) ? mod[1] : len;
	o_mod = mod[0];
	space_type = bit_space_type(flags);
	if (!(space_type & MINUS))
		while (mod[0]-- > len)
			ft_putchar(' ');
	ft_putstrn(str, len);
	if (space_type & MINUS)
		while (mod[0]-- > len)
			ft_putchar(' ');
	if (null)
		free(str);
	return ((o_mod > len) ? o_mod : len);
}

int	print_pointer(long long *p, char *flags, int mod)
{
	int		num_length;
	long	address;
	char	space_type;
	int		o_mod;

	o_mod = mod;
	address = (long)p;
	num_length = ft_numlen(address, 16, sizeof(long));
	space_type = bit_space_type(flags);
	if (!(space_type & MINUS))
		while (mod-- > num_length + 2)
			ft_putchar(' ');
	print_precision(HEXA, 0);
	ft_putbase(address, HEXA, sizeof(long) * 8, 0);
	if (space_type & MINUS)
		while (mod-- > num_length + 2)
			ft_putchar(' ');
	return ((o_mod > num_length + 2) ? o_mod : num_length + 2);
}

int	print_string(char *str, char *flags, int mod)
{
	char	space_type;
	int		len;
	int		null;

	null = (str == NULL) ? 1 : 0;
	if (null)
		str = ft_strdup("(null)");
	len = ft_strlen(str);
	space_type = bit_space_type(flags);
	if (!(space_type & MINUS))
		print_spaces(mod - len);
	ft_putstr(str);
	if (space_type & MINUS)
		print_spaces(mod - len);
	if (null)
		free(str);
	return ((mod > len) ? mod : len);
}

int	print_char(char c, char *flags, int mod)
{
	char	space_type;

	space_type = bit_space_type(flags);
	if (!(space_type & MINUS))
		print_spaces(mod - 1);
	ft_putchar(c);
	if ((space_type & MINUS))
		print_spaces(mod - 1);
	return ((mod > 1) ? mod : 1);
}
