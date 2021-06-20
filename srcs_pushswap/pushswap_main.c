/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap_main.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkhong <jkhong@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/20 19:35:24 by jkhong            #+#    #+#             */
/*   Updated: 2021/06/20 19:43:25 by jkhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doubly_linked_list.h"
#include "libpushswap.h"
#include "common_utils.h"

static void	sort_stack(int *arr, int arrsize)
{
	t_dstack	stacks;
	int			len_before;
	int			len_after;

	stacks = make_stacks(arr, arrsize);
	traverse_to_median(arr, arrsize, &stacks);
	free(arr);
	quick_sort(&stacks, stacks.len, 'a');
	len_before = count_operations(stacks.operations->start);
	if (stacks.operations->start)
	{
		while (1)
		{
			scan_operation_lst(stacks.operations->start);
			make_efficient(stacks.operations->start, stacks.len);
			len_after = count_operations(stacks.operations->start);
			if (len_before == len_after)
				break ;
			len_before = len_after;
		}
	}
	print_operations(stacks.operations->start);
	free_stacks(&stacks);
}

int	main(int argc, char *argv[])
{
	int	arrsize;
	int	*arr;

	if (argc == 1)
		return (0);
	arrsize = argc - 1;
	arr = verify_input(arrsize, &argv[1]);
	if (arr)
		sort_stack(arr, arrsize);
	return (0);
}
