/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkhong <jkhong@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/20 14:10:31 by jkhong            #+#    #+#             */
/*   Updated: 2021/06/20 19:47:40 by jkhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doubly_linked_list.h"
#include "common_utils.h"

static void	sort_two_b(t_dstack *stacks)
{
	t_dlist	*tmp;

	tmp = stacks->b->start;
	if (tmp->content < tmp->next->content)
		sb(stacks);
	else
		return ;
}

static void	sort_three_b_end(t_dstack *stacks)
{
	const int	tmp1 = stacks->b->start->content;
	const int	tmp2 = stacks->b->start->next->content;
	const int	tmp3 = stacks->b->start->next->next->content;

	if (tmp1 < tmp2)
	{
		if (tmp3 < tmp1)
			sb(stacks);
		else
			rb(stacks);
		if (tmp2 < tmp3)
			sb(stacks);
	}
	else
	{
		if (tmp1 > tmp2 && tmp1 < tmp3)
			rrb(stacks);
		else if (tmp3 > tmp2 && tmp3 < tmp1)
		{
			pa(stacks);
			rrb(stacks);
			pb(stacks);
		}
	}
}

static void	pa_sb_pb(t_dstack *stacks)
{
	pa(stacks);
	sb(stacks);
	pb(stacks);
}

static void	sort_three_b_noend(t_dstack *stacks)
{
	const int	tmp1 = stacks->b->start->content;
	const int	tmp2 = stacks->b->start->next->content;
	const int	tmp3 = stacks->b->start->next->next->content;

	if (tmp1 < tmp2 && tmp3 < tmp1)
		sb(stacks);
	else if (tmp1 > tmp3 && tmp2 < tmp3)
		pa_sb_pb(stacks);
	else if (tmp3 > tmp1 && tmp2 < tmp1)
	{
		pa_sb_pb(stacks);
		sb(stacks);
	}
	else if (tmp2 > tmp3 && tmp1 < tmp3)
	{
		sb(stacks);
		pa_sb_pb(stacks);
	}
	else if (tmp3 > tmp2 && tmp1 < tmp2)
	{
		sb(stacks);
		pa_sb_pb(stacks);
		sb(stacks);
	}
}

int	sort_less_four_b(t_dstack *stacks, int len)
{
	t_dlist	*tmp;

	if (len == 2)
		sort_two_b(stacks);
	else if (len == 3)
	{
		tmp = stacks->b->start->next->next->next;
		if (!tmp)
			sort_three_b_end(stacks);
		else
			sort_three_b_noend(stacks);
	}
	return (0);
}
