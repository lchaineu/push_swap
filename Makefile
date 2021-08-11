NAME			= push_swap

CC				= gcc
FLAGS			= -Wall -Werror -Wextra
INCL			= ./inc/
LIBFT_PATH		= ./Lib19/

CFLAGS			=-I$(LIBFT_PATH)inc/ -I $(INCL) $(FLAGS)

LINKS		=	-L $(LIBFT_PATH) -lft



SRCS_EXIT	=	free.c

SRCS_MAIN	=	main.c

SRCS_OPERATIONS		=	apply_ops_and_write.c
						operations.c

SRCS_PARSE_AND_SET	=	args_checkers.c
						set_and_print_stack.c
						stack_checkers.c

SRCS_SORTING		=	big_stacks_sorting.c
						calculate_opti_ops.c
						small_stack_sorting.c
						sort_and_print_answer.c

SRCS_UTILS			=	add_remove_elem.c
						utils.c


OBJS			= ${SRCS:.c=.o}


######## RULES ########

all:			$(NAME)

$(NAME):		 $(OBJ_PSWAP)
			@$(CC) -o $(NAME) $(OBJ_PSWAP) $(CFLAGS) $(LINKS)

clean:
			@/bin/rm -rf $(OBJ_PSWAP)	

fclean:		 clean
				@$(RM) $(NAME)
				@make fclean -C $(LIBFT)

re:				fclean all

.PHONY:			all fclean clean re
