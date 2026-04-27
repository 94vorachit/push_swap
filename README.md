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
	* Sort 100 random numbers in fewer than 700 operations. 'mcom'
	* Sort 500 random numbers in no more than 5500 operations.
* For minimal project validation (which implies a minimum grade of 80%), you can succeed with different averages:
	* 100 numbers in under 1100 operations and 500 numbers in under 8500 operations '42Y'
	* 100 numbers in under 700 operations and 500 numbers in under 11500 operations
	* 100 numbers in under 1300 operations and 500 numbers in under 5500 operation

### Bonus

The bonus part is to write a program named ```checker```, which will get as an argument the stack A formatted as a list of integers. Checker will then wait and read instructions on the standard input. Once all the instructions have been read, checker will execute them on the stack received as an argument (After giving the instructions press ```ctrl + d```).

If after executing those instructions, stack a is actually sorted and b is empty, then checker must display ```"OK"``` else ```"KO"```. If checker arguments are invalid it displays ```"Error"```.

The checker code can be found in the checker.c file in this repository.

# `Instrctions`

At the beginning. I make the two linked lists (stacks) A and B. `A` contains all input numbers, `B` starts empty `(NULL)`. Each individual number/value was stored in a node of a linked list. Assign an index to each node and respective value.

### `Stack`
```
typedef struct 		s_stack
{
	int				value;
	int				index;
	struct s_stack	*next;
} 					t_stack;
```

## Resources

*   Radix sort:
    
    *   A tutorial on using radix sort with push_swap: [https://medium.com/nerd-for-tech/push-swap-tutorial-fa746e6aba1e](https://medium.com/nerd-for-tech/push-swap-tutorial-fa746e6aba1e)
    *   A video explanation of radix sort: [https://youtu.be/XiuSW_mEn7g](https://youtu.be/XiuSW_mEn7g)
* Bitwise operators: https://www.programiz.com/c-programming/bitwise-operators
* https://github.com/arommers/push_swap/tree/master
* https://github.com/mcombeau/push_swap/tree/main 
* https://github.com/hu8813/push_swap/tree/main
* https://github.com/42YerevanProjects/push_swap/tree/master
* https://www.youtube.com/watch?v=4dMsuxfqufg
* https://oyhoyhk.github.io/

```
t_stack	*stack_a;
t_stack *stack_b;
```
### `Argument errors`

Next step. Check the errors. Errors include, some arguments not being integers, some arguments exceeding the integer limits, and/or the presence of duplicates. In case of error, it must display "Error" followed by an '\n' on the standard error.

: `check_input(ac, av)`
```
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
		if (check_unique(temp))						// Duplicates
			ft_putstr("ERROR");
		if (!check_nbr(temp[i]))					// Not being integers
			ft_putstr("ERROR");
		i++;
	}
	if (ac == 2)
		ft_free (temp);
}
```
### `Initialize`

```
stack_a = init_list(ac, av);	 
stack_b = NULL;
```

Function init_list :	Builds stack_a from program input arguments.
```
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

Function insert_at_tail :	Adds a new number at the end of the linked list.
```
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


# `Additional`

* LIBFT