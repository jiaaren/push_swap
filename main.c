#include "doubly_linked_list.h"
#include "libpushswap.h"

int	partition_a(t_dstack *stacks, int len)
{
	int		i;
	int		pivot;
	int		pushed;

	i = 0;
	pushed = 0;
	// pivot probably can choose a median number instead
	pivot = stacks->a->start->content;
	while (i++ < len)
	{
		if (stacks->a->start->content >= pivot)
			ra(stacks);
		else
		{
			pb(stacks);
			pushed++;
		}
	}
	i = 0;
	while (i++ < (len - pushed - 1))
		rra(stacks);
	return (pushed);
}

int	partition_b(t_dstack *stacks, int len)
{
	int		i;
	int		pivot;
	int		pushed;

	i = 0;
	pushed = 0;
	// pivot probably can choose a median number instead
	pivot = stacks->b->start->content;
	while (i++ < len)
	{
		if (stacks->b->start->content <= pivot)
			rb(stacks);
		else
		{
			pa(stacks);
			pushed++;
		}
	}
	i = 0;
	while (i++ < (len - pushed - 1))
		rrb(stacks);
	return (pushed);
}

void	merge_to_a(t_dstack *stacks, int stack_b_len)
{
	int i;

	i = 0;
	rra(stacks);
	while (i < stack_b_len)
	{
		pa(stacks);
		i++;
	}
}

void	merge_to_b(t_dstack *stacks, int stack_a_len)
{
	int i;

	i = 0;
	rrb(stacks);
	while (i < stack_a_len)
	{
		pb(stacks);
		i++;
	}
}

void	sort_two_a(t_dstack *stacks)
{
	t_dlist *tmp;

	tmp = stacks->a->start;
	if (tmp->content > tmp->next->content)
		sa(stacks);
	else
		return ;
}

void	sort_three_a_end(t_dstack *stacks)
{
	int	tmp1;
	int tmp2;
	int tmp3;

	tmp1 = stacks->a->start->content;
	tmp2 = stacks->a->start->next->content;
	tmp3 = stacks->a->start->next->next->content;
	if (tmp1 > tmp2)
	{
		if (tmp3 > tmp1)	// 2 1 3
			sa(stacks);
		else				// 3 1 2
			ra(stacks);
		if (tmp2 > tmp3) // 3 2 1
			sa(stacks);
	}
	else
	{
		if (tmp1 < tmp2 && tmp1 > tmp3) // 2 3 1
			rra(stacks);
		else if (tmp3 < tmp2 && tmp3 > tmp1)
		{
			pb(stacks);
			rra(stacks);
			pa(stacks);
		}
	}
}

int	sort_three_a_noend(t_dstack *stacks)
{
	int	tmp1;
	int tmp2;
	int tmp3;

	tmp1 = stacks->a->start->content;
	tmp2 = stacks->a->start->next->content;
	tmp3 = stacks->a->start->next->next->content;
	if (tmp1 > tmp2 && tmp3 > tmp1)
		sa(stacks);
	else if (tmp1 < tmp2 && tmp3 > tmp2)
		;
	else if (tmp1 < tmp3 && tmp2 > tmp3)
	{
		pb(stacks);
		sa(stacks);
		pa(stacks);
	}
	else if (tmp3 < tmp1 && tmp2 > tmp1)
	{
		pb(stacks);
		sa(stacks);
		pa(stacks);
		sa(stacks);
	}
	else if (tmp2 < tmp3 && tmp1 > tmp3)
	{
		sa(stacks);
		pb(stacks);
		sa(stacks);
		pa(stacks);
	}
	else if (tmp3 < tmp2 && tmp1 > tmp2)
	{
		sa(stacks);
		pb(stacks);
		sa(stacks);
		pa(stacks);
		sa(stacks);
	}
}

int	sort_less_four_a(t_dstack *stacks, int len)
{
	t_dlist *tmp;

	if (len == 2)
		sort_two_a(stacks);
	else if (len == 3)
	{
		tmp = stacks->a->start->next->next->next;
		if (!tmp)
			sort_three_a_end(stacks);
		else
			sort_three_a_noend(stacks);
	}
}

void	sort_two_b(t_dstack *stacks)
{
	t_dlist *tmp;

	tmp = stacks->b->start;
	if (tmp->content < tmp->next->content)
		sb(stacks);
	else
		return ;
}

void	sort_three_b_end(t_dstack *stacks)
{
	int	tmp1;
	int tmp2;
	int tmp3;

	tmp1 = stacks->b->start->content;
	tmp2 = stacks->b->start->next->content;
	tmp3 = stacks->b->start->next->next->content;
	if (tmp1 < tmp2)
	{
		if (tmp3 < tmp1)	// 2 1 3
			sb(stacks);
		else				// 3 1 2
			rb(stacks);
		if (tmp2 < tmp3) // 3 2 1
			sb(stacks);
	}
	else
	{
		if (tmp1 > tmp2 && tmp1 < tmp3) // 2 3 1
			rrb(stacks);
		else if (tmp3 > tmp2 && tmp3 < tmp1)
		{
			pa(stacks);
			rrb(stacks);
			pb(stacks);
		}
	}
}

int	sort_three_b_noend(t_dstack *stacks)
{
	int	tmp1;
	int tmp2;
	int tmp3;

	tmp1 = stacks->b->start->content;
	tmp2 = stacks->b->start->next->content;
	tmp3 = stacks->b->start->next->next->content;
	if (tmp1 < tmp2 && tmp3 < tmp1)
		sb(stacks);
	else if (tmp1 > tmp2 && tmp3 < tmp2)
		;
	else if (tmp1 > tmp3 && tmp2 < tmp3)
	{
		pa(stacks);
		sb(stacks);
		pb(stacks);
	}
	else if (tmp3 > tmp1 && tmp2 < tmp1)
	{
		pa(stacks);
		sb(stacks);
		pb(stacks);
		sb(stacks);
	}
	else if (tmp2 > tmp3 && tmp1 < tmp3)
	{
		sb(stacks);
		pa(stacks);
		sb(stacks);
		pb(stacks);
	}
	else if (tmp3 > tmp2 && tmp1 < tmp2)
	{
		sb(stacks);
		pa(stacks);
		sb(stacks);
		pb(stacks);
		sb(stacks);
	}
}

int	sort_less_four_b(t_dstack *stacks, int len)
{
	t_dlist *tmp;

	if (len == 2)
		sort_two_b(stacks);
	else if (len == 3)
	{
		tmp = stacks->b->start->next->next->next;
		if (!tmp)
			sort_three_b_end(stacks);
		else
			sort_three_b_noend(stacks);
	}
}

void	print_stack(t_dstack *stacks)
{
	printf("%i\n", stacks->len);
	printf("\n__a_front__\n");
	ft_printlst(stacks->a->start, 'f');
	printf("\n__b_front__\n");
	ft_printlst(stacks->b->start, 'f');
}

void	quick_sort(t_dstack *stacks, int stack_len, char cur_stack)
{
	int pushed_opposite;

	if (stack_len <= 1)
		return ;
	if (stack_len == 2 || stack_len == 3)
	{
		if (cur_stack == 'a')
			sort_less_four_a(stacks, stack_len);
		else
			sort_less_four_b(stacks, stack_len);
		return ;
	}
	if (cur_stack == 'a')
	{
		pushed_opposite = partition_a(stacks, stack_len);
		quick_sort(stacks, stack_len - pushed_opposite - 1, 'a');
		quick_sort(stacks, pushed_opposite, 'b');
		merge_to_a(stacks, pushed_opposite);
	}
	else
	{
		pushed_opposite = partition_b(stacks, stack_len);
		quick_sort(stacks, stack_len - pushed_opposite - 1, 'b');
		quick_sort(stacks, pushed_opposite, 'a');
		merge_to_b(stacks, pushed_opposite);

	}
}	

int main(int argc, char *argv[])
{
	int arrsize;
	int	*arr;
	t_dstack stacks;

	int len_before;
	int len_after;
	if (argc == 1)
		return (0);
	arrsize = argc - 1;

	// initialise stacks

	arr = verify_input(arrsize, &argv[1]);
	if (arr)
	{
		stacks = make_stacks(arr, arrsize);
		traverse_to_median(arr, arrsize, &stacks);
		free(arr);
		quick_sort(&stacks, stacks.len, 'a');
	
		print_stack(&stacks);
	
		len_before = count_operations(stacks.operations->start); 
		if (stacks.operations->start) {
			while (1) 
			{
				scan_operation_lst(stacks.operations->start);
				make_efficient(stacks.operations->start, stacks.len);
				len_after = count_operations(stacks.operations->start);
				if (len_before == len_after)
					break ;
				len_before = len_after;
			}
		}
		// ft_printlst(stacks.operations->start, 'f');
		print_operations(stacks.operations->start);
	}
}