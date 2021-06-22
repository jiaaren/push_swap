# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jkhong <jkhong@student.42kl.edu.my>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/18 11:30:38 by jkhong            #+#    #+#              #
#    Updated: 2021/06/22 15:10:10 by jkhong           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS_COM	=	$(wildcard ./srcs_common/*.c)
SRCS_PS		=	$(wildcard ./srcs_pushswap/*.c)
SRCS_CHECK	=	$(wildcard ./srcs_checker/*.c)
OBJS_COM	=	${SRCS_COM:.c=.o}
OBJS_PS		=	${SRCS_PS:.c=.o}
OBJS_CHECK	=	${SRCS_CHECK:.c=.o}
HEADER		=	-I ./includes -I ./libft/includes
LIB			=	-L ./libft	-l ft
CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror
NAME_PS		=	push_swap
NAME_CHECK	=	checker

%.o: %.c
			$(CC) $(CFLAGS) -c $(HEADER)  -O3 $< -o ${<:.c=.o}

all:		$(NAME_PS) $(NAME_CHECK)

libft:
			make -C ./libft

clean_libft:
			make clean -C ./libft

$(NAME_PS): libft $(OBJS_PS) $(OBJS_COM)
			$(CC) $(CFLAGS) -o $(NAME_PS) $(OBJS_COM) $(OBJS_PS) $(LIB)

$(NAME_CHECK): libft $(OBJS_CHECK) $(OBJS_COM)
			$(CC) $(CFLAGS) -o $(NAME_CHECK) $(OBJS_COM) $(OBJS_CHECK) $(LIB) 

clean:		clean_libft
			rm -f $(OBJS_COM) $(OBJS_PS) $(OBJS_CHECK)

fclean:		clean
			rm -f $(NAME_PS) $(NAME_CHECK) ./libft/libft.a

re:			fclean all

.PHONY:		all clean fclean re libft clean_libft
