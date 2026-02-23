/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vorhansa <vorhansa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 16:47:13 by vorhansa          #+#    #+#             */
/*   Updated: 2026/02/23 18:58:37 by vorhansa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_putstr(char *str)
{
	int	i;
	
	i = 0;
	while (str[i])
		write(1, &str[i++], 1);
	write(1, "\n", 1);
	exit (0);
}

int	count_arge(char **av)
{
	int	i;
	
	i = 0;
	while (av[i])
		i++;
	return (i);
}

int	check_unique(char **av)
{
	int	i;
	int	j;
	int	len;

	i = 0;
	len = count_arge(av);
	while (i < len)
	{
		j = i + 1;
		while (j < len)
		{
			if (ft_atoi(av[i]) == ft_atoi(av[j]))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	check_nbr(char *av)
{
	int	i;

	i = 0;
	if (av[i] == '-')
		i++;
	while (av[i])
	{
		if (!ft_isdigit(av[i]))
			return (0);
		i++;
	}
	return (1);
}

void	check_input(int ac, char **av)
{
	char	**
}