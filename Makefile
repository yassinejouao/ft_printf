# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jbouazao <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/25 10:02:55 by jbouazao          #+#    #+#              #
#    Updated: 2019/08/07 13:56:52 by yjouaoud         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
SRC_DIR = src
OBJ_DIR = obj
OBJ_DIRS = $(OBJ_DIR) $(OBJ_DIR)/f_conv $(OBJ_DIR)/u_conv $(OBJ_DIR)/p_conv
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a
INC_DIR = src

FILE_NAMES = atoi_base.c d_proc.c misc_arithmetics.c misc_flg.c \
			perc_proc.c s_proc.c u_proc.c c_proc.c f_proc.c misc_f_proc.c \
			o_proc.c print_f.c str_add.c x_proc.c capx_proc.c ft_printf.c \
			misc.c misc_finfz_proc.c p_proc.c round.c str_mul.c

SRC_FILES = $(addprefix $(SRC_DIR)/,$(FILE_NAMES))
OBJ_FILES = $(addprefix $(OBJ_DIR)/,$(FILE_NAMES:.c=.o))

all: $(NAME)
$(NAME): $(LIBFT) $(OBJ_FILES)
	@cp $(LIBFT) $(NAME)
	ar rc $(NAME) $(OBJ_FILES)
	ranlib $(NAME)
$(OBJ_FILES): $(OBJ_DIR)/%.o : $(SRC_DIR)/%.c | $(OBJ_DIRS)
	gcc -c -Wall -Werror -Wextra -I $(INC_DIR) $^ -o $@
$(OBJ_DIRS):
	@mkdir $(OBJ_DIRS)
$(LIBFT):
	@make -C $(LIBFT_DIR)
clean:
	rm -rf $(OBJ_DIR)
	@make -C $(LIBFT_DIR) clean
fclean: clean
	rm -f $(NAME)
	@make -C $(LIBFT_DIR) fclean
re: fclean all