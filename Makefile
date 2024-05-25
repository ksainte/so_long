# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ksainte <ksainte@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/21 13:23:41 by ksainte           #+#    #+#              #
#    Updated: 2024/05/25 17:16:18 by ksainte          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc -g3
CFLAGS = -Wall -Wextra -Werror
SRCS = src/main.c src/color.c src/hooks.c src/window.c src/image.c src/open.c src/get_next_line.c src/get_next_line_utils.c
LIBFT_PATH = Libft
MLX_PATH = mlx
LIBFT_ARCHIVE = $(LIBFT_PATH)/libft.a
MLX_ARCHIVE = $(MLX_PATH)/mlx.a
EXEC_NAME = so_long
OBJS = $(notdir $(SRCS:.c=.o))
FLAGS = -L mlx -lmlx -L Libft -lft -framework OpenGL -framework AppKit

MLX_DIR = ./mlx
MLX_ARCHIVE = $(MLX_DIR)/libmlx.a

 
all: $(MLX_LIB) $(EXEC_NAME)
 
$(EXEC_NAME): $(OBJS) $(LIBFT_ARCHIVE) $(MLX_ARCHIVE)
	$(CC) $(CFLAGS) -o $(EXEC_NAME) $(OBJS) $(FLAGS)
 
$(MLX_ARCHIVE):
	$(MAKE) -C $(MLX_PATH)
	
$(LIBFT_ARCHIVE):
	$(MAKE) -C $(LIBFT_PATH)

%.o: src/%.c
	$(CC) $(CFLAGS) -Imlx -c $< -o $@

clean:
	$(MAKE) -C $(MLX_PATH) clean
	$(MAKE) -C $(LIBFT_PATH) clean
	rm -f $(OBJS)

fclean: clean
	$(MAKE) -C $(LIBFT_PATH) fclean
	$(MAKE) -C $(MLX_PATH) fclean
	rm -f $(EXEC_NAME)

re: fclean all

.PHONY: all
