/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nondec_num_flags.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slynn-ev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/18 13:57:00 by slynn-ev          #+#    #+#             */
/*   Updated: 2018/01/21 14:25:46 by slynn-ev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	nondec_print_zeroes(int zeroes, int base, int precision, int caps)
{
	int	nl_mod;

	if (caps)
		;
	nl_mod = zeroes;
	if (precision)
	{
		if (base == DECIMAL)
			zeroes--;
		else
			zeroes -= precision;
		if (base == DECIMAL)
			ft_putchar((precision == 1) ? '+' : '-');
		if (base == OCTAL || base == OCTAL_UPPER)
			ft_putchar('0');
		if (base == HEXA)
			ft_putstr("0x");
		if (base == HEXA_UPPER)
			ft_putstr("0X");
	}
	nl_mod -= zeroes;
	while (zeroes-- > 0)
		ft_putchar('0');
	return (nl_mod);
}

int	get_precision(char *flags, int base, long long num)
{
	if (base == DECIMAL)
	{
		if (num < 0)
			return (2);
		if (ft_strrchr(flags, '+'))
			return (1);
		return (0);
	}
	if (!(ft_strrchr(flags, '#')) || base == BINARY)
		return (0);
	if (base == HEXA || base == HEXA_UPPER)
		return (2);
	return (1);
}

int	print_precision(int base, int precision)
{
	int nl_mod;

	nl_mod = 0;
	if (base == DECIMAL && precision)
	{
		nl_mod++;
		ft_putchar((precision == 1) ? '+' : '-');
	}
	if (base == OCTAL || base == OCTAL_UPPER)
	{
		nl_mod++;
		ft_putchar('0');
	}
	if (base == HEXA || base == HEXA_UPPER)
		nl_mod += 2;
	if (base == HEXA)
		ft_putstr("0x");
	if (base == HEXA_UPPER)
		ft_putstr("0X");
	return (nl_mod);
}


int	nondec_print_spaces(int spaces, int base, int precision, int caps)
{
	int	nl_mod;

	if (caps)
		;
	nl_mod = spaces;
	if (base == DECIMAL && precision)
		spaces--;
	else
		spaces -= precision; 
	nl_mod -= spaces;
	while (spaces-- > 0)
		ft_putchar(' ');
	if (precision)
	{
		if (base == DECIMAL)
			ft_putchar((precision == 1) ? '+' : '-');
		if (base == OCTAL || base == OCTAL_UPPER)
			ft_putchar('0');
		if (base == HEXA)
			ft_putstr("0x");
		if (base == HEXA_UPPER)
			ft_putstr("0X");
	}
	return (nl_mod);
}
