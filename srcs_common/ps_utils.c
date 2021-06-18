/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkhong <jkhong@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 21:01:48 by jkhong            #+#    #+#             */
/*   Updated: 2021/06/18 18:47:01 by jkhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doubly_linked_list.h"
#include "libft.h"
/*
	Initialise start and ends of stack to NULL
	Not automatically set to null, need this or else
	doubly linked list and operation functions do not work properly
*/
t_dstack	make_stacks(int *arr, int arrsize)
{
	t_dstack	stacks;
	t_dlist		*tmp;
	int			i;

	stacks.a = malloc(sizeof(t_stack));
	stacks.b = malloc(sizeof(t_stack));
	stacks.operations = malloc(sizeof(t_stack));
	i = 0;
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
	t_dlist	*tmp;

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

long	ft_long_atoi(const char *str)
{
	long	num;
	int		neg;

	num = 0;
	neg = 1;
	while (*str == ' ' || *str == '\f' || *str == '\n'
		|| *str == '\r' || *str == '\t' || *str == '\v')
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			neg *= -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		num = (num * 10) + (*str - '0');
		str++;
	}
	return (num * (long)neg);
}

void	*print_error(void)
{
	ft_putstr_fd("Error\n", 1);
	return (NULL);
}
