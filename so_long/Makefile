# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mboyansa <mboyansa@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/06 17:03:54 by mboyansa          #+#    #+#              #
#    Updated: 2023/07/16 03:46:13 by mboyansa         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = so_long.c utils.c utils2.c utils3.c utils4.c utils5.c utils6.c

NAME = so_long
CC = gcc
CFLAGS = -Wall -Wextra -Werror
LFLAGS = -framework AppKit -framework OpenGL -L./mlx -lmlx
MLX = ./mlx/libmlx.a
FT_PRINTF = ./printf/libftprintf.a
GET_NEXT_LINE = ./get_next_line/next_line.a
RM = rm -rf
LIBC = ar -rcs

all: $(MLX) $(NAME)

$(NAME): $(SRCS) $(MLX) $(FT_PRINTF) $(GET_NEXT_LINE)
	@gcc $(CFLAGS) $(LFLAGS) $(SRCS) $(FT_PRINTF) $(GET_NEXT_LINE) -o $(NAME)
	@echo "-*-*-*- OK -*-*-*-"

$(MLX) :
	@make -C ./mlx 2>/dev/null

$(FT_PRINTF) :
	@make -C ./printf

$(GET_NEXT_LINE) :
	@make -C ./get_next_line

clean:

fclean: clean
	@rm -rf $(NAME)
	@make clean -C ./mlx
	@make fclean -C ./printf
	@make fclean -C ./get_next_line

re: fclean all

.PHONY: all bonus clean fclean re .c.o