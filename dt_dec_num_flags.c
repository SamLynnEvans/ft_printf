/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dot_printer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slynn-ev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 17:05:55 by slynn-ev          #+#    #+#             */
/*   Updated: 2018/01/17 15:51:13 by slynn-ev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int dt_num_zero_case(int space_type, int mod, int plus)
{
	int	count;

	count = 0;
	if (plus != 1 && mod == 0 && space_type == ' ')
	{
		ft_putchar(' ');
		return (1);
	}
	if (space_type != '-') 
	while (mod > count + plus)
	{
		ft_putchar(' ');
		count++;	
	}
	count += put_sign(plus);
	if (space_type == '-') 
		while (mod > count++)
			ft_putchar(' ');
	return (count);
}

int	dec_mod2_greater_print(int plus, int mod2, long long num)
{	
	int		count;
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
	int		count;
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
	int	count;
	int	num_length;
	
	count = 0;
	num_length = get_num_length(num, DECIMAL);
	count += put_sign(plus);	
	while (mod2-- > num_length)
	{
		ft_putchar('0');
		count++;
	}
	pf_putnbr(num);
	while (mod	> num_length + count)
	{
		ft_putchar(' ');
		count++;
	}
	return (count + num_length);
}
