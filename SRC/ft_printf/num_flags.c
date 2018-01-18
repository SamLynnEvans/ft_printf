/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   num_flags.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slynn-ev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/08 17:37:49 by slynn-ev          #+#    #+#             */
/*   Updated: 2018/01/18 19:30:56 by slynn-ev         ###   ########.fr       */
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
			if (flags[i] == '0' && flags[i + 1] != '.' && flags[i - 1] != '.')
				return ('0');
			i++;
		}
		if (ft_strrchr(flags, ' '))
			return (' ');
	}
	return (0);
}

int		dec_print_spaces(int spaces, char is_space, int plus)
{
	int nl_mod;

	nl_mod = 1;
	if (plus == -1 && spaces <= 0)
		spaces--;
	else if (spaces <= 0 && plus == 1)
		ft_putchar('+');
	else if (is_space && spaces <= 0 && plus != -1)
		ft_putchar(' ');
	else
	{
		spaces -= (plus == -1) ? 1 : 0;
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

int		dec_print_zeroes(int zeroes, int plus, char *flags)
{
	int	nl_mod;

	nl_mod = zeroes;
	if (ft_strrchr(flags, ' ') && plus == 0)
	{
		ft_putchar(' ');
		zeroes--;
	}
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

void	print_spaces(int spaces)
{
	while (spaces-- > 0)
		ft_putchar(' ');
}

int		put_sign(int plus, char *flags)
{
	if (plus == 0)
	{
		if (ft_strrchr(flags, ' '))
		{
			ft_putchar(' ');
			return (1);
		}
		return (0);
	}
	if (plus == 1)
		ft_putchar('+');
	if (plus == -1)
		ft_putchar('-');
	return (1);
}
