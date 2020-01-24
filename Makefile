# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dmorrige <dmorrige@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/24 17:50:09 by bdebbie           #+#    #+#              #
#    Updated: 2020/01/24 19:08:22 by dmorrige         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = ./srcs/ft_printf.c \
	./srcs/ft_intlen.c \
	./srcs/ft_itoa_pf.c  \

OBJ = $(SRC:%.c=%.o)
NAME = libftprintf.a
NAME_LIBFT = ./libft/libft.a
HEADER = ./includes/printf.h
FLAGS = -Wall -Wextra -I./includes/ -I./libft/
LFLAGS = -L./libft/ -lft

all:
	$(MAKE) -C ./libft
	$(MAKE) $(NAME)

$(NAME): $(OBJ) $(HEADER)
	ar rc $(NAME)_temp.a $(OBJ)
	libtool -static -o $(NAME) $(NAME)_temp.a $(NAME_LIBFT)

$(OBJ): %.o:%.c
	gcc $(FLAGS) -c $< -o $@

debug:
	gcc $(FLAGS) $(SRC) ./srcs/main.c $(LFLAGS) -o ./debug.out

clean:
	$(MAKE) -C ./libft clean
	@rm -rf ./srcs/*.o

fclean: clean
	$(MAKE) -C ./libft fclean
	@rm -rf libftprintf.a

re: fclean all

.PHONY: all libft clean fclean re
