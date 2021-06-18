# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jkhong <jkhong@student.42kl.edu.my>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/18 11:30:54 by jkhong            #+#    #+#              #
#    Updated: 2021/06/18 11:55:18 by jkhong           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS_COM	=	$(wildcard ../srcs_common/*.c)
SRCS_CHECK	=	$(wildcard ../srcs_checker/*.c)
HEADER		=	-I ../includes -I ../libft/includes
LIB			=	-L ../libft	-l ft
NAME		=	checker

all:		$(NAME)

$(NAME):	
			gcc $(HEADER) $(SRCS_COM) $(SRCS_CHECK) $(LIB) -o $(NAME)

clean:		
			rm -f $(NAME)

re:			clean all