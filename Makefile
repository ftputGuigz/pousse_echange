# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gpetit <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/23 13:49:56 by gpetit            #+#    #+#              #
#    Updated: 2021/06/24 13:01:41 by gpetit           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME= push_swap

CC= clang

CFLAGS= -Wall -Wextra -Werror

LIBFT= -Llibft -lft 

SRCS= main.c

OBJS= $(SRCS:.c=.o)

%.o: %.c
	$(CC) -Iincludes $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS)
	make -C libft/
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT)

clean:
	rm -f $(OBJS)

fclean: clean
	make fclean -C libft/
	rm -f $(NAME)

re: fclean $(NAME)

.PHONY: all clean fclean re 


