/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reduce_remove_duplicate.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkhong <jkhong@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/20 15:08:42 by jkhong            #+#    #+#             */
/*   Updated: 2021/06/22 13:41:20 by jkhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doubly_linked_list.h"
#include "common_utils.h"

// handles instances where there are dupliecate sa/sb/ss
static void	scan_swap(t_dlist *op_c, t_dlist *op_n)
{
	if (op_c->content == op_n->content)
	{
		op_c->content = none;
		op_n->content = none;
	}
	else if ((op_c->content == SA && op_n->content == SB)
		|| (op_c->content == SB && op_n->content == SA))
	{
		op_c->content = SS;
		op_n->content = none;
	}
}

static void	scan_overlap(t_dlist *op_c, t_dlist *op_n,
		int opp_operation, int swap)
{
	int		op;

	while (op_n)
	{
		op = op_n->content;
		if (op == swap || op == SS || op == PA
			|| op == PB || op == RR || op == RRR)
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

// Need to check of op == none
static void	scan_overlap_push(t_dlist *op_c, t_dlist *op_n, int opp_operation)
{
	int		op;

	while (op_n)
	{
		op = op_n->content;
		if (!(op == PA || op == PB || op == none))
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

// until list - 1 because we are performing comparisons
void	scan_operation_lst(t_dlist *ops)
{
	int	op;

	while (ops->next)
	{
		op = ops->content;
		if (op == SA || op == SB || op == SS)
			scan_swap(ops, ops->next);
		else if (op == PA)
			scan_overlap_push(ops, ops->next, PB);
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
