NAME = push_swap

CFLAGS = -Wall -Wextra -Werror
PRINTF = "./ft_printf/libftprintf.a"
SRC = $(shell find ./src -iname "*.c")
MAIN = push_swap.c

OBJ = $(SRC:.c=.o)

all:	$(NAME)

$(NAME): $(OBJ)
		make -C ./ft_printf
		@$(CC) $(MAIN) $(SRC) $(PRINTF) $(HEADERS) -o $(NAME)
		make clean

%.o: %.c
	@$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS)

clean:
		make clean  -C ./ft_printf
		rm -f ${OBJ}

fclean:	clean
		make fclean -C ./ft_printf
		rm -f $(NAME)

re:	clean all
