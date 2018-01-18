/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_int_unsigned.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slynn-ev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 17:10:28 by slynn-ev          #+#    #+#             */
/*   Updated: 2018/01/17 22:33:34 by slynn-ev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	pf_int_unsigned(long long n, char *flags, int mod)
{
	unsigned int	num;
	char			space_type;
	int				extra;
	int				num_length;
	
	num = (unsigned int)n;	
	num_length = get_unum_length(num, DECIMAL);
	extra = mod - num_length;
	space_type = get_space_type(flags);
	if (space_type == ' ' || !(space_type))
		while (extra-- > 0)
		   ft_putchar(' ');	
	else if (space_type == '0')
		while (extra-- > 0)
		   ft_putchar('0');	
	pf_putnbr(num);
	if (space_type == '-')
		print_spaces(mod - num_length);
	return (mod > num_length) ? mod : num_length;
}

int	pf_long_unsigned(long long n, char *flags, int mod)
{
	unsigned long		num;
	char				space_type;
	int					extra;
	int					num_length;
	
	num = (long)n;	
	num_length = get_unum_length(num, DECIMAL);
	extra = mod - num_length;
	space_type = get_space_type(flags);
	if (space_type == ' ' || !(space_type))
		while (extra-- > 0)
		   ft_putchar(' ');	
	else if (space_type == '0')
		while (extra-- > 0)
		   ft_putchar('0');	
	pf_putnbr_unsigned(num);
	if (space_type == '-')
		print_spaces(mod - num_length);
	return (mod > num_length) ? mod : num_length;
}

int	pf_ll_unsigned(long long n, char *flags, int mod)
{
	unsigned long long	num;
	char				space_type;
	int					extra;
	int					num_length;
	
	num = (uint64_t)n;	
	num_length = get_unum_length(num, DECIMAL);
	extra = mod - num_length;
	space_type = get_space_type(flags);
	if (space_type == ' ' || !(space_type))
		while (extra-- > 0)
		   ft_putchar(' ');	
	else if (space_type == '0')
		while (extra-- > 0)
		   ft_putchar('0');	
	pf_putnbr_unsigned(num);
	if (space_type == '-')
		print_spaces(mod - num_length);
	return (mod > num_length) ? mod : num_length;
}

int	pf_short_unsigned(long long n, char *flags, int mod)
{
	unsigned short	num;
	char			space_type;
	int				num_length;
	int				extra;

	num = (unsigned short)n;	
	num_length = get_unum_length(num, DECIMAL);
	extra = mod - num_length;
	space_type = get_space_type(flags);
	if (space_type == ' ' || !(space_type))
		while (extra-- > 0)
		   ft_putchar(' ');	
	else if (space_type == '0')
		while (extra-- > 0)
		   ft_putchar('0');	
	pf_putnbr_unsigned(num);
	if (space_type == '-')
		print_spaces(mod - num_length);
	return (mod > num_length) ? mod : num_length;
}

int	pf_hh_unsigned(long long n, char *flags, int mod)
{
	unsigned char	num;
	char			space_type;
	int				extra;
	int				num_length;
	
	num = (unsigned char)n;	
	num_length = get_unum_length(num, DECIMAL);
	extra = mod - num_length;
	space_type = get_space_type(flags);
	if (space_type == ' ' || !(space_type))
		while (extra-- > 0)
		   ft_putchar(' ');	
	else if (space_type == '0')
		while (extra-- > 0)
		   ft_putchar('0');	
	pf_putnbr_unsigned(num);
	if (space_type == '-')
		print_spaces(mod - num_length);
	return (mod > num_length) ? mod : num_length;
}
