/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vorhansa <vorhansa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 15:39:33 by vorhansa          #+#    #+#             */
/*   Updated: 2026/03/05 16:09:22 by vorhansa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	count_nodes(t_stack *head)
{
	int	i;

	i = 0;
	while (head != NULL)
	{
		head = head->next;
		i++;
	}
	return (i);
}

void	free_stack(t_stack **head)
{
	t_stack	*tmp;

	while (*head)
	{
		tmp = *head;
		*head = (*head)->next;
		free(tmp);
	}
}

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