NAME = zombie

OBJ_PATH = objs

SRC = main.cpp newZombie.cpp randomChump.cpp Zombie.cpp

OBJ = $(patsubst %.cpp,$(OBJ_PATH)/%.o,$(SRC))

CC = c++
CFLAGS = -Wall -Werror -Wextra -std=c++98

all: $(NAME)

$(OBJ_PATH)/%.o: %.cpp
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME) : ${OBJ} Makefile Zombie.hpp
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) 

clean:
	rm -rf $(OBJ_PATH)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re