/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unicode.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slynn-ev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 18:57:00 by slynn-ev          #+#    #+#             */
/*   Updated: 2018/01/17 20:12:18 by slynn-ev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <locale.h>

int	print_uc_two_bit(int c)
{
	int bitmask[2];
	unsigned char x[2];

	x[0] = 192;
	x[1] = 128;
	bitmask[0] = 1984 & c;
	bitmask[1] = 63 & c;
	x[0] |= (bitmask[0] >> 6);
	x[1] |= bitmask[1];
	write(1, x, 2);
	return (2);
}

int	print_uc_three_bit(int c)
{
	int bitmask[3];
	unsigned char x[3];

	x[0] = 224;
	x[1] = 128;
	x[2] = 128;
	bitmask[0] = 61440 & c;
	bitmask[1] = 4032 & c;
	bitmask[2] = 63 & c;
	x[0] |= bitmask[0] >> 12;
	x[1] |= bitmask[1] >> 6;
	x[2] |= bitmask[2];
	write(1, x, 3);
	return (3);
}

int	print_uc_four_bit(int c)
{
	int bitmask[4];
	unsigned char x[4];

	x[0] = 240;
	x[1] = 128;
	x[2] = 128;
	x[3] = 128;
	bitmask[0] = 1835008 & c;
	bitmask[1] = 258048 & c;
	bitmask[2] = 4032 & c;
	bitmask[3] = 63 & c;
	x[0] |= bitmask[0] >> 18;
	x[1] |= bitmask[1] >> 12;
	x[2] |= bitmask[2] >> 6;
	x[3] |= bitmask[3];
	write(1, x, 4);
	return (3);
}

int	ft_putchar_unicode(int c, char *flags)
{
	if (c > 127 && c < 2047)
		print_uc_two_bit(c);
	if (c > 2047 && c < 65535)
		print_uc_three_bit(c);
	if (c > 65536 && c < 1112064)
		print_uc_four_bit(c);
	return (1);
}

int main()
{
	char *str;
	int		c;
	setlocale(LC_CTYPE, "");
	c = 99123;
	ft_putchar_unicode(c, str);
	printf("\n%C\n", c);
}
