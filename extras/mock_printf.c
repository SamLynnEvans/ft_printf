/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mock_printf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slynn-ev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/05 19:00:30 by slynn-ev          #+#    #+#             */
/*   Updated: 2018/01/05 21:15:25 by slynn-ev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_print_num			g_pf_num_tab[] =
{
	{"d", &ft_pf_decimal},
};

t_print_chars		g_pf_char_tab[] =
{
	{"s", &ft_pf_string},
	{"%", &ft_pf_percent},
};

char	is_int_type(char *str, int *skip)
{
	int	i;

	i = 1;
	while (str[i] == '#' || str[i] == '+' || str[i] == '-' 
	|| str[i] == ' ' || str[i] == '0' || str[i] == 'j' || str[i] == 'l'
	|| str[i] == 'z' || str[i] == 'h') 
		i++;
	*skip = i;
	if (str[i] == 'u' || str[i] == 'd')
		return (1);
	else
		return (0);
}

void	print_chars(char *prnt_str, char *str, star)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (str[i] == '#' || str[i] == '+' || str[i] == '-' 
	|| str[i] == ' ' || str[i] == '0' || str[i] == 'j' || str[i] == 'l'
	|| str[i] == 'z' || str[i] == 'h') 
		i++;
	while (j < 3)
	{
		if (str[i] == *g_pf_char_tab[j].c)
		{
			g_pf_char_tab[j].print(prnt_str);
			break ;
		}
		j++;
	}
}

void	print_number(int num, char *str, star)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (str[i] == '#' || str[i] == '+' || str[i] == '-' 
	|| str[i] == ' ' || str[i] == '0' || str[i] == 'j' || str[i] == 'l'
	|| str[i] == 'z' || str[i] == 'h') 
		i++;
	while (j < 3)
	{
		if (str[i] == *g_pf_num_tab[j].c)
		{
			g_pf_num_tab[j].print(num, str);
			break ;
		}
		j++;
	}
}

void get_flags(char *str, int *skip, int *star, char **flags)
{
	int	i;

	i = 1;
	*stars = 0;
	while (str[i] == '#' || str[i] == '+' || str[i] == '-' 
	|| str[i] == ' ' || str[i] == '0' || str[i] == 'j' || str[i] == 'l'
	|| str[i] == 'z' || str[i] == 'h')
	{
		*flags[i - 1] = str[i];
		if (str[i] == '*')
			*stars = 1;
		i++;
	}
	*flags[i - 1] = '\0';	
	*skip = i;
	
}

void	m_printf(char *str, ...)
{
	va_list	ap;
	int		skip;
	int		star;
	char	*flags;

	va_start(ap, str);
	while (*str)
	{
		if (*str == '%')
		{
			get_flags(str, &skip, &star, &flags);
			if ((is_int_type(str + skip))
				print_number(va_arg(ap, int), flags, str + skip, star);
			else
				print_chars(va_arg(ap, char *), flags, str + skip, star);
			str += skip;
		}
		else
			ft_putchar(str[i]);
		str++;
	}
	va_end(ap);
}

int		main()
{
	char	*p = "pie";
	char	*s = "sam";
	int		d = 66;

	m_printf("sam is %s and pie is %s and he likes %d", p, s, d);
}
