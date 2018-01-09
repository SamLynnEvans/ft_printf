/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putbase_lower.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slynn-ev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/08 17:45:10 by slynn-ev          #+#    #+#             */
/*   Updated: 2018/01/09 15:37:52 by slynn-ev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

char g_hexadec[16] = "0123456789abcdef";
char g_hexadec_uc[16] = "0123456789ABCDEF";

void	rc_putbase_lower(long long num, int base)
{
	if (num)
	{
		rc_putbase_lower(num/base, base);
		ft_putchar(g_hexadec[num % base]);
	}
}

void	rc_putbase_upper(long long num, int base)
{
	if (num)
	{
		rc_putbase_upper(num/base, base);
		ft_putchar(g_hexadec_uc[num % base]);
	}
}

void ft_print_output(char *output, int output_len)
{
	while (output_len-- >= 0)
		ft_putchar(output[output_len]);
}

void	neg_base_printer(long long num, int base, int int_size, int caps)
{
	char	output[64];
	int		bitmask;
	int		mask_width;
	int		x;
	int		count[2];

	x = 0;
	count[1] = 0;
	mask_width = (base == HEXA) ? 4 : 0;	
	if (base != HEXA)
		mask_width = (base == OCTAL) ? 3 : 1;	
	while (x < int_size)
	{
		bitmask = 0;
		count[0] = 0;	
			while (count[0] < mask_width)
			{
				if ((num & 1UL << x))
					bitmask ^= 1UL << count[0]; 
				count[0]++;
				x++;
			}
		output[count[1]++] = (caps) ? g_hexadec_uc[bitmask] : g_hexadec[bitmask];
	}
	ft_print_output(output, count[1]);
}


void	ft_putbase(long long num, int base, int int_size, int caps)
{
	int neg;

	neg = 0;
	if (num == 0)
		ft_putchar('0');
	if (num < 0)
		neg_base_printer(num, base, int_size, caps);
	else
	{
		if (!caps)
			rc_putbase_lower(num, base);
		else
			rc_putbase_upper(num, base);
	}
}
