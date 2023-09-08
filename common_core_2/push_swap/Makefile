# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: blvilarn <blvilarn@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/28 15:55:18 by blvilarn          #+#    #+#              #
#    Updated: 2023/03/28 15:56:30 by blvilarn         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#TODO: Not even started lol

#VARIABLES
NAME = push_swap.a
HEADER = push_swap.h
FLAGS = -Wall -Werror -Wextra
SRC = ft_printf.c str_utils.c int_utils.c
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
