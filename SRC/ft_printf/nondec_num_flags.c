/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nondec_num_flags.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slynn-ev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/18 13:57:00 by slynn-ev          #+#    #+#             */
/*   Updated: 2018/01/21 17:58:11 by slynn-ev         ###   ########.fr       */
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
		zeroes -= print_precision(base, precision);
	nl_mod -= zeroes;
	while (zeroes-- > 0)
		ft_putchar('0');
	return (nl_mod);
}

int	print_zeroes(int zeroes)
{
	int	count;

	count = 0;
	while (zeroes-- > 0)
	{
		count++;
		ft_putchar('0');
	}
	return (count);
}

char	bit_space_type(char *flags)
{
	char space_type;
	int	i;

	i = 0;
	space_type = 0;
	while (flags[i])
	{
		if (flags[i] == '-')
			space_type |= MINUS;
		else if (flags[i] == ' ')
			space_type |= SPACE;
		else if (flags[i] == '0' && !(ft_isdigit(flags[i - 1])))
			space_type |= ZERO;
		i++;
	}
	return (space_type);
}


int	get_precision(char *flags, int base, long long num)
{
	if (base == DECIMAL)
	{
		if (num < 0)
			return (NEG);
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
		print_precision(base, precision);
	return (nl_mod);
}
