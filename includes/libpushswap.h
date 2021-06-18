/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libpushswap.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkhong <jkhong@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 21:04:02 by jkhong            #+#    #+#             */
/*   Updated: 2021/06/18 18:05:48 by jkhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBPUSHSWAP_H
# define LIBPUSHSWAP_H

# include <unistd.h>
# include "doubly_linked_list.h"


void        ft_putstr(char *str);
void        *print_error(void);
// make sure to have argc - 1 and &argv[1]
int         *verify_input(int argc, char *argv[]);


t_dstack	make_stacks(int *arr, int arrsize);
void        free_stacks(t_dstack *stacks);
int         is_sorted(t_dstack *stacks);

void		scan_operation_lst(t_dlist *ops);
void		print_operations(t_dlist *ops);
int			count_operations(t_dlist *ops);

int			*merge_sort(int *array, int start, int end);
int			get_median(int *arr, int arrsize);
int			to_traverse(int *arr, int arrsize, int median);
void		traverse_to_median(int *arr, int arrsize, t_dstack *stacks);

void		make_efficient(t_dlist *ops, int stack_len);
void		print_stack(t_dstack *stacks);

#endif