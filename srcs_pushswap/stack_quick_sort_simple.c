/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_quick_sort_simple.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkhong <jkhong@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 20:28:33 by jkhong            #+#    #+#             */
/*   Updated: 2021/06/22 13:43:18 by jkhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doubly_linked_list.h"
#include "common_utils.h"
#include "libpushswap.h"

static int	partition_a(t_dstack *stacks, int len)
{
	int		i;
	int		pivot;
	int		pushed;

	i = 0;
	pushed = 0;
	pivot = stacks->a->start->content;
	while (i++ < len)
	{
		if (stacks->a->start->content >= pivot)
			ra(stacks);
		else
		{
			pb(stacks);
			pushed++;
		}
	}
	i = 0;
	while (i++ < (len - pushed - 1))
		rra(stacks);
	return (pushed);
}

static int	partition_b(t_dstack *stacks, int len)
{
	int		i;
	int		pivot;
	int		pushed;

	i = 0;
	pushed = 0;
	pivot = stacks->b->start->content;
	while (i++ < len)
	{
		if (stacks->b->start->content <= pivot)
			rb(stacks);
		else
		{
			pa(stacks);
			pushed++;
		}
	}
	i = 0;
	while (i++ < (len - pushed - 1))
		rrb(stacks);
	return (pushed);
}

static void	merge_to_a(t_dstack *stacks, int stack_b_len)
{
	int	i;

	i = 0;
	rra(stacks);
	while (i < stack_b_len)
	{
		pa(stacks);
		i++;
	}
}

static void	merge_to_b(t_dstack *stacks, int stack_a_len)
{
	int	i;

	i = 0;
	rrb(stacks);
	while (i < stack_a_len)
	{
		pb(stacks);
		i++;
	}
}

void	quick_sort_simple(t_dstack *stacks, int stack_len, char cur_stack)
{
	int	pushed;

	if (stack_len <= 1)
		return ;
	if (stack_len == 2 || stack_len == 3)
	{
		if (cur_stack == 'a')
			sort_less_four_a(stacks, stack_len);
		else
			sort_less_four_b(stacks, stack_len);
	}
	else if (cur_stack == 'a')
	{
		pushed = partition_a(stacks, stack_len);
		quick_sort_simple(stacks, stack_len - pushed - 1, 'a');
		quick_sort_simple(stacks, pushed, 'b');
		merge_to_a(stacks, pushed);
	}
	else
	{
		pushed = partition_b(stacks, stack_len);
		quick_sort_simple(stacks, stack_len - pushed - 1, 'b');
		quick_sort_simple(stacks, pushed, 'a');
		merge_to_b(stacks, pushed);
	}
}
