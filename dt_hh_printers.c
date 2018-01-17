/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dt_hh_printers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slynn-ev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 22:46:48 by slynn-ev          #+#    #+#             */
/*   Updated: 2018/01/16 15:43:14 by slynn-ev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	pf_dot_hh_decimal(long long n, char *flags)
{
	int		mod[2];
	int		plus;
	char	space_type;
	int		num_l;
	char	num;

	num  = (char)n;
	num_l = get_num_length(num, DECIMAL);
	plus = (ft_strrchr(flags, '+')) ? 1 : 0;
	plus = (num < 0) ? -1 : plus;
	get_mod_values(flags, &mod[0], &mod[1]);
	space_type = get_space_type(flags);
	if (mod[1] == 0 && num == 0)
		return (dt_num_zero_case(space_type, flags, 0));
	if (space_type == ' ' && plus == 0 && mod[0] <= num_l && mod[1] <= num_l)
	{
		ft_putchar(' ');
		pf_putnbr(num);
		return (num_l + 1);
	}
	if (mod[1] >= mod[0])
		return (dec_mod2_greater_print(plus, mod[1], num));
	else if (space_type != '-')
		return (dec_dot_space_print(plus, mod[0], mod[1], num));
	return (dec_dot_lft_adj_print(plus, mod[0], mod[1], num));
}

int	pf_dot_hh_hex_lower(long long n, char *flags)
{
	char	space_type;
	int		count;
	char		num;
	int		num_l;
	int		precision;

	num = (char)n;
	count = 0;
	num_l = (num >= 0) ? get_num_length(num, HEXA) : (sizeof(char) * 8) / 4;
	precision = (ft_strrchr(flags, '#') && num != 0) ? 2 : 0;
	space_type = (ft_strrchr(flags, '-')) ? '-' : '0';
	if (mod_is_zero(flags) && num == 0)
		return (dt_num_zero_case(space_type, flags, 0));
	if (space_type != '-')
	{
		count += non_dec_dot_spaceprint(num_l, flags, HEXA, precision);
		ft_putbase(num, HEXA, sizeof(char) * 8, 0);
		return (count + num_l);
	}
	count += non_dec_dot_leftadj_print1(num_l, flags, HEXA, precision);
	ft_putbase(num, HEXA, sizeof(char) * 8, 0);
	return (non_dec_dot_leftadj_print2(num, flags, count) + num_l);
}

int	pf_dot_hh_hex_upper(long long n, char *flags)
{
	char	space_type;
	int		count;
	char	num;
	int		num_l;
	int		precision;

	num = (char)n;
	count = 0;
	num_l = (num >= 0) ? get_num_length(num, HEXA) : (sizeof(char) * 8) / 4;
	precision = (ft_strrchr(flags, '#') && num != 0) ? 2 : 0;
	space_type = (ft_strrchr(flags, '-')) ? '-' : '0';
	if (mod_is_zero(flags) && num == 0)
		return (dt_num_zero_case(space_type, flags, 0));
	if (space_type != '-')
	{
		count += non_dec_dot_spaceprint_uc(num_l, flags, HEXA, precision);
		ft_putbase(num, HEXA, sizeof(char) * 8, 1);
		return (count + num_l);
	}
	count += non_dec_dot_leftadj_print1_uc(num_l, flags, HEXA, precision);
	ft_putbase(num, HEXA, sizeof(char) * 8, 1);
	return (non_dec_dot_leftadj_print2(num_l, flags, count) + num_l);
}

int	pf_dot_hh_octal(long long n, char *flags)
{
	char	space_type;
	int		count;
	char		num;
	int		num_l;
	int		precision;

	num = (char)n;
	count = 0;
	num_l = (num >= 0) ? get_num_length(num, OCTAL) : (sizeof(char) * 8) / 3 + 1;
	space_type = (ft_strrchr(flags, '-')) ? '-' : '0';
	precision = (ft_strrchr(flags, '#') && num != 0) ? 1 : 0;
	if (mod_is_zero(flags) && num == 0 && !(ft_strrchr(flags, '#')))
		return (dt_num_zero_case(space_type, flags, 0));
	if (space_type != '-')
	{
		count += non_dec_dot_spaceprint(num_l, flags, OCTAL, precision);
		ft_putbase(num, OCTAL, sizeof(char) * 8, 0);
		return (count + num_l);
	}
	count += non_dec_dot_leftadj_print1(num_l, flags, HEXA, precision);
	ft_putbase(num, OCTAL, sizeof(char) * 8, 0);
	return (non_dec_dot_leftadj_print2(num_l, flags, count) + num_l);
}
