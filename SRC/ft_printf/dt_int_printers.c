/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dt_int_printers.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slynn-ev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 23:49:24 by slynn-ev          #+#    #+#             */
/*   Updated: 2018/01/19 12:00:10 by slynn-ev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	pf_dot_int_decimal(long long num, char *flags, int mod[2])
{
	int		plus;
	char	space_type;
	int		num_l;

	num_l = get_num_length(num, DECIMAL);
	plus = (ft_strrchr(flags, '+')) ? 1 : 0;
	plus = (num < 0) ? -1 : plus;
	space_type = get_space_type(flags);
	if (mod[1] == 0 && num == 0)
		return (dt_num_zero_case(space_type, mod[0], plus));
	if (space_type == ' ' && plus == 0 && mod[0] <= num_l && mod[1] <= num_l)
	{
		ft_putchar(' ');
		pf_putnbr(num);
		return (num_l + 1);
	}
	if (mod[1] >= mod[0])
		return (dec_mod2_greater_print(plus, mod[1], num, num_l));
	else if (space_type != '-')
		return (dec_dot_space_print(plus, mod, num_l, num));
	return (dec_dot_lft_adj_print(plus, mod, flags, num));
}

int	pf_dot_int_hex_lower(long long n, char *flags, int mod[2])
{
	char	space_type;
	int		count;
	int		num;
	int		num_l;
	int		precision;

	num = (int)n;
	count = 0;
	num_l = (num >= 0) ? get_num_length(num, HEXA) : (sizeof(int) * 8) / 4;
	precision = (ft_strrchr(flags, '#') && num != 0) ? 2 : 0;
	space_type = (ft_strrchr(flags, '-')) ? '-' : '0';
	if (!mod[1] && num == 0)
		return (dt_num_zero_case(space_type, mod[0], 0));
	if (space_type != '-')
	{
		count += non_dec_dot_spaceprint(num_l, mod, HEXA, precision);
		ft_putbase(num, HEXA, sizeof(int) * 8, 0);
		return (count + num_l);
	}
	count += non_dec_dot_leftadj_print1(num_l, mod[1], HEXA, precision);
	ft_putbase(num, HEXA, sizeof(int) * 8, 0);
	return (non_dec_dot_leftadj_print2(num, mod[0], count) + num_l);
}

int	pf_dot_int_hex_upper(long long n, char *flags, int mod[2])
{
	char	space_type;
	int		count;
	int		num;
	int		num_l;
	int		precision;

	num = (int)n;
	count = 0;
	num_l = (num >= 0) ? get_num_length(num, HEXA) : (sizeof(int) * 8) / 4;
	precision = (ft_strrchr(flags, '#') && num != 0) ? 2 : 0;
	space_type = (ft_strrchr(flags, '-')) ? '-' : '0';
	if (!mod[1] && num == 0 && !(ft_strrchr(flags, '#')))
		return (dt_num_zero_case(space_type, mod[0], 0));
	if (space_type != '-')
	{
		count += non_dec_dot_spaceprint_uc(num_l, mod, HEXA, precision);
		ft_putbase(num, HEXA, sizeof(int) * 8, 1);
		return (count + num_l);
	}
	count += non_dec_dot_leftadj_print1_uc(num_l, mod[1], HEXA, precision);
	ft_putbase(num, HEXA, sizeof(int) * 8, 1);
	return (non_dec_dot_leftadj_print2(num_l, mod[0], count) + num_l);
}

int	pf_dot_int_octal(long long n, char *flags, int mod[2])
{
	char	space_type;
	int		count;
	int		num;
	int		num_l;
	int		precision;

	num = (int)n;
	count = 0;
	num_l = (num >= 0) ? get_num_length(num, OCTAL) : (sizeof(int) * 8) / 3 + 1;
	space_type = (ft_strrchr(flags, '-')) ? '-' : '0';
	precision = (ft_strrchr(flags, '#') && num != 0 && mod[1] <= num_l) ? 1 : 0;
	if (!mod[1] && num == 0 && !(ft_strrchr(flags, '#')))
		return (dt_num_zero_case(space_type, mod[0], 0));
	if (space_type != '-')
	{
		count += non_dec_dot_spaceprint(num_l, mod, OCTAL, precision);
		ft_putbase(num, OCTAL, sizeof(int) * 8, 0);
		return (count + num_l);
	}
	count += non_dec_dot_leftadj_print1(num_l, mod[1], OCTAL, precision);
	ft_putbase(num, OCTAL, sizeof(int) * 8, 0);
	return (non_dec_dot_leftadj_print2(num_l, mod[0], count) + num_l);
}

int	pf_dot_int_binary(long long n, char *flags, int mod[2])
{
	char	space_type;
	int		count;
	int		num_l;
	int		num;

	num = (int)n;
	count = 0;
	num_l = (num >= 0) ? get_num_length(num, BINARY) : sizeof(long long) * 8;
	space_type = (ft_strrchr(flags, '-')) ? '-' : '0';
	if (mod[1] == 0 && num == 0)
		return (dt_num_zero_case(space_type, mod[0], 0));
	if (space_type != '-')
	{
		count += non_dec_dot_spaceprint(num_l, mod, BINARY, 0);
		ft_putbase(num, BINARY, sizeof(long long) * 8, 0);
		return (count + num_l);
	}
	count += non_dec_dot_leftadj_print1(num_l, mod[1], BINARY, 0);
	ft_putbase(num, BINARY, sizeof(long long) * 8, 0);
	return (non_dec_dot_leftadj_print2(num_l, mod[0], count) + num_l);
}
