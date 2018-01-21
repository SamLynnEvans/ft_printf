/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_numbers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slynn-ev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/06 15:38:14 by slynn-ev          #+#    #+#             */
/*   Updated: 2018/01/21 21:29:14 by slynn-ev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_print_num			g_n_tab[] =
{
	{"d", "0", &pf_int_decimal},
	{"D", "0", &pf_int_decimal},
	{"i", "0", &pf_int_decimal},
	{"b", "0", &pf_int_binary},
	{"x", "0", &pf_int_hex_lower},
	{"X", "0", &pf_int_hex_upper},
	{"o", "0", &pf_int_octal},
	{"O", "0", &pf_ll_octal},
	{"u", "0", &pf_int_unsigned},
	{"U", "0", &pf_ll_unsigned},
	{"d", "L", &pf_int_decimal},
	{"D", "L", &pf_int_decimal},
	{"i", "L", &pf_int_decimal},
	{"x", "L", &pf_ll_hex_lower},
	{"X", "L", &pf_ll_hex_upper},
	{"o", "L", &pf_ll_octal},
	{"O", "L", &pf_ll_octal},
	{"u", "L", &pf_ll_unsigned},
	{"U", "L", &pf_ll_unsigned},
	{"d", "j", &pf_int_decimal},
	{"D", "j", &pf_int_decimal},
	{"i", "j", &pf_int_decimal},
	{"x", "j", &pf_ll_hex_lower},
	{"X", "j", &pf_ll_hex_upper},
	{"o", "j", &pf_ll_octal},
	{"O", "j", &pf_ll_octal},
	{"u", "j", &pf_ll_unsigned},
	{"U", "j", &pf_ll_unsigned},
	{"d", "l", &pf_int_decimal},
	{"D", "l", &pf_int_decimal},
	{"i", "l", &pf_int_decimal},
	{"x", "l", &pf_ll_hex_lower},
	{"X", "l", &pf_ll_hex_upper},
	{"o", "l", &pf_ll_octal},
	{"O", "l", &pf_ll_octal},
	{"u", "l", &pf_long_unsigned},
	{"U", "l", &pf_ll_unsigned},
	{"d", "z", &pf_int_decimal},
	{"D", "z", &pf_int_decimal},
	{"i", "z", &pf_int_decimal},
	{"x", "z", &pf_ll_hex_lower},
	{"X", "z", &pf_ll_hex_upper},
	{"o", "z", &pf_ll_octal},
	{"O", "z", &pf_ll_octal},
	{"u", "z", &pf_ll_unsigned},
	{"U", "z", &pf_ll_unsigned},
	{"d", "h", &pf_short_decimal},
	{"x", "h", &pf_short_hex_lower},
	{"D", "h", &pf_int_decimal},
	{"i", "h", &pf_short_decimal},
	{"X", "h", &pf_short_hex_upper},
	{"o", "h", &pf_short_octal},
	{"O", "h", &pf_ll_octal},
	{"u", "h", &pf_short_unsigned},
	{"U", "h", &pf_ll_unsigned},
	{"d", "H", &pf_hh_decimal},
	{"x", "H", &pf_hh_hex_lower},
	{"D", "H", &pf_int_decimal},
	{"i", "H", &pf_hh_decimal},
	{"X", "H", &pf_hh_hex_upper},
	{"o", "H", &pf_hh_octal},
	{"O", "H", &pf_ll_octal},
	{"u", "H", &pf_hh_unsigned},
	{"U", "H", &pf_ll_unsigned},
};

t_print_nondec		g_ndectab[] =
{
	{'0', &pf_int_nondecprint},
	{'h', &pf_short_nondecprint},
	{'H', &pf_hh_nondecprint},
	{'L', &pf_long_nondecprint},
};


t_print_dt_num		g_dtab[] =
{
	{"d", "0", &pf_dot_int_decimal},
	{"D", "0", &pf_dot_int_decimal},
	{"i", "0", &pf_dot_int_decimal},
	{"x", "0", &pf_dot_int_hex_lower},
	{"X", "0", &pf_dot_int_hex_upper},
	{"o", "0", &pf_dot_int_octal},
	{"O", "0", &pf_dot_ll_octal},
	{"d", "L", &pf_dot_int_decimal},
	{"D", "L", &pf_dot_int_decimal},
	{"i", "L", &pf_dot_int_decimal},
	{"x", "L", &pf_dot_ll_hex_lower},
	{"X", "L", &pf_dot_ll_hex_upper},
	{"o", "L", &pf_dot_ll_octal},
	{"O", "L", &pf_dot_ll_octal},
	{"d", "z", &pf_dot_int_decimal},
	{"D", "z", &pf_dot_int_decimal},
	{"i", "z", &pf_dot_int_decimal},
	{"x", "z", &pf_dot_ll_hex_lower},
	{"X", "z", &pf_dot_ll_hex_upper},
	{"o", "z", &pf_dot_ll_octal},
	{"O", "z", &pf_dot_ll_octal},
	{"d", "l", &pf_dot_int_decimal},
	{"D", "l", &pf_dot_int_decimal},
	{"i", "l", &pf_dot_int_decimal},
	{"x", "l", &pf_dot_ll_hex_lower},
	{"X", "l", &pf_dot_ll_hex_upper},
	{"o", "l", &pf_dot_ll_octal},
	{"O", "l", &pf_dot_ll_octal},
	{"d", "j", &pf_dot_int_decimal},
	{"D", "j", &pf_dot_int_decimal},
	{"i", "j", &pf_dot_int_decimal},
	{"x", "j", &pf_dot_ll_hex_lower},
	{"X", "j", &pf_dot_ll_hex_upper},
	{"o", "j", &pf_dot_ll_octal},
	{"O", "j", &pf_dot_ll_octal},
	{"d", "h", &pf_dot_short_decimal},
	{"D", "h", &pf_dot_int_decimal},
	{"i", "h", &pf_dot_short_decimal},
	{"x", "h", &pf_dot_short_hex_lower},
	{"X", "h", &pf_dot_short_hex_upper},
	{"o", "h", &pf_dot_short_octal},
	{"O", "h", &pf_dot_ll_octal},
	{"d", "H", &pf_dot_hh_decimal},
	{"D", "H", &pf_dot_int_decimal},
	{"i", "H", &pf_dot_hh_decimal},
	{"x", "H", &pf_dot_hh_hex_lower},
	{"X", "H", &pf_dot_hh_hex_upper},
	{"o", "H", &pf_dot_hh_octal},
	{"O", "H", &pf_dot_ll_octal},
	{"u", "h", &pf_dot_unsigned_short},
	{"U", "h", &pf_dot_unsigned_short},
	{"u", "H", &pf_dot_unsigned_hh},
	{"U", "H", &pf_dot_unsigned_hh},
	{"u", "l", &pf_dot_unsigned_long},
	{"U", "l", &pf_dot_unsigned_long},
	{"u", "j", &pf_dot_unsigned_long},
	{"U", "j", &pf_dot_unsigned_long},
	{"u", "L", &pf_dot_unsigned_long},
	{"U", "L", &pf_dot_unsigned_long},
	{"u", "z", &pf_dot_unsigned_long},
	{"U", "z", &pf_dot_unsigned_long},
	{"u", "0", &pf_dot_unsigned_decimal},
	{"U", "0", &pf_dot_unsigned_decimal},
};

char					read_count(int count[4])
{
	if (count[2] || count[0] || count[3])
		return (sizeof(long long));
	if (count[1] >= 2)
		return (sizeof(char));
	if (count[1] == 1)
		return (sizeof(short));
	return (sizeof(int));
}

char					get_int_size(char *flags)
{
	int	count[4];
	int	i;

	i = 0;
	while (i < 4)
		count[i++] = 0;
	i = 0;
	while (flags[i])
	{
		if (flags[i] == 'l')
			count[0]++;
		if (flags[i] == 'h')
			count[1]++;
		if (flags[i] == 'j')
			count[2]++;
		if (flags[i] == 'z')
			count[3]++;
		i++;
	}
	return (read_count(count));
}

long long				get_num(va_list ap, int size)
{
	if (size == sizeof(int) || size == sizeof(short) || size == sizeof(char))
		return (va_arg(ap, int));
	return (va_arg(ap, long long));
}

int	get_base(char *c)
{
	if (*c == 'x')
		return (HEXA);
	if (*c == 'X')
		return (HEXA_UPPER);
	if (*c == 'O')
		return (OCTAL_UPPER);
	if (*c == 'o')
		return (OCTAL);
	if (*c == 'b' || *c == 'B')
		return (BINARY);
	return (DECIMAL);
}

int						print_number(va_list ap,
char *flags, char *c, int mod[2])
{
	char	int_size;
	int 	base;
	
	if (*c == 'D' || *c == 'O' || *c == 'U')
		flags = ft_strjoin(flags, "ll");
	base = get_base(c);
	int_size = get_int_size(flags);
	if (!(ft_strrchr(flags, '.')))
	{
		if (*c != 'u' && *c != 'U')
			return (pf_int_nondecprint(get_num(ap, int_size), flags, mod[0], base));
		else
			return (pf_ndt_unsigned(va_arg(ap, unsigned long long), flags, mod[0]));
	}
	else
	{
		if (*c != 'u' && *c != 'U')
			return (pf_dot_all(get_num(ap, int_size), flags, mod, base));
		else
			return (pf_unsigned(va_arg(ap, unsigned long long), flags, mod));
		/*	while (j < 4)
	{
		if (int_size == g_ndectab[j].int_size)
			return (g_ndectab[j].print(get_num(ap, int_size), flags, mod[0], base));
		j++;
	}*/
	}/*
	j = 0;
	if (ft_strrchr(flags, '.') && mod[1] >= 0)
		while (j < 63)
		{
			if (*c == *g_dtab[j].c && int_size == *g_dtab[j].int_size)
				return (g_dtab[j].print(get_num(ap, int_size), flags, mod));
			j++;
		}
	while (j < 64)
	{
		if (*c == *g_n_tab[j].c && int_size == *g_n_tab[j].int_size)
			return (g_n_tab[j].print(get_num(ap, int_size), flags, mod[0]));
		j++;
	}
	return (0);*/
	return (0);
}
