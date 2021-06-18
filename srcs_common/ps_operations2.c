/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_operations2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkhong <jkhong@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/18 17:49:31 by jkhong            #+#    #+#             */
/*   Updated: 2021/06/18 18:01:47 by jkhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common_utils.h"

/*
	PA & PB
	check if there are any values in stack_b, need a separate
	function to make sure any popping of data from a stack will make
	both start and end point to NULL
*/
void	pa(t_dstack *stacks)
{
	if (stacks->b && stacks->b->start)
		ft_dlstadd_front(ft_dlstpop_front(stacks->b), stacks->a);
	update_operations(stacks, PA);
}

void	pb(t_dstack *stacks)
{
	if (stacks->a && stacks->a->start)
		ft_dlstadd_front(ft_dlstpop_front(stacks->a), stacks->b);
	update_operations(stacks, PB);
}

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

/*
	 double check if i really need these if statements
*/
void	rr(t_dstack *stacks)
{
	if (stacks->a)
		ft_dlstadd_back(ft_dlstpop_front(stacks->a), stacks->a);
	if (stacks->b)
		ft_dlstadd_back(ft_dlstpop_front(stacks->b), stacks->b);
	update_operations(stacks, RR);
}
