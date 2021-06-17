#include "doubly_linked_list.h"
#include "libpushswap.h"

int main(void)
{
	int arr[] = {4, -12, 0, 100, 98, 56, 32};
	int arrsize = 7;

	t_dstack stacks = make_stacks(arr, arrsize);
	sa(&stacks);
	sb(&stacks);
	pb(&stacks);
	sb(&stacks);
	pb(&stacks);
	sb(&stacks);
	pa(&stacks);
	sb(&stacks);
	ra(&stacks);
	pb(&stacks);
	pb(&stacks);
	rb(&stacks);
	rr(&stacks);
	rra(&stacks);
	rrb(&stacks);
	rrr(&stacks);

	printf("\n__a_front__\n");
	ft_printlst(stacks.a->start, 'f');
	printf("\n__a_back__\n");
	ft_printlst(stacks.a->end, 'b');

	printf("\n__b_front__\n");
	ft_printlst(stacks.b->start, 'f');
	printf("\n__b_back__\n");
	ft_printlst(stacks.b->end, 'b');

}