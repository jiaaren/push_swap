/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libpushswap.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkhong <jkhong@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 21:04:02 by jkhong            #+#    #+#             */
/*   Updated: 2021/06/17 13:38:21 by jkhong           ###   ########.fr       */
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
}               t_dstack;

typedef enum s_operations
{
	none,
	sa,
	sb,
	ss,
	pa,
	pb,
	ra,
	rb,
	rr,
	rra,
	rrb,
	rrr,
}           e_operations;

int         ft_strlen(char *str);
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

#endif