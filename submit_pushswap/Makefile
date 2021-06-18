# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jkhong <jkhong@student.42kl.edu.my>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/18 11:30:38 by jkhong            #+#    #+#              #
#    Updated: 2021/06/18 20:00:57 by jkhong           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS_COM	=	$(wildcard ../srcs_common/*.c)
SRCS_PS		=	$(wildcard ../srcs_pushswap/*.c)
OBJS_COM	=	${SRCS_COM:.c=.o}
OBJS_PS		=	${SRCS_PS:.c=.o}
HEADER		=	-I ../includes -I ../libft/includes
LIB			=	-L ../libft	-l ft
CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror
NAME		=	push_swap

%.o: %.c
			$(CC) $(CFLAGS) -c $(LIB) $(HEADER)  -O3 $< -o ${<:.c=.o}

all:		$(NAME)

$(NAME): 	$(OBJS_PS) $(OBJS_COM) 
			$(CC) $(CFLAGS) $(HEADER) -o $(NAME) $(OBJS_COM) $(OBJS_PS) $(LIB) 

clean:
			rm -f $(OBJS_COM) $(OBJS_PS)

fclean:		clean
			rm -f $(NAME)

re:			fclean all

.PHONY:		all clean fclean re