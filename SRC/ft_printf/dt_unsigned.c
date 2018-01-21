/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dt_unsigned.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slynn-ev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 23:39:23 by slynn-ev          #+#    #+#             */
/*   Updated: 2018/01/21 21:59:07 by slynn-ev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static unsigned long long	ushorten_num(long long n, int size)
{
	if (size == sizeof(int))
		return ((unsigned int)n);
	if (size == sizeof(char))
		return ((unsigned char)n);
	if (size == sizeof(short))
		return ((unsigned short)n);
	return (0);
}

int	pf_unsigned(unsigned long long num, char *flags, int mod[2], int dot)
{
	char				space_type;
	int					num_l;
	int					size;
	int					count;
	
	size = get_int_size(flags);
	if (size != sizeof(long long))
		num = ushorten_num(num, size);
	num_l = (mod[1] == 0 && num == 0 && dot) ? 0 : get_unum_length(num, DECIMAL);
	count = num_l;
	space_type = bit_space_type(flags);
	if (!(space_type & MINUS) && (dot || !(space_type & ZERO)))
		count += dot_spaces(num_l, mod, 0, 10);
	if (dot)
		count += print_zeroes(mod[1] - num_l);
	else if (space_type & ZERO)
		count += print_zeroes(mod[0] - num_l);
	if (num == 0 && (mod[1] != 0 || !dot))
		ft_putchar('0');
	else if (mod[1] != 0 || num != 0)
		rc_putbase(num, DECIMAL);
	if (space_type & MINUS)
		count += print_spaces(mod[0] - count);
	return (count);
}

int	pf_ndt_unsigned(unsigned long long num, char *flags, int mod)
{
	char				space_type;
	int					extra;
	int					num_length;
	int					size;

	size = get_int_size(flags);
	if (size != sizeof(long long))
		num = ushorten_num(num, size);
	num_length = get_unum_length(num, DECIMAL);
	extra = mod - num_length;
	space_type = get_space_type(flags);
	if (space_type == ' ' || !(space_type))
		while (extra-- > 0)
			ft_putchar(' ');
	else if (space_type == '0')
		while (extra-- > 0)
			ft_putchar('0');
	if (num == 0)
		ft_putchar('0');
	else
		rc_putbase(num, DECIMAL);
	if (space_type == '-')
		print_spaces(mod - num_length);
	return (mod > num_length) ? mod : num_length;
}

int	pf_dot_unsigned_decimal(long long n, char *flags, int mod[2])
{
	char			space_type;
	int				num_l;
	unsigned int	num;

	num = (unsigned int)n;
	num_l = get_unum_length(num, DECIMAL);
	space_type = get_space_type(flags);
	if (mod[1] == 0 && num == 0)
		return (dt_num_zero_case(space_type, mod[0], 0));
	if (space_type == ' ' && mod[0] <= num_l && mod[1] <= num_l)
	{
		ft_putchar(' ');
		pf_putnbr_unsigned(num);
		return (num_l + 1);
	}
	if (mod[1] >= mod[0])
		return (dec_mod2_greater_print_us(mod[1], num, num_l));
	else if (space_type != '-')
		return (dec_dot_space_print_us(mod, num, num_l));
	else
		return (dec_dot_lft_adj_print_us(mod, num, num_l));
}

int	pf_dot_unsigned_long(long long n, char *flags, int mod[2])
{
	char				space_type;
	int					num_l;
	unsigned long long	num;

	num = (unsigned long long)n;
	num_l = get_unum_length(num, DECIMAL);
	space_type = get_space_type(flags);
	if (mod[1] == 0 && num == 0)
		return (dt_num_zero_case(space_type, mod[0], 0));
	if (space_type == ' ' && mod[0] <= num_l && mod[1] <= num_l)
	{
		ft_putchar(' ');
		pf_putnbr_unsigned(num);
		return (num_l + 1);
	}
	if (mod[1] >= mod[0])
		return (dec_mod2_greater_print_us(mod[1], num, num_l));
	else if (space_type != '-')
		return (dec_dot_space_print_us(mod, num, num_l));
	else
		return (dec_dot_lft_adj_print_us(mod, num, num_l));
}

int	pf_dot_unsigned_short(long long n, char *flags, int mod[2])
{
	char			space_type;
	int				num_l;
	unsigned short	num;

	num = (unsigned short)n;
	num_l = get_unum_length(num, DECIMAL);
	space_type = get_space_type(flags);
	if (mod[1] == 0 && num == 0)
		return (dt_num_zero_case(space_type, mod[0], 0));
	if (space_type == ' ' && mod[0] <= num_l && mod[1] <= num_l)
	{
		ft_putchar(' ');
		pf_putnbr_unsigned(num);
		return (num_l + 1);
	}
	if (mod[1] >= mod[0])
		return (dec_mod2_greater_print_us(mod[1], num, num_l));
	else if (space_type != '-')
		return (dec_dot_space_print_us(mod, num, num_l));
	else
		return (dec_dot_lft_adj_print_us(mod, num, num_l));
}

int	pf_dot_unsigned_hh(long long n, char *flags, int mod[2])
{
	char			space_type;
	int				num_l;
	unsigned char	num;

	num = (unsigned char)n;
	num_l = get_unum_length(num, DECIMAL);
	space_type = get_space_type(flags);
	if (mod[1] == 0 && num == 0)
		return (dt_num_zero_case(space_type, mod[0], 0));
	if (space_type == ' ' && mod[0] <= num_l && mod[1] <= num_l)
	{
		ft_putchar(' ');
		pf_putnbr_unsigned(num);
		return (num_l + 1);
	}
	if (mod[1] >= mod[0])
		return (dec_mod2_greater_print_us(mod[1], num, num_l));
	else if (space_type != '-')
		return (dec_dot_space_print_us(mod, num, num_l));
	else
		return (dec_dot_lft_adj_print_us(mod, num, num_l));
}
