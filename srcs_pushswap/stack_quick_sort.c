/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_quick_sort.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkhong <jkhong@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/20 14:10:37 by jkhong            #+#    #+#             */
/*   Updated: 2021/06/21 09:52:10 by jkhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doubly_linked_list.h"
#include "common_utils.h"
#include "libpushswap.h"

static int	give_median(t_dlist *lst, int len)
{
	int	*tmp;
	int	*tmp_sorted;
	int i;
	int	median;

	tmp = malloc(sizeof(int) * len);
	i = 0;
	while (i < len)
	{
		tmp[i] = lst->content;
		lst = lst->next;
		i++;
	}
	tmp_sorted = merge_sort(tmp, 0, len - 1);
	median = tmp_sorted[(len - 1) / 2];
	free(tmp_sorted);
	free(tmp);
	return (median);
}
/*
	else if (stacks->a->start->content < pivot)
	{
		pb(stacks);
		pushed++;
	}
	else
	{
		pb(stacks);
		rb(stacks);
	}
*/

static int	partition_a(t_dstack *stacks, int len)
{
	int		i;
	int		pivot;
	int		pushed;

	i = 0;
	pushed = 0;
	pivot = give_median(stacks->a->start, len);
	while (i++ < len)
	{
		if (stacks->a->start->content > pivot)
			ra(stacks);
		else
		{
			pb(stacks);
			if (stacks->a->start->content < pivot)
				pushed++;
			else
				rb(stacks);
		}
	}
	i = 0;
	while (i++ < (len - pushed - 1))
		rra(stacks);
	return (pushed);
}

/*
	else if (stacks->b->start->content > pivot)
	{
		pa(stacks);
		pushed++;
	}
	else
	{
		pa(stacks);
		ra(stacks);
	}
*/
static int	partition_b(t_dstack *stacks, int len)
{
	int		i;
	int		pivot;
	int		pushed;

	i = 0;
	pushed = 0;
	pivot = give_median(stacks->b->start, len);
	while (i++ < len)
	{
		if (stacks->b->start->content < pivot)
			rb(stacks);
		else
		{
			pa(stacks);
			if (stacks->b->start->content > pivot)
				pushed++;
			else
				ra(stacks);
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
	rrb(stacks);
	pa(stacks);
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
	rra(stacks);
	pb(stacks);
	while (i < stack_a_len)
	{
		pb(stacks);
		i++;
	}
}

void	quick_sort(t_dstack *stacks, int stack_len, char cur_stack)
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
		quick_sort(stacks, stack_len - pushed - 1, 'a');
		quick_sort(stacks, pushed, 'b');
		merge_to_a(stacks, pushed);
	}
	else
	{
		pushed = partition_b(stacks, stack_len);
		quick_sort(stacks, stack_len - pushed - 1, 'b');
		quick_sort(stacks, pushed, 'a');
		merge_to_b(stacks, pushed);
	}
}	
