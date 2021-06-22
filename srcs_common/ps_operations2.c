/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_operations2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkhong <jkhong@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/18 17:49:31 by jkhong            #+#    #+#             */
/*   Updated: 2021/06/22 13:38:25 by jkhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common_utils.h"

void	ra(t_dstack *stacks)
{
	if (stacks->a)
		ft_dlstadd_back(ft_dlstpop_front(stacks->a), stacks->a);
	update_operations(stacks, RA);
}

void	rb(t_dstack *stacks)
{
	if (stacks->b)
		ft_dlstadd_back(ft_dlstpop_front(stacks->b), stacks->b);
	update_operations(stacks, RB);
}

void	rr(t_dstack *stacks)
{
	if (stacks->a)
		ft_dlstadd_back(ft_dlstpop_front(stacks->a), stacks->a);
	if (stacks->b)
		ft_dlstadd_back(ft_dlstpop_front(stacks->b), stacks->b);
	update_operations(stacks, RR);
}

void	rra(t_dstack *stacks)
{
	if (stacks->a)
		ft_dlstadd_front(ft_dlstpop_back(stacks->a), stacks->a);
	update_operations(stacks, RRA);
}

void	rrb(t_dstack *stacks)
{
	if (stacks->b)
		ft_dlstadd_front(ft_dlstpop_back(stacks->b), stacks->b);
	update_operations(stacks, RRB);
}
