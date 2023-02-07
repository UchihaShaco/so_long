# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jalwahei <jalwahei@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/28 15:25:35 by jalwahei          #+#    #+#              #
#    Updated: 2023/02/07 19:22:03 by jalwahei         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

SRCS = main.c add_images.c so_long_val.c so_long_move.c so_valid.c

OBJS = $(SRCS:.c=.o)

CFLAGS = -Wall -Wextra -Werror

LIBFT = libft

all: $(NAME)

$(NAME): $(OBJS)
	make -C ./libft
	make -C ./ft_printf
	$(CC) $(CFLAGS) $(SRCS) -framework OpenGL -framework AppKit ./mlx/libmlx.a ./libft/libft.a ./ft_printf/libftprintf.a -o $(NAME)

%.o: %.c
	cc $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
