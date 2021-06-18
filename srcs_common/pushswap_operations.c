/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap_operations.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkhong <jkhong@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 21:01:48 by jkhong            #+#    #+#             */
/*   Updated: 2021/06/18 15:22:15 by jkhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doubly_linked_list.h"
#include "libpushswap.h"

void	update_operations(t_dstack *stacks, e_operations op)
{
	t_dlist	*new;

	new = ft_dlstnew(op);
	ft_dlstadd_back(new, stacks->operations);	
}

void	sa(t_dstack *stacks)
{
	ft_dlstflip_front(stacks->a);
	update_operations(stacks, SA);
	// ft_putstr("sa\n");
}

void	sb(t_dstack *stacks)
{
	ft_dlstflip_front(stacks->b);
	update_operations(stacks, SB);
	// ft_putstr("sb\n");
}

void	ss(t_dstack *stacks)
{
	ft_dlstflip_front(stacks->a);
	ft_dlstflip_front(stacks->b);
	update_operations(stacks, SS);
	// ft_putstr("ss\n");
}

void	pa(t_dstack *stacks)
{
	if (stacks->b && stacks->b->start) // check if there are any values in stack_b, need a separate function to make sure any popping of data from a stack will make both start and end point to NULL
		ft_dlstadd_front(ft_dlstpop_front(stacks->b), stacks->a);
	update_operations(stacks, PA);
	// ft_putstr("pa\n"); // do nothnig if b is empty, but do i still need to output this?
}

void	pb(t_dstack *stacks)
{
	if (stacks->a && stacks->a->start) // check if there are any values in stack_b, need a separate function to make sure any popping of data from a stack will make both start and end point to NULL
		ft_dlstadd_front(ft_dlstpop_front(stacks->a), stacks->b);
	update_operations(stacks, PB);
	// ft_putstr("pb\n"); // do nothnig if b is empty, but do i still need to output this?
}

void	ra(t_dstack *stacks)
{
	if (stacks->a)
		ft_dlstadd_back(ft_dlstpop_front(stacks->a), stacks->a);
	update_operations(stacks, RA);
	// ft_putstr("ra\n");
}

void	rb(t_dstack *stacks)
{
	if (stacks->b)
		ft_dlstadd_back(ft_dlstpop_front(stacks->b), stacks->b);
	update_operations(stacks, RB);
	// ft_putstr("rb\n");
}

void	rr(t_dstack *stacks)
{
	if (stacks->a) // double check if ir eally need these if statements
		ft_dlstadd_back(ft_dlstpop_front(stacks->a), stacks->a);
	if (stacks->b) // double check if ir eally need these if statements
		ft_dlstadd_back(ft_dlstpop_front(stacks->b), stacks->b);
	update_operations(stacks, RR);
	// ft_putstr("rr\n");
}

void	rra(t_dstack *stacks)
{
	if (stacks->a)
		ft_dlstadd_front(ft_dlstpop_back(stacks->a), stacks->a);
	update_operations(stacks, RRA);
	// ft_putstr("rra\n");
}

void	rrb(t_dstack *stacks)
{
	if (stacks->b)
		ft_dlstadd_front(ft_dlstpop_back(stacks->b), stacks->b);
	update_operations(stacks, RRB);
	// ft_putstr("rrb\n");
}

void	rrr(t_dstack *stacks)
{
	if (stacks->a)
		ft_dlstadd_front(ft_dlstpop_back(stacks->a), stacks->a);
	if (stacks->b)
		ft_dlstadd_front(ft_dlstpop_back(stacks->b), stacks->b);
	update_operations(stacks, RRR);
	// ft_putstr("rrr\n");
}

t_dstack	make_stacks(int *arr, int arrsize)
{
	t_dstack	stacks;
	t_dlist		*tmp;
	int			i;

	stacks.a = malloc(sizeof(t_stack));
	stacks.b = malloc(sizeof(t_stack));
	stacks.operations = malloc(sizeof(t_stack));
	i = 0;
	// need to initialise or else got leaks
	// probabyl can separate function
	stacks.a->start = NULL;
	stacks.a->end = NULL;
	stacks.b->start = NULL;
	stacks.b->end = NULL;
	stacks.operations->start = NULL;
	stacks.operations->end = NULL;
	while (i < arrsize)
	{
		tmp = ft_dlstnew(arr[i]);
		ft_dlstadd_back(tmp, stacks.a);
		i++;
	}
	stacks.len = arrsize;
	return (stacks);
}

void	free_stacks(t_dstack *stacks)
{
	if (stacks->a->start)
		ft_dlstclear(&stacks->a->start);
	if (stacks->b->start)
		ft_dlstclear(&stacks->b->start);
	if (stacks->operations->start)
		ft_dlstclear(&stacks->operations->start);
	free(stacks->a);
	free(stacks->b);
	free(stacks->operations);
}

int	is_sorted(t_dstack *stacks)
{
	int		len;
	t_dlist *tmp;

	len = 0;
	tmp = stacks->a->start;
	while (tmp)
	{
		len++;
		if (!tmp->next)
			break ;
		if (tmp->content > tmp->next->content)
			return (0);
		tmp = tmp->next;
	}
	if (len != stacks->len)
		return (0);
	return (1);
}