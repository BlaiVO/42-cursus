NAME = megaphone
FILES = megaphone.cpp
CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98

all: $(NAME)

$(NAME): $(NAME).cpp
	$(CC) $(CFLAGS) -o $(NAME) $(NAME).cpp
clean:
	$(RM) $(NAME) $(OBJS)

re: clean all

.PHONY: all clean re