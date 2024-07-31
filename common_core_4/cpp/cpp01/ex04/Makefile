NAME = loosed
FILES = main.cpp
CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98

all: $(NAME)

$(NAME): $(FILES)
	$(CC) $(CFLAGS) -o $(NAME) $(FILES)

clean:
	$(RM) tests/*.replace

fclean:
	$(RM) $(NAME) tests/*.replace

re: clean all

.PHONY: all clean fclean re