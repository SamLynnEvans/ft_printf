/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nondec_num_flags.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slynn-ev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/18 13:57:00 by slynn-ev          #+#    #+#             */
/*   Updated: 2018/01/18 20:04:00 by slynn-ev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	nondec_print_zeroes(int zeroes, int base, int precision, int caps)
{
	int	nl_mod;

	nl_mod = zeroes;
	if (precision)
	{
		if (base == 8)
		{
			zeroes--;
			ft_putchar('0');
		}
		if (base == 16)
			zeroes -= 2;
		if (base == 16 && !caps)
			ft_putstr("0x");
		if (base == 16 && caps)
			ft_putstr("0X");
	}
	nl_mod -= zeroes;
	while (zeroes-- > 0)
		ft_putchar('0');
	return (nl_mod);
}

int	print_precision(int base, int caps)
{
	int nl_mod;

	nl_mod = 0;
	if (base == 8)
	{
		nl_mod++;
		ft_putchar('0');
	}
	if (base == 16)
		nl_mod += 2;
	if (base == 16 && !caps)
		ft_putstr("0x");
	if (base == 16 && caps)
		ft_putstr("0X");
	return (nl_mod);
}

int	nondec_print_spaces(int spaces, int base, int precision, int caps)
{
	int	nl_mod;

	nl_mod = spaces;
	if (precision)
	{
		if (base == 8)
			spaces--;
		if (base == 16)
			spaces -= 2;
	}
	nl_mod -= spaces;
	while (spaces-- > 0)
		ft_putchar(' ');
	if (precision)
	{
		if (base == 8)
			ft_putchar('0');
		if (base == 16 && !caps)
			ft_putstr("0x");
		if (base == 16 && caps)
			ft_putstr("0X");
	}
	return (nl_mod);
}
