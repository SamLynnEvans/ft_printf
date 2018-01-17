/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slynn-ev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/05 12:43:22 by slynn-ev          #+#    #+#             */
/*   Updated: 2018/01/17 15:57:45 by slynn-ev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# define STAR -1
# define FLAG_CHARACTERS str[i] == '.' || str[i] == '#' || str[i] == '+' || str[i] == '-' || str[i] == ' ' || str[i] == '0' || str[i] == 'j' || str[i] == 'l' || str[i] == 'z' || str[i] == 'h' || str[i] == '*' || (str[i] <= '9' && str[i] >= '0')
# define DECIMAL 10
# define HEXA 16
# define OCTAL 8
#define RED     "\x1b[31m"
#define GREEN   "\x1b[32m"
#define YELLOW  "\x1b[33m"
#define BLUE    "\x1b[34m"
#define MAGENTA "\x1b[35m"
#define CYAN    "\x1b[36m"
#define RESET   "\x1b[0m"

#include <stdlib.h>
#include <stdarg.h>
#include <stdio.h>
#include "libft.h"

typedef int		(*p_num)(long long, char *, int);
typedef int		(*p_dt_num)(long long, char *, int *);
typedef void	(*p_chars)(char *, char *);

typedef struct	s_print_colour
{
	char *colour;
	char *print_c;
}				t_print_colour;

typedef struct	s_print_num
{
	char		*c;
	char		*int_size;
	p_num		print; 
}				t_print_num;

typedef struct	s_print_dt_num
{
	char		*c;
	char		*int_size;
	p_dt_num	print; 
}				t_print_dt_num;

typedef struct	s_print_chars
{
	char		*c;
	p_chars		print; 
}				t_print_chars;

char	get_space_type(char *flags);
int		dec_print_spaces(int spaces, char is_space, int plus);
int		dec_print_zeroes(int zeroes, int plus);
int		ft_printf(char *str, ...);
int		get_num_length(long long num, int base);
int		get_unum_length(unsigned long long num, int base);
int		pf_dot_int_decimal(long long num, char *flags, int mod[2]);
int		pf_dot_int_hex_lower(long long n, char *flags, int mod[2]);
int		pf_long_unsigned(long long n, char *flags, int mod);
int		print_precision(int base, int caps);
int		put_sign(int plus);
int		dec_dot_lft_adj_print(int plus, int mod, int mod2, long long num);
int		dec_dot_lft_adj_print_us(int mod, int mod2, unsigned long long num);
int		dec_mod2_greater_print(int plus, int mod2, long long num);
int		dec_mod2_greater_print_us(int mod2, unsigned long long num);
int		non_dec_dot_leftadj_print1(int num_l, int mod, int base, int caps);
int		non_dec_dot_leftadj_print1_uc(int num_l, int mod, int base, int precision);
int		non_dec_dot_leftadj_print2(int num_l, int mod, int count);
int		non_dec_dot_spaceprint(int num_l, int mod[2], int base, int caps);
int		non_dec_dot_spaceprint_uc(int num_l, int mod[2], int base, int precision);
int		nondec_print_spaces(int spaces, int base, int precision, int caps);
int		nondec_print_zeroes(int zeroes, int base, int precision, int caps);
int		pf_dot_hh_decimal(long long n, char *flags, int mod[2]);
int		pf_dot_hh_hex_lower(long long n, char *flags, int mod[2]);
int		pf_dot_hh_hex_upper(long long n, char *flags, int mod[2]);
int		pf_dot_hh_octal(long long n, char *flags, int mod[2]);
int		pf_dot_int_hex_upper(long long n, char *flags, int mod[2]);
int		pf_dot_int_octal(long long n, char *flags, int mod[2]);
int		pf_dot_ll_hex_lower(long long num, char *flags, int mod[2]);
int		pf_dot_ll_hex_upper(long long num, char *flags, int mod[2]);
int		pf_dot_ll_octal(long long num, char *flagsi, int mod[2]);
int		pf_dot_short_decimal(long long n, char *flags, int mod[2]);
int		pf_dot_short_hex_lower(long long n, char *flags, int mod[2]);
int		pf_dot_short_hex_upper(long long n, char *flags, int mod[2]);
int		pf_dot_short_octal(long long n, char *flags, int mod[2]);
int		pf_dot_unsigned_decimal(long long n, char *flags, int mod[2]);
int		pf_dot_unsigned_hh(long long n, char *flags, int mod[2]);
int		pf_dot_unsigned_long(long long n, char *flags, int mod[2]);
int		pf_dot_unsigned_short(long long n, char *flags, int mod[2]);
int		pf_hh_decimal(long long n, char *flags, int mod);
int		pf_hh_hex_lower(long long n, char *flags, int mod);
int		pf_hh_hex_upper(long long n, char *flags, int mod);
int		pf_hh_octal(long long n, char *flags, int mod);
int		pf_hh_unsigned(long long num, char *flags, int mod);
int		pf_int_decimal(long long num, char *flags, int mod);
int		pf_int_hex_lower(long long num, char *flags, int mod);
int		pf_int_hex_upper(long long num, char *flags, int mod);
int		pf_int_octal(long long num, char *flags, int mod);
int		pf_int_unsigned(long long num, char *flags, int mod);
int		pf_l_decimal(long long num, char *flags, int mod);
int		pf_l_hex_lower(long long num, char *flags, int mod);
int		pf_l_hex_upper(long long num, char *flags, int mod);
int		pf_l_octal(long long num, char *flags, int mod);
int		pf_ll_decimal(long long num, char *flags, int mod);
int		pf_ll_hex_lower(long long num, char *flags, int mod);
int		pf_ll_hex_lower(long long num, char *flags, int mod);
int		pf_ll_hex_upper(long long num, char *flags, int mod);
int		pf_ll_octal(long long num, char *flags, int mod);
int		pf_ll_unsigned(long long n, char *flags, int mod);
int		pf_short_decimal(long long n, char *flags, int mod);
int		pf_short_decimal(long long n, char *flags, int mod);
int		pf_short_hex_lower(long long n, char *flags, int mod);
int		pf_short_hex_lower(long long n, char *flags, int mod);
int		pf_short_hex_upper(long long n, char *flags, int mod);
int		pf_short_octal(long long n, char *flags, int mod);
int		pf_short_unsigned(long long n, char *flags, int mod);
int		print_char(char c, char *flags, int mod[2]);
int		print_chars(va_list ap, char *flags, char *c, int mod[2]);
int		print_number(va_list ap, char *flags, char *c, int mod[2]);
int		print_pointer(long long *p, char *flags, int mod);
int		print_string(char *str, char *flags, int mod[2]);
int 	dec_dot_space_print(int plus, int mod, int mod2, long long num);
int 	dec_dot_space_print_us(int mod, int mod2, unsigned long long num);
int 	dt_num_zero_case(int space_type, int mod, int plus);
int 	get_precision(int base);
void	ft_pf_percent(char *str, char *flags);
void	ft_pf_string(char *str, char *flags);
void	ft_putbase(long long num, int base, int filler, int caps);
void	pf_putnbr(long long n);
void	pf_putnbr_unsigned(unsigned long long n);
void	print_left_adj(int spaces);
void 	get_mod_values(char *flags, int *mod, int *mod2);

#endif
