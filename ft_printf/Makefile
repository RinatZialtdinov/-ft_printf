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

SRC = ./srcs/printf.c \
	./srcs/ft_putchar.c \
	./srcs/ft_putstr.c \
	./srcs/ft_intlen.c \
	./srcs/ft_strcmp.c \
	./srcs/ft_strlen.c \
	./srcs/ft_itoa.c  \
	./srcs/ft_strjoin.c \
	./srcs/ft_strchr.c \
	./srcs/ft_strnew.c \
	./srcs/write_x.c \
	./srcs/write_s.c \
	./srcs/write_percent.c \
	./srcs/write_idu.c \
	./srcs/write_f.c \
	./srcs/type_x.c \
	./srcs/type_s.c \
	./srcs/type_p.c \
	./srcs/type_idu.c \
	./srcs/precision_f.c \
	./srcs/precision_x.c \
	./srcs/percent.c \
	./srcs/flags.c \
	./srcs/convert_f.c \
	./srcs/common_functions.c \
	./srcs/check_size_x.c \
	./srcs/check_size_f.c \
	./srcs/file1.c

OBJ = $(SRC:%.c=%.o)
NAME = libftprintf.a
HEADER = ./includes/printf.h

all: $(NAME)

$(NAME): $(OBJ) $(HEADER)
	ar rc $(NAME) $(OBJ)

$(OBJ): %.o:%.c
	@gcc -Wall -Wextra -Werror -c $<
	mv *.o ./srcs/

clean:
	@rm -rf ./srcs/*.o

fclean: clean
	@rm -rf libftprintf.a

re: fclean all
