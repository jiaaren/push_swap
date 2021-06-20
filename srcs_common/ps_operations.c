/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_operations.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkhong <jkhong@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/18 17:49:26 by jkhong            #+#    #+#             */
/*   Updated: 2021/06/20 19:32:10 by jkhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common_utils.h"

void	sa(t_dstack *stacks)
{
	ft_dlstflip_front(stacks->a);
	update_operations(stacks, SA);
}

void	sb(t_dstack *stacks)
{
	ft_dlstflip_front(stacks->b);
	update_operations(stacks, SB);
}

void	ss(t_dstack *stacks)
{
	ft_dlstflip_front(stacks->a);
	ft_dlstflip_front(stacks->b);
	update_operations(stacks, SS);
}

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
