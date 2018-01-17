# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: slynn-ev <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/05 21:56:14 by slynn-ev          #+#    #+#              #
#    Updated: 2018/01/17 14:29:34 by slynn-ev         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = int_printers.c \
ft_pf_percent.c \
ft_pf_string.c \
ft_printf.c \
ft_putchar.c \
ft_putnbr.c \
ft_putstr.c \
print_numbers.c \
ft_atoi.c \
ft_strrchr.c \
get_num_length.c \
num_flags.c \
ft_putbase.c \
pf_putnbr.c \
ft_putnbr.c \
pf_unsigned.c \
long_printers.c \
longlong_printers.c \
short_printers.c \
hh_printers.c \
libft/ft_intdebug.c \
dt_int_printers.c \
dt_dec_num_flags.c \
dt_nondec_num_flags.c \
dt_ll_printers.c \
dt_short_printers.c \
dt_hh_printers.c \
dt_unsigned.c \
dt_unsigned_num_flags.c \
print_chars.c \
libft/ft_strlen.c \
libft/ft_strdup.c \
libft/ft_strcmp.c \

OBJ = $(SRC:.c=.o)

NAME = libftprintf.a

all: $(NAME)

$(NAME): $(OBJ)
	gcc -c -Wall -Wextra -Werror $(SRC) -Ift_printf.h -Ilibft.h -g
	ar rc $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
