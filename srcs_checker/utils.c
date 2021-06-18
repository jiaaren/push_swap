/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkhong <jkhong@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/18 12:05:35 by jkhong            #+#    #+#             */
/*   Updated: 2021/06/18 19:00:25 by jkhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "libchecker.h"
#include "doubly_linked_list.h"
#include "libpushswap.h"
#include "common_utils.h"

t_list	*make_list(int fd, int *row)
{
	char	*tmp;
	t_list	*lst;
	t_list	*last;
	t_list	*new;

	lst = NULL;
	last = lst;
	*row = 0;
	// interesting to have modified this, original version results in n2 time complexity
	while (get_next_line(fd, &tmp) > 0)
	{
		new = ft_lstnew(tmp);
		if (!last)
			ft_lstadd_back(&lst, new);
		else
			ft_lstadd_back(&last, new); // update to keep track of last?
		last = new;
		(*row)++;
	}
	free(tmp);
	return (lst);
}

int	return_index(char *operation)
{
	const char* operations[] = {"sa", "sb", "ss", "pa", "pb", "ra", 
			"rb", "rr", "rra", "rrb", "rrr"};
	int index;

	index = 0;
	while (index < OPERATION_NUM)
	{
		if (ft_strncmp(operation, operations[index], 4) == 0) // 4 because rrr has NUL as 4th end
			return (index);
		index++;
	}
	return (-1);
}

int	cycle_operation(t_list *lst, t_dstack *stacks)
{
	static void (*f[]) (t_dstack *) = {sa, sb, ss, pa, pb, ra, rb, rr, rra, rrb, rrr};
	int	index;

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
	int		operation_count; // unnecessary

	lst = make_list(0, &operation_count);
	if (cycle_operation(lst, stacks) != -1)
	{
		if (is_sorted(stacks))
			ft_putstr("OK\n");
		else
			ft_putstr("KO\n");
	}
	ft_lstclear(&lst, free);
}