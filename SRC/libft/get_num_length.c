/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_num_length.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slynn-ev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/10 14:21:05 by slynn-ev          #+#    #+#             */
/*   Updated: 2018/01/18 14:24:57 by slynn-ev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	get_num_length(long long num, int base)
{
	int count;

	count = 0;
	while (num)
	{
		num /= base;
		count++;
	}
	return ((count == 0) ? 1 : count);
}

int	get_unum_length(unsigned long long num, int base)
{
	int count;

	count = 0;
	while (num)
	{
		num /= base;
		count++;
	}
	return ((count == 0) ? 1 : count);
}
