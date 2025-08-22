# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: assabich <assabich@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/15 17:31:56 by assabich          #+#    #+#              #
#    Updated: 2025/03/10 14:08:37 by assabich         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_DIR = .
INC_DIR = .

SRC = $(addprefix $(SRC_DIR)/, \
		ft_memmove.c \
		ft_memcpy.c \
		ft_strlcpy.c \
		ft_strlcat.c \
		ft_isalpha.c \
		ft_isdigit.c \
		ft_isalnum.c \
		ft_isascii.c \
		ft_isprint.c \
		ft_memset.c \
		ft_bzero.c \
		ft_toupper.c \
		ft_tolower.c \
		ft_strchr.c \
		ft_strrchr.c \
		ft_strncmp.c \
		ft_memchr.c \
		ft_memcmp.c \
		ft_strnstr.c \
		ft_atoi.c \
		ft_calloc.c \
		ft_strdup.c \
		ft_substr.c \
		ft_strjoin.c \
		ft_strtrim.c \
		ft_split.c \
		ft_itoa.c \
		ft_strmapi.c \
		ft_striteri.c \
		ft_putchar_fd.c \
		ft_putstr_fd.c \
		ft_putendl_fd.c \
		ft_putnbr_fd.c \
		ft_strlen.c \
		get_next_line.c \
		get_next_line_utils.c \
)

BONUS = $(addprefix $(SRC_DIR)/, \
		ft_lstadd_back.c \
		ft_lstclear.c \
		ft_lstiter.c \
		ft_lstmap.c \
		ft_lstsize.c \
		ft_lstadd_front.c \
		ft_lstdelone.c \
		ft_lstlast.c \
		ft_lstnew.c)

OBJS = $(SRC:.c=.o)
OBJS_B = $(BONUS:.c=.o)
NAME = libft.a
CC = gcc
AR = ar
FLAGS = -Wall -Wextra -Werror
INC = $(INC_DIR)/libft.h

all: $(NAME)

$(NAME) : $(OBJS)
	$(AR) rcs $(NAME) $(OBJS)

bonus: 	$(OBJS) $(OBJS_B) 
	$(AR) rcs $(NAME) $(OBJS_B)
	
%.o: %.c $(INC)
	$(CC) $(FLAGS) -c $< -o $@ -I$(INC_DIR)
	
clean:
	rm -f $(OBJS) $(OBJS_B)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re