NAME			= push_swap

SRCS_LIST		= \
							push_swap.c

SRCS			= $(addprefix ${FOLDER}/, ${SRCS_LIST})

OBJS			= ${SRCS:.c=.o}

FOLDER			= srcs

LIBFT			= Lib19

CC				= gcc

CFLAGS			= -Wall -Wextra -Werror
LFLAGS			= -L Lib19 -lft

RM				= rm -f

all:			$(NAME)

$(NAME):		$(OBJS)
						@make bonus -s -C $(LIBFT)
						@$(CC) $(CFLAGS) $(LFLAGS) $(OBJS) -o $(NAME)

%.o: %.c
				@$(CC) $(CFLAGS) -o $@ -c $<

clean:
				@$(RM) $(OBJS)
				@make clean -C $(LIBFT)


fclean:		 clean
				@$(RM) $(NAME)
				@make fclean -C $(LIBFT)

re:				fclean all

.PHONY:			all fclean clean re
