*This Project Has Been Created As Part Of The 42 Curriculum By **Vorhansa***

# `Description`

Push Swap is a sorting algorithm implementation project and part of the Codam/school 42 core curriculum. The project tasks the students with writing a program in C that takes an unsorted list of integers as input and sorts them in ascending order using only two "stacks" and a limited set of operations. The aim of the project is to test the student's understanding of various sorting algorithms, their corresponding complexities and data structures, and the student's ability to implement this in code.

### Push_Swap Rules and Grading

The program is only allowed two stacks to work with, stack A and stack B. All the numbers are initially added to stack A, and B is empty.

The possible actions are:

* `pa` (push A): Take the first element at the top of B and put it at the top of A. Do nothing if B is empty.
* `pb` (push B): Take the first element at the top of A and put it at the top of B. Do nothing if A is empty.
* `sa` (swap A): Swap the first 2 elements at the top of stack A. Do nothing if there is only one or no elements.
* `sb` (swap B): Swap the first 2 elements at the top of stack B. Do nothing if there is only one or no elements.
* `ss`: `sa` and `sb` at the same time.
* `ra` (rotate A): Shift all elements of stack A up by 1. The first element becomes the last one.
* `rb` (rotate B): Shift all elements of stack B up by 1. The first element becomes the last one.
* `rr`: `ra` and `rb` at the same time.
* `rra` (reverse rotate A): Shift all elements of stack A down by 1. The last element becomes the first one.
* `rrb` (reverse rotate B): Shift all elements of stack b down by 1. The last element becomes the first one.
* `rrr` : `rra` and `rrb` at the same time.

* For maximum project validation (100%) and eligibility for bonuses, you must:
	* Sort 100 random numbers in fewer than 700 operations.
	* Sort 500 random numbers in no more than 5500 operations.
* For minimal project validation (which implies a minimum grade of 80%), you can succeed with different averages:
	* 100 numbers in under 1100 operations and 500 numbers in under 8500 operations.
	* 100 numbers in under 700 operations and 500 numbers in under 11500 operations.
	* 100 numbers in under 1300 operations and 500 numbers in under 5500 operation.  

### Bonus

The bonus part is to write a program named ```checker```, which will get as an argument the stack A formatted as a list of integers. Checker will then wait and read instructions on the standard input. Once all the instructions have been read, checker will execute them on the stack received as an argument (After giving the instructions press ```ctrl + d```).

If after executing those instructions, stack a is actually sorted and b is empty, then checker must display ```"OK"``` else ```"KO"```. If checker arguments are invalid it displays ```"Error"```.

The checker code can be found in the checker.c file in this repository.

# `Instrctions`

At the beginning. I make the two linked lists (stacks) A and B. `A` contains all input numbers, `B` starts empty `(NULL)`. Each individual number/value was stored in a node of a linked list. Assign an index to each node and respective value.

### `Stack`
```bash
typedef struct 		s_stack
{
	int				value;
	int				index;
	struct s_stack	*next;
} 					t_stack;
```


```bash
t_stack	*stack_a;
t_stack *stack_b;
```
### `Argument errors`

Next step. Check the errors. Errors include, some arguments not being integers, some arguments exceeding the integer limits, and/or the presence of duplicates. In case of error, it must display "Error" followed by an '\n' on the standard error.

: `check_input(ac, av)`
```bash
void	check_input(int ac, char **av)
{
	int		i;
	long	temp_av;
	char	**temp;

	i = 0;
	if (ac == 2)
		temp = ft_split(av[1], ' ');		// split argument from "1 2 3 4" to "1" "2" "3" "4"
	else
		temp = av + 1;
	while (temp[i])
	{
		temp_av = ft_atoi(temp[i]);
		if (temp_av < INT_MIN || temp_av > INT_MAX)	// Integer limits
			ft_putstr("ERROR");
		if (check_unique(temp))				// Duplicates
			ft_putstr("ERROR");
		if (!check_nbr(temp[i]))			// Not being integers
			ft_putstr("ERROR");
		i++;
	}
	if (ac == 2)
		ft_free (temp);
}
```
### `Initialize`

```bash
stack_a = init_list(ac, av);	 
stack_b = NULL;
```

Function `init_list` :	Builds `stack_a` from program input arguments.
```bash
t_stack	*init_list(int ac, char **av)
{
	t_stack	*stack_a;				// stack_a is resulting list.
	char	**tmp;					// tmp is token source.
	int		i;						// i is index.

	stack_a = NULL;
	i = 0;
	if (ac == 2)					// If ac == 2, user passed one quoted string like "3 2 1". 
		tmp = ft_split(av[1], ' ');	// ft_split splits it into tmp array.
	else							// If numbers are separate args, tmp points directly to av 
	{
		i = 1;						// i starts at 1 to skip program name.
		tmp = av;
	}
	while (tmp[i])
	{
		insert_at_tail(&stack_a, ft_atoi(tmp[i]));	// Adds a new number at the end of the linked list.
		i++;
	}
	if (ac == 2)
		ft_free(tmp);				// Free split array if allocated.
	return (stack_a);
}
```

Function `insert_at_tail` :	Adds a new number at the end of the linked list.
```bash
void	insert_at_tail(t_stack **head, int new_value)
{
	t_stack	*new_node;
	t_stack	*current;

	if (*head == NULL)				// If head is NULL, create first node and return.
	{
		*head = ft_lstnew_int(new_value);
		return ;
	}
	current = *head;
	while (current->next != NULL)	// Creates node then links it as last element.
		current = current->next;
	new_node = ft_lstnew_int(new_value);
	current->next = new_node;
}
```

Function `ft_lstnew_int` :	Creates a new linked-list node for the stack. Allocates and returns a pointer to a new `t_stack` node holding the given integer.
```bash
t_stack	*ft_lstnew_int(int value)
{
	t_stack	*new_node;

	new_node = ft_calloc(1, sizeof(t_stack));
	if (!new_node)
		return (NULL);
	new_node->value = value;		// Sets value to the provided int
	new_node->index = 0;
	new_node->next = NULL;
	return (new_node);
}
```

### `Set index`
```bash
set_index(stack_a, count_nodes(stack_a));
```
#### `Algorithm`

Before sorting our list we simplify our numbers for two reasons. 

First, Radix sort is a linear sorting algorithm that works by sorting the elements based on their digits. It sorts the elements by comparing the digits at different positions in each element. Since radix sort relies on the relative order of digits within the elements, it can only sort non-negative integers by their binary, decimal, or other positional representation. Negative integers cannot be sorted directly with radix sort because their binary representation involves a sign bit.\
Second, radix's [complexity](https://en.wikipedia.org/wiki/Analysis_of_algorithms) is based on the amount of bits respresenting an integer. We can reduce our big numbers to, at maximum, the biggest index in our linked list. Significantly reducing the number of operations needed to sort.

For example, if we need to sort these numbers

`87 -487 781 -100 101 0 1`

We want to replace them with 0, 1, 2, ...

`-487 -100 0 1 87 101 781` becomes `0 1 2 3 4 5 6`

`87 -487 781 -100 101 0 1` becomes `4 0 6 1 5 2 3`

So, instead of sorting `87 -487 781 -100 101 0 1`, now we only need to sort `4 0 6 1 5 2 3`.

With this method we can simplify any list of integers to make them in the range [0,N) ( ≥ 0 and < N, N is the size of the list).

When binary sorting with radix sort, each element in the list is viewed as a string of bits, and the algorithm sorts the elements based on the values of each bit position, starting from the least significant bit (rightmost) to the most significant bit (leftmost). This process is repeated until all bit positions have been considered, and the list is sorted. As mentioned above, one of the reasons why we reduce the actual numbers to index values. Less bits to take into consideration.

Function `set_index` : assigns each node in the stack a rank index (0..n-1) based on value.
```bash
void	set_index(t_stack *head, int link_size)
{
	t_stack	*biggest;
	t_stack	*tmp;

	while (link_size-- > 0)
	{
		biggest = NULL;
		tmp = head;
		while (tmp)
		{
			if (!tmp->index && (biggest == NULL
					|| tmp->value > biggest->value))
				biggest = tmp;
			tmp = tmp->next;
		}
		if (biggest)
			biggest->index = link_size;
	}
}
```
After completion, every node's `index` represents its sorted position: largest → n-1, smallest → 0.

### `Sort stack`
```bash
sort_stack(&stack_a, &stack_b);
```
#### The Actual Sorting

When we take our earlier input `4 0 6 1 5 2 3` their binary equivalents will be `100 000 110 001 101 010 11`.
The first argument will be at the top of our stack and subsequent numbers will be added behind/below it.

Starting at the least significant bit, we use the `AND` bitwise operation [ARG & 1](https://www.programiz.com/c-programming/bitwise-operators#and) and check to see if there is either a `1` or a `0` at that position.
If it's a 0 (lower in value), it get's pushed to Stack B, otherwise it rotates to the bottom. After all 0's have been pushed to Stack B, we push em all back to Stack A. Our list is now sorted at the least significant bit position in 0's and 1's.

```bash
100                             100
000                             000 
110                             110
001                    010      010
101             001    110      001
010             101    000      101
011             011    100      011
----   ----     ----   ----     ----   ----
a      b        a      b        a      b
```
We move over one bit and repeat this process.

```bash
100                             100
000                             000 
110                             001
010                    101      101
001             010    001      010
101             110    000      110
011             011    100      011
----   ----     ----   ----     ----   ----
a      b        a      b        a      b
```

Our list is now sorted for the second digit. We repeat this process one last time for the last available digit.

```bash
100                             000
000                             001 
001                             010
101                    011      011
010             100    010      100
110             101    001      101
011             110    000      110
----   ----     ----   ----     ----   ----
a      b        a      b        a      b
```
As you can see, the list is now completely sorted.


```bash
void	sort_stack(t_stack **stack_a, t_stack **stack_b)
{
	int	size;

	size = count_nodes(*stack_a);
	if (!sorted(stack_a) && size <= 3)
		sort_three(stack_a);
	else if (!sorted(stack_a) && size <= 5)
		sort_five(stack_a, stack_b);
	else if (!sorted(stack_a))
		radix_sort(stack_a, stack_b);
	else
	{
		free_stack(stack_a);
		free_stack(stack_b);
	}
}
```
appropriate algorithm based on size:
* 3 or fewer elements: Calls `sort_three()` — optimized for small stacks with minimal operations.
* 4-5 elements: Calls `sort_five()` — uses stack_b as auxiliary and sorts via a targeted approach.
* More than 5 elements: Calls `radix_sort()` — efficient for larger inputs using the radix/bucket sort strategy.

#### `sort_three()`
```
void	sort_three(t_stack **head)
{
	int	biggest;

	biggest = find_biggest(*head);
	if ((*head)->index == biggest)
		rotate_a(head);
	else if ((*head)->next->index == biggest)
		r_rotate_a(head);
	if ((*head)->index > (*head)->next->index)
		swap_a(head);
}
```
#### `sort_five()`
```
void	sort_five(t_stack **stack_a, t_stack **stack_b)
{
	int	size;

	size = count_nodes(*stack_a);
	while (size--)
	{
		if ((*stack_a)->index == 0 || (*stack_a)->index == 1)
			push_b(stack_a, stack_b);
		else
			rotate_a(stack_a);
	}
	sort_three(stack_a);
	push_a(stack_a, stack_b);
	push_a(stack_a, stack_b);
	if ((*stack_a)->index > (*stack_a)->next->index)
		swap_a(stack_a);
}
```
#### `radix_sort()`
```
void	radix_sort(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*head_a;
	int		i;
	int		j;
	int		size;
	int		max_bits;

	i = 0;
	size = count_nodes(*stack_a);
	max_bits = get_max_bits(*stack_a);	// finds how many bit positions are needed;
	while (i < max_bits)
	{
		j = 0;
		while (j < size)
		{
			head_a = *stack_a;
			if (((head_a->index >> i) & 1) == 1)
				rotate_a(stack_a);	// If bit i of top node's index is 1 → rotate_a() (keep it in A, move to bottom).
			else
				push_b(stack_a, stack_b);	// Else → push_b() (move it to B).
			j++;
		}
		while (*stack_b != NULL)
			push_a(stack_a, stack_b);
		i++;
	}
}
```
# `Resources`
* Radix sort:
	* A tutorial on using radix sort with push_swap: [https://medium.com/nerd-for-tech/push-swap-tutorial-fa746e6aba1e](https://medium.com/nerd-for-tech/push-swap-tutorial-fa746e6aba1e)
	* A video explanation of radix sort: [https://youtu.be/XiuSW_mEn7g](https://youtu.be/XiuSW_mEn7g)
* [Bitwise operators](https://www.programiz.com/c-programming/bitwise-operators)
* [Push Swap Tutorial](https://www.youtube.com/watch?v=4dMsuxfqufg)
* [Push Swap Visualizer](https://oyhoyhk.github.io/)
* https://github.com/arommers/push_swap/tree/master
* https://github.com/mcombeau/push_swap/tree/main 
* https://github.com/hu8813/push_swap/tree/main
* https://github.com/42YerevanProjects/push_swap/tree/master

# `Additional`

* LIBFT

### AI Usage
GitHub Copilot (GPT-5 mini backend) is used for
* Is used to analyze other's people code sample, comprehend the code logic.
* Is used to help with debugging where logic errors occured.
* Discussed about logic, but is not usable enough.
* Used for finding information about micro-optimization, techniques, coding convention.
	* Circular stack implementation, what's the best practice to implement.