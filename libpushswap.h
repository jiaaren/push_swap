/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libpushswap.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkhong <jkhong@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 21:04:02 by jkhong            #+#    #+#             */
/*   Updated: 2021/06/17 21:44:59 by jkhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBPUSHSWAP_H
# define LIBPUSHSWAP_H

# include <unistd.h>
# include "doubly_linked_list.h"

typedef struct s_dstack
{
	t_stack *a;
	t_stack *b;
	int     len;
	t_stack	*operations;
}               t_dstack;

typedef enum s_operations
{
	none,
	SA,
	SB,
	SS,
	PA,
	PB,
	RA,
	RB,
	RR,
	RRA,
	RRB,
	RRR,
}           e_operations;

void        ft_putstr(char *str);
void        *print_error(void);
// make sure to have argc - 1 and &argv[1]
int         *verify_input(int argc, char *argv[]);

void        sa(t_dstack *stacks);
void        sb(t_dstack *stacks);
void        ss(t_dstack *stacks);
void        pa(t_dstack *stacks);
void        pb(t_dstack *stacks);
void        ra(t_dstack *stacks);
void        rb(t_dstack *stacks);
void        rr(t_dstack *stacks);
void        rra(t_dstack *stacks);
void        rrb(t_dstack *stacks);
void        rrr(t_dstack *stacks);
t_dstack	make_stacks(int *arr, int arrsize);
void        free_stacks(t_dstack *stacks);
int         is_sorted(t_dstack *stacks);

void	scan_operation_lst(t_dlist *ops);
void	print_operations(t_dlist *ops);
int	count_operations(t_dlist *ops);

int	*merge_sort(int *array, int start, int end);
int	get_median(int *arr, int arrsize);
int	to_traverse(int *arr, int arrsize, int median);
void	traverse_to_median(int *arr, int arrsize, t_dstack *stacks);

void	make_efficient(t_dlist *ops, int stack_len);
#endif