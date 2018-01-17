/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unicode.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slynn-ev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 18:57:00 by slynn-ev          #+#    #+#             */
/*   Updated: 2018/01/17 20:20:35 by slynn-ev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <locale.h>

int	print_uc_two_bit(int c)
{
	unsigned char x[2];

	x[0] = 192 | ((1984 & c) >> 6);
	x[1] = 128 | (63 & c);
	write(1, x, 2);
	return (2);
}

int	print_uc_three_bit(int c)
{
	unsigned char 	x[3];

	x[0] = 224 | ((61440 & c) >> 12);
	x[1] = 128 | ((4032 & c) >> 6);
	x[2] = 128 | (63 & c);
	write(1, x, 3);
	return (3);
}

int	print_uc_four_bit(int c)
{
	unsigned char x[4];

	x[0] = 240 | ((1835008 & c) >> 18);
	x[1] = 128 | ((258048 & c) >> 12);
	x[2] = 128 | ((4032 & c) >> 6);
	x[3] = 128 | (63 & c);
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

int main(int ac, char **av)
{
	char *str;
	setlocale(LC_CTYPE, "");
	
	ft_putchar_unicode(ft_atoi(av[1]), str);
	printf("\n%C\n", ft_atoi(av[1]));
}
