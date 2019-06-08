NAME = corewar

FLAGS = -Wall -Wextra -Werror

SRC = parse_args.c main.c

OBJ = $(SRC:%.c=%.o)

INCL = libft/includes/

all: $(NAME)
		
$(NAME): make_lib $(OBJ)
$(NAME): $(OBJ)
		 @gcc -o $(NAME) $(OBJ) -L./libft -lft

make_lib:
		 @make -C libft/

.c.o:
		@gcc $(FLAGS) -I $(INCL) -o $@ -c $<

clean:
		@make -C libft/ clean
		@rm -f $(OBJ)

fclean: clean
		@make -C libft/ fclean
		@rm -f $(NAME)

re:		fclean all
