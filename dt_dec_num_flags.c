/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dot_printer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slynn-ev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 17:05:55 by slynn-ev          #+#    #+#             */
/*   Updated: 2018/01/16 15:20:53 by slynn-ev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	mod_is_zero(char *flags)
{
	int	i;
	int	found_number;
	int	num;

	found_number = 0;
	i = 0;
	num = 0;
	while (flags[i] && found_number != 1)
	{
		if (flags[i] == '.')
			while (flags[i])
			{
				if (flags[i] >= '0' && flags[i] <= '9')
				{
					num = ft_atoi(flags + i);
					found_number = 1;
				}
				i++;
			}
		i++;
	}
	return ((num == 0) ? 1 : 0);
}

int dt_num_zero_case(int space_type, char *flags, int plus)
{
	int	count;
	int	mod;
	int	mod2;

	get_mod_values(flags, &mod, &mod2);
	count = 0;
	if (plus != 1 && mod == 0 && space_type == ' ')
	{
		ft_putchar(' ');
		return (1);
	}
	if (space_type != '-') 
	while (mod > count + plus)
	{
		ft_putchar(' ');
		count++;	
	}
	count += put_sign(plus);
	if (space_type == '-') 
		while (mod > count++)
			ft_putchar(' ');
	return (count);
}

void get_mod_values(char *flags, int *mod, int *mod2)
{
	int	i;

	*mod = 0;
	*mod2 = 0;
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

int	dec_mod2_greater_print(int plus, int mod2, long long num)
{	
	int		count;
	int		num_length;

	count = 0;
	num_length = get_num_length(num, DECIMAL);
	count += put_sign(plus);
	while (mod2-- > num_length)
	{	
		count++;
		ft_putchar('0');
	}
	pf_putnbr(num);
	return (count + num_length);
}

int dec_dot_space_print(int plus, int mod, int mod2, long long num)	
{
	int		count;
	int		num_length;
	
	count = mod;
	num_length = get_num_length(num, DECIMAL);
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
	return (count);
}

int	dec_dot_lft_adj_print(int plus, int mod, int mod2, long long num)
{
	int	count;
	int	num_length;
	
	count = 0;
	num_length = get_num_length(num, DECIMAL);
	count += put_sign(plus);	
	while (mod2-- > num_length)
	{
		ft_putchar('0');
		count++;
	}
	pf_putnbr(num);
	while (mod	> num_length + count)
	{
		ft_putchar(' ');
		count++;
	}
	return (count + num_length);
}
