/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doubly_linked_list.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkhong <jkhong@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 17:35:33 by jkhong            #+#    #+#             */
/*   Updated: 2021/06/17 11:59:49 by jkhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doubly_linked_list.h"

t_dlist	*ft_dlstnew(int data)
{
	t_dlist *tmp;

	tmp = malloc(sizeof(t_dlist));
	if (!tmp)
		return (NULL);
	tmp->content = data;
	tmp->next = NULL;
	tmp->prev = NULL;
	return (tmp);
}

// when initialising, start and end will be pointing to a node, both of which will have a next and prev of NULL
void	ft_dlst_first(t_dlist *new, t_stack *stack)
{
	stack->start = new;
	stack->end = new;	
}

void	ft_dlstadd_front(t_dlist *new, t_stack *stack)
{
	t_dlist *tmp_next;

	if (!stack->start)
		ft_dlst_first(new, stack);
	else
	{
		tmp_next = stack->start;
		new->next = tmp_next;
		if (tmp_next)				// needed this just in case that the first has a NULL next, so don't have to assign a prev
			tmp_next->prev = new;
		stack->start = new;
	}
}

t_dlist	*ft_dlstpop_front(t_stack *stack)
{
	t_dlist *tmp_pop;
	t_dlist *tmp_new_head;

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
	t_dlist *tmp_pop;
	t_dlist *tmp_new_tail;

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
	t_dlist *tmp_prev;

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
	int len;

	len = 0;
	while (lst)
	{
		len++;
		lst = lst->next;
	}
	return (len);
}

void	ft_dlstclear(t_dlist **lst)
{
	t_dlist *tmp;

	while (*lst)
	{
		tmp = (*lst)->next;
		free(*lst);
		(*lst) = tmp;
	}
	*lst = NULL;
}

void	ft_dlstflip_front(t_stack *stack)
{
	t_dlist	*elem1;
	t_dlist	*elem2;

	if (!stack->start)
		return ;
	if (!stack->start->next)
		return ;
	elem1 = stack->start;
	elem2 = stack->start->next;
	if (elem2->next)
		elem2->next->prev = elem1;
	else
		stack->end = elem1;
	elem1->next = elem2->next;
	elem1->prev = elem2;
	elem2->next = elem1;
	elem2->prev = NULL;
	stack->start = elem2;
}

// replace printf with ftprintf
void	ft_printlst(t_dlist *lst, char direction)
{
	if (direction == 'f' || direction == 'F')
	{
		while (lst)
		{
			printf("%i\n", lst->content);
			lst = lst->next;
		}
	}
	if (direction == 'b' || direction == 'B')
	{
		while (lst)
		{
			printf("%i\n", lst->content);
			lst = lst->prev;
		}
	}
}