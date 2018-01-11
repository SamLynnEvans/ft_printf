/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dot_printer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slynn-ev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 17:05:55 by slynn-ev          #+#    #+#             */
/*   Updated: 2018/01/11 23:52:56 by slynn-ev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void get_mod_values(char *flags, int *mod, int *mod2)
{
	int	i;

	*mod2 = 0;
	i = 0;
	while (flags[i] != '.')
	{
		if (flags[i] >= '0' && flags[i] <= '9')
		{
			*mod = ft_atoi(flags + i);
			while (flags[i] <= '9' && flags[i] >= '0')
				i++;
		}
		else
			i++;
	}
	while (flags[i])
	{
		if (flags[i] <= '9' && flags[i] >= '0')
		{
			*mod2 = ft_atoi(flags+ i);
			break ;
		}
		i++;
	}
}

int	dec_mod2_greater_print(int plus, int mod2, long long num)
{	
	int count;
	int		num_length;

	count = 0;
	num_length = get_num_length(num, DECIMAL);
	count += put_sign(plus);
	while (mod2-- > num_length)
	{	
		count++;
		ft_putchar('0');
	}
	pf_putnbr(num);
	return (count + num_length);
}

int dec_dot_space_print(int plus, int mod, int mod2, long long num)	
{
	int count;
	int		num_length;

	count = mod;
	num_length = get_num_length(num, DECIMAL);
	mod -= (plus == -1 || plus == 1) ? 1 : 0;
	while (mod	> mod2 && mod > num_length)
	{
		ft_putchar(' ');
		mod--;
	}
	put_sign(plus);	
	while (mod2-- > num_length)
		ft_putchar('0');
	pf_putnbr(num);
	return (count);
}

int	dec_dot_lft_adj_print(int plus, int mod, int mod2, long long num)
{
	int count;
	int		num_length;

	count = mod;
	num_length = get_num_length(num, DECIMAL);
	mod -= (plus == -1 || plus == 1) ? 1 : 0;
	put_sign(plus);	
	while (mod2-- > num_length)
		ft_putchar('0');
	pf_putnbr(num);
	while (mod	> mod2 && mod > num_length)
	{
		ft_putchar(' ');
		mod--;
	}
	return (count);
}

int	dec_dot_putnbr(long long num, int num_length, int plus)
{
	num_length += put_sign(plus);
	ft_putnbr(num);
	return (num_length);
}
