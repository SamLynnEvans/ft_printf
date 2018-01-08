/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_decimal.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slynn-ev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/05 15:54:38 by slynn-ev          #+#    #+#             */
/*   Updated: 2018/01/08 18:45:03 by slynn-ev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_pf_decimal(long long num, char *flags, int mod)
{
	int		n;
	char	space_type;
	int		plus;

	n = (int)num;
	space_type = 0;
	plus = 0;
	if (*flags)
		space_type = get_space_type(flags, &plus);
	if (space_type == ' ' || !(space_type))
		print_spaces(num, mod, space_type, plus, DECIMAL);	
	else if (space_type == '0')
		print_zeroes(num, mod, plus, DECIMAL);
	else if (space_type == '-' && plus && num >= 0)
	{
		ft_putchar('+');
		mod--;
	}
	ft_putnbr(num);
	if (space_type == '-')
		print_left_adj(num, mod, DECIMAL);
}

void	ft_pf_hex_lower(long long num, char *flags, int mod)
{
	int		n;
	char	space_type;
	int		plus;

	n = (int)num;
	plus = 0;
	space_type = get_space_type(flags, &plus);
	if (space_type == ' ' || !(space_type))
		print_spaces(num, mod, space_type, plus, HEXA);	
	else if (space_type == '0')
		print_zeroes(num, mod, plus, HEXA);
	else if (space_type == '-' && plus)
	{
		ft_putchar('+');
		mod--;
	}
	ft_putbase_lower(num, HEXA);
	if (space_type == '-')
		print_left_adj(num, mod, HEXA);
}
