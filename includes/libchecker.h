/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libchecker.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkhong <jkhong@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/18 12:06:18 by jkhong            #+#    #+#             */
/*   Updated: 2021/06/21 21:25:55 by jkhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBCHECKER_H
# define LIBCHECKER_H

# define OPERATION_NUM 11
# include <stdio.h>
# include "libft.h"
# include "libpushswap.h"
# include "libchecker.h"

t_list	*make_list(int fd, int *row);
void	apply_operation(t_dstack *stacks);

#endif
