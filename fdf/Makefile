# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: omeyer <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/07/02 14:51:42 by omeyer            #+#    #+#              #
#    Updated: 2017/07/02 18:24:30 by omeyer           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

SRC = main.c fdf.c data.c play.c cart_to_iso.c

OBJ = main.o fdf.o data.o play.o cart_to_iso.o

FLAGS = -Wall -Wextra -Werror -lmlx -framework OpenGL -framework AppKit

FETCHLIB = -L libft/ -lft

all: $(NAME)

$(NAME):
	$(MAKE) -C libft/ all
	gcc -o $(NAME) $(SRC) $(FLAGS) $(FETCHLIB)

clean:
	$(MAKE) -C libft/ clean
	/bin/rm -f $(OBJ)

fclean: clean
	/bin/rm -f $(NAME)
	$(MAKE) -C libft/ fclean

re:	fclean all
