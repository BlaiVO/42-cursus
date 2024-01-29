# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: blvilarn <blvilarn@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/04 17:25:14 by blvilarn          #+#    #+#              #
#    Updated: 2024/01/22 16:06:14 by blvilarn         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SERVER_NAME = server
CLIENT_NAME = client

SERVER_BONUS_NAME = server_bonus
CLIENT_BONUS_NAME = client_bonus

CFLAGS = -Wall -Wextra -Werror

SERVER_FILES = server.c
CLIENT_FILES = client.c

SERVER_BONUS_FILES = server_bonus.c
CLIENT_BONUS_FILES = client_bonus.c

FILES = $(SERVER_FILES) $(CLIENT_FILES)

BONUS_FILES = $(SERVER_BONUS_FILES) $(CLIENT_BONUS_FILES)

SRC_DIR = src/
SRC = $(addprefix $(SRC_DIR), $(FILES))
BONUS_SRC = $(addprefix $(SRC_DIR), $(BONUS_FILES))

OBJ_DIR = objects/
SERVER_OBJS = $(addprefix $(OBJ_DIR), $(SERVER_FILES:.c=.o))
CLIENT_OBJS = $(addprefix $(OBJ_DIR), $(CLIENT_FILES:.c=.o))
SERVER_DEPS = $(addprefix $(OBJ_DIR), $(SERVER_FILES:.c=.d))
CLIENT_DEPS = $(addprefix $(OBJ_DIR), $(CLIENT_FILES:.c=.d))

SERVER_BONUS_OBJS = $(addprefix $(OBJ_DIR), $(SERVER_BONUS_FILES:.c=.o))
CLIENT_BONUS_OBJS = $(addprefix $(OBJ_DIR), $(CLIENT_BONUS_FILES:.c=.o))
SERVER_BONUS_DEPS = $(addprefix $(OBJ_DIR), $(SERVER_BONUS_FILES:.c=.d))
CLIENT_BONUS_DEPS = $(addprefix $(OBJ_DIR), $(CLIENT_BONUS_FILES:.c=.d))

RM = rm -rf

GREEN = \033[1;92m
RED = \033[1;91m
NC = \033[0m

LIBS = libft/libft.a

$(OBJ_DIR)%.o: $(SRC_DIR)%.c Makefile
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) -I./ -c $< -o $@

all: libs
	@$(MAKE) $(SERVER_NAME) --no-print-directory
	@$(MAKE) $(CLIENT_NAME) --no-print-directory

$(SERVER_NAME): $(SERVER_OBJS) libs
	@$(CC) $(CFLAGS) $(SERVER_OBJS) $(LIBS) -o $@
	@echo "$(GREEN)server compiled$(NC)"

$(CLIENT_NAME): $(CLIENT_OBJS) libs
	@$(CC) $(CFLAGS) $(CLIENT_OBJS) $(LIBS) -o $@
	@echo "$(GREEN)client compiled$(NC)"
	
libs:
	@$(MAKE) -C libft --no-print-directory > /dev/zero

clean:
	@$(RM) $(OBJ_DIR) --no-print-directory
	@$(MAKE) clean -C libft --no-print-directory
	@echo "$(RED)\ndestruction successful\n$(NC)"

fclean: clean
	@$(RM) $(SERVER_NAME) $(CLIENT_NAME) $(SERVER_BONUS_NAME) $(CLIENT_BONUS_NAME) $(LIBS)

re: fclean all

bonus: all
	@$(MAKE) -C libft --no-print-directory
	@$(MAKE) $(SERVER_BONUS_NAME) --no-print-directory
	@$(MAKE) $(CLIENT_BONUS_NAME) --no-print-directory

$(SERVER_BONUS_NAME): $(SERVER_BONUS_OBJS)
	@$(CC) $(CFLAGS) $(SERVER_BONUS_OBJS) $(LIBS) -o $@
	@echo "$(GREEN)server bonus compiled$(NC)"	

$(CLIENT_BONUS_NAME): $(CLIENT_BONUS_OBJS)
	@$(CC) $(CFLAGS) $(CLIENT_BONUS_OBJS) $(LIBS) -o $@
	@echo "$(GREEN)client bonus compiled$(NC)"

.PHONY: all clean fclean re bonus server client libs

-include $(DEPS)