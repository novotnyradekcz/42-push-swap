/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovotny <rnovotny@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 17:13:41 by rnovotny          #+#    #+#             */
/*   Updated: 2023/10/16 15:42:31 by rnovotny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	calculate_score_rrr(int **stacks, int a, int b)
{
	int min[2];
	
	min[0] = stacks[0][0] + stacks[1][0];
	if (a >= b && a + 1 < min[0])
	{
		min[0] = a + 1;
		min[1] = 1;	// rr
	}
	if (stacks[1][0] - b >= stacks[0][0] - a && stacks[1][0] - b + 1 < min[0])
	{
		min[0] = stacks[1][0] - b + 1;
		min[1] = 2;	// rrr
	}
	if (a <= b && b + 1 < min[0])
	{
		min[0] = b + 1;
		min[1] = 1;	// rr
	}
	if (stacks[1][0] - b <= stacks[0][0] - a && stacks[0][0] - a + 1 < min[0])
	{
		min[0] = stacks[0][0] - a + 1;
		min[1] = 2;	// rrr
	}
	stacks[2][a + 1] = min[0];
	stacks[4][a + 1] = min[1];
}

void	calculate_score(int **stacks, int a, int b)
{
	int	min;
	int	moves;

	min = stacks[0][0] + stacks[1][0];
	if (a + stacks[1][0] - b + 1 < min)
	{
		min = a + stacks[1][0] - b + 1;
		moves = 4;	// ra, rrb
	}
	if (b + stacks[0][0] - a + 1 < min)
	{
		min = b + stacks[0][0] - a + 1;
		moves = 8;	// rra, rb
	}
	calculate_score_rrr(stacks, a, b);
	if (min < stacks[2][a + 1])
	{
		stacks[2][a + 1] = min;
		stacks[2][a + 1] = min;
		stacks[3][a + 1] = b + 1;
			stacks[2][a + 1] = min;
		stacks[3][a + 1] = b + 1;
			stacks[4][a + 1] = moves;
	}
	stacks[3][a + 1] = b + 1;
}

void	assign_score(int **stacks, int position)
{
	int	i;

	i = stacks[2][0];
	if (stacks[0][position] > find_min_max(stacks[1], -1))
	{
		while (stacks[0][position] < stacks[1][i])
		{
			i++;
			if (i > stacks[1][0])
				i = 1;
		}
	}
	calculate_score(stacks, position - 1, i - 1);
}

void	do_sort(int **stacks, int *operations)
{
	int	i;

	while (stacks[0][0])
	{
		i = 0;
		stacks[2][0] = find_offset(stacks);
		while (i++ < stacks[0][0])
			assign_score(stacks, i);
		stacks[3][0] = find_min_index(stacks);
		stacks[4][0] = stacks[3][stacks[3][0]];
		if (stacks[4][stacks[3][0]] == 1)
			move_rr(stacks, operations);
		if (stacks[4][stacks[3][0]] == 2)
			move_rrr(stacks, operations);
		if (stacks[4][stacks[3][0]] == 4 || stacks[4][stacks[3][0]] == 8)
			move_ra_rb(stacks, operations);
		push_b(stacks, operations);
	}
}

void	start_sort(int **stacks, int *operations)
{
	int	i;

	push_b(stacks, operations);
	push_b(stacks, operations);
	do_sort(stacks, operations);
	stacks[2][0] = find_offset(stacks);
	i = 0;
	if (stacks[2][0] <= stacks[1][0] / 2 + 1)
	{
		while (++i < stacks[2][0])
			rotate(stacks, 1, operations);
	}
	else
	{
		while (i++ < stacks[1][0] - stacks[2][0] + 1)
			reverse_rotate(stacks, 1, operations);
	}
	while (stacks[1][0])
		push_a(stacks, operations);
}
