/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_operations.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkhong <jkhong@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/18 17:49:26 by jkhong            #+#    #+#             */
/*   Updated: 2021/06/18 17:59:45 by jkhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common_utils.h"

void	update_operations(t_dstack *stacks, int op)
{
	t_dlist	*new;

	new = ft_dlstnew(op);
	ft_dlstadd_back(new, stacks->operations);
}

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
