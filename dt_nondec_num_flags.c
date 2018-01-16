/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dt_nondec_num_flags.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slynn-ev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 20:34:07 by slynn-ev          #+#    #+#             */
/*   Updated: 2018/01/16 15:21:16 by slynn-ev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	non_dec_dot_leftadj_print1(int num_l, char *flags, int base, int precision)
{
	int		mod;
	int		mod2;
	int		count;
	
	count = 0;
	get_mod_values(flags, &mod, &mod2);
	if (precision)
		count += print_precision(base, 0);
	while (mod2-- > num_l)
	{
		count++;
		ft_putchar ('0');
	}
	return (count);
}

int	non_dec_dot_leftadj_print1_uc(int num_l, char *flags, int base, int precision)
{
	int		mod;
	int		mod2;
	int		count;
	
	count = 0;
	get_mod_values(flags, &mod, &mod2);
	if (precision)
		count += print_precision(base, 1);
	while (mod2-- > num_l)
	{
		count++;
		ft_putchar ('0');
	}
	return (count);
}

int	non_dec_dot_leftadj_print2(int num_l, char *flags, int count)
{
	int		mod;
	int		mod2;

	get_mod_values(flags, &mod, &mod2);
	while (mod > num_l + count)
	{
		ft_putchar(' ');
		count++;	
	}
	return (count);
}	

int	non_dec_dot_spaceprint(int num_l, char *flags, int base, int precision)
{
	int		mod;
	int		mod2;
	int		count;
	
	count = 0;
	get_mod_values(flags, &mod, &mod2);
	while (mod > mod2 + precision && mod > num_l + precision)
	{
		ft_putchar(' ');
		count++;
		mod--;
	}
	if (precision)
		count += print_precision(base, 0);
	while (mod2-- > num_l)
	{
		count++;
		ft_putchar ('0');
	}
	return (count);
}

int	non_dec_dot_spaceprint_uc(int num_l, char *flags, int base, int precision)
{
	int		mod;
	int		mod2;
	int		count;
	
	count = 0;
	get_mod_values(flags, &mod, &mod2);
	while (mod > mod2 + precision && mod > num_l + precision)
	{
		ft_putchar(' ');
		count++;
		mod--;
	}
	if (precision)
		count += print_precision(base, 1);
	while (mod2-- > num_l)
	{
		count++;
		ft_putchar ('0');
	}
	return (count);
}
