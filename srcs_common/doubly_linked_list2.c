/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doubly_linked_list2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkhong <jkhong@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/18 17:20:05 by jkhong            #+#    #+#             */
/*   Updated: 2021/06/18 17:39:34 by jkhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doubly_linked_list.h"

/*
	Needed to check if tmp_next != NULL
	just in case that the first has a NULL next, where a prev cannot be assigned
*/
void	ft_dlstadd_front(t_dlist *new, t_stack *stack)
{
	t_dlist	*tmp_next;

	if (!stack->start)
		ft_dlst_first(new, stack);
	else
	{
		tmp_next = stack->start;
		new->next = tmp_next;
		if (tmp_next)
			tmp_next->prev = new;
		stack->start = new;
	}
}

t_dlist	*ft_dlstpop_front(t_stack *stack)
{
	t_dlist	*tmp_pop;
	t_dlist	*tmp_new_head;

	if (!stack->start)
		return (NULL);
	tmp_pop = stack->start;
	tmp_new_head = tmp_pop->next;
	stack->start = tmp_new_head;
	if (tmp_new_head)
		tmp_new_head->prev = NULL;
	else
		stack->end = NULL;
	tmp_pop->next = NULL;
	tmp_pop->prev = NULL;
	return (tmp_pop);
}

t_dlist	*ft_dlstpop_back(t_stack *stack)
{
	t_dlist	*tmp_pop;
	t_dlist	*tmp_new_tail;

	if (!stack->end)
		return (NULL);
	tmp_pop = stack->end;
	tmp_new_tail = tmp_pop->prev;
	stack->end = tmp_new_tail;
	if (tmp_new_tail)
		tmp_new_tail->next = NULL;
	else
		stack->start = NULL;
	tmp_pop->prev = NULL;
	tmp_pop->next = NULL;
	return (tmp_pop);
}

void	ft_dlstadd_back(t_dlist *new, t_stack *stack)
{
	t_dlist	*tmp_prev;

	if (!stack->end)
		ft_dlst_first(new, stack);
	else
	{
		tmp_prev = stack->end;
		new->prev = tmp_prev;
		if (tmp_prev)
			tmp_prev->next = new;
		stack->end = new;
	}
}

int	ft_dlstsize(t_dlist *lst)
{
	int	len;

	len = 0;
	while (lst)
	{
		len++;
		lst = lst->next;
	}
	return (len);
}
