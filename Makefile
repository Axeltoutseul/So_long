# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: axbaudri <axbaudri@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/13 17:33:18 by axbaudri          #+#    #+#              #
#    Updated: 2025/08/08 14:32:35 by axbaudri         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

CFLAGS = -Wall -Wextra -Werror -g3

RM = rm -f

NAME = so_long

SRCS = check_map.c \
	find_positions.c \
	free_map.c \
	get_map.c \
	init_map.c \
	move_player.c \
	read_content.c \
	so_long.c

OBJS = $(SRCS:.c=.o)

LIBFT = libft/libft.a

MLX = mlx_linux/libmlx_Linux.a

$(LIBFT):
	make -C libft/

$(MLX):
	make -c mlx_linux/

$(NAME): $(OBJS) $(LIBFT) $(MLX)
	$(CC) $(CFLAGS) $(OBJS) -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME) $(LIBFT)

%.o: %.c
	$(CC) $(CFLAGS) -I/usr/include -Imlx_linux -O3 -c $< -o $@

all: $(NAME)

clean:
	$(RM) $(OBJS)
	make clean -C libft/

fclean: clean
	$(RM) $(NAME)
	$(RM) $(LIBFT)

re: fclean all

.PHONY: all clean fclean re
