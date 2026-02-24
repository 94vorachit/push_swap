/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vorhansa <vorhansa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 14:57:23 by vorhansa          #+#    #+#             */
/*   Updated: 2026/02/24 17:01:38 by vorhansa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <limits.h> //INT_MIN, INT_MAX
# include "../libft/libft.h"

// check input
int		check_unique(char **av);
int		check_nbr(char *av);
void	check_input(int ac, char **av);

typedef struct 		s_stack
{
	int				value;
	int				index;
	struct s_stack	*next;
} 					t_stack;

# endif