/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_decimal.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slynn-ev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/05 15:54:38 by slynn-ev          #+#    #+#             */
/*   Updated: 2018/01/09 19:26:55 by slynn-ev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	pf_int_decimal(long long num, char *flags, int mod)
{
	char	space_type;
	int		plus;
	int		num_length;

	num_length = get_num_length(num, DECIMAL);
	plus = (ft_strrchr(flags, '+')) ? 1 : 0;
	space_type = get_space_type(flags);
	plus = (num < 0) ? -1 : plus;
	mod -= (num < 0) ? 1 : 0;
	if (space_type == ' ' || !(space_type))
		dec_print_spaces(mod - num_length, space_type, plus);	
	else if (space_type == '0')
		dec_print_zeroes(mod - num_length, plus);
	else if (space_type == '-' && plus == 1 && num >= 0)
	{
		ft_putchar('+');
		mod--;
	}
	ft_putnbr(num);
	if (space_type == '-')
		print_left_adj(mod - num_length);
}

void	pf_int_hex_lower(long long n, char *flags, int mod)
{
	int		num;
	char	space_type;
	int		precision;
	int		num_length;

	num = (int)n;
	num_length = get_num_length(num, HEXA);
	precision = (ft_strrchr(flags, '#')) ? 1 : 0;
	space_type = get_space_type(flags);
	if (num < 0)
		mod -= 8 - num_length;
	if (space_type == ' ' || !(space_type))
		nondec_print_spaces(mod - num_length, HEXA, precision, 0);	
	if (space_type == '0')
		nondec_print_zeroes(mod - num_length, HEXA, precision, 0);
	if (precision && space_type == '-')
		mod = print_precision(HEXA, 0, mod);
	ft_putbase(num, HEXA, sizeof(int) * 8, 0);
	if (space_type == '-')
		print_left_adj(mod - num_length);
}

void	pf_int_hex_upper(long long n, char *flags, int mod)
{
	int		num;
	char	space_type;
	int		precision;
	int		num_length;

	num = (int)n;
	num_length = get_num_length(num, HEXA);
	precision = (ft_strrchr(flags, '#')) ? 1 : 0;
	space_type = get_space_type(flags);
	if (num < 0)
		mod -= 8 - num_length;
	if (space_type == ' ' || !(space_type))
		nondec_print_spaces(mod - num_length, HEXA, precision, 0);	
	if (space_type == '0')
		nondec_print_zeroes(mod - num_length, HEXA, precision, 0);
	if (precision && space_type == '-')
		mod = print_precision(HEXA, 0, mod);
	ft_putbase(num, HEXA, sizeof(int) * 8, 0);
	if (space_type == '-')
		print_left_adj(mod - num_length);
}

void pf_int_octal(long long n, char *flags, int mod)
{
	int		num;
	char	space_type;
	int		precision;
	int		num_length;

	num = (int)n;
	num_length = get_num_length(num, OCTAL);
	precision = (ft_strrchr(flags, '#')) ? 1 : 0;
	space_type = get_space_type(flags);
	if (num < 0)
		mod -= 11 - num_length;
	if (space_type == ' ' || !(space_type))
		nondec_print_spaces(mod - num_length, OCTAL, precision, 0);	
	if (space_type == '0')
		nondec_print_zeroes(mod - num_length, OCTAL, precision, 0);
	if (precision && space_type == '-')
		mod = print_precision(OCTAL, 0, mod);
	ft_putbase(num, OCTAL, sizeof(int) * 8, 0);
	if (space_type == '-')
		print_left_adj(mod - num_length);
}
