/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   num_flags.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slynn-ev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/08 17:37:49 by slynn-ev          #+#    #+#             */
/*   Updated: 2018/01/22 14:02:33 by slynn-ev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	dot_spaces(int num_l, int mod[2], int precision, int base)
{
	int	count;
	int	min;

	min = (mod[1] > num_l) ? mod[1] : num_l;
	count = 0;
	if (base == DECIMAL && precision)
		precision = 1;
	while (mod[0] > min + precision)
	{
		ft_putchar(' ');
		mod[0]--;
		count++;
	}
	return (count);
}

int	fs(char space_type, int count, int **mod)
{
	if (space_type & SPACE)
	{
		ft_putchar(' ');
		if (*mod[1] > count)
			*mod[0] = *mod[0] - 1;
		return (1);
	}
	return (0);
}
