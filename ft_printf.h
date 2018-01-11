/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slynn-ev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/05 12:43:22 by slynn-ev          #+#    #+#             */
/*   Updated: 2018/01/11 14:12:47 by slynn-ev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# define STAR -1
# define FLAG_CHARACTERS str[i] == '.' || str[i] == '#' || str[i] == '+' || str[i] == '-' || str[i] == ' ' || str[i] == '0' || str[i] == 'j' || str[i] == 'l' || str[i] == 'z' || str[i] == 'h' || str[i] == '*' || (str[i] <= '9' && str[i] >= '0')
# define DECIMAL 10
# define HEXA 16
# define OCTAL 8

#include <stdlib.h>
#include <stdarg.h>
#include <stdio.h>
#include "libft.h"

typedef int		(*p_num)(long long, char *, int);
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

char	get_space_type(char *flags);
int	put_sign(int plus);
int		get_num_length(long long num, int base);
int		get_unum_length(unsigned long long num, int base);
int		print_precision(int base, int caps);
int	dec_print_spaces(int spaces, char is_space, int plus);
int	dec_print_zeroes(int zeroes, int plus);
void	ft_pf_percent(char *str, char *flags);
void	ft_pf_string(char *str, char *flags);
int	ft_printf(char *str, ...);
void	ft_putbase(long long num, int base, int filler, int caps);
int	nondec_print_spaces(int spaces, int base, int precision, int caps);
int	nondec_print_zeroes(int zeroes, int base, int precision, int caps);
int	pf_int_decimal(long long num, char *flags, int mod);
int	pf_int_hex_lower(long long num, char *flags, int mod);
int	pf_int_hex_upper(long long num, char *flags, int mod);
int	pf_int_octal(long long num, char *flags, int mod);
int	pf_int_unsigned(long long num, char *flags, int mod);
int	pf_l_decimal(long long num, char *flags, int mod);
int	pf_l_hex_lower(long long num, char *flags, int mod);
int	pf_l_hex_upper(long long num, char *flags, int mod);
int	pf_l_octal(long long num, char *flags, int mod);
int	pf_ll_decimal(long long num, char *flags, int mod);
int	pf_ll_hex_lower(long long num, char *flags, int mod);
int	pf_ll_hex_lower(long long num, char *flags, int mod);
int	pf_ll_hex_upper(long long num, char *flags, int mod);
int	pf_ll_octal(long long num, char *flags, int mod);
int	pf_ll_unsigned(long long n, char *flags, int mod);
int	pf_short_decimal(long long n, char *flags, int mod);
int	pf_short_decimal(long long n, char *flags, int mod);
int	pf_short_hex_lower(long long n, char *flags, int mod);
int	pf_short_hex_lower(long long n, char *flags, int mod);
int	pf_short_hex_upper(long long n, char *flags, int mod);
int	pf_short_octal(long long n, char *flags, int mod);
int	pf_short_unsigned(long long n, char *flags, int mod);
int	pf_hh_decimal(long long n, char *flags, int mod);
int	pf_hh_hex_lower(long long n, char *flags, int mod);
int	pf_hh_hex_upper(long long n, char *flags, int mod);
int	pf_hh_octal(long long n, char *flags, int mod);
int	pf_hh_unsigned(long long num, char *flags, int mod);
int	print_number(va_list ap, char *flags, char *c, int mod);
void	pf_putchar(char *str, char *flags);
void	pf_putnbr(long long n);
void	pf_putnbr_unsigned(unsigned long long n);
void	pf_putstr(char *str, char *flags);
void	print_chars(char *prnt_str, char *flags, char *c, int star);
void	print_left_adj(int spaces);

#endif
