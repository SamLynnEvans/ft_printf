/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slynn-ev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 10:58:37 by slynn-ev          #+#    #+#             */
/*   Updated: 2018/01/10 14:03:28 by slynn-ev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_rc_putnbr_unsigned(unsigned long long num)
{
	if (num)
	{
		ft_rc_putnbr_unsigned(num / 10);
		ft_putchar(num % 10 + '0');
	}
}

void		pf_putnbr(long long a)
{
	if (a < 0)
	{
		a *= -1;
	}
	if (a == 0)
		ft_putchar('0');
	else
		ft_rc_putnbr_unsigned(a);
}

void		pf_putnbr_unsigned(unsigned long long a)
{
	if (a == 0)
		ft_putchar('0');
	else
		ft_rc_putnbr_unsigned(a);
}
