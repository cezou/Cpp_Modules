NAME = HITHISISBRAIN

OBJ_PATH = objs

SRC = main.cpp

OBJ = $(patsubst %.cpp,$(OBJ_PATH)/%.o,$(SRC))

CC = c++
CFLAGS = -Wall -Werror -Wextra -std=c++98

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