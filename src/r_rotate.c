/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_rotate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vorhansa <vorhansa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 16:41:06 by vorhansa          #+#    #+#             */
/*   Updated: 2026/03/04 16:45:33 by vorhansa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_ccw(t_stack **head)
{
	t_stack	*prev_tail;
	t_stack	*new_tail;

	if (*head == NULL || (*head)->next == NULL)
		return ;
	prev_tail = *head;
	while (prev_tail->next != NULL)
	{
		new_tail = prev_tail;
		prev_tail = prev_tail->next;
	}
	prev_tail->next = *head;
	new_tail->next = NULL;
	*head = prev_tail;
}

void	r_rotate_a(t_stack **head)
{
	rotate_ccw(head);
	write(1, "rra\n", 4);
}

void	r_rotate_b(t_stack **head)
{
	rotate_ccw(head);
	write(1, "rrb\n", 4);
}

void	r_rotate_ab(t_stack **stack_a, t_stack **stack_b)
{
	rotate_ccw(stack_a);
	rotate_ccw(stack_b);
	write(1, "rrr\n", 4);
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
	
// 	r_rotate_a(&stack_a);
// 	printf("---------- stack a ----------\n");
// 	print_list(stack_a);

// 	r_rotate_b(&stack_b);
// 	printf("---------- stack b ----------\n");
// 	print_list(stack_b);
	
// 	r_rotate_ab(&stack_a, &stack_b);
// 	printf("---------- stack a ----------\n");
// 	print_list(stack_a);
// 	printf("---------- stack b ----------\n");
// 	print_list(stack_b);
	
// 	return (0);
// }