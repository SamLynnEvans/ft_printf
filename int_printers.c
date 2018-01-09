/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_decimal.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slynn-ev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/05 15:54:38 by slynn-ev          #+#    #+#             */
/*   Updated: 2018/01/09 15:43:14 by slynn-ev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_pf_decimal(long long n, char *flags, int mod)
{
	int		num;
	char	space_type;
	int		plus;
	int		num_length;

	num = (int)n;
	num_length = get_num_length(num, DECIMAL);
	plus = (ft_strrchr(flags, '+')) ? 1 : 0;
	space_type = get_space_type(flags);
	if (num < 0)
	{
		plus = -1;
		mod--;
	}
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

void	ft_pf_hex_lower(long long n, char *flags, int mod)
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

void	ft_pf_hex_upper(long long n, char *flags, int mod)
{
	int		num;
	char	space_type;
	int		plus;

	num = (int)n;
	space_type = get_space_type(flags);
	
	plus = 0;
	if (ft_strrchr(flags, '#') && num)
		mod -= 2;
	if (space_type == ' ' || !(space_type))
		print_spaces(num, mod, space_type, plus, HEXA);	
	if (ft_strrchr(flags, '#') && num)
		ft_putstr("0X");
	if (space_type == '0')
		print_zeroes(num, mod, plus, HEXA);
	ft_putbase(num, HEXA, 8 - get_num_length(num, HEXA), 1);
	if (space_type == '-')
		print_left_adj(num, mod, HEXA);
}

void ft_pf_octal(long long n, char *flags, int mod)
{
	int		num;
	char	space_type;
	int		plus;

	num = (int)n;
	space_type = get_space_type(flags);
	plus = 0;
	if (ft_strrchr(flags, '#') && num)
		mod --;
	if (space_type == ' ' || !(space_type))
		print_spaces(num, mod, space_type, plus, OCTAL);	
	if (ft_strrchr(flags, '#') && num)
		ft_putchar('0');
	if (space_type == '0')
		print_zeroes(num, mod, plus, HEXA);
	ft_putbase(num, HEXA, 16 - get_num_length(num, OCTAL), 1);
	if (space_type == '-')
		print_left_adj(num, mod, OCTAL);	
}*/
