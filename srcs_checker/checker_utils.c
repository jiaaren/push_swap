/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkhong <jkhong@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/18 12:05:35 by jkhong            #+#    #+#             */
/*   Updated: 2021/06/22 00:36:20 by jkhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doubly_linked_list.h"
#include "libft.h"
#include "common_utils.h"
#include "libchecker.h"

/*
	- interesting to have modified this, 
	original version results in n2 time complexity
	- need if statement to check if last != NULL
*/
t_list	*make_list(int fd, int *row)
{
	char	*tmp;
	t_list	*lst;
	t_list	*last;
	t_list	*new;

	lst = NULL;
	last = lst;
	*row = 0;
	while (get_next_line(fd, &tmp) > 0)
	{
		new = ft_lstnew(tmp);
		if (!last)
			ft_lstadd_back(&lst, new);
		else
			ft_lstadd_back(&last, new);
		last = new;
		(*row)++;
	}
	free(tmp);
	return (lst);
}

// fix ftstrncmp to 4 because rrr has NUL as 4th end
static int	return_index(char *operation)
{
	const char	*operations[]
	= {"sa", "sb", "ss", "pa", "pb", "ra", "rb", "rr", "rra", "rrb", "rrr"};
	int			index;

	index = 0;
	while (index < OPERATION_NUM)
	{
		if (ft_strncmp(operation, operations[index], 4) == 0)
			return (index);
		index++;
	}
	return (-1);
}

static int	cycle_operation(t_list *lst, t_dstack *stacks)
{
	static	void	(*f[])(t_dstack *)
	= {sa, sb, ss, pa, pb, ra, rb, rr, rra, rrb, rrr};
	int				index;

	while (lst)
	{
		index = return_index((char *)lst->content);
		if (index == -1)
		{
			print_error();
			return (-1);
		}
		f[index](stacks);
		lst = lst->next;
	}
	return (0);
}

void	apply_operation(t_dstack *stacks)
{
	t_list	*lst;
	int		operation_count;

	lst = make_list(0, &operation_count);
	if (cycle_operation(lst, stacks) != -1)
	{
		if (is_sorted(stacks))
			ft_putstr_fd("OK\n", 1);
		else
			ft_putstr_fd("KO\n", 1);
	}
	ft_lstclear(&lst, free);
}
