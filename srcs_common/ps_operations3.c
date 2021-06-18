/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_operations3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkhong <jkhong@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/18 17:49:42 by jkhong            #+#    #+#             */
/*   Updated: 2021/06/18 18:01:58 by jkhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common_utils.h"

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

void	rrr(t_dstack *stacks)
{
	if (stacks->a)
		ft_dlstadd_front(ft_dlstpop_back(stacks->a), stacks->a);
	if (stacks->b)
		ft_dlstadd_front(ft_dlstpop_back(stacks->b), stacks->b);
	update_operations(stacks, RRR);
}
