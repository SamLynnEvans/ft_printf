/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slynn-ev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/05 12:43:22 by slynn-ev          #+#    #+#             */
/*   Updated: 2018/01/08 18:45:21 by slynn-ev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# define STAR -1
# define FLAG_CHARACTERS str[i] == '#' || str[i] == '+' || str[i] == '-' || str[i] == ' ' || str[i] == '0' || str[i] == 'j' || str[i] == 'l'|| str[i] == 'z' || str[i] == 'h' || str[i] == '*' || (str[i] <= '9' && str[i] >= '0')
# define DECIMAL 10
# define HEXA 16
# define OCTAL 8

#include <stdlib.h>
#include <stdarg.h>
#include <stdio.h>
#include "libft.h"

typedef void	(*p_num)(long long, char *, int);
typedef void	(*p_chars)(char *, char *);

typedef struct	s_print_num
{
	char		*c;
	char		*int_size;
	p_num		print; 
}				t_print_num;

typedef struct	s_print_chars
{
	char		*c;
	p_chars		print; 
}				t_print_chars;


void	ft_pf_string(char *str, char *flags);
void	ft_pf_percent(char *str, char *flags);
void	ft_putbase_lower(long long num, int	base);
void	print_zeroes(long long num, int mod, int plus, int base);
void	ft_pf_hex_lower(long long num, char *flags, int mod);
char	get_space_type(char *flags, int *plus);
int		get_num_length(long long num, int base);
void	ft_pf_decimal(long long num, char *flags, int star);
void	ft_printf(char *str, ...);
void	print_number(int num, char *flags, char *c, int star);
void	print_spaces(long long num, int mod, char is_space, int plus, int base);
void	print_left_adj(long long num, int mod, int base);

#endif
