/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_printers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slynn-ev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/21 20:51:05 by slynn-ev          #+#    #+#             */
/*   Updated: 2018/01/21 20:52:39 by slynn-ev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	pf_int_decimal(long long num, char *flags, int mod)
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

long long	shorten_number(long long num, int int_size)
{
	if (int_size == sizeof(short))
		return ((short)num);
	return ((char)num);
}

int	pf_int_nondecprint(long long num, char *flags, int mod, int base)
{
	char	space_type;
	int		p;
	int		num_length;
	char	int_size;

	int_size = get_int_size(flags);
	if (int_size == sizeof(char) || int_size == sizeof(short))
		num = shorten_number(num, int_size);
	p = (base == DECIMAL || num != 0) ? get_precision(flags, base, num) : 0;
	num_length = get_num_length2(num, base, int_size);
	space_type = bit_space_type(flags);
	if (!p && base == DECIMAL && (space_type & SPACE))
		num_length += print_spaces(1);
	if (!(space_type & MINUS) && !(space_type & ZERO))
		num_length += print_spaces(mod - (num_length + ((p == NEG) ? 1 : p)));
	if (p)
		num_length += print_precision(base, p);
	if (space_type & ZERO && !(space_type & MINUS))
		num_length += print_zeroes(mod - num_length);
	ft_putbase(num, base, int_size * 8, 0);
	if (space_type & MINUS)
		num_length += print_spaces(mod - num_length);
	return (mod > num_length) ? mod : num_length;
}

int	pf_short_nondecprint(long long n, char *flags, int mod, int base)
{
	short	num;
	char	space_type;
	int		p;
	int		num_length;

	num = (short)n;
	p = (base != DECIMAL || num != 0) ? get_precision(flags, base, num) : 0;
	num_length = get_num_length2(num, base, sizeof(short));
	space_type = get_space_type(flags);
	if (!p && base == DECIMAL && (space_type == '-' || num_length >= mod) && ft_strrchr(flags, ' '))
	{
		ft_putchar(' ');
		num_length++;
	}	
	if (space_type == ' ' || !(space_type))
		num_length += nondec_print_spaces(mod - num_length, base, p, 0);
	if (space_type == '0')
		num_length += nondec_print_zeroes(mod - num_length, base, p, 0);
	if (p && space_type == '-')
		num_length += print_precision(base, p);
	ft_putbase(num, base, sizeof(short) * 8, 0);
	if (space_type == '-')
		print_spaces(mod - num_length);
	return (mod > num_length) ? mod : num_length;
}

int	pf_hh_nondecprint(long long n, char *flags, int mod, int base)
{
	char	num;
	char	space_type;
	int		p;
	int		num_length;

	num = (char)n;
	p = (base != DECIMAL || num != 0) ? get_precision(flags, base, num) : 0;
	num_length = get_num_length2(num, base, sizeof(char));
	space_type = get_space_type(flags);
	if (!p && base == DECIMAL && (space_type == '-' || num_length >= mod) && ft_strrchr(flags, ' '))
	{
		ft_putchar(' ');
		num_length++;
	}
	if (space_type == ' ' || !(space_type))
		num_length += nondec_print_spaces(mod - num_length, base, p, 0);
	if (space_type == '0')
		num_length += nondec_print_zeroes(mod - num_length, base, p, 0);
	if (p && space_type == '-')
		num_length += print_precision(base, p);
	ft_putbase(num, base, sizeof(char) * 8, 0);
	if (space_type == '-')
		print_spaces(mod - num_length);
	return (mod > num_length) ? mod : num_length;
}

int	pf_long_nondecprint(long long num, char *flags, int mod, int base)
{
	char		space_type;
	int			p;
	int			num_length;

	p = (base != DECIMAL || num != 0) ? get_precision(flags, base, num) : 0;
	num_length = get_num_length2(num, base, sizeof(long long));
	space_type = get_space_type(flags);
	if (!p && base == DECIMAL && (space_type == '-' || num_length >= mod) && ft_strrchr(flags, ' '))
	{
		ft_putchar(' ');
		num_length++;
	}	
	if (space_type == ' ' || !(space_type))
		num_length += nondec_print_spaces(mod - num_length, base, p, 0);
	if (space_type == '0')
		num_length += nondec_print_zeroes(mod - num_length, base, p, 0);
	if (p && space_type == '-')
		num_length += print_precision(base, p);
	ft_putbase(num, base, sizeof(long long) * 8, 0);
	if (space_type == '-')
		print_spaces(mod - num_length);
	return (mod > num_length) ? mod : num_length;
}

int	pf_int_hex_lower(long long n, char *flags, int mod)
{
	int		num;
	char	space_type;
	int		p;
	int		num_length;

	num = (int)n;
	num_length = get_num_length(num, HEXA);
	p = (ft_strrchr(flags, '#') && num != 0) ? 1 : 0;
	space_type = get_space_type(flags);
	if (num < 0)
		num_length = (sizeof(int) * 8) / 4;
	if (space_type == ' ' || !(space_type))
		num_length += nondec_print_spaces(mod - num_length, HEXA, p, 0);
	if (space_type == '0')
		num_length += nondec_print_zeroes(mod - num_length, HEXA, p, 0);
	if (p && space_type == '-')
		num_length += print_precision(HEXA, 0);
	ft_putbase(num, HEXA, sizeof(int) * 8, 0);
	if (space_type == '-')
		print_spaces(mod - num_length);
	return (mod > num_length) ? mod : num_length;
}

int	pf_int_hex_upper(long long n, char *flags, int mod)
{
	int		num;
	char	space_type;
	int		p;
	int		num_length;

	num = (int)n;
	num_length = get_num_length(num, HEXA);
	p = (ft_strrchr(flags, '#') && num != 0) ? 1 : 0;
	space_type = get_space_type(flags);
	if (num < 0)
		num_length = (sizeof(int) * 8) / 4;
	if (space_type == ' ' || !(space_type))
		num_length += nondec_print_spaces(mod - num_length, HEXA, p, 1);
	if (space_type == '0')
		num_length += nondec_print_zeroes(mod - num_length, HEXA, p, 1);
	if (p && space_type == '-' && num != 0)
		num_length += print_precision(HEXA, 1);
	ft_putbase(num, HEXA, sizeof(int) * 8, 1);
	if (space_type == '-')
		print_spaces(mod - num_length);
	return (mod > num_length) ? mod : num_length;
}

int	pf_int_octal(long long n, char *flags, int mod)
{
	int		num;
	char	space_type;
	int		p;
	int		num_length;

	num = (int)n;
	num_length = get_num_length(num, OCTAL);
	p = (ft_strrchr(flags, '#') && num != 0) ? 1 : 0;
	space_type = get_space_type(flags);
	if (num < 0)
		num_length = (sizeof(int) * 8) / 3 + 1;
	if (space_type == ' ' || !(space_type))
		num_length += nondec_print_spaces(mod - num_length, OCTAL, p, 0);
	if (space_type == '0')
		num_length += nondec_print_zeroes(mod - num_length, OCTAL, p, 0);
	if (p && space_type == '-')
		num_length += print_precision(OCTAL, 0);
	ft_putbase(num, OCTAL, sizeof(int) * 8, 0);
	if (space_type == '-')
		print_spaces(mod - num_length);
	return (mod > num_length) ? mod : num_length;
}

int	pf_int_binary(long long n, char *flags, int mod)
{
	int		num;
	char	space_type;
	int		num_length;

	num = (int)n;
	num_length = get_num_length(num, BINARY);
	space_type = get_space_type(flags);
	if (num < 0)
		num_length = (sizeof(int) * 8);
	if (space_type == ' ' || !(space_type))
		num_length += nondec_print_spaces(mod - num_length, BINARY, 0, 0);
	if (space_type == '0')
		num_length += nondec_print_zeroes(mod - num_length, BINARY, 0, 0);
	ft_putbase(num, BINARY, sizeof(int) * 8, 0);
	if (space_type == '-')
		print_spaces(mod - num_length);
	return (mod > num_length) ? mod : num_length;
}
