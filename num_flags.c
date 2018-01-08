/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   num_flags.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slynn-ev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/08 17:37:49 by slynn-ev          #+#    #+#             */
/*   Updated: 2018/01/08 18:40:43 by slynn-ev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	get_space_type(char *flags, int *plus)
{
	int	i;

	i = 0;
	if (*flags)
	{
		if (ft_strrchr(flags, '+'))
			*plus = 1;
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

void	print_spaces(long long num, int mod, char is_space, int plus, int base)
{
	int	num_length;
	
	num_length = get_num_length(num, base);
	if (num_length >= mod && plus)
	{
		ft_putchar('+');
		return ;
	}
	else if (is_space && num_length >= mod)
	{
		ft_putchar(' ');
		return ;
	}
	while (num_length < mod)
	{
		if (num_length + 1 == mod && plus)
			ft_putchar('+');
		else
			ft_putchar(' ');
		num_length++;
	}
}

void	print_zeroes(long long num, int mod, int plus, int base)
{
	int	num_length;

	num_length = get_num_length(num, base);
	if (plus)
	{
		ft_putchar('+');
		num_length++;
	}
	while (num_length < mod)
	{
		ft_putchar('0');
		num_length++;
	}
}

void	print_left_adj(long long num, int mod, int base)
{
	int	num_length;
	
	num_length = get_num_length(num, base);
	while (num_length < mod)
	{
		ft_putchar(' ');
		num_length++;
	}
}
