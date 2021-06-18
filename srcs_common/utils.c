/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkhong <jkhong@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 21:06:24 by jkhong            #+#    #+#             */
/*   Updated: 2021/06/18 15:04:04 by jkhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libpushswap.h"
#include <limits.h>

void	print_stack(t_dstack *stacks)
{
	printf("\n__a_front__\n");
	ft_printlst(stacks->a->start, 'f');
	printf("\n__b_front__\n");
	ft_printlst(stacks->b->start, 'f');
}

int	ft_strlen(char *str)
{
	int len;

	len = 0;
	while (*(str + len))
		len++;
	return (len);
}

void	ft_putstr(char *str)
{
	write(1, str, ft_strlen(str));
}

int	check_int_dig(char **nums, int numlen)
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

// link ft_atoi
long	*make_long_arr(char **nums, int numlen)
{
	int		i;
	long	*tmp;

	tmp = malloc(sizeof(long) * numlen);
	i = 0;
	while(i < numlen)
	{
		tmp[i] = ft_long_atoi(nums[i]);
		i++;
	}
	return (tmp);
}

int *make_int_arr(long *nums, int numlen)
{
	int i;
	int *tmp;

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

int check_dup(int *nums, int numlen)
{
	int i;
	int j;

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

void	*print_error(void)
{
	ft_putstr("Error\n");
	return (NULL);
}

int *verify_input(int argc, char *argv[])
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


