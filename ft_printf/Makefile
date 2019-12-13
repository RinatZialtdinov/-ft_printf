# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bdebbie <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/24 17:50:09 by bdebbie           #+#    #+#              #
#    Updated: 2019/11/15 23:07:24 by bdebbie          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = printf.c \
	ft_putchar.c \
	ft_putstr.c \
	ft_intlen.c \
	ft_strcmp.c \
	ft_strlen.c

OBJ = $(SRC:%.c=%.o)
NAME = libftprintf.a
HEADER = printf.h

all: $(NAME)

$(NAME): $(OBJ) $(HEADER)
	ar rc $(NAME) $(OBJ)

$(OBJ): %.o:%.c
	@gcc -Wall -Wextra -Werror -c $<

clean:
	@rm -rf ./*.o

fclean: clean
	@rm -rf libftprintf.a

re: fclean all
