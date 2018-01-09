/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slynn-ev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 10:58:37 by slynn-ev          #+#    #+#             */
/*   Updated: 2018/01/09 12:58:14 by slynn-ev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_rc_putnbr(long num)
{
	if (num)
	{
		ft_rc_putnbr(num / 10);
		ft_putchar(num % 10 + '0');
	}
}

void		pf_putnbr(int n)
{
	long	a;

	a = (long)n;
	if (a < 0)
	{
		a *= -1;
	}
	if (a == 0)
		ft_putchar('0');
	else
		ft_rc_putnbr(a);
}
