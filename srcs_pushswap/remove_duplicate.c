/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_duplicate.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkhong <jkhong@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 15:20:10 by jkhong            #+#    #+#             */
/*   Updated: 2021/06/20 15:20:58 by jkhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doubly_linked_list.h"
#include "libpushswap.h"
#include "common_utils.h"
#include "libft.h"

int	count_operation(t_dlist *ops, int operation)
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

int	swap(int operation)
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

void	make_efficient(t_dlist *ops, int stack_len)
{
	int	a_len;
	int	b_len;
	int	to_count;
	int	count;
	int	to_swap;
	int	operation;

	a_len = stack_len;
	b_len = 0;
	to_count = 1;
	while (ops)
	{
		if (ops->content == PB)
		{
			a_len--;
			b_len++;
		}
		else if (ops->content == PA)
		{
			a_len++;
			b_len--;
		}
		// else if (ops->content == RA || ops->content == RB || 
		// 	ops->content == RB || ops->content == RRB || ops->content == none)
		// 	;
		else
		{
			if (to_count)
			{
				// this assumes that i will never have a zero len pa/pb
				if (ops->content == RA || ops->content == RRA)
				{
					count = count_operation(ops, ops->content);
					if (count > (a_len / 2))
					{
						to_count = 0;
						to_swap = a_len - count;
						operation = ops->content;
					}
				}
				else if (ops->content == RB || ops->content == RRB)
				{
					count = count_operation(ops, ops->content);
					if (count > (b_len / 2))
					{
						to_count = 0;
						to_swap = b_len - count;
						operation = ops->content;
					}
				}
			}
			if (!to_count && ops->content == operation)
			{
				if (to_swap-- > 0)
					ops->content = swap(operation);
				else if (to_swap <= 0 && count)
					ops->content = none;
				count--;
				if (!count)
					to_count = 1;
			}
		}
		ops = ops->next;
	}
}
