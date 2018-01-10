/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_int_unsigned.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slynn-ev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 17:10:28 by slynn-ev          #+#    #+#             */
/*   Updated: 2018/01/10 16:12:49 by slynn-ev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	pf_int_unsigned(long long n, char *flags, int mod)
{
	unsigned int	num;
	char			space_type;
	int				plus;
	int				num_length;
	
	num = (unsigned int)n;	
	num_length = get_unum_length(num, DECIMAL);
	plus = 0;
	space_type = get_space_type(flags);
	if (space_type == ' ' || !(space_type))
		dec_print_spaces(mod - num_length, space_type, plus);	
	else if (space_type == '0')
		dec_print_zeroes(mod - num_length, plus);
	pf_putnbr(num);
	if (space_type == '-')
		print_left_adj(mod - num_length);
}

void	pf_ll_unsigned(long long n, char *flags, int mod)
{
	unsigned long long	num;
	char				space_type;
	int					plus;
	int					num_length;
	
	num = (uint64_t)n;	
	num_length = get_unum_length(num, DECIMAL);
	plus = 0;
	space_type = get_space_type(flags);
	if (space_type == ' ' || !(space_type))
		dec_print_spaces(mod - num_length, space_type, plus);	
	else if (space_type == '0')
		dec_print_zeroes(mod - num_length, plus);
	pf_putnbr_unsigned(num);
	if (space_type == '-')
		print_left_adj(mod - num_length);
}

void	pf_short_unsigned(long long n, char *flags, int mod)
{
	unsigned short		num;
	char				space_type;
	int					plus;
	int					num_length;
	
	num = (unsigned short)n;	
	num_length = get_unum_length(num, DECIMAL);
	plus = 0;
	space_type = get_space_type(flags);
	if (space_type == ' ' || !(space_type))
		dec_print_spaces(mod - num_length, space_type, plus);	
	else if (space_type == '0')
		dec_print_zeroes(mod - num_length, plus);
	pf_putnbr_unsigned(num);
	if (space_type == '-')
		print_left_adj(mod - num_length);
}

void	pf_shortshort_unsigned(long long n, char *flags, int mod)
{
	unsigned char	num;
	char			space_type;
	int				plus;
	int				num_length;
	
	num = (unsigned char)n;	
	num_length = get_unum_length(num, DECIMAL);
	plus = 0;
	space_type = get_space_type(flags);
	if (space_type == ' ' || !(space_type))
		dec_print_spaces(mod - num_length, space_type, plus);	
	else if (space_type == '0')
		dec_print_zeroes(mod - num_length, plus);
	pf_putnbr_unsigned(num);
	if (space_type == '-')
		print_left_adj(mod - num_length);
}
