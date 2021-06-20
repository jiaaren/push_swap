/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reduce_make_efficient.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkhong <jkhong@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 15:20:10 by jkhong            #+#    #+#             */
/*   Updated: 2021/06/20 19:45:21 by jkhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doubly_linked_list.h"
#include "libpushswap.h"
#include "common_utils.h"

static int	count_operation(t_dlist *ops, int operation)
{
	int	count;

	count = 0;
	while (ops)
	{
		if (ops->content != operation)
			break ;
		count++;
		ops = ops->next;
	}
	return (count);
}

static int	swap(int operation)
{
	if (operation == RA)
		return (RRA);
	if (operation == RRA)
		return (RA);
	if (operation == RB)
		return (RRB);
	if (operation == RRB)
		return (RB);
	return (none);
}

// else if (ops->content == RA || ops->content == RB || 
// 	ops->content == RB || ops->content == RRB || ops->content == none)
// this assumes that i will never have a zero len pa/pb

static void	update_count(t_dlist *ops, t_efficient *x)
{
	if (ops->content == RA || ops->content == RRA)
	{
		x->count = count_operation(ops, ops->content);
		if (x->count > (x->a_len / 2))
		{
			x->to_count = false;
			x->to_swap = x->a_len - x->count;
			x->operation = ops->content;
		}
	}
	else if (ops->content == RB || ops->content == RRB)
	{
		x->count = count_operation(ops, ops->content);
		if (x->count > (x->b_len / 2))
		{
			x->to_count = 0;
			x->to_swap = x->b_len - x->count;
			x->operation = ops->content;
		}
	}
}

static void	swap_operations(t_dlist *ops, t_efficient *x)
{
	if (x->to_swap-- > 0)
		ops->content = swap(x->operation);
	else if (x->to_swap <= 0 && x->count)
		ops->content = none;
	x->count--;
	if (!x->count)
		x->to_count = true;
}

/*
	t_efficient is made up of the following data types
		int		a_len;
		int		b_len;
		bool	to_count;
		int		count;
		int		to_swap;
		int		operation;
	have not initialised the rest (i.e. except a_len and t_count), 
	as static will default the rest to 0.
*/
void	make_efficient(t_dlist *ops, int stack_len)
{
	static t_efficient	x;

	x.a_len = stack_len;
	x.to_count = true;
	while (ops)
	{
		if (ops->content == PB)
		{
			x.a_len--;
			x.b_len++;
		}
		else if (ops->content == PA)
		{
			x.a_len++;
			x.b_len--;
		}
		else
		{
			if (x.to_count)
				update_count(ops, &x);
			if (!x.to_count && ops->content == x.operation)
				swap_operations(ops, &x);
		}
		ops = ops->next;
	}
}
