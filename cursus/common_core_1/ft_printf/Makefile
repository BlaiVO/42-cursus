# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: blvilarn <blvilarn@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/09 17:47:37 by blvilarn          #+#    #+#              #
#    Updated: 2023/01/09 19:31:58 by blvilarn         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#VARIABLES
NAME = libftprintf.a
HEADER = ft_printf.h
FLAGS = -Wall -Werror -Wextra
SRC = ft_printf.c utils.c
OBJS = $(SRC:.c=.o)

#RULES
%.o: %.c $(HEADER)
	$(CC) $(FLAGS) -c $< -o $@

all: $(NAME)

$(NAME) : $(OBJS)
	ar -rcs $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

#PHONY
.PHONY: all clean fclean re
