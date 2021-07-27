# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gpetit <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/27 16:43:52 by gpetit            #+#    #+#              #
#    Updated: 2021/07/27 17:08:53 by gpetit           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = checker

CC = clang

CFLAGS = -Wall -Wextra -Werror -g3

LIBFT = -L../libft -lft

SRCS = main.c

OBJS = $(SRCS:.c=.o)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@


all: $(NAME)

$(NAME): $(OBJS)
	make -C ../libft/
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	make fclean -C ../libft/
	rm -f $(NAME)

re: fclean $(NAME)

.PHONY: all clean fclean re


