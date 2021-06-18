/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doubly_linked_list.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkhong <jkhong@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 17:38:47 by jkhong            #+#    #+#             */
/*   Updated: 2021/06/18 18:49:24 by jkhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOUBLY_LINKED_LIST_H
# define DOUBLY_LINKED_LIST_H

# include <stdlib.h>
# include <stdio.h>

typedef struct s_dlist
{
	struct s_dlist	*next;
	int				content;
	struct s_dlist	*prev;
}				t_dlist;

typedef struct s_stack
{
	t_dlist			*start;
	t_dlist			*end;
}				t_stack;

typedef struct s_dstack
{
	t_stack			*a;
	t_stack			*b;
	int				len;
	t_stack			*operations;
}				t_dstack;

t_dlist		*ft_dlstnew(int data);
void		ft_dlst_first(t_dlist *new, t_stack *stack);
void		ft_dlstadd_front(t_dlist *new, t_stack *stack);
void		ft_dlstadd_back(t_dlist *new, t_stack *stack);
void		ft_dlstclear(t_dlist **lst);
void		ft_printlst(t_dlist *lst, char direction);
t_dlist		*ft_dlstpop_front(t_stack *stack);
t_dlist		*ft_dlstpop_back(t_stack *stack);
void		ft_dlstflip_front(t_stack *stack);

#endif