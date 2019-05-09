# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hgysella <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/11 16:10:43 by hgysella          #+#    #+#              #
#    Updated: 2019/03/06 18:00:10 by hgysella         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_P = push_swap

NAME_C = checker

FLAGS = -Wall -Wextra -Werror

SRC = read_a.c optimize.c optim_oper.c my_atoi.c op_a.c op_b.c\
	  create_list_op.c sort.c bubble_sort.c

SRC_P = main.c sort_three.c push_swap.c

SRC_C = check.c

OBJ = $(SRC:.c=.o)

OBJ_P = $(SRC_P:.c=.o)

OBJ_C = $(SRC_C:.c=.o)

all: $(NAME_P) $(NAME_C)
				
$(NAME_P): make_lib $(OBJ) $(OBJ_P)
		@gcc -o $(NAME_P) $(OBJ) $(OBJ_P) -L./libft -lft

$(NAME_C): make_lib $(OBJ) $(OBJ_C)
		@gcc -o $(NAME_C) $(OBJ) $(OBJ_C) -L./libft -lft

make_lib:
		@make -C libft/

.c.o:
		@gcc $(FLAGS) -I. -o $@ -c $<

clean:
		@make -C libft/ clean
		@rm -f $(OBJ) $(OBJ_P) $(OBJ_C)

fclean: clean
		@make -C libft/ fclean
		@rm -f $(NAME_P)
		@rm -f $(NAME_C)

re: fclean all
