# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hgysella <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/13 15:41:01 by hgysella          #+#    #+#              #
#    Updated: 2018/12/19 14:00:58 by hgysella         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

SRC = main.c ft_read_map.c ft_create_map.c ft_matrix.c \
	  ft_tetrik.c ft_print.c ft_swap_str.c

all: $(NAME)
			
$(NAME): 
	make -C libft/
	gcc -Wall -Wextra -Werror -o $(NAME) $(SRC) -L./libft -lft

clean:
	make -C libft/ clean
	rm -f *.o

fclean: clean
	make -C libft/ fclean
	rm -f $(NAME)
	rm -rf *.dSYM

re: fclean all
