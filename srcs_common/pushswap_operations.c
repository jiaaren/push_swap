/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap_operations.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkhong <jkhong@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 21:01:48 by jkhong            #+#    #+#             */
/*   Updated: 2021/06/18 18:02:51 by jkhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doubly_linked_list.h"
#include "libpushswap.h"

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