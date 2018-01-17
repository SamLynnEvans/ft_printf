/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dt_ll_printers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slynn-ev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 20:50:31 by slynn-ev          #+#    #+#             */
/*   Updated: 2018/01/17 17:15:00 by slynn-ev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	pf_dot_ll_hex_lower(long long num, char *flags, int mod[2])
{
	char	space_type;
	int		count;
	int		num_l;
	int		precision;

	count = 0;
	precision = (ft_strrchr(flags, '#') && num != 0) ? 2 : 0;
	num_l = (num >= 0) ? get_num_length(num, HEXA) : (sizeof(int) * 8) / 4;
	space_type = (ft_strrchr(flags, '-')) ? '-' : '0';
	if (mod[1] == 0 && num == 0)
		return (dt_num_zero_case(space_type, mod[0], 0));
	if (space_type != '-')
	{
		count += non_dec_dot_spaceprint(num_l, mod, HEXA, precision);
		ft_putbase(num, HEXA, sizeof(long long) * 8, 0);
		return (count + num_l);
	}
	count += non_dec_dot_leftadj_print1(num_l, mod[1], HEXA, precision);
	ft_putbase(num, HEXA, sizeof(long long) * 8, 0);
	return (non_dec_dot_leftadj_print2(num_l, mod[0], count) + num_l);
}

int	pf_dot_ll_hex_upper(long long num, char *flags, int mod[2])
{
	char	space_type;
	int		count;
	int		precision;
	int		num_l;

	count = 0;
	precision = (ft_strrchr(flags, '#') && num != 0) ? 2 : 0;
	num_l = (num >= 0) ? get_num_length(num, HEXA) : (sizeof(long long) * 8) / 4;
	space_type = (ft_strrchr(flags, '-')) ? '-' : '0';
	if (mod[1] == 0 && num == 0)
		return (dt_num_zero_case(space_type, mod[0], 0));
	if (space_type != '-')
	{
		count += non_dec_dot_spaceprint_uc(num_l, mod, HEXA, precision);
		ft_putbase(num, HEXA, sizeof(long long) * 8, 1);
		return (count + num_l);
	}
	count += non_dec_dot_leftadj_print1_uc(num_l, mod[1], HEXA, precision);
	ft_putbase(num, HEXA, sizeof(long long) * 8, 1);
	return (non_dec_dot_leftadj_print2(num_l, mod[0], count) + num_l);
}

int	pf_dot_ll_octal(long long num, char *flags, int mod[2])
{
	char	space_type;
	int		count;
	int		num_l;
	int		precision;

	count = 0;
	precision = (ft_strrchr(flags, '#') && num != 0) ? 1 : 0;
	num_l = (num >= 0) ? get_num_length(num, OCTAL) : (sizeof(long long) * 8) / 3 + 1;
	space_type = (ft_strrchr(flags, '-')) ? '-' : '0';
	if (mod[1] == 0 && num == 0 && !(ft_strrchr(flags, '#')))
		return (dt_num_zero_case(space_type, mod[0], 0));
	if (space_type != '-')
	{
		count += non_dec_dot_spaceprint(num_l, mod, OCTAL, precision);
		ft_putbase(num, OCTAL, sizeof(long long) * 8, 0);
		return (count + num_l);
	}
	count += non_dec_dot_leftadj_print1(num_l, mod[1], HEXA, precision);
	ft_putbase(num, OCTAL, sizeof(long long) * 8, 0);
	return (non_dec_dot_leftadj_print2(num_l, mod[0], count) + num_l);
}
