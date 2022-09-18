# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yjouaoud <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/03/27 15:16:26 by yjouaoud          #+#    #+#              #
#    Updated: 2019/03/27 16:00:40 by yjouaoud         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
SRC = *.c
W = -Wall -Wextra -Werror

all: $(NAME)
			
$(NAME):
	@gcc $(W) -c $(SRC)
	@ar rc $(NAME) *.o

clean:
	@/bin/rm -f *.o

fclean: clean
	@/bin/rm -f $(NAME)

re: fclean all
