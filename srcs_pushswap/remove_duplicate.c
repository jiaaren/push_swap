/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_duplicate.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkhong <jkhong@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 15:20:10 by jkhong            #+#    #+#             */
/*   Updated: 2021/06/18 18:05:29 by jkhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doubly_linked_list.h"
#include "libpushswap.h"
#include "common_utils.h"

void	scan_swap(t_dlist *op_c, t_dlist *op_n)
{
	if (op_c->content == op_n->content) // handles instances where there are dupliecate sa/sb/ss
	{
		op_c->content = none;
		op_n->content = none;
	}
	else if ((op_c->content == SA && op_n->content == SB) || 
		(op_c->content == SB && op_n->content == SA))
	{
		op_c->content = SS;
		op_n->content = none;
	}
}

void	scan_push(t_dlist *op_c, t_dlist *op_n)
{
	if ((op_c->content == PA && op_n->content == PB) || 
		(op_c->content == PB && op_n->content == PA))
	{
		op_c->content = none;
		op_n->content = none;
	}
}

void	scan_overlap(t_dlist *op_c, t_dlist *op_n, int opp_operation, int swap)
{
	int		op;

	while (op_n)
	{
		op = op_n->content;
		if (op == swap || op == SS || op == PA || op == PB || op == RR || op == RRR)
			break ;
		else if (op == opp_operation)
		{
			op_c->content = none;
			op_n->content = none;
			break ;
		}
		op_n = op_n->next;
	}
}
void	scan_overlap_push(t_dlist *op_c, t_dlist *op_n, int opp_operation)
{
	int		op;

	while (op_n)
	{
		op = op_n->content;
		if (!(op == PA || op == PB || op == none)) // need none here 
			break ;
		else if (op == opp_operation)
		{
			op_c->content = none;
			op_n->content = none;
			break ;
		}
		op_n = op_n->next;
	}
}

void	scan_operation_lst(t_dlist *ops)
{
	int op;

	while (ops->next) // until list - 1 because we are performing comparisons
	{
		op = ops->content;
		if (op == SA || op == SB || op == SS)
			scan_swap(ops, ops->next);
		else if (op == PA)
			scan_overlap_push(ops, ops->next, PB);
			// scan_push(ops, ops->next);
		else if (op == PB)
			scan_overlap_push(ops, ops->next, PA);
		else if (op == RA)
			scan_overlap(ops, ops->next, RRA, SA);
		else if (op == RRA)
			scan_overlap(ops, ops->next, RA, SA);
		else if (op == RB)
			scan_overlap(ops, ops->next, RRB, SB);
		else if (op == RRB)
			scan_overlap(ops, ops->next, RB, SB);
		ops = ops->next;
	}
}

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

void	print_operations(t_dlist *ops)
{
	const char *ops_str[] = {"none", "sa\n", "sb\n", "ss\n", "pa\n", "pb\n", 
						"ra\n", "rb\n", "rr\n", "rra\n", "rrb\n", "rrr\n"};

	while (ops)
	{
		if (ops->content != none)
			ft_putstr((char *)ops_str[ops->content]);
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