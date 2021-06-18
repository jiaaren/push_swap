/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common_utils.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkhong <jkhong@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/18 17:53:01 by jkhong            #+#    #+#             */
/*   Updated: 2021/06/18 18:03:47 by jkhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	COMMON_UTILS_H
# define COMMON_UTILS_H

# include "doubly_linked_list.h"

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

void	update_operations(t_dstack *stacks, int op);
void    sa(t_dstack *stacks);
void    sb(t_dstack *stacks);
void    ss(t_dstack *stacks);
void    pa(t_dstack *stacks);
void    pb(t_dstack *stacks);
void    ra(t_dstack *stacks);
void    rb(t_dstack *stacks);
void    rr(t_dstack *stacks);
void    rra(t_dstack *stacks);
void    rrb(t_dstack *stacks);
void    rrr(t_dstack *stacks);

#endif