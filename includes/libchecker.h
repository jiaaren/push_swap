/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libchecker.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkhong <jkhong@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/18 12:06:18 by jkhong            #+#    #+#             */
/*   Updated: 2021/06/22 00:36:45 by jkhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBCHECKER_H
# define LIBCHECKER_H

# define OPERATION_NUM 11
# include "libft.h"
# include "libpushswap.h"
# include "libchecker.h"

t_list	*make_list(int fd, int *row);
void	apply_operation(t_dstack *stacks);

#endif
