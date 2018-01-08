/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slynn-ev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 10:09:03 by slynn-ev          #+#    #+#             */
/*   Updated: 2018/01/08 18:30:12 by slynn-ev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long long	ft_long_atoi(const char *s)
{
	long long	p;
	int			sign;

	sign = 1;
	p = 0;
	while (*s == '\t' || *s == ' ' || *s == '\n' || *s == '\f' || *s == '\r' ||
	*s == '\v')
		s++;
	if (*s == '-')
	{
		sign = -1;
		s++;
	}
	else if (*s == '+')
		s++;
	while (*s <= '9' && *s >= '0')
	{
		p = p * 10 + *s - '0';
		s++;
	}
	return (p * sign);
}
