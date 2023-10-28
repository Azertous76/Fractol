# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abailleu <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/16 18:12:02 by abailleu          #+#    #+#              #
#    Updated: 2023/10/16 18:12:04 by abailleu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol
CC = gcc -Wall -Wextra -Werror -O3 -march=native -flto -fno-signed-zeros -funroll-loops
NOR = norminette -R CheckForbiddenSourceHeader
SRC = main.c init.c renders.c string_utils.c math_utils.c events.c
OBJ = $(SRC:.c=.o)

%.o: %.c
	$(CC) -Imlx -c $< -o $@

$(NAME): $(OBJ)
	$(CC) $(OBJ) minilibx-linux/libmlx.a  -lX11 -lXext -lm -o $(NAME)

all: $(NAME)

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re:	fclean all
