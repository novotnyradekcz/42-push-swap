/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculations.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovotny <rnovotny@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 15:15:17 by rnovotny          #+#    #+#             */
/*   Updated: 2023/10/11 19:09:37 by rnovotny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#include <stdio.h>

void	special_cases(int **stacks, short *operations)
{
	if (stacks[0][0] == 1)
		return ;
	if (stacks[0][0] == 2)
		two(stacks, operations);
	else if (stacks[0][0] == 3)
		three(stacks, operations);
	else if (stacks[0][0] == 4)
		four(stacks, operations);
	else
		five(stacks, operations);
	return ;
}

int	calculations(int **stacks, int number)
{
	int	i;
	int	front;
	int	back;

	i = 1;
	while (i <= stacks[1][0] && stacks[1][i] > stacks[0][number])
		i++;
	front = i - 1;
	back = stacks[1][0] - front;
	back++;
	back--;
	// if (front < back)
	// 	return (front);
	// else
	// 	return ((-1) * back);
	return (front);
}

int	find_min_index(int *stack)
{
	int	i;
	int	min;
	int	index;

	i = 0;
	min = stack[1];
	index = 0;
	while (i++ < stack[0])
	{
		if (stack[i] < min)
		{
			min = stack[i];
			index = i;
		}
	}
	return (index);
}

int	find_min_max(int *stack, int min_or_max)
{
	int	i;
	int extremum;

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

void	print_stack(int *stack)
{
	int	i;

	i = 0;
	while (i++ < stack[0])
		printf("%d ", stack[i]);
	printf("\n");
}

void	sorting(int **stacks, int *moves, short *operations)
{
	int i;
	
	if (moves[1] >= 0)
	{
		i = 0;
		while (i++ < moves[0])
			rotate(stacks, 0, operations);
		i = 0;
		while (i++ < moves[1])
			rotate(stacks, 1, operations);
		push_b(stacks, operations);
		i = find_min_max(stacks[1], 1);
		while (stacks[1][1] != i)
			reverse_rotate(stacks, 1, operations);
	}
	if (moves[1] < 0)
	{
		i = 0;
		while (i++ < (stacks[0][0] - moves[0] - 1))
			reverse_rotate(stacks, 0, operations);
		i = 0;
		while (i++ < (stacks[1][0] + moves[1] - 1))
			reverse_rotate(stacks, 1, operations);
		push_b(stacks, operations);
		i = find_min_max(stacks[1], 1);
		while (stacks[1][1] != i)
			rotate(stacks, 1, operations);
	}
}

void	calculate_score(int **stacks, int a, int b)
{
	int	min;
	int	moves;

	min = stacks[0][0] + stacks[1][0];
	if (a >= b)
	{
		if (a + 1 < min)
		{
			min = a + 1;
			moves = 1;	// rr
		}
		if (stacks[1][0] - b + 2 < min)
		{
			min = stacks[1][0] - b + 2;
			moves = 2;	// rrr
		}
	}
	if (a <= b)
	{
		if (b + 1 < min)
		{
			min = b + 1;
			moves = 1;	// rr
		}
		if (stacks[0][0] - a + 2 < min)
		{
			min = stacks[0][0] - a + 2;
			moves = 2;	// rrr
		}
	}
	if (a + stacks[1][0] - b + 2 < min)
	{
		min = a + stacks[1][0] - b + 2;
		moves = 4;	// ra, rrb
	}
	if (b + stacks[0][0] - a + 2 < min)
	{
		min = b + stacks[0][0] - a + 2;
		moves = 8;	// rra, rb
	}
	printf("calculate_score, after ifs\n");
	stacks[2][a + 1] = min;
	stacks[3][a + 1] = b + 1;
	printf("calculate_score, before stacks[4]\n");
	stacks[4][a + 1] = moves;
	printf("calculate_score, end\n");
}

void	assign_score(int **stacks, int position)
{
	int	i;
	int	max;

	i = stacks[2][0];
	max = find_min_max(stacks[1], 1);
	if (stacks[0][position] > max)
		i = find_offset(stacks) - 1;
	if (i == stacks[1][0])
		i = 1;
	else
		i++;
	while (stacks[0][position] < stacks[1][i] && stacks[1][i] != max)
	{
		i++;
		if (i >= stacks[1][0])
			i = 1;
	}
	printf("assign_score, before calculate_score\n");
	calculate_score(stacks, position - 1, i - 1);
	printf("assign_score, after calculate_score\n");
}

void	move(int **stacks, short *operations)
{
	int	i;
	int	a;
	int	b;

	i = 0;
	if (stacks[3][stacks[3][0]] == 1)
	{
		a = stacks[0][stacks[3][0]];
		b = stacks[1][stacks[4][0]];
		if (a < b)
		{
			while (++i < a)
				rotate(stacks, -1, operations);
			while (++i < b)
				rotate(stacks, 1, operations);
		}
		else
		{
			while (++i < b)
				rotate(stacks, -1, operations);
			while (++i < a)
				rotate(stacks, 0, operations);
		}
	}
	if (stacks[3][stacks[3][0]] == 2)
	{
		a = stacks[0][0] - stacks[0][stacks[3][0]] + 1;
		b = stacks[1][0] - stacks[1][stacks[4][0]] + 1;
		if (a < b)
		{
			while (i++ < a)
				reverse_rotate(stacks, -1, operations);
			while (i++ < b)
				reverse_rotate(stacks, 1, operations);
		}
		else
		{
			while (i++ < b)
				reverse_rotate(stacks, -1, operations);
			while (i++ < a)
				reverse_rotate(stacks, 0, operations);
		}
	}
	if (stacks[3][stacks[3][0]] == 4)
	{
		a = stacks[0][stacks[3][0]];
		b = stacks[1][0] - stacks[1][stacks[4][0]] + 1;
		while (++i < a)
			rotate(stacks, 0, operations);
		i = 0;
		while (i++ < b)
			reverse_rotate(stacks, 1, operations);

	}
	if (stacks[3][stacks[3][0]] == 8)
	{
		a = stacks[0][0] - stacks[0][stacks[3][0]] + 1;
		b = stacks[1][stacks[4][0]];
		while (i++ < a)
			reverse_rotate(stacks, 0, operations);
		i = 0;
		while (++i < b)
			rotate(stacks, 1, operations);
	}
	push_b(stacks, operations);
}

void	turk_sort(int **stacks, short *operations)
{
	int	i;

	push_b(stacks, operations);
	push_b(stacks, operations);
	// if (stacks[1][1] < stacks[1][2])
		// swap(stacks, 1, operations);
	while (stacks[0][0])
	{
		printf("turk_sort, start of loop\n");
		i = 0;
		stacks[2][0] = find_offset(stacks);
		printf("turk_sort, after find_offset\n");
		while (i++ < stacks[0][0])
			assign_score(stacks, i);
		printf("turk_sort, after assign_score\n");
		stacks[3][0] = find_min_index(stacks[2]);
		stacks[4][0] = stacks[3][stacks[3][0]];
		move(stacks, operations);
		printf("turk_sort, end of loop\n");
	}
	while (stacks[1][0])
		push_a(stacks, operations);
	print_stack(stacks[0]);
}

// new approach:
// stick to moving all numbers from A to B in reverse order and then simply moving them back
// but
// before pushing each number, calculate the number of operations it would take
// simply as how close is this number to the edge of the stack
// and how much the other stack would need to be shifted
// if rotating is in the same direction
// take into account combining ra + rb into rr or rra + rrb into rrr
// save this score for each number on A
// then select the one with lowest score and execute operations to move it
// repeat