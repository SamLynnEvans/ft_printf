/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unicode_utf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slynn-ev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 22:37:04 by slynn-ev          #+#    #+#             */
/*   Updated: 2018/01/17 22:37:20 by slynn-ev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	int_putchar(int c)
{
	write(1, &c, 1);
}

void	print_uc_two_byte(int c)
{
	unsigned char x[2];

	x[0] = 192 | ((1984 & c) >> 6);
	x[1] = 128 | (63 & c);
	write(1, x, 2);
}

void	print_uc_three_byte(int c)
{
	unsigned char 	x[3];

	x[0] = 224 | ((61440 & c) >> 12);
	x[1] = 128 | ((4032 & c) >> 6);
	x[2] = 128 | (63 & c);
	write(1, x, 3);
}

void	print_uc_four_byte(int c)
{
	unsigned char x[4];

	x[0] = 240 | ((1835008 & c) >> 18);
	x[1] = 128 | ((258048 & c) >> 12);
	x[2] = 128 | ((4032 & c) >> 6);
	x[3] = 128 | (63 & c);
	write(1, x, 4);
}
