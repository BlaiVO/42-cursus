NAME = abstract
CC = c++
C_FLAGS = -Wall -Wextra -Werror -MMD -std=c++98 -pedantic
RM = rm -f

SRC = main.cpp Animal.cpp Dog.cpp Cat.cpp Brain.cpp

F_OBJ = obj/
OBJ = $(addprefix $(F_OBJ), $(SRC:.cpp=.o))
DEP = $(addprefix $(F_OBJ), $(SRC:.cpp=.d))

all: dir $(NAME)

-include ${DEP}

dir:
	@mkdir -p $(F_OBJ)

$(F_OBJ)%.o: %.cpp Makefile
	$(CC) $(C_FLAGS) -I ./ -c $< -o $@

$(NAME):: $(OBJ)
	$(CC) $(C_FLAGS) $(^) -o $(NAME)

clean:
	$(RM) $(OBJ) $(DEP)
	$(RM) -R obj

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re