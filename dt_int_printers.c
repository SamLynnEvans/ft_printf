/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dt_int_printers.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slynn-ev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 23:49:24 by slynn-ev          #+#    #+#             */
/*   Updated: 2018/01/12 00:09:18 by slynn-ev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	pf_dot_int_decimal(long long num, char *flags, int mod)
{
	int		mod2;
	int		plus;
	char	space_type;

	plus = (ft_strrchr(flags, '+')) ? 1 : 0;
	plus = (num < 0) ? -1 : plus;
	get_mod_values(flags, &mod, &mod2);
	space_type = (ft_strrchr(flags, '-')) ? '-' : '0';
	if (mod2 >= mod)
		return (dec_mod2_greater_print(plus, mod2, num));
	else if (space_type != '-')
		return (dec_dot_space_print(plus, mod, mod2, num));
	else
		return (dec_dot_lft_adj_print(plus, mod, mod2, num));
}
	
int	pf_dot_int_hex_lower(long long n, char *flags, int mod)
{
	int		mod2;
	int		plus;
	char	space_type;
	int		num_length;

	get_mod_values(flags, &mod, &mod2);
	space_type = (ft_strrchr(flags, '-')) ? '-' : '0';
	

}
int	pf_int_hex_lower(long long n, char *flags, int mod)
{
	int		num;
	char	space_type;
	int		precision;
	int		num_length;

	num = (int)n;
	num_length = get_num_length(num, HEXA);
	get_mod_values(flags, &mod, &mod2);
	precision = (ft_strrchr(flags, '#') && num != 0) ? 1 : 0;
	space_type = get_space_type(flags);
	if (num < 0)
		num_length = (sizeof(int) * 8) / 4;
	if (mod2 >= mod)
		return (dec_mod2_greater_print(plus, mod2, num));









	if (space_type == ' ' || !(space_type))
		num_length += nondec_print_spaces(mod - num_length, HEXA, precision, 0);	
	if (space_type == '0')
		num_length += nondec_print_zeroes(mod - num_length, HEXA, precision, 0);
	if (precision && space_type == '-')
		num_length += print_precision(HEXA, 0);
	ft_putbase(num, HEXA, sizeof(int) * 8, 0);
	if (space_type == '-')
		print_left_adj(mod - num_length);
	return (mod > num_length) ? mod : num_length;
}
