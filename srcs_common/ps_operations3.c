/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_operations3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkhong <jkhong@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/18 17:49:42 by jkhong            #+#    #+#             */
/*   Updated: 2021/06/20 19:34:22 by jkhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common_utils.h"
#include "libft.h"
#include <unistd.h>

void	rrr(t_dstack *stacks)
{
	if (stacks->a)
		ft_dlstadd_front(ft_dlstpop_back(stacks->a), stacks->a);
	if (stacks->b)
		ft_dlstadd_front(ft_dlstpop_back(stacks->b), stacks->b);
	update_operations(stacks, RRR);
}

void	update_operations(t_dstack *stacks, int op)
{
	t_dlist	*new;

	new = ft_dlstnew(op);
	ft_dlstadd_back(new, stacks->operations);
}

static void	output_print(char *buffer, int *buff_filled)
{
	if (write(1, buffer, *buff_filled))
		*buff_filled = 0;
}

void	print_operations(t_dlist *ops)
{
	const char	*ops_str[] = {"none", "sa\n", "sb\n", "ss\n", "pa\n", "pb\n",
						"ra\n", "rb\n", "rr\n", "rra\n", "rrb\n", "rrr\n"};
	char		buffer[10000];
	int			buff_filled;
	char		*tmp;

	buff_filled = 0;
	while (ops)
	{
		if (ops->content != none)
		{
			tmp = (char *)ops_str[ops->content];
			while (*tmp)
			{
				buffer[buff_filled] = *tmp++;
				buff_filled++;
			}
		}
		if (buff_filled > 9500)
			output_print(buffer, &buff_filled);
		ops = ops->next;
	}
	if (buff_filled)
		output_print(buffer, &buff_filled);
}

int	count_operations(t_dlist *ops)
{
	int	len;

	len = 0;
	while (ops)
	{
		if (ops->content != none)
			len++;
		ops = ops->next;
	}
	return (len);
}
