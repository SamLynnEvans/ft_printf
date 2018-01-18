/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dt_unsigned_num_flags.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slynn-ev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 23:44:29 by slynn-ev          #+#    #+#             */
/*   Updated: 2018/01/17 23:27:15 by slynn-ev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	dec_mod2_greater_print_us(int mod2, unsigned long long num, int num_length)
{	
	int 	count;

	count = 0;
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

int dec_dot_space_print_us(int mod[2], unsigned long long num, int num_length)
{
	int count;

	count = mod[0];
	while (mod[0] > mod[1] && mod[0] > num_length)
	{
		ft_putchar(' ');
		mod[0]--;
	}
	while (mod[1]-- > num_length)
		ft_putchar('0');
	if (num == 0 && mod[1] == 0)
		ft_putchar(' ');
	else
		pf_putnbr_unsigned(num);
	return ((count > num_length) ? count : num_length);
}

int	dec_dot_lft_adj_print_us(int mod[2], unsigned long long num, int num_length)
{
	int count;

	count = mod[0];
	while (mod[1]-- > num_length)
		ft_putchar('0');
	if (num == 0 && mod[1] == 0)
		ft_putchar(' ');
	else
		pf_putnbr_unsigned(num);
	while (mod[0] > mod[1] && mod[0] > num_length)
	{
		ft_putchar(' ');
		mod[0]--;
	}
	return (count);
}
