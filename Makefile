SRCS    = main.c sort_operation.c list_crea.c

		  
HEADER  = push_swap.h

OBJS    = ${SRCS:.c=.o}

NAME    = push_swap

CC      = cc

RM      = rm -f
LIB = libft.a 
CFLAGS = -I./libft

CFLAGS1 = -Wall -Wextra -Werror -L./libft -lft -g3
#CFLAGS1 = -Wall -Wextra -Werror -L../Libft -lft -g3
#CFLAGS1 = -Wall -Wextra -Werror -L../minilibx-linux -lmlx_Linux -lmlx  -lXext -lX11 -lm -g3 -fsanitize=address

OPT     = valgrind  --leak-check=full

.c.o:
		${CC} ${CFLAGS} -c $< -o ${<:.c=.o}		
#		${CC} -c $< -o ${<:.c=.o}

all:    ${NAME}

${NAME}  :${OBJS}
		make -C ./libft
		${CC} ${CFLAGS1} $^ -o $@ ./libft/libft.a

clean:  
		make clean -C ./libft
		${RM} ${OBJS}


fclean: clean
		${RM} ${NAME}


re:     fclean all

.PHONY:         all clean fclean re
