# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: assabich <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/02 10:54:58 by assabich          #+#    #+#              #
#    Updated: 2024/12/08 14:07:49 by assabich         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
FLAGS = -Wextra -Werror -Wall
AR = ar
NAME = libftprintf.a

SRC = ft_putchar.c \
      ft_putstr.c \
      ft_base.c \
      ft_ubase.c \
      ft_unsign.c \
      ft_printf.c 

INC = ft_printf.h

OBJ = $(SRC:.c=.o)


all : $(NAME)

$(NAME) : $(OBJ)
	$(AR) rcs $(NAME) $(OBJ)

%.o: %.c $(INC)
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
