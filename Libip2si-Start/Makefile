NAME    = libip2si.a
CC      = gcc
CFLAGS  = -Wall -Wextra -Werror -I./includes

SRC     = sources/ip_putchar.c \
          sources/ip_putstr.c \
          sources/ip_strlen.c \
          sources/ip_strcmp.c \
          sources/ip_swap.c

OBJ     = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)
	@echo "Biblio $(NAME) créée"

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
