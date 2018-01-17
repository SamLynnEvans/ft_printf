/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dt_unsigned_num_flags.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slynn-ev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 23:44:29 by slynn-ev          #+#    #+#             */
/*   Updated: 2018/01/16 15:40:40 by slynn-ev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	dec_mod2_greater_print_us(int mod2, unsigned long long num)
{	
	int 	count;
	int		num_length;

	count = 0;
	num_length = get_unum_length(num, DECIMAL);
	while (mod2-- > num_length)
	{	
		count++;
		ft_putchar('0');
	}
	if (num == 0 && mod2 == 0)
		ft_putchar(' ');
	else
		pf_putnbr_unsigned(num);
	return (count + num_length);
}

int dec_dot_space_print_us(int mod, int mod2, unsigned long long num)	
{
	int count;
	int		num_length;

	count = mod;
	num_length = get_unum_length(num, DECIMAL);
	while (mod	> mod2 && mod > num_length)
	{
		ft_putchar(' ');
		mod--;
	}
	while (mod2-- > num_length)
		ft_putchar('0');
	if (num == 0 && mod2 == 0)
		ft_putchar(' ');
	else
		pf_putnbr_unsigned(num);
	return (count);
}

int	dec_dot_lft_adj_print_us(int mod, int mod2, unsigned long long num)
{
	int count;
	int		num_length;

	count = mod;
	num_length = get_unum_length(num, DECIMAL);
	while (mod2-- > num_length)
		ft_putchar('0');
	if (num == 0 && mod2 == 0)
		ft_putchar(' ');
	else
		pf_putnbr_unsigned(num);
	while (mod	> mod2 && mod > num_length)
	{
		ft_putchar(' ');
		mod--;
	}
	return (count);
}
