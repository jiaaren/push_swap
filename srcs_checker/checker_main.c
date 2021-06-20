/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkhong <jkhong@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/20 19:56:16 by jkhong            #+#    #+#             */
/*   Updated: 2021/06/20 19:58:57 by jkhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doubly_linked_list.h"
#include "common_utils.h"
#include "libchecker.h"

int	main(int argc, char *argv[])
{
	int			arrsize;
	int			*arr;
	t_dstack	stacks;

	if (argc == 1)
		return (1);
	arrsize = argc - 1;
	arr = verify_input(arrsize, &argv[1]);
	if (arr)
	{
		stacks = make_stacks(arr, arrsize);
		free(arr);
		apply_operation(&stacks);
		free_stacks(&stacks);
	}
	return (0);
}
