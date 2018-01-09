/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_numbers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slynn-ev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/06 15:38:14 by slynn-ev          #+#    #+#             */
/*   Updated: 2018/01/09 13:11:51 by slynn-ev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_print_num			g_pf_num_tab[] =
{
	{"d", "0", &ft_pf_decimal},
//	{"D", "0", &ft_pf_decimal},
//	{"i", "0", &ft_pf_decimal},
	{"x", "0", &ft_pf_hex_lower},
//	{"X", "0", &ft_pf_hex_upper},
//	{"o", "0", &ft_pf_octal},
//	{"O", "0", &ft_pf_octal},
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

void	print_number(int num, char *flags, char *c, int mod)
{
	int		j;
	char	int_size;
	
	int_size = get_int_size(flags);
	j = 0;
	while (j < 10)
	{
		if (*c == *g_pf_num_tab[j].c && int_size == *g_pf_num_tab[j].int_size)
		{
			g_pf_num_tab[j].print(num, flags, mod);
			break ;
		}
		j++;
	}
}
