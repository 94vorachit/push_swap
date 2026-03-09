/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vorhansa <vorhansa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 16:27:40 by vorhansa          #+#    #+#             */
/*   Updated: 2026/03/04 16:41:34 by vorhansa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_cw(t_stack **head)
{
	t_stack	*tail;

	if (*head == NULL || (*head)->next == NULL)
		return ;
	tail = *head;
	while (tail->next != NULL)
		tail = tail->next;
	tail->next = *head;
	*head = (*head)->next;
	tail->next->next = NULL;
}

void	rotate_a(t_stack **head)
{
	rotate_cw(head);
	write (1, "ra\n", 3);
}

void	rotate_b(t_stack **head)
{
	rotate_cw(head);
	write (1, "rb\n", 3);
}

void	rotate_ab(t_stack **stack_a, t_stack **stack_b)
{
	rotate_cw(stack_a);
	rotate_cw(stack_b);
	write(1, "rr\n", 3);
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
// 	push_b(&stack_a, &stack_b);
// 	printf("---------- stack a ----------\n");
// 	print_list(stack_a);
// 	printf("---------- stack b ----------\n");
// 	print_list(stack_b);
	
// 	rotate_a(&stack_a);
// 	printf("---------- stack a ----------\n");
// 	print_list(stack_a);

// 	rotate_b(&stack_b);
// 	printf("---------- stack b ----------\n");
// 	print_list(stack_b);
	
// 	rotate_ab(&stack_a, &stack_b);
// 	printf("---------- stack a ----------\n");
// 	print_list(stack_a);
// 	printf("---------- stack b ----------\n");
// 	print_list(stack_b);
	
// 	return (0);
// }