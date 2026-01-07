NAME    = libip2si.a
CC      = gcc
CFLAGS  = -Wall -Wextra -Werror -I./includes
RM      = rm -f

SRCS    = sources/ip_putchar.c \
          sources/ip_swap.c \
          sources/ip_putnbr.c \
          sources/ip_memset.c \
          sources/ip_memcpy.c \
          sources/ip_range.c \
          sources/ip_strdup.c \
          sources/ip_struct_magic.c \
          sources/ip_magic_number.c \
          sources/ip_iterative_factorial.c \
          sources/ip_pow.c \
          sources/simple_xor.c \
          sources/ip_file_info.c \
          sources/ip_cat.c \
          sources/ip_cp.c \
          sources/ip_crypt_file.c

OBJS    = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)
	@echo "Librairie créée avec succès !"

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all
