NAME = cpp03

OBJ_PATH = objs
SRC_PATH = srcs

SRC = ClapTrap.cpp main.cpp
# SRC := $(addprefix $(SRC_PATH)/,$(SRC))

OBJ = $(patsubst %.cpp,$(OBJ_PATH)/%.o,$(SRC))

CC = c++
CFLAGS = -Wall -Werror -Wextra -std=c++98 -g

all: $(NAME)

$(OBJ_PATH)/%.o: %.cpp
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME) : ${OBJ} Makefile
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) 

clean:
	rm -rf $(OBJ_PATH)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re