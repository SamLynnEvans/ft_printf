/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_chars.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slynn-ev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/16 19:25:15 by slynn-ev          #+#    #+#             */
/*   Updated: 2018/01/17 22:20:16 by slynn-ev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void ft_putstrn(char *str, int n)
{
	int	i;

	i = 0;
	while (str[i] && i < n)
		ft_putchar(str[i++]);
}

int	dt_print_str(char *str, char *flags, int mod[2])
{
	char	space_type;
	int		o_mod;
	int		len;
	
	len = ft_strlen(str);
	len = (mod[1] < len) ? mod[1] : len;
	o_mod = mod[0];
	space_type = get_space_type(flags);	
	if (space_type != '-')
		while (mod[0]-- > len)
			ft_putchar(' ');
	ft_putstrn(str, len);
	if (space_type == '-')
		while (mod[0]-- > len)
			ft_putchar(' ');
	return ((o_mod > len) ? o_mod : len);
}

int	print_pointer(long long *p, char *flags, int mod)
{
	int		num_length;
	long	address;
	char	space_type;
	int		o_mod;
	
	o_mod = mod;
	address = (long)p;
	num_length = get_num_length(address, HEXA);
	space_type = get_space_type(flags);
	if (space_type != '-')
		while (mod-- > num_length + 2)
			ft_putchar(' ');
	print_precision(HEXA, 0);
	ft_putbase(address, HEXA, sizeof(long) * 8, 0);
	if (space_type == '-')
		while (mod-- > num_length + 2)
			ft_putchar(' ');
	return ((o_mod > num_length + 2) ? o_mod : num_length + 2);
}

int	print_string(char *str, char *flags, int mod)
{
	char	space_type;
	int		len;
	int		null;

	null = (str == NULL) ? 1 : 0;
	if (null)
		str = ft_strdup("(null)");
	len = ft_strlen(str);
	space_type = get_space_type(flags);	
	if (space_type != '-')
		print_spaces(mod - len);
	ft_putstr(str);
	if (space_type == '-')
		print_spaces(mod - len);
	if (null)
		free(str);
	return ((mod > len) ? mod : len);
}

int	print_char(char c, char *flags, int mod)
{
	char	space_type;

	space_type = get_space_type(flags);	
	if (space_type != '-')
		print_spaces(mod - len);
	ft_putchar(c);
	if (space_type == '-')
		print_spaces(mod - len);
	return ((mod > 1) ? mod : 1);
}
