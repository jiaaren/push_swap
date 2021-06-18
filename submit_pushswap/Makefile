# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jkhong <jkhong@student.42kl.edu.my>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/18 11:30:38 by jkhong            #+#    #+#              #
#    Updated: 2021/06/18 12:52:14 by jkhong           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS_COM	=	$(wildcard ../srcs_common/*.c)
SRCS_PS		=	$(wildcard ../srcs_pushswap/*.c)
LIB			=	-I ../includes
NAME	=	push_swap
all:		$(NAME)

$(NAME):	
			gcc $(LIB) $(SRCS_COM) $(SRCS_PS) -o $(NAME)

clean:		
			rm -f $(NAME)

re:			clean all