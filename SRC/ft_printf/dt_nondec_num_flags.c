/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dt_nondec_num_flags.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slynn-ev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 20:34:07 by slynn-ev          #+#    #+#             */
/*   Updated: 2018/01/21 17:55:29 by slynn-ev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	non_dec_dot_leftadj_print1(int num_l, int mod, int base, int precision)
{
	int		count;

	count = 0;
	if (precision)
		count += print_precision(base, precision);
	while (mod-- > num_l)
	{
		count++;
		ft_putchar('0');
	}
	return (count);
}

int	non_dec_dot_leftadj_print1_uc(int num_l, int mod, int base, int precision)
{
	int		count;

	count = 0;
	if (precision)
		count += print_precision(base, precision);
	while (mod-- > num_l)
	{
		count++;
		ft_putchar('0');
	}
	return (count);
}

int	non_dec_dot_leftadj_print2(int num_l, int mod, int count)
{
	while (mod > num_l + count)
	{
		ft_putchar(' ');
		count++;
	}
	return (count);
}

int	non_dec_dot_spaceprint(int num_l, int mod[2], int base, int precision)
{
	int		count;

	count = 0;
	while (mod[0] > mod[1] + precision && mod[0] > num_l + precision)
	{
		ft_putchar(' ');
		count++;
		mod[0]--;
	}
	if (precision)
		count += print_precision(base, precision);
	while (mod[1]-- > num_l)
	{
		count++;
		ft_putchar('0');
	}
	return (count);
}

int	non_dec_dot_spaceprint_uc(int num_l, int mod[2], int base, int precision)
{
	int		count;

	count = 0;
	while (mod[0] > mod[1] + precision && mod[0] > num_l + precision)
	{
		ft_putchar(' ');
		count++;
		mod[0]--;
	}
	if (precision)
		count += print_precision(base, precision);
	while (mod[1]-- > num_l)
	{
		count++;
		ft_putchar('0');
	}
	return (count);
}
