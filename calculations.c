/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculations.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovotny <rnovotny@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 15:15:17 by rnovotny          #+#    #+#             */
/*   Updated: 2023/11/10 12:16:04 by rnovotny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#include <stdio.h>

int	find_min_index(int **stacks)
{
	int	i;
	int	min;
	int	index;

	i = 0;
	min = stacks[2][1];
	index = 1;
	while (i++ < stacks[0][0])
	{
		if (stacks[2][i] < min)
		{
			min = stacks[2][i];
			index = i;
		}
	}
	return (index);
}

int	find_min_max(int *stack, int min_or_max)
{
	int	i;
	int	extremum;

	i = 0;
	extremum = stack[1];
	if (min_or_max < 0)
	{
		while (i++ < stack[0])
		{
			if (stack[i] < extremum)
				extremum = stack[i];
		}
	}
	else
	{
		while (i++ < stack[0])
		{
			if (stack[i] > extremum)
				extremum = stack[i];
		}
	}
	return (extremum);
}

int	find_offset(int **stacks)
{
	int	i;
	int	max;

	i = 1;
	max = find_min_max(stacks[1], 1);
	while (i < stacks[1][0] && stacks[1][i] != max)
		i++;
	return (i);
}

long	ft_atoi(const char *nptr)
{
	int		i;
	int		neg;
	long	res;

	neg = 1;
	res = 0;
	i = 0;
	while ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == 32)
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			neg = -neg;
		i++;
	}
	while (nptr[i] >= 48 && nptr[i] <= 57)
	{
		res = res * 10 + (nptr[i] - 48);
		i++;
	}
	return (neg * res);
}
