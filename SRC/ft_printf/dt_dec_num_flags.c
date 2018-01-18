/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dot_printer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slynn-ev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 17:05:55 by slynn-ev          #+#    #+#             */
/*   Updated: 2018/01/18 19:25:00 by slynn-ev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	print_sign(int plus)
{
	if (plus == 0)
		return (0);
	if (plus == 1)
		ft_putchar('+');
	if (plus == -1)
		ft_putchar('-');
	return (1);
}

int			dt_num_zero_case(int space_type, int mod, int plus)
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
	count += print_sign(plus);
	if (space_type == '-')
		while (mod > count++)
			ft_putchar(' ');
	return (count);
}

int			dec_mod2_greater_print(int plus, int mod2,
long long num, int num_length)
{
	int	count;

	count = 0;
	count += print_sign(plus);
	while (mod2-- > num_length)
	{
		count++;
		ft_putchar('0');
	}
	pf_putnbr(num);
	return (count + num_length);
}

int			dec_dot_space_print(int plus, int mod[2],
int num_length, long long num)
{
	int		count;
	int		sign_put;

	count = mod[0];
	mod[0] -= (plus == -1 || plus == 1) ? 1 : 0;
	while (mod[0] > mod[1] && mod[0] > num_length)
	{
		ft_putchar(' ');
		mod[0]--;
	}
	sign_put = print_sign(plus);
	while (mod[1]-- > num_length)
		ft_putchar('0');
	pf_putnbr(num);
	return ((num_length + sign_put > count) ? num_length + sign_put : count);
}

int			dec_dot_lft_adj_print(int plus, int mod[2],
char *flags, long long num)
{
	int	count;
	int	num_length;

	count = 0;
	num_length = get_num_length(num, DECIMAL);
	count += put_sign(plus, flags);
	while (mod[1]-- > num_length)
	{
		ft_putchar('0');
		count++;
	}
	pf_putnbr(num);
	while (mod[0] > num_length + count)
	{
		ft_putchar(' ');
		count++;
	}
	return (count + num_length);
}
