CC = gcc
CFLAGS = -Wall -Wextra -Werror -c
SRC = src/ft_printf.c \
	  src/pf_parse.c \
	  src/pf_isflag.c \
	  src/pf_istype.c \
	  src/pf_getdignum.c \
	  src/pf_putstr.c \
	  src/pf_putint.c \
	  src/pf_puthex.c \
	  src/pf_write_data.c \
	  src/pf_order.c \
	  src/pf_putprec.c \
	  src/pf_putprefix.c \
	  src/pf_putwidth.c \
	  src/pf_getarg.c \
	  src/pf_lcnew.c \
	  src/pf_lcadd_back.c \
	  src/pf_lcprint_n_clear.c \
	  src/pf_lcclear.c \
	  src/pf_putnbr.c
OBJ = $(notdir $(SRC:.c=.o))

LIBFT_DIR = ../../..
INC = $(LIBFT_DIR)/inc
NAME = printf.a

all: $(NAME)

$(NAME): $(OBJ)

%.o: src/%.c
	$(CC) $(CFLAGS) $< -I $(INC)  -o $@ && ar -rcs $(NAME) $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
