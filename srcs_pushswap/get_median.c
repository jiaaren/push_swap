/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_median.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkhong <jkhong@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 16:43:43 by jkhong            #+#    #+#             */
/*   Updated: 2021/06/21 21:11:10 by jkhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libpushswap.h"
#include "common_utils.h"

int	get_median(int *arr, int arrsize)
{
	int	*tmp;
	int	median;

	tmp = merge_sort(arr, 0, arrsize - 1);
	median = tmp[(arrsize - 1) / 2];
	free(tmp);
	return (median);
}

/*
	positive return would mean to execute r 'n' times
	negative return would mean execuing rr n times
*/
int	to_traverse(int *arr, int arrsize, int median)
{
	int	index;
	int	i;
	int	r;
	int	rr;

	index = 0;
	i = -1;
	while (++i < arrsize)
		if (arr[i] == median)
			index = i;
	r = index;
	rr = arrsize - index;
	if (r <= rr)
		return (r);
	else
		return (-rr);
}

/*
	Note: no need to care about instances of 0, i.e. no movement required
*/
void	traverse_to_median(int *arr, int arrsize, t_dstack *stacks)
{
	int	median;
	int	traverse;

	median = get_median(arr, arrsize);
	traverse = to_traverse(arr, arrsize, median);
	if (traverse > 0)
		while (traverse--)
			ra(stacks);
	else if (traverse < 0)
		while (traverse++)
			rra(stacks);
}

// for stack_quick_sort_median
int	give_median(t_dlist *lst, int len)
{
	int	*tmp;
	int	*tmp_sorted;
	int	i;
	int	median;

	tmp = malloc(sizeof(int) * len);
	i = 0;
	while (i < len)
	{
		tmp[i] = lst->content;
		lst = lst->next;
		i++;
	}
	tmp_sorted = merge_sort(tmp, 0, len - 1);
	median = tmp_sorted[(len - 1) / 2];
	free(tmp_sorted);
	free(tmp);
	return (median);
}
