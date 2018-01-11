/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dot_printer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slynn-ev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 17:05:55 by slynn-ev          #+#    #+#             */
/*   Updated: 2018/01/11 21:58:29 by slynn-ev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void get_mod_values(char *flags, int *mod, int *mod2)
{
	int	i;

	i = 0;
	while (flags[i] != '.')
	{
		if (flags[i] >= '0' && flags[i] <= '9')
		{
			*mod = ft_atoi(flags + i);
			while (flags[i] <= '9' && flags[i] >= '0')
				i++;
		}
		else
			i++;
	}
	while (flags[i])
	{
		if (flags[i] <= '9' && flags[i] >= '0')
		{
			*mod2 = ft_atoi(flags+ i);
			break ;
		}
		i++;
	}
}

int	pf_dot_int_decimal(long long num, char *flags, int mod)
{
	int		mod2;
	int		plus;
	char	space_type;
	int		num_length;

	mod = 0;
	mod2 = 0;
	plus = (ft_strrchr(flags, '+')) ? 1 : 0;
	plus = (num < 0) ? -1 : plus;
	num_length = get_num_length(num, DECIMAL);
	get_mod_values(flags, &mod, &mod2);
	space_type = (ft_strrchr(flags, '-')) ? '-' : '0';
	if (mod2 >= mod)
	{
		put_sign(plus);
		while (mod2-- > num_length)
			ft_putchar('0');
		pf_putnbr(num);
	}
	else if (mod > num_length && space_type != '-')
	{
		mod -= (plus == -1 || plus == 1) ? 1 : 0;
		while (mod	> mod2 && mod > num_length)
		{
			ft_putchar(' ');
			mod--;
		}
		put_sign(plus);	
		while (mod2-- > num_length)
			ft_putchar('0');
		pf_putnbr(num);
	}
	else if (mod > num_length && space_type == '-')
	{
		mod -= (plus == -1 || plus == 1) ? 1 : 0;
		put_sign(plus);	
		while (mod2-- > num_length)
			ft_putchar('0');
		pf_putnbr(num);
		while (mod	> mod2 && mod > num_length)
		{
			ft_putchar(' ');
			mod--;
		}
	}
	return (1);
}
