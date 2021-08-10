#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include "../Lib19/libft.h"

typedef struct s_elem {
	int				nb;
	struct s_elem	*next;
}	t_elem;

typedef struct s_stack {
	t_elem	*first;
	int		count;
	int		biggest;
	int		biggest_bis;
	int		biggest_ter;
	int		min;
}	t_stack;

typedef struct s_data {
	t_stack		*a_stack;
	t_stack		*b_stack;
	char		**av;
	int			is_av_malloc;
}	t_data;

typedef struct s_sorting
{
	int		ra;
	int		rb;
	int		rra;
	int		rrb;
}	t_sorting;

int		main(int ac, char **av);

int		check_arg(int ac, char **av);

int		get_proper_stack(int *ac, char ***av, t_data *data);

void	exit_and_free(t_data *data, int n);

void	free_arg(char **av);

t_stack	*fill_stack_with_ints(int ac, char **av);

t_stack	*init_empty_stack(void);

int		add_elem(t_stack *stack, int new_nb);

int		rem_elem(t_stack *stack);

void	free_stack(t_stack	*stack);

void	ft_lstclear_ps(t_elem *elem);

int		is_double(t_stack *stack);

int		is_sorted(t_stack *a_stack, t_stack *b_stack);

void	print_stack(t_stack *stack);

void	sort_by_type_of_stack(t_stack *a_stack, t_stack *b_stack);

void	sort_stack_of_two(t_stack *a_stack);

void	sort_stack_of_three(t_stack *a_stack);

void	sa_and_rep(t_stack *a_stack);

void	ra_and_rep(t_stack *a_stack);

void	rra_and_rep(t_stack *a_stack);

void	rb_and_rep(t_stack *b_stack);

void	rrb_and_rep(t_stack *b_stack);

void	swap(t_stack *stack);

void	rotate(t_stack *stack);

void	rev_rotate(t_stack *stack);

int		push(t_stack *a_stack, t_stack *b_stack);

void	stack_max_nb(t_stack *stack);

void	sort_big_stack(t_stack *a_stack, t_stack *b_stack);

#endif