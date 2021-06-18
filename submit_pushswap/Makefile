# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jkhong <jkhong@student.42kl.edu.my>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/18 11:30:38 by jkhong            #+#    #+#              #
#    Updated: 2021/06/18 17:31:09 by jkhong           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS_COM	=	$(wildcard ../srcs_common/*.c)
SRCS_PS		=	$(wildcard ../srcs_pushswap/*.c)
HEADER		=	-I ../includes -I ../libft/includes
LIB			=	-L ../libft	-l ft
NAME		=	push_swap

all:		$(NAME)

$(NAME):	
			gcc $(HEADER) $(SRCS_COM) $(SRCS_PS) $(LIB) -o $(NAME)

clean:		
			rm -f $(NAME)

re:			clean all