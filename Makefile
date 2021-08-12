# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lanachaineux <lanachaineux@student.42.f    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/12 08:17:32 by lanachaineu       #+#    #+#              #
#    Updated: 2021/08/12 08:22:57 by lanachaineu      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC					=	gcc
FLAGS				=	-Wall -Werror -Wextra
INCL				=	./inc/
LIBFT_PATH			=	./Lib19/

CFLAGS				=	-I$(LIBFT_PATH)inc/ -I $(INCL) $(FLAGS)

LINKS				=	-L $(LIBFT_PATH) -lft

######NAME#####

NAME				=	push_swap

###########PATH#############

SRCS_PATH			=	srcs/

SRCS_EXIT			=	frees.c

SRCS_MAIN			=	main.c

SRCS_OPERATIONS		=	apply_ops_and_write.c \
						operations.c

SRCS_PARSE_AND_SET	=	args_checkers.c \
						set_and_print_stack.c \
						stack_checkers.c

SRCS_SORTING		=	big_stacks_sorting.c \
						calculate_opti_ops.c \
						small_stack_sorting.c \
						sort_and_print_answer.c

SRCS_UTILS			=	add_remove_elem.c \
						utils.c

SRCS				=	$(addprefix $(SRCS_PATH)Exit/, $(SRCS_EXIT)) \
						$(addprefix $(SRCS_PATH)Main/, $(SRCS_MAIN)) \
						$(addprefix $(SRCS_PATH)Operations/, $(SRCS_OPERATIONS)) \
						$(addprefix $(SRCS_PATH)Parse_and_Set/, $(SRCS_PARSE_AND_SET)) \
						$(addprefix $(SRCS_PATH)Sorting/, $(SRCS_SORTING)) \
						$(addprefix $(SRCS_PATH)Utils/, $(SRCS_UTILS)) \

OBJS				= ${SRCS:.c=.o}

######## RULES ########

all : libs $(NAME)

$(NAME) : libs $(OBJS)
	@$(CC) -o $(NAME) $(OBJS) $(CFLAGS) $(LINKS)

clean :
	@/bin/rm -rf $(OBJS)
	@make -C $(LIBFT_PATH) clean	

fclean : clean
	@$(RM) $(NAME)
	@/bin/rm -rf $(LIBFT_PATH)libft.a

libs :
	@make -C $(LIBFT_PATH)

re : fclean all

.PHONY : all fclean clean re
