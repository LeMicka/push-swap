NAME        := push_swap
CC        := gcc
FLAGS    := -g -Wall -Werror -Wextra
################################################################################
#                                 PROGRAM'S SRCS                               #
################################################################################

SRCS        :=      main.c \
												arg_errors.c \
												list.c \
												var_struct_creating.c \
												start_sort.c \
												sort_5.c \
												sort_bigs.c \
												moves_calculator.c \
												moves_calculator_helpers.c \
												swap.c \
												push.c \
												rotate.c \
												reverse_rotate.c \
													printf/ft_printf.c \
													printf/ft_printhex.c \
													printf/ft_printnbr.c \
													printf/ft_printptr.c \
													printf/libft/ft_atoi.c \
													printf/libft/ft_atoi_long.c \
													printf/libft/ft_bzero.c \
													printf/libft/ft_calloc.c \
													printf/libft/ft_isalnum.c \
													printf/libft/ft_isalpha.c \
													printf/libft/ft_isascii.c \
													printf/libft/ft_isdigit.c \
													printf/libft/ft_isprint.c \
													printf/libft/ft_itoa.c \
													printf/libft/ft_lstadd_back.c \
													printf/libft/ft_lstadd_front.c \
													printf/libft/ft_lstclear.c \
													printf/libft/ft_lstdelone.c \
													printf/libft/ft_lstiter.c \
													printf/libft/ft_lstlast.c \
													printf/libft/ft_lstmap.c \
													printf/libft/ft_lstnew.c \
													printf/libft/ft_lstsize.c \
													printf/libft/ft_memchr.c \
													printf/libft/ft_memcmp.c \
													printf/libft/ft_memcpy.c \
													printf/libft/ft_memmove.c \
													printf/libft/ft_memset.c \
													printf/libft/ft_putchar_fd.c \
													printf/libft/ft_putendl_fd.c \
													printf/libft/ft_putnbr_fd.c \
													printf/libft/ft_putstr.c \
													printf/libft/ft_putstr_fd.c \
													printf/libft/ft_split.c \
													printf/libft/ft_strcat.c \
													printf/libft/ft_strchr.c \
													printf/libft/ft_strcpy.c \
													printf/libft/ft_strdup.c \
													printf/libft/ft_striteri.c \
													printf/libft/ft_strjoin.c \
													printf/libft/ft_strlcat.c \
													printf/libft/ft_strlcpy.c \
													printf/libft/ft_strlen.c \
													printf/libft/ft_strmapi.c \
													printf/libft/ft_strncmp.c \
													printf/libft/ft_strnstr.c \
													printf/libft/ft_strrchr.c \
													printf/libft/ft_strtrim.c \
													printf/libft/ft_substr.c \
													printf/libft/ft_tolower.c \
													printf/libft/ft_toupper.c \
													printf/libft/ft_strcmp.c \
													printf/printf_functions.c \
													
OBJS        := $(SRCS:.c=.o)

.c.o:
	${CC} ${FLAGS} -c $< -o ${<:.c=.o}

################################################################################
#                                  Makefile  objs                              #
################################################################################


CLR_RMV		:= \033[0m
RED		    := \033[1;31m
GREEN		:= \033[1;32m
YELLOW		:= \033[1;33m
BLUE		:= \033[1;34m
CYAN 		:= \033[1;36m
RM		    := rm -f

${NAME}:	${OBJS}
			@echo "$(GREEN)Compilation ${CLR_RMV}of ${YELLOW}$(NAME) ${CLR_RMV}..."
			${CC} ${FLAGS} -o ${NAME} ${OBJS}
			@echo "$(GREEN)$(NAME) created[0m ✔️"

all:		${NAME}

py:		all
		python3 visualizer.py `ruby -e "puts (-50..49).to_a.shuffle.join(' ')"`

bonus:		all

clean:
			@ ${RM} *.o */*.o */*/*.o
			@ echo "$(RED)Deleting $(CYAN)$(NAME) $(CLR_RMV)objs ✔️"

fclean:		clean
			@ ${RM} ${NAME}
			@ echo "$(RED)Deleting $(CYAN)$(NAME) $(CLR_RMV)binary ✔️"

re:			fclean all

.PHONY:		all clean fclean re


