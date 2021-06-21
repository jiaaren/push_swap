/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common_utils.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkhong <jkhong@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/18 17:53:01 by jkhong            #+#    #+#             */
/*   Updated: 2021/06/22 00:43:29 by jkhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMON_UTILS_H
# define COMMON_UTILS_H

# include "doubly_linked_list.h"

typedef enum e_operations
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
}			t_operations;

// push_swap operations
void		update_operations(t_dstack *stacks, int op);
void		sa(t_dstack *stacks);
void		sb(t_dstack *stacks);
void		ss(t_dstack *stacks);
void		pa(t_dstack *stacks);
void		pb(t_dstack *stacks);
void		ra(t_dstack *stacks);
void		rb(t_dstack *stacks);
void		rr(t_dstack *stacks);
void		rra(t_dstack *stacks);
void		rrb(t_dstack *stacks);
void		rrr(t_dstack *stacks);

// other push_swap operation utils
void		print_operations(t_dlist *ops);
int			count_operations(t_dlist *ops);

// verification of user inputs
long		ft_long_atoi(const char *str);
int			*verify_input(int argc, char *argv[]);
void		*print_error(void);

// initialisation of stack
t_dstack	make_stacks(int *arr, int arrsize);
void		free_stacks(t_dstack *stacks);
int			is_sorted(t_dstack *stacks);

// Other utils
void		print_stack(t_dstack *stacks);

#endif