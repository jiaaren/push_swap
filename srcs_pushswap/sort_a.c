/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkhong <jkhong@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/20 14:10:25 by jkhong            #+#    #+#             */
/*   Updated: 2021/06/20 19:47:34 by jkhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doubly_linked_list.h"
#include "common_utils.h"

static void	sort_two_a(t_dstack *stacks)
{
	t_dlist	*tmp;

	tmp = stacks->a->start;
	if (tmp->content > tmp->next->content)
		sa(stacks);
	else
		return ;
}

static void	sort_three_a_end(t_dstack *stacks)
{
	const int	tmp1 = stacks->a->start->content;
	const int	tmp2 = stacks->a->start->next->content;
	const int	tmp3 = stacks->a->start->next->next->content;

	if (tmp1 > tmp2)
	{
		if (tmp3 > tmp1)
			sa(stacks);
		else
			ra(stacks);
		if (tmp2 > tmp3)
			sa(stacks);
	}
	else
	{
		if (tmp1 < tmp2 && tmp1 > tmp3)
			rra(stacks);
		else if (tmp3 < tmp2 && tmp3 > tmp1)
		{
			pb(stacks);
			rra(stacks);
			pa(stacks);
		}
	}
}

static void	pb_sa_pa(t_dstack *stacks)
{
	pb(stacks);
	sa(stacks);
	pa(stacks);
}

static void	sort_three_a_noend(t_dstack *stacks)
{
	const int	tmp1 = stacks->a->start->content;
	const int	tmp2 = stacks->a->start->next->content;
	const int	tmp3 = stacks->a->start->next->next->content;

	if (tmp1 > tmp2 && tmp3 > tmp1)
		sa(stacks);
	else if (tmp1 < tmp3 && tmp2 > tmp3)
		pb_sa_pa(stacks);
	else if (tmp3 < tmp1 && tmp2 > tmp1)
	{
		pb_sa_pa(stacks);
		sa(stacks);
	}
	else if (tmp2 < tmp3 && tmp1 > tmp3)
	{
		sa(stacks);
		pb_sa_pa(stacks);
	}
	else if (tmp3 < tmp2 && tmp1 > tmp2)
	{
		sa(stacks);
		pb_sa_pa(stacks);
		sa(stacks);
	}
}

int	sort_less_four_a(t_dstack *stacks, int len)
{
	t_dlist	*tmp;

	if (len == 2)
		sort_two_a(stacks);
	else if (len == 3)
	{
		tmp = stacks->a->start->next->next->next;
		if (!tmp)
			sort_three_a_end(stacks);
		else
			sort_three_a_noend(stacks);
	}
	return (0);
}
