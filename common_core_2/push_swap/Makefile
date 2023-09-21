# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: blvilarn <blvilarn@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/04 16:15:09 by blvilarn          #+#    #+#              #
#    Updated: 2023/09/21 18:52:35 by blvilarn         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CFLAGS = -Wall -Wextra -Werror -MMD
FILES = push_swap.c input_handler.c utils.c stack_handler.c stack_sorter.c simple_operations.c \
		testing_utils.c small_sorter.c

SRC_DIR = src/
SRC = $(addprefix $(SRC_DIR), $(FILES))

OBJ_DIR = objects/
OBJS = $(addprefix $(OBJ_DIR), $(FILES:.c=.o))
DEPS = $(addprefix $(OBJ_DIR), $(FILES:.c=.d))
RM = rm -rf

GREEN = \033[1;92m
RED = \033[1;91m
NC = \033[0m

LIBS = libft/libft.a

$(OBJ_DIR)%.o: $(SRC_DIR)%.c Makefile
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) -I./ -c $< -o $@

all:
	@$(MAKE) -C libft --no-print-directory 1> /dev/null
	@$(MAKE) $(NAME) --no-print-directory

$(NAME):: $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) $(LIBS) -o $@
	@echo "$(GREEN)push_swap compiled$(NC)"

$(NAME)::
	@echo -n

clean:
	@$(RM) $(OBJ_DIR) --no-print-directory
	@$(MAKE) clean -C libft --no-print-directory
	@echo "$(RED)\ndestruction successful\n$(NC)"

fclean: clean
	@$(RM) $(NAME) $(LIBS)

re: fclean all

.PHONY: all clean fclean re

-include $(DEPS)