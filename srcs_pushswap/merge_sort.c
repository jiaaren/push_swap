/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkhong <jkhong@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 16:58:35 by jkhong            #+#    #+#             */
/*   Updated: 2021/06/22 00:39:11 by jkhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

static int	*merge(int *array1, int size1, int *array2, int size2)
{
	int	*tmp;
	int	tmp_i;
	int	track_arr1;
	int	track_arr2;

	tmp = malloc(sizeof(int) * (size1 + size2));
	tmp_i = 0;
	track_arr1 = 0;
	track_arr2 = 0;
	while (track_arr1 < size1 && track_arr2 < size2)
	{
		if (array1[track_arr1] < array2[track_arr2])
			tmp[tmp_i] = array1[track_arr1++];
		else
			tmp[tmp_i] = array2[track_arr2++];
		tmp_i++;
	}
	while (track_arr1 < size1)
		tmp[tmp_i++] = array1[track_arr1++];
	while (track_arr2 < size2)
		tmp[tmp_i++] = array2[track_arr2++];
	free(array1);
	free(array2);
	return (tmp);
}

int	*merge_sort(int *array, int start, int end)
{
	int	mid;
	int	*tmp1;
	int	*tmp2;

	if (start == end)
	{
		tmp1 = malloc(sizeof(int) * 1);
		*tmp1 = array[start];
		return (tmp1);
	}
	mid = (start + end) / 2;
	tmp1 = merge_sort(array, start, mid);
	tmp2 = merge_sort(array, mid + 1, end);
	return (merge(tmp1, mid - start + 1, tmp2, end - mid));
}
