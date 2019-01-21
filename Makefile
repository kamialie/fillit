# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lwyl-the <lwyl-the@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/12 11:42:49 by rgyles            #+#    #+#              #
#    Updated: 2018/12/16 16:36:04 by rgyles           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

LIB = libft/libft.a

SRC = main.c ft_read_and_check.c ft_list.c ft_char_to_bit.c ft_solve.c ft_map.c ft_print.c

OBJ = $(SRC:.c=.o)

all: $(NAME)
	
$(NAME): $(LIB)
	gcc  -Wall -Wextra -Werror -c $(SRC)
	gcc  -o $(NAME) -Llibft -lft $(OBJ)

$(LIB):
	cd libft && make
	cd libft && make clean

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)
	cd libft && make fclean

re: fclean all
