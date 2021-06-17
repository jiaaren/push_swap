
SRCS	=	main.c	doubly_linked_list.c	pushswap_operations.c	utils.c		remove_duplicate.c	merge_sort.c	median.c
NAME	=	push_swap
all:		$(NAME)

$(NAME):	
			gcc -I/ $(SRCS) -o $(NAME)

clean:		
			rm -f $(NAME)

re:			clean all