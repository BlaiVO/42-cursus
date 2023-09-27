# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: blvilarn <blvilarn@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/04 16:15:09 by blvilarn          #+#    #+#              #
#    Updated: 2023/09/27 17:43:55 by blvilarn         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philosophers
CFLAGS = -Wall -Wextra -Werror
FILES = philosophers.c not_libft.c

SRC_DIR = src/
SRC = $(addprefix $(SRC_DIR), $(FILES))

OBJ_DIR = objects/
OBJS = $(addprefix $(OBJ_DIR), $(FILES:.c=.o))
DEPS = $(addprefix $(OBJ_DIR), $(FILES:.c=.d))
RM = rm -rf

GREEN = \033[1;92m
RED = \033[1;91m
NC = \033[0m

$(OBJ_DIR)%.o: $(SRC_DIR)%.c Makefile
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) -I./ -c $< -o $@

all:
	@$(MAKE) $(NAME) --no-print-directory

$(NAME):: $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -o $@
	@echo "$(GREEN)philosophers compiled$(NC)"

$(NAME)::
	@echo -n

clean:
	@$(RM) $(OBJ_DIR) --no-print-directory
	@echo "$(RED)destruction successful$(NC)"

fclean: clean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re

-include $(DEPS)