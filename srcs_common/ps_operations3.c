/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_operations3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkhong <jkhong@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/18 17:49:42 by jkhong            #+#    #+#             */
/*   Updated: 2021/06/20 15:04:40 by jkhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common_utils.h"
#include "libft.h"

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

void	print_operations(t_dlist *ops)
{
	const char *ops_str[] = {"none", "sa\n", "sb\n", "ss\n", "pa\n", "pb\n", 
						"ra\n", "rb\n", "rr\n", "rra\n", "rrb\n", "rrr\n"};

	while (ops)
	{
		if (ops->content != none)
			ft_putstr_fd((char *)ops_str[ops->content], 1);
		ops = ops->next;
	}
}

int	count_operations(t_dlist *ops)
{
	int len;

	len = 0;
	while (ops)
	{
		if (ops->content != none)
			len++;
		ops = ops->next;
	}
	return (len);
}
