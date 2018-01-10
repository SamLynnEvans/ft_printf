/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   long_printers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slynn-ev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 19:33:01 by slynn-ev          #+#    #+#             */
/*   Updated: 2018/01/10 12:22:44 by slynn-ev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	pf_ll_decimal(long long num, char *flags, int mod)
{
	char	space_type;
	int		plus;
	int		num_length;

	num_length = get_num_length(num, DECIMAL);
	plus = (ft_strrchr(flags, '+')) ? 1 : 0;
	space_type = get_space_type(flags);
	plus = (num < 0) ? -1: plus;
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
	pf_putnbr(num);
	if (space_type == '-')
		print_left_adj(mod - num_length);
}

void	pf_ll_hex_lower(long long num, char *flags, int mod)
{
	char	space_type;
	int		precision;
	int		num_length;
	
	num_length = get_num_length(num, HEXA);
	precision = (ft_strrchr(flags, '#')) ? 1 : 0;
	space_type = get_space_type(flags);
	if (num < 0)
		mod -= (sizeof(long long) * 8) / 4 - num_length;
	if (space_type == ' ' || !(space_type))
		nondec_print_spaces(mod - num_length, HEXA, precision, 0);	
	if (space_type == '0')
		nondec_print_zeroes(mod - num_length, HEXA, precision, 0);
	if (precision && space_type == '-')
		mod = print_precision(HEXA, 0, mod);
	ft_putbase(num, HEXA, sizeof(long long) * 8, 0);
	if (space_type == '-')
		print_left_adj(mod - num_length);
}

void	pf_ll_hex_upper(long long num, char *flags, int mod)
{
	char	space_type;
	int		precision;
	int		num_length;
	
	num_length = get_num_length(num, HEXA);
	precision = (ft_strrchr(flags, '#')) ? 1 : 0;
	space_type = get_space_type(flags);
	if (num < 0)
		mod -= (sizeof(long long) * 8) / 4 - num_length;
	if (space_type == ' ' || !(space_type))
		nondec_print_spaces(mod - num_length, HEXA, precision, 1);	
	if (space_type == '0')
		nondec_print_zeroes(mod - num_length, HEXA, precision, 1);
	if (precision && space_type == '-')
		mod = print_precision(HEXA, 0, mod);
	ft_putbase(num, HEXA, sizeof(long long) * 8, 1);
	if (space_type == '-')
		print_left_adj(mod - num_length);
}

void	pf_ll_octal(long long num, char *flags, int mod)
{
	char	space_type;
	int		precision;
	int		num_length;
	
	num_length = get_num_length(num, OCTAL);
	precision = (ft_strrchr(flags, '#')) ? 1 : 0;
	space_type = get_space_type(flags);
	if (num < 0)
		mod -= (sizeof(long long) * 8) / 3 - num_length;
	if (space_type == ' ' || !(space_type))
		nondec_print_spaces(mod - num_length, OCTAL, precision, 0);	
	if (space_type == '0')
		nondec_print_zeroes(mod - num_length, OCTAL, precision, 0);
	if (precision && space_type == '-')
		mod = print_precision(OCTAL, 0, mod);
	ft_putbase(num, OCTAL, sizeof(long long) * 8, 0);
	if (space_type == '-')
		print_left_adj(mod - num_length);
}
