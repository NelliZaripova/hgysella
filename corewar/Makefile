# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jwinthei <jwinthei@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/20 13:26:35 by jwinthei          #+#    #+#              #
#    Updated: 2019/08/02 16:21:57 by jwinthei         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

ASM  = asm
CW   = corewar
VS   = vs_hex
LIB  = libft.a

SRC_D= src/
ASM_D= asm/
CW_D = cw/
ASM_D= asm/
OP_D = op/
VS_D = vs/
LIB_D= libft/

INC_S= includes/
INC_L= libft/includes/

ASM_S=	asm.c		srcs1.c		srcs2.c		srcs3.c			srcs4.c		srcs5.c		srcs6.c\
		srcs7.c		srcs8.c		srcs9.c		srcs10.c		srcs11.c	srcs12.c	srcs13.c\
		srcs14.c	srcs15.c	disasm.c	disasm_func.c	add_args.c	op_check.c	op_check1.c\
		op_check2.c	op_check3.c	op_check4.c	read_champs.c 	help.c		command_read.c\
		ltoa_base.c	ft_atol.c	strjoin_.c	strdup_.c		strtrim_.c
		
OP_S =	op_add.c	op_aff.c	op_and.c	op_fork.c	op_ld.c		op_ldi.c\
		op_lfork.c	op_live.c	op_lld.c	op_lldi.c	op_or.c		op_st.c\
		op_sti.c	op_sub.c	op_xor.c	op_zjmp.c

VS_S =	vs.c			vs_init.c	vs_func.c	vs_print_windows.c

CW_S =	corewar.c		cw_init.c	cw_out.c	cw_strrstr.c\
		champ_func.c	car_func.c	dbg_log.c	cw_byte_func.c\
		cw_map_filler.c	cw_validator.c			cw_codage_validator.c


CW_C =	$(addprefix $(SRC_D)/$(CW_D), $(CW_S))	$(addprefix $(SRC_D)/$(CW_D)/$(OP_D)/, $(OP_S))\
		$(addprefix $(SRC_D)/$(VS_D), $(VS_S))
		
ASM_C=	$(addprefix $(SRC_D)/$(ASM_D)/, $(ASM_S))

FLG  = -Wall -Wextra -Werror
CFLAGS=-O3 -I $(INC_L) -I $(INC_S) $(FLG) 

CW_O = $(CW_C:.c=.o)
ASM_O = $(ASM_C:.c=.o)

all: $(LIB) $(CW) $(ASM) CLR

$(LIB): $(LIB_D)*.c
	@make -C $(LIB_D)

$(CW): $(LIB_D)*.c $(CW_O)
	gcc -O2 -o $(CW) $(CW_O) $(CFLAGS) -L $(LIB_D) -lft -lncurses

$(ASM): $(LIB_D)*.c $(ASM_O)
	gcc -O2 -o $(ASM) $(ASM_C) $(CFLAGS) -L $(LIB_D) -lft

clean:
	rm -f *.o
	rm -f $(SRC_D)/$(ASM_D)/*.o
	rm -f $(SRC_D)/$(VS_D)/*.o
	rm -f $(SRC_D)/$(CW_D)/*.o
	rm -f $(SRC_D)/$(CW_D)/$(OP_D)/*.o
	make -C $(LIB_D) clean
	clear

fclean: clean
	rm -f $(CW)
	rm -f $(ASM)
	make -C $(LIB_D) fclean
	clear

re: fclean all

CLR:
	clear
