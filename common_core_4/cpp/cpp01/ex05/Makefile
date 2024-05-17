NAME = harl
FILES = main.cpp harl.cpp
CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98

all: $(NAME)

$(NAME): $(FILES)
	$(CC) $(CFLAGS) -o $(NAME) $(FILES)

clean:
	$(RM) $(NAME)

re: clean all

.PHONY: all clean fclean re