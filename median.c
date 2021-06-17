/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   median.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkhong <jkhong@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 16:43:43 by jkhong            #+#    #+#             */
/*   Updated: 2021/06/17 18:54:29 by jkhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libpushswap.h"

int	get_median(int *arr, int arrsize)
{
	int *tmp;
	int	median;

	tmp = merge_sort(arr, 0, arrsize - 1);
	median = tmp[(arrsize - 1) / 2];
	free(tmp);
	return (median);
}

// positive return would mean to execute r 'n' times, negative return would mean execuing rr n times
int	to_traverse(int *arr, int arrsize, int median)
{
	int index;
	int i;
	int r;
	int rr;

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

void	traverse_to_median(int *arr, int arrsize, t_dstack *stacks)
{
	int median;
	int	traverse;

	median = get_median(arr, arrsize);
	traverse = to_traverse(arr, arrsize, median);
	if (traverse > 0)
		while (traverse--)
			ra(stacks);
	else if (traverse < 0)
		while (traverse++)
			rra(stacks);
	// no need to care about instances of 0, i.e. no movement required
}