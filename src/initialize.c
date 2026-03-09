/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vorhansa <vorhansa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 15:22:27 by vorhansa          #+#    #+#             */
/*   Updated: 2026/03/05 15:44:45 by vorhansa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_list(t_stack *head)
{
	t_stack	*current;
	int	i;

	current = head;
	i = 0;
	while (current)
	{
		printf("node[%d] : value = %d : index [%d]\n", i, current->value, current->index);
		current = current->next;
		i++;
	}
}

t_stack	*ft_lstnew_int(int value)
{
	t_stack	*new_node;

	new_node = ft_calloc(1, sizeof(t_stack));
	if (!new_node)
		return (NULL);
	new_node->value = value;
	new_node->index = 0;
	new_node->next = NULL;
	return (new_node);
}

void	insert_at_tail(t_stack **head, int new_value)
{
	t_stack	*new_node;
	t_stack	*current;

	if (*head == NULL)
	{
		*head = ft_lstnew_int(new_value);
		return ;
	}
	current = *head;
	while (current->next != NULL)
		current = current->next;
	new_node = ft_lstnew_int(new_value);
	current->next = new_node;
}

t_stack	*init_list(int ac, char **av)
{
	t_stack	*stack_a;
	char	**tmp;
	int		i;

	stack_a = NULL;
	i = 0;
	if (ac == 2)
		tmp = ft_split(av[1], ' ');
	else
	{
		i = 1;
		tmp = av;
	}
	while (tmp[i])
	{
		insert_at_tail(&stack_a, ft_atoi(tmp[i]));
		i++;
	}
	if (ac == 2)
		ft_free(tmp);
	return (stack_a);
}
