/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dt_unsigned.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slynn-ev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 23:39:23 by slynn-ev          #+#    #+#             */
/*   Updated: 2018/01/16 15:39:53 by slynn-ev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	pf_dot_unsigned_decimal(long long n, char *flags)
{
	int				mod[2];
	char			space_type;
	int				num_l;
	unsigned long long	num;

	num  = (unsigned long long)n;
	num_l = get_unum_length(num, DECIMAL);
	get_mod_values(flags, &mod[0], &mod[1]);
	space_type = get_space_type(flags);
	if (mod[1] == 0 && num == 0)
		return (dt_num_zero_case(space_type, flags, 0));
	if (space_type == ' ' && mod[0] <= num_l && mod[1] <= num_l)
	{
		ft_putchar(' ');
		pf_putnbr_unsigned(num);
		return (num_l + 1);
	}
	if (mod[1] >= mod[0])
		return (dec_mod2_greater_print_us(mod[1], num));
	else if (space_type != '-')
		return (dec_dot_space_print_us(mod[0], mod[1], num));
	else
		return (dec_dot_lft_adj_print_us(mod[0], mod[1], num));
}

int	pf_dot_unsigned_short_decimal(long long n, char *flags)
{
	int				mod[2];
	char			space_type;
	int				num_l;
	unsigned short	num;
	
	num  = (unsigned short)n;
	num_l = get_unum_length(num, DECIMAL);
	get_mod_values(flags, &mod[0], &mod[1]);
	space_type = get_space_type(flags);
	if (mod[1] == 0 && num == 0)
		return (dt_num_zero_case(space_type, flags, 0));
	if (space_type == ' ' && mod[0] <= num_l && mod[1] <= num_l)
	{
		ft_putchar(' ');
		pf_putnbr_unsigned(num);
		return (num_l + 1);
	}
	if (mod[1] >= mod[0])
		return (dec_mod2_greater_print_us(mod[1], num));
	else if (space_type != '-')
		return (dec_dot_space_print_us(mod[0], mod[1], num));
	else
		return (dec_dot_lft_adj_print_us(mod[0], mod[1], num));
}

int	pf_dot_unsigned_hh_decimal(long long n, char *flags)
{
	int				mod[2];
	char			space_type;
	int				num_l;
	unsigned char	num;
	
	num  = (unsigned char)n;
	num_l = get_unum_length(num, DECIMAL);
	get_mod_values(flags, &mod[0], &mod[1]);
	space_type = get_space_type(flags);
	if (mod[1] == 0 && num == 0)
		return (dt_num_zero_case(space_type, flags, 0));
	if (space_type == ' ' && mod[0] <= num_l && mod[1] <= num_l)
	{
		ft_putchar(' ');
		pf_putnbr_unsigned(num);
		return (num_l + 1);
	}
	if (mod[1] >= mod[0])
		return (dec_mod2_greater_print_us(mod[1], num));
	else if (space_type != '-')
		return (dec_dot_space_print_us(mod[0], mod[1], num));
	else
		return (dec_dot_lft_adj_print_us(mod[0], mod[1], num));
}