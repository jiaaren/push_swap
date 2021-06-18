/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkhong <jkhong@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 18:00:46 by jkhong            #+#    #+#             */
/*   Updated: 2021/05/02 11:38:15 by jkhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char	num;

	if ((n / 10) != 0)
		ft_putnbr_fd(n / 10, fd);
	if (n < 0 && n >= -9)
		write(fd, "-", 1);
	if (n < 0)
		num = (-(n % 10)) + '0';
	else
		num = (n % 10) + '0';
	write(fd, &num, 1);
}
