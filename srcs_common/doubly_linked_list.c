/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doubly_linked_list.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkhong <jkhong@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 17:35:33 by jkhong            #+#    #+#             */
/*   Updated: 2021/06/18 17:37:20 by jkhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doubly_linked_list.h"
#include "libft.h"

t_dlist	*ft_dlstnew(int data)
{
	t_dlist	*tmp;

	tmp = malloc(sizeof(t_dlist));
	if (!tmp)
		return (NULL);
	tmp->content = data;
	tmp->next = NULL;
	tmp->prev = NULL;
	return (tmp);
}

/* 
	when initialising, start and end will required to be pointing to a node,
	both of which will have a next and prev of NULL
*/
void	ft_dlst_first(t_dlist *new, t_stack *stack)
{
	stack->start = new;
	stack->end = new;
}

void	ft_dlstclear(t_dlist **lst)
{
	t_dlist	*tmp;

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

void	ft_printlst(t_dlist *lst, char direction)
{
	if (direction == 'f' || direction == 'F')
	{
		while (lst)
		{
			ft_putnbr_fd(lst->content, 1);
			ft_putchar_fd('\n', 1);
			lst = lst->next;
		}
	}
	if (direction == 'b' || direction == 'B')
	{
		while (lst)
		{
			ft_putnbr_fd(lst->content, 1);
			ft_putchar_fd('\n', 1);
			lst = lst->prev;
		}
	}
}
