/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putbase_lower.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slynn-ev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/08 17:45:10 by slynn-ev          #+#    #+#             */
/*   Updated: 2018/01/08 18:48:03 by slynn-ev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char g_hexadec[16] = "0123456789abcdef";

void	rc_putbase_lower(long long num, int base)
{
	if (num)
	{
		rc_putbase_lower(num/base, base);
		ft_putchar(g_hexadec[num % base]);
	}
}

void	ft_putbase_lower(long long num, int	base)
{
	int	sign;
	
	sign = 1;
	if (num == 0)
	{
		ft_putchar(0);
		return ;
	}
	if (num < 0)
	{
		ft_putchar('-');
		num *= num * -1;
	}
	rc_putbase_lower(num, base); 
}
