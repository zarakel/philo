CC = gcc

RM = rm -f

CFLAGS = -Wall -Wextra -Werror

NAME = get_next_line.a

OBJ = $(SRC:.c=.o)

SRC = $(wildcard *.c)

all: $(NAME)

$(NAME): $(OBJ)
	ar -rcs $(NAME) $(OBJ)

clean:
	$(RM) $(OBJ) $(BOBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

bonus: $(OBJ) $(BOBJ)
	ar -rcs $(NAME) $(OBJ) $(BOBJ)

.PHONEY: libft.a all clean fclean re bonus
