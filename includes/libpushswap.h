/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libpushswap.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkhong <jkhong@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 21:04:02 by jkhong            #+#    #+#             */
/*   Updated: 2021/06/20 15:25:11 by jkhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBPUSHSWAP_H
# define LIBPUSHSWAP_H

# include <unistd.h>
# include <stdbool.h>
# include "doubly_linked_list.h"

typedef struct	s_efficient
{
	int		a_len;
	int		b_len;
	bool	to_count;
	int		count;
	int		to_swap;
	int		operation;
} 				t_efficient;


void		scan_operation_lst(t_dlist *ops);

int			*merge_sort(int *array, int start, int end);
int			get_median(int *arr, int arrsize);
int			to_traverse(int *arr, int arrsize, int median);
void		traverse_to_median(int *arr, int arrsize, t_dstack *stacks);

void		make_efficient(t_dlist *ops, int stack_len);
void		print_stack(t_dstack *stacks);

int			sort_less_four_b(t_dstack *stacks, int len);
int			sort_less_four_a(t_dstack *stacks, int len);
void		quick_sort(t_dstack *stacks, int stack_len, char cur_stack);

#endif