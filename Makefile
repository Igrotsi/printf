NAME 		= 	libftprintf.a
CC 		= 	cc
HEAD		=	printf.h
CFLAGS 		= 	-Wall -Werror -Wextra -g
SRC 		= 	ft_printf.c \
			ft_putchar.c \
			ft_putnbr_base.c \
			ft_putnbr_lb.c \
			ft_putnbr.c \
			ft_putstr.c \
			ft_strlen.c \
			print_adress.c \
			sort_params.c

OBJ 		= 	$(SRC:%.c=%.o)

all: 			$(NAME)

$(NAME): 		$(OBJ)
				ar rcs $(NAME) $(OBJ)

%.o: %.c		$(HEAD) Makefile
				$(CC) $(CFLAGS) -c $< -o $@
clean:
				rm -f $(OBJ) $(OBJ_BONUS)

fclean:			clean
				rm -f $(NAME)

re:				fclean all

.PHONY:				all clean fclean re
