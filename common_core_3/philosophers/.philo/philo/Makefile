# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: blvilarn <blvilarn@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/12 12:00:09 by blvilarn          #+#    #+#              #
#    Updated: 2024/01/12 12:00:13 by blvilarn         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo
CFLAGS = -Wall -Wextra -Werror -MMD
FILES = main.c utils.c monitor.c routine_actions.c threads.c utils_get_params.c

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
	@echo "$(GREEN) philosophers compiled$(NC)"

$(NAME)::
	@echo -n

clean:
	@$(RM) $(OBJ_DIR) --no-print-directory
	@echo "$(RED)\ndestruction successful\n$(NC)"

fclean: clean
	@$(RM) $(NAME) 

re: fclean all

.PHONY: all clean fclean re bonus

-include $(DEPS)