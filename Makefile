NAME 		= 	libftprintf.a
CC 		= 	cc
HEAD		=	printf.h
CFLAGS 		= 	-Wall -Werror -Wextra -g
SRC 		= 	


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
