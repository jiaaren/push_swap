/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_utils2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkhong <jkhong@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 21:06:24 by jkhong            #+#    #+#             */
/*   Updated: 2021/06/22 00:42:44 by jkhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common_utils.h"
#include "libft.h"
#include <limits.h>

/*
	Not used for final submission
	void	print_stack(t_dstack *stacks)
	{
		ft_putstr_fd("\n__a_front__\n", 1);
		ft_printlst(stacks->a->start, 'f');
		ft_putstr_fd("\n__b_front__\n", 1);
		ft_printlst(stacks->b->start, 'f');
	}
*/

static int	check_int_dig(char **nums, int numlen)
{
	int		i;
	char	*str;

	i = 0;
	while (i < numlen)
	{
		str = nums[i];
		if (*str == '-')
			str++;
		while (*str)
		{
			if (!(*str >= '0' && *str <= '9'))
				return (0);
			str++;
		}
		i++;
	}
	return (1);
}

static long	*make_long_arr(char **nums, int numlen)
{
	int		i;
	long	*tmp;

	tmp = malloc(sizeof(long) * numlen);
	i = 0;
	while (i < numlen)
	{
		tmp[i] = ft_long_atoi(nums[i]);
		i++;
	}
	return (tmp);
}

static int	*make_int_arr(long *nums, int numlen)
{
	int	i;
	int	*tmp;

	i = 0;
	tmp = malloc(sizeof(int) * numlen);
	while (i < numlen)
	{
		if ((nums[i] < INT_MIN || nums[i] > INT_MAX))
		{
			free(tmp);
			free(nums);
			return (NULL);
		}
		tmp[i] = (int)(nums[i]);
		i++;
	}
	free(nums);
	return (tmp);
}

static int	check_dup(int *nums, int numlen)
{
	int	i;
	int	j;

	i = 0;
	while (i < numlen)
	{
		j = i + 1;
		while (j < numlen)
		{
			if (nums[i] == nums[j])
			{
				free(nums);
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

/*
	Verify_input -> only function to be used externally
	Performs the following checks
	1. Checks argv to ensure only digits and ('-') are part of user input
	2. Creates long array to check int overflows
	3. Creates int array and check for duplicates
	- function returns false/NULL if checks are not satisfied

	Make sure to use (argc - 1) and (&argv[1])
*/
int	*verify_input(int argc, char *argv[])
{
	long	*tmp_long;
	int		*tmp_int;

	if (!check_int_dig(argv, argc))
		return (print_error());
	tmp_long = make_long_arr(argv, argc);
	tmp_int = make_int_arr(tmp_long, argc);
	if (!tmp_int)
		return (print_error());
	if (!check_dup(tmp_int, argc))
		return (print_error());
	return (tmp_int);
}
