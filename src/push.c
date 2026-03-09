/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vorhansa <vorhansa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 16:06:38 by vorhansa          #+#    #+#             */
/*   Updated: 2026/03/04 16:22:42 by vorhansa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_stack **stack_from, t_stack **stack_to)
{
	t_stack	*tmp;

	if (stack_from == NULL || *stack_from == NULL)
		return ;
	tmp = *stack_from;
	*stack_from = (*stack_from)->next;
	if (stack_to == NULL)
		*stack_to = tmp;
	else
	{
		tmp->next = *stack_to;
		*stack_to = tmp;
	}
}

void	push_a(t_stack **stack_a, t_stack **stack_b)
{
	push(stack_b, stack_a);
	write(1, "pa\n", 3);
}

void	push_b(t_stack **stack_a, t_stack **stack_b)
{
	push(stack_a, stack_b);
	write(1, "pb\n", 3);
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

// 	return (0);
// }