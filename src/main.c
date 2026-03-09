/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vorhansa <vorhansa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 15:32:49 by vorhansa          #+#    #+#             */
/*   Updated: 2026/03/05 16:09:49 by vorhansa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char  **av)
{
	t_stack	*stack_a;
	t_stack *stack_b;

	if (ac < 2)
		return (0);
	check_input(ac, av);
	stack_a = init_list(ac, av);
	set_index(stack_a, count_nodes(stack_a));
	printf("---------- stack a ----------\n");
	print_list(stack_a);
	stack_b = NULL;
	printf("---------- stack b ----------\n");
	print_list(stack_b);

	push_b(&stack_a, &stack_b);
	push_b(&stack_a, &stack_b);
	push_b(&stack_a, &stack_b);
	printf("---------- stack a ----------\n");
	print_list(stack_a);
	printf("---------- stack b ----------\n");
	print_list(stack_b);

	// swap_a(&stack_a);
	// printf("---------- stack a ----------\n");
	// print_list(stack_a);
	// swap_b(&stack_b);
	// printf("---------- stack b ----------\n");
	// print_list(stack_b);

	// swap_ab(&stack_a, &stack_b);
	// printf("---------- stack a ----------\n");
	// print_list(stack_a);
	// printf("---------- stack b ----------\n");
	// print_list(stack_b);
	
	// rotate_a(&stack_a);
	// printf("---------- stack a ----------\n");
	// print_list(stack_a);

	// rotate_b(&stack_b);
	// printf("---------- stack b ----------\n");
	// print_list(stack_b);
	
	// rotate_ab(&stack_a, &stack_b);
	// printf("---------- stack a ----------\n");
	// print_list(stack_a);
	// printf("---------- stack b ----------\n");
	// print_list(stack_b);

	// r_rotate_a(&stack_a);
	// printf("---------- stack a ----------\n");
	// print_list(stack_a);

	// r_rotate_b(&stack_b);
	// printf("---------- stack b ----------\n");
	// print_list(stack_b);
	
	// r_rotate_ab(&stack_a, &stack_b);
	// printf("---------- stack a ----------\n");
	// print_list(stack_a);
	// printf("---------- stack b ----------\n");
	// print_list(stack_b);
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}
