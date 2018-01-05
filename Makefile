# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: slynn-ev <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/05 21:56:14 by slynn-ev          #+#    #+#              #
#    Updated: 2018/01/05 22:20:34 by slynn-ev         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = ft_pf_decimal.c \
ft_pf_percent.c \
ft_pf_string.c \
ft_printf.c \
ft_putchar.c \
ft_putnbr.c \
ft_putstr.c \

OBJ = $(SRC:.c=.o)

NAME = libftprintf.a

all: $(NAME)

$(NAME): $(OBJ)
	gcc -c -Wall -Wextra -Werror $(SRC) -Ift_printf.h -Ilibft.h
	ar rc $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
