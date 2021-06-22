/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkhong <jkhong@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/20 19:56:16 by jkhong            #+#    #+#             */
/*   Updated: 2021/06/22 14:53:43 by jkhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doubly_linked_list.h"
#include "common_utils.h"
#include "libchecker.h"

void	free_split(char **tmp_char)
{
	char	**ptr;

	ptr = tmp_char;
	while (*ptr)
		free(*ptr++);
	free(tmp_char);
}

// returns length of array
int	give_array(char ***argv)
{
	char	**tmp_char;
	int		arrsize;

	tmp_char = ft_split((*argv)[1], ' ');
	arrsize = 0;
	while (tmp_char[arrsize])
		arrsize++;
	*argv = tmp_char;
	return (arrsize);
}

int	main(int argc, char *argv[])
{
	int			arrsize;
	int			*arr;
	t_dstack	stacks;

	if (argc == 1)
		return (0);
	if (argc == 2)
		arrsize = give_array(&argv);
	else
	{
		argv = &argv[1];
		arrsize = argc - 1;
	}
	arr = verify_input(arrsize, argv);
	if (argc == 2)
		free_split(argv);
	if (arr)
	{
		stacks = make_stacks(arr, arrsize);
		free(arr);
		apply_operation(&stacks);
		free_stacks(&stacks);
	}
	return (0);
}
