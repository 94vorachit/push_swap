/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vorhansa <vorhansa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 14:57:23 by vorhansa          #+#    #+#             */
/*   Updated: 2026/03/09 17:10:15 by vorhansa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <limits.h> //INT_MIN, INT_MAX
# include "../libft/libft.h"

typedef struct 		s_stack
{
	int				value;
	int				index;
	struct s_stack	*next;
} 					t_stack;

// check input
int		check_unique(char **av);
int		check_nbr(char *av);
void	check_input(int ac, char **av);

// initialize
void	print_list(t_stack *head);
t_stack	*ft_lstnew_int(int value);
void	insert_at_tail(t_stack **head, int new_value);
t_stack	*init_list(int ac, char **av);

// push
void	push(t_stack **stack_from, t_stack **stack_to);
void	push_a(t_stack **stack_a, t_stack **stack_b);
void	push_b(t_stack **stack_a, t_stack **stack_b);

// swap
void	swap(t_stack **head);
void	swap_a(t_stack **head);
void	swap_b(t_stack **head);
void	swap_ab(t_stack **stack_a, t_stack **stack_b);

// rotate
void	rotate_cw(t_stack **head);
void	rotate_a(t_stack **head);
void	rotate_b(t_stack **head);
void	rotate_ab(t_stack **stack_a, t_stack **stack_b);

// r_rotate
void	rotate_ccw(t_stack **head);
void	r_rotate_a(t_stack **head);
void	r_rotate_b(t_stack **head);
void	r_rotate_ab(t_stack **stack_a, t_stack **stack_b);

// index
int		count_nodes(t_stack *head);
void	set_index(t_stack *head, int link_size);
void	free_stack(t_stack **head);
int		sorted(t_stack **head);

// sort
int		find_biggest(t_stack *head);
void	sort_three(t_stack **head);
void	sort_five(t_stack **stack_a, t_stack **stack_b);
void	sort_stack(t_stack **stack_a, t_stack **stack_b);

// radix
void	radix_sort(t_stack **stack_a, t_stack **stack_b);

# endif