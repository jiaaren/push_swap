#include "libpushswap.h"
#include "doubly_linked_list.h"
#include "libchecker.h"

int	main(int argc, char *argv[])
{
	int		arrsize;
	int		*arr;
	t_dstack stacks;
	
	if (argc == 1)
		return (1);
	arrsize = argc - 1;
	arr = verify_input(arrsize, &argv[1]);
	if (arr)
	{
		stacks = make_stacks(arr, arrsize);
		free(arr);
		apply_operation(&stacks);
		free_stacks(&stacks);
	}
	return (0);
}