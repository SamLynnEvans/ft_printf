/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   num_flags.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slynn-ev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/08 17:37:49 by slynn-ev          #+#    #+#             */
/*   Updated: 2018/01/11 14:29:44 by slynn-ev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	get_space_type(char *flags)
{
	int	i;

	i = 0;
	if (*flags)
	{
		if (ft_strrchr(flags, '-'))
			return ('-');
		while (flags[i])
		{
			if (flags[i] >= '1' && flags[i] <= '9')
				while (flags[i] >= '0' && flags[i] <= '9')
					i++;
			if (flags[i] == '0')
				return ('0');
			i++;
		}
		if (ft_strrchr(flags, ' '))
			return (' ');
	}
	return (0);
}

int	dec_print_spaces(int spaces, char is_space, int plus)
{
	int nl_mod;
	
	nl_mod = 1;
	if (plus == -1)
		spaces--;
	else if (spaces <= 0 && plus == 1)
		ft_putchar('+');
	else if (is_space && spaces <= 0 && plus != -1)
		ft_putchar(' ');
	else
	{
		while (spaces > 0)
		{
			if (spaces - 1 == 0 && plus == 1)
				ft_putchar('+');
			else
				ft_putchar(' ');
			spaces--;
		}
		nl_mod = 0;
	}
	if (plus == -1)
		ft_putchar('-');
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

int	dec_print_zeroes(int zeroes, int plus)
{
	int	nl_mod;

	nl_mod = zeroes;
	if (plus == -1)
	{
		ft_putchar('-');
		zeroes--;
	}
	if (plus == 1)
	{
		ft_putchar('+');
		zeroes--;
	}
	nl_mod -= zeroes;
		while (zeroes-- > 0)
			ft_putchar('0');
	return (nl_mod);
}

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

int		print_precision(int base, int caps)
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

void	print_left_adj(int spaces)
{
	while (spaces-- > 0)
		ft_putchar(' ');
}

int	put_sign(int plus)
{
	if (plus == 0)
		return (0);
	if (plus == 1)
		ft_putchar('+');
	if (plus == -1)
		ft_putchar('-');
	return (1);
}
