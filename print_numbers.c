/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_numbers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slynn-ev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/06 15:38:14 by slynn-ev          #+#    #+#             */
/*   Updated: 2018/01/11 14:10:43 by slynn-ev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_print_num			g_pf_num_tab[] =
{
	{"d", "0", &pf_int_decimal},
	{"D", "0", &pf_int_decimal},
	{"i", "0", &pf_int_decimal},
	{"x", "0", &pf_int_hex_lower},
	{"X", "0", &pf_int_hex_upper},
	{"o", "0", &pf_int_octal},
	{"O", "0", &pf_int_octal},
	{"u", "0", &pf_int_unsigned},
	{"d", "L", &pf_int_decimal},
	{"D", "L", &pf_int_decimal},
	{"i", "L", &pf_int_decimal},
	{"x", "L", &pf_ll_hex_lower},
	{"X", "L", &pf_ll_hex_upper},
	{"o", "L", &pf_ll_octal},
	{"O", "L", &pf_ll_octal},
	{"u", "L", &pf_ll_unsigned},
	{"d", "j", &pf_int_decimal},
	{"D", "j", &pf_int_decimal},
	{"i", "j", &pf_int_decimal},
	{"x", "j", &pf_ll_hex_lower},
	{"X", "j", &pf_ll_hex_upper},
	{"o", "j", &pf_ll_octal},
	{"O", "j", &pf_ll_octal},
	{"u", "j", &pf_ll_unsigned},
	{"d", "l", &pf_int_decimal},
	{"D", "l", &pf_int_decimal},
	{"i", "l", &pf_int_decimal},
	{"x", "l", &pf_ll_hex_lower},
	{"X", "l", &pf_ll_hex_upper},
	{"o", "l", &pf_ll_octal},
	{"O", "l", &pf_ll_octal},
	{"u", "l", &pf_ll_unsigned},
	{"d", "z", &pf_int_decimal},
	{"D", "z", &pf_int_decimal},
	{"i", "z", &pf_int_decimal},
	{"x", "z", &pf_ll_hex_lower},
	{"X", "z", &pf_ll_hex_upper},
	{"o", "z", &pf_ll_octal},
	{"O", "z", &pf_ll_octal},
	{"u", "z", &pf_ll_unsigned},
	{"d", "h", &pf_short_decimal},
	{"x", "h", &pf_short_hex_lower},
	{"D", "h", &pf_short_decimal},
	{"i", "h", &pf_short_decimal},
	{"X", "h", &pf_short_hex_upper},
	{"o", "h", &pf_short_octal},
	{"O", "h", &pf_short_octal},
	{"u", "h", &pf_short_unsigned},
	{"d", "H", &pf_hh_decimal},
	{"x", "H", &pf_hh_hex_lower},
	{"D", "H", &pf_hh_decimal},
	{"i", "H", &pf_hh_decimal},
	{"X", "H", &pf_hh_hex_upper},
	{"o", "H", &pf_hh_octal},
	{"O", "H", &pf_hh_octal},
	{"u", "H", &pf_hh_unsigned},
};

char	read_count(int count[4])
{
	if (count[2] >= 1)
		return ('j');
	if (count[0] >= 2)
		return ('L');
	if (count[3] >= 1)
		return ('z');
	if (count[0] == 1)
		return ('l');
	if (count[1] >= 2)
		return ('H');
	if (count[1] == 1)
		return ('h');
	return ('0');
}

char	get_int_size(char *flags)
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

long long	get_num(va_list ap, int int_size)
{
	if (int_size == '0' || int_size == 'h' || int_size == 'H')
		return (va_arg(ap, int));
	if (int_size == 'l')
		return (va_arg(ap, long));
	if (int_size == 'L')
		return (va_arg(ap, long long));
	if (int_size == 'z')
		return (va_arg(ap, size_t));
	return (va_arg(ap, uintmax_t));
}

int	print_number(va_list ap, char *flags, char *c, int mod)
{
	int		j;
	char	int_size;

	int_size = get_int_size(flags);
	j = 0;
//	if (*c == 'u' && int_size == 'L')
//		pf_ll_unsigned(va_arg(ap, unsigned long long), flags, mod);
//	else
//	{
	while (j < 100)
		{
			if (*c == *g_pf_num_tab[j].c && int_size == *g_pf_num_tab[j].int_size)
			{
				return (g_pf_num_tab[j].print(get_num(ap, int_size), flags, mod));
			}
			j++;
		}
//	}
	return (0);
}
