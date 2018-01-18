/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   short_printers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slynn-ev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/10 14:35:47 by slynn-ev          #+#    #+#             */
/*   Updated: 2018/01/18 22:06:05 by slynn-ev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	pf_short_decimal(long long n, char *flags, int mod)
{
	char	space_type;
	int		plus;
	int		num_length;
	short	num;

	num = (short)n;
	num_length = get_num_length(num, DECIMAL);
	plus = (ft_strrchr(flags, '+')) ? 1 : 0;
	space_type = get_space_type(flags);
	plus = (num < 0) ? -1 : plus;
	if (space_type == ' ' || !(space_type))
		num_length += dec_print_spaces(mod - num_length, space_type, plus);
	else if (space_type == '0')
		num_length += dec_print_zeroes(mod - num_length, plus, flags);
	else if (space_type == '-' && num != 0)
		num_length += put_sign(plus, flags);
	pf_putnbr(num);
	if (space_type == '-')
		print_spaces(mod - num_length);
	return (mod > num_length) ? mod : num_length;
}

int	pf_short_hex_lower(long long n, char *flags, int mod)
{
	short	num;
	char	space_type;
	int		p;
	int		num_length;

	num = (short)n;
	num_length = get_num_length(num, HEXA);
	p = (ft_strrchr(flags, '#')) ? 1 : 0;
	p = (num == 0) ? 0 : p;
	space_type = get_space_type(flags);
	if (num < 0)
		num_length = (sizeof(short) * 8) / 4;
	if (space_type == ' ' || !(space_type))
		num_length += nondec_print_spaces(mod - num_length, HEXA, p, 0);
	if (space_type == '0')
		num_length += nondec_print_zeroes(mod - num_length, HEXA, p, 0);
	if (p && space_type == '-')
		num_length += print_precision(HEXA, 0);
	ft_putbase(num, HEXA, sizeof(short) * 8, 0);
	if (space_type == '-')
		print_spaces(mod - num_length);
	return (mod > num_length) ? mod : num_length;
}

int	pf_short_hex_upper(long long n, char *flags, int mod)
{
	short	num;
	char	space_type;
	int		p;
	int		num_length;

	num = (short)n;
	num_length = get_num_length(num, HEXA);
	p = (ft_strrchr(flags, '#')) ? 1 : 0;
	p = (num == 0) ? 0 : p;
	space_type = get_space_type(flags);
	if (num < 0)
		num_length = (sizeof(short) * 8) / 4;
	if (space_type == ' ' || !(space_type))
		num_length += nondec_print_spaces(mod - num_length, HEXA, p, 1);
	if (space_type == '0')
		num_length += nondec_print_zeroes(mod - num_length, HEXA, p, 1);
	if (p && space_type == '-')
		num_length += print_precision(HEXA, 1);
	ft_putbase(num, HEXA, sizeof(short) * 8, 1);
	if (space_type == '-')
		print_spaces(mod - num_length);
	return (mod > num_length) ? mod : num_length;
}

int	pf_short_octal(long long n, char *flags, int mod)
{
	short	num;
	char	space_type;
	int		p;
	int		num_length;

	num = (short)n;
	num_length = get_num_length(num, OCTAL);
	p = (ft_strrchr(flags, '#')) ? 1 : 0;
	p = (num == 0) ? 0 : p;
	space_type = get_space_type(flags);
	if (num < 0)
		num_length = (sizeof(short) * 8) / 3 + 1;
	if (space_type == ' ' || !(space_type))
		num_length += nondec_print_spaces(mod - num_length, OCTAL, p, 0);
	if (space_type == '0')
		num_length += nondec_print_zeroes(mod - num_length, OCTAL, p, 0);
	if (p && space_type == '-')
		num_length += print_precision(OCTAL, 0);
	ft_putbase(num, OCTAL, sizeof(short) * 8, 0);
	if (space_type == '-')
		print_spaces(mod - num_length);
	return (mod > num_length) ? mod : num_length;
}

int	pf_short_binary(long long n, char *flags, int mod)
{
	short	num;
	char	space_type;
	int		num_length;

	num = (short)n;
	num_length = get_num_length(num, BINARY);
	space_type = get_space_type(flags);
	if (num < 0)
		num_length = (sizeof(short) * 8);
	if (space_type == ' ' || !(space_type))
		num_length += nondec_print_spaces(mod - num_length, BINARY, 0, 0);
	if (space_type == '0')
		num_length += nondec_print_zeroes(mod - num_length, BINARY, 0, 0);
	ft_putbase(num, BINARY, sizeof(short) * 8, 0);
	if (space_type == '-')
		print_spaces(mod - num_length);
	return (mod > num_length) ? mod : num_length;
}
