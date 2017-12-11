NAME = gnl

LIB = libft

SRC = get_next_line.c

OBJ = get_next_line.o

FLAGS = -Wextra -Werror -Wall

INCL = libft/includes

all: $(name)

$(NAME): $(LIB)
	clang $(FLAGS) -I $(INCL) -o $(OBJ) -c $(SRC)
	clang $(FLAGS) -I $(INCL) -o main.o -c main.c
	clang -o $(NAME) $(OBJ) main.o -I $(INCL) -L libft/ -lft

$(LIB):
	make -C libft/
