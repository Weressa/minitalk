# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: assabich <assabich@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/08/18 20:40:17 by assabich          #+#    #+#              #
#    Updated: 2025/08/22 17:01:14 by assabich         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#compiler + flags
CC = cc
CFLAGS = -Wall -Werror -Wextra

#executable names
SERVER = server
CLIENT = client

#source files
SRCS_SERVER = server.c utils.c
SRCS_CLIENT = client.c utils.c

#object files (.c to .o)
OBJS_SERVER = $(SRCS_SERVER:.c=.o)
OBJS_CLIENT = $(SRCS_CLIENT:.c=.o)

#My libraries
LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a
PRINTF_DIR = ./ft_printf
PRINTF = $(PRINTF_DIR)/libftprintf.a

#Default rule = build both programs
all: $(LIBFT) $(PRINTF) $(SERVER) $(CLIENT)

#How to build server
$(SERVER): $(OBJS_SERVER) $(LIBFT) $(PRINTF)
	$(CC) $(CFLAGS) -o $(SERVER) $(OBJS_SERVER) $(LIBFT) $(PRINTF)
	
#How to build the client
$(CLIENT): $(OBJS_CLIENT) $(LIBFT) $(PRINTF)
	$(CC) $(CFLAGS) -o $(CLIENT) $(OBJS_CLIENT) $(LIBFT) $(PRINTF)

#Build libraries
$(LIBFT):
	make -C $(LIBFT_DIR)

$(PRINTF):
	make -C $(PRINTF_DIR)

#How to buid .o from .c files
%.o: %.cc
	&(CC) $(CFLAGS) -c $< -o $@
	
#Remove compiled obj
clean:
	rm -f $(OBJS_SERVER) $(OBJS_CLIENT)
	make -C $(LIBFT_DIR) clean
	make -C $(PRINTF_DIR) clean

#Remove everything ( obj + execut)
fclean: clean
	rm -f $(SERVER) $(CLIENT)
	make -C $(LIBFT_DIR) fclean
	make -C $(PRINTF_DIR) fclean

#Rebuild everything
re: fclean all

.PHONY: all clean fclean re