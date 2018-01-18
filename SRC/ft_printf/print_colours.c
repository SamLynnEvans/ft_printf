/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_colours.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slynn-ev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/18 13:46:43 by slynn-ev          #+#    #+#             */
/*   Updated: 2018/01/18 20:04:44 by slynn-ev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_print_colour g_colour_tab[] = {
	{"RED", "\x1b[31m"},
	{"GREEN", "\x1b[32m"},
	{"YELLOW", "\x1b[33m"},
	{"BLUE", "\x1b[34m"},
	{"MAGENTA", "\x1b[35m"},
	{"CYAN", "\x1b[36m"},
	{"EOC", "\x1b[0m"},
};

int	print_colour(char *str, int *skip)
{
	char	*colour;
	int		i;
	int		j;

	j = -1;
	i = 0;
	colour = malloc(sizeof(char) * 11);
	while (str[i + 1] != '}' && i < 10)
	{
		colour[i] = str[i + 1];
		i++;
	}
	colour[i] = '\0';
	while (++j < 7)
		if (!(ft_strcmp(colour, g_colour_tab[j].colour)))
		{
			ft_putstr(g_colour_tab[j].print_c);
			break ;
		}
	if (j == 7)
		ft_putchar(*str);
	*skip = (j == 7) ? 0 : i + 1;
	free(colour);
	return (j == 7) ? 1 : 0;
}
