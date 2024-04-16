NAME = libftprintf.a

LIBFT = ./libft/libft.a
CFLAGS = -Wall -Wextra -Werror
INC = ft_printf.h

SRC =	ft_printf.c \
	print_strings.c \
	print_nbr.c

OBJ = $(SRC:.c=.o)

all: $(NAME) clean

$(NAME): ${OBJ}
	make -C ./libft
	cp $(LIBFT) ${NAME}
	ar rc ${NAME} ${OBJ}

clean:
	${MAKE} clean -C ./libft
	rm -f ${OBJ}
	
fclean:	clean
	${MAKE} fclean -C ./libft
	rm -f ${NAME}
	
re: fclean all
