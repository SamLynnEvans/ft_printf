/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   long_printers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slynn-ev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 19:33:01 by slynn-ev          #+#    #+#             */
/*   Updated: 2018/01/18 22:05:28 by slynn-ev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	pf_l_decimal(long long num, char *flags, int mod)
{
	char	space_type;
	int		plus;
	int		num_length;

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

int	pf_l_hex_lower(long long num, char *flags, int mod)
{
	char	space_type;
	int		p;
	int		num_length;

	num_length = get_num_length(num, HEXA);
	p = (ft_strrchr(flags, '#')) ? 1 : 0;
	p = (num == 0) ? 0 : p;
	space_type = get_space_type(flags);
	if (num < 0)
		num_length = (sizeof(long) * 8) / 4;
	if (space_type == ' ' || !(space_type))
		num_length += nondec_print_spaces(mod - num_length, HEXA, p, 0);
	if (space_type == '0')
		num_length += nondec_print_zeroes(mod - num_length, HEXA, p, 0);
	if (p && space_type == '-')
		num_length += print_precision(HEXA, 0);
	ft_putbase(num, HEXA, sizeof(long) * 8, 0);
	if (space_type == '-')
		print_spaces(mod - num_length);
	return (mod > num_length) ? mod : num_length;
}

int	pf_l_hex_upper(long long num, char *flags, int mod)
{
	char	space_type;
	int		p;
	int		num_length;

	num_length = get_num_length(num, HEXA);
	p = (ft_strrchr(flags, '#')) ? 1 : 0;
	p = (num == 0) ? 0 : p;
	space_type = get_space_type(flags);
	if (num < 0)
		num_length = (sizeof(long) * 8) / 4;
	if (space_type == ' ' || !(space_type))
		num_length += nondec_print_spaces(mod - num_length, HEXA, p, 1);
	if (space_type == '0')
		num_length += nondec_print_zeroes(mod - num_length, HEXA, p, 1);
	if (p && space_type == '-')
		num_length += print_precision(HEXA, 1);
	ft_putbase(num, HEXA, sizeof(long) * 8, 1);
	if (space_type == '-')
		print_spaces(mod - num_length);
	return (mod > num_length) ? mod : num_length;
}

int	pf_l_octal(long long num, char *flags, int mod)
{
	char	space_type;
	int		p;
	int		num_length;

	num_length = get_num_length(num, OCTAL);
	p = (ft_strrchr(flags, '#')) ? 1 : 0;
	p = (num == 0) ? 0 : p;
	space_type = get_space_type(flags);
	if (num < 0)
		num_length = (sizeof(long) * 8) / 3 + 1;
	if (space_type == ' ' || !(space_type))
		num_length += nondec_print_spaces(mod - num_length, OCTAL, p, 0);
	if (space_type == '0')
		num_length += nondec_print_zeroes(mod - num_length, OCTAL, p, 0);
	if (p && space_type == '-')
		num_length += print_precision(OCTAL, 0);
	ft_putbase(num, OCTAL, sizeof(long) * 8, 0);
	if (space_type == '-')
		print_spaces(mod - num_length);
	return (mod > num_length) ? mod : num_length;
}

int	pf_long_binary(long long n, char *flags, int mod)
{
	int		num;
	char	space_type;
	int		num_length;

	num = (long)n;
	num_length = get_num_length(num, BINARY);
	space_type = get_space_type(flags);
	if (num < 0)
		num_length = (sizeof(long) * 8);
	if (space_type == ' ' || !(space_type))
		num_length += nondec_print_spaces(mod - num_length, BINARY, 0, 0);
	if (space_type == '0')
		num_length += nondec_print_zeroes(mod - num_length, BINARY, 0, 0);
	ft_putbase(num, BINARY, sizeof(long) * 8, 0);
	if (space_type == '-')
		print_spaces(mod - num_length);
	return (mod > num_length) ? mod : num_length;
}