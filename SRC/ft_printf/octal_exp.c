/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   octal_exp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slynn-ev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/18 23:47:24 by slynn-ev          #+#    #+#             */
/*   Updated: 2018/01/19 00:40:36 by slynn-ev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include <stdio.h>

typedef union 	u_data
{

}				t_data;				

int printer(long long num, int int_size)
{
	unsigned int 		d;
	unsigned short 		s;
	unsigned long long 	l;
	unsigned char		c;
	int					i;
	char 			str[100];
	char			tmp;
	int				j;

	j = 0;
	i = 0;
	if (int_size == 'd')
	{
		d = (unsigned int)num;
		while (d)
		{
			str[i++] = d % 8 + '0';
			d /= 8;			
		}
		str[i] = '\0';
	}
	if (int_size == 's')
	{
		 s = (unsigned short)num;
		while (s)
		{
			str[i++] = s % 8 + '0';
			s /= 8;			
		}
		str[i] = '\0';	
	}
	if (int_size == 'c')
	{
		 c = (unsigned char)num;
		while (c)
		{
			str[i++] = c % 8 + '0';
			c /= 8;			
		}
		str[i] = '\0';
	}
	if (int_size == 'l')
	{
		l = (unsigned long)num;
		while (l)
		{
			str[i++] = l % 8 + '0';
			l /= 8;			
		}
		str[i] = '\0';
	}
	i--;
	while (j < i)
	{
		tmp = str[j];
		str[j++] = str[i];
		str[i--] = tmp;
	}
	printf("%s\n", str);
	return (1);
}

int main()
{
	printer(ULLONG_MAX, 'l');
	printf("%llo\n", ULLONG_MAX);
	printer(UCHAR_MAX, 'c');
	printf("%hho\n", UCHAR_MAX);
}
