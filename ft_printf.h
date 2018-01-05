/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slynn-ev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/05 12:43:22 by slynn-ev          #+#    #+#             */
/*   Updated: 2018/01/05 22:20:31 by slynn-ev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <stdlib.h>
#include <stdarg.h>
#include <stdio.h>
#include "libft.h"

typedef void	(*p_num)(long long, char *);
typedef void	(*p_chars)(char *, char *);

typedef struct	s_print_num
{
	char		*c;
	p_num		print; 

}				t_print_num;

typedef struct	s_print_chars
{
	char		*c;
	p_chars		print; 

}				t_print_chars;

void	ft_pf_string(char *str, char *flags);
void	ft_pf_percent(char *str, char *flags);
void	ft_pf_decimal(long long num, char *flags);
void	ft_printf(char *str, ...);

#endif
