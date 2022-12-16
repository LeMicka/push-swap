LIBFT = libft

LFLAGS = libft/libft.a

NAME    = libftprintf.a

SRCS    = ft_printf.c printf_functions.c ft_printptr.c ft_printnbr.c ft_printhex.c

OBJS    = ${SRCS:.c=.o}

CC  = gcc

FLAGS   = -Wall -Werror -Wextra

RM  = rm -f

AR = ar rcs

all: $(LFLAGS) $(NAME)

$(LFLAGS):
		$(MAKE) -C $(LIBFT) all

$(NAME): $(OBJS)
		@make -C $(LIBFT)
		@cp libft/libft.a .
		@mv libft.a $(NAME)
		@$(AR) $(NAME) $(OBJS)

%.o : %.c
	$(CC) $(FLAGS) -o $@ -c $<

clean:
	$(MAKE) -C ./libft clean
	rm -rf $(OBJS)

fclean:  clean
	$(MAKE) -C ./libft fclean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re