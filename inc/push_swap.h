#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include "../Lib19/libft.h"

typedef struct s_elem {
	int				num;
	struct s_list	*next;
}	t_elem;

typedef struct s_stack {
	t_list	*first;
	int		count;
	int		max;
	int		min;
}	t_stack;

typedef struct s_data {
	t_stack		*a_stack;
	t_stack		*b_stack;
	char		**av;
	int			is_av_malloc;
}	t_data;

int		main(int ac, char **av);

int		check_arg(int ac, char **av);

int		get_proper_stack(int *ac, char ***av, t_data *data);

void	exit_and_free(t_data *data, int n);

void	free_arg(char **av);

t_stack	*fill_stack_with_ints(int ac, char **av);

t_stack	*init_empty_stack(void);

#endif