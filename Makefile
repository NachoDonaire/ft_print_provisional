SRCS		= 	count_functions.c ft_printf.c print_functions.c count_functions_2.c \
				print_functions_2.c
OBJS		=	${SRCS:.c=.o}
NAME		=	libftprintf.a
CC			=	gcc
RM 			=	rm -f
CFLAGS		=	-Wall -Werror -Wextra
.c.o:
	${CC} ${CFLAGS} -c ${SRCS} 
all:	${NAME}
$(NAME):	${OBJS}
	ar rc ${NAME} ${OBJS}
	ranlib ${NAME}
clean:
	${RM} ${OBJS}
fclean:
	${RM} ${NAME}
re:	fclean all
.PHONY: all clean fclean re
