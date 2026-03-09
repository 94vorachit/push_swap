/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vorhansa <vorhansa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 16:17:28 by vorhansa          #+#    #+#             */
/*   Updated: 2026/03/04 16:27:04 by vorhansa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack **head)
{
	t_stack	*tmp;

	if (!*head || (*head)->next == NULL)
		return ;
	tmp = (*head)->next;
	(*head)->next = tmp->next;
	tmp->next = *head;
	*head = tmp;
}

void	swap_a(t_stack **head)
{
	swap(head);
	write(1, "sa\n", 3);
}

void	swap_b(t_stack **head)
{
	swap(head);
	write(1, "sb\n", 3);
}

void	swap_ab(t_stack **stack_a, t_stack **stack_b)
{
	swap(stack_a);
	swap(stack_b);
	write(1, "ss\n", 3);
}

// int	main(int ac, char  **av)
// {
// 	t_stack	*stack_a;
// 	t_stack *stack_b;

// 	if (ac < 2)
// 		return (0);
// 	check_input(ac, av);
// 	stack_a = init_list(ac, av);
// 	printf("---------- stack a ----------\n");
// 	print_list(stack_a);
// 	stack_b = NULL;
// 	printf("---------- stack b ----------\n");
// 	print_list(stack_b);

// 	push_b(&stack_a, &stack_b);
// 	push_b(&stack_a, &stack_b);
// 	printf("---------- stack a ----------\n");
// 	print_list(stack_a);
// 	printf("---------- stack b ----------\n");
// 	print_list(stack_b);

// 	swap_a(&stack_a);
// 	printf("---------- stack a ----------\n");
// 	print_list(stack_a);

// 	swap_b(&stack_b);
// 	printf("---------- stack b ----------\n");
// 	print_list(stack_b);

	// swap_ab(&stack_a, &stack_b);
	// printf("---------- stack a ----------\n");
	// print_list(stack_a);
	// printf("---------- stack b ----------\n");
	// print_list(stack_b);
	
// 	return (0);
// }