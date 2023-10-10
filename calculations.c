/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculations.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovotny <rnovotny@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 15:15:17 by rnovotny          #+#    #+#             */
/*   Updated: 2023/10/10 15:49:07 by rnovotny         ###   ########.fr       */
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

int	find_max(int *stack)
{
	int	i;
	int maximum;

	i = 0;
	maximum = stack[1];
	while (i++ < stack[0])
	{
		if (stack[i] > maximum)
			maximum = stack[i];
	}
	return (maximum);
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
		i = find_max(stacks[1]);
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
		i = find_max(stacks[1]);
		while (stacks[1][1] != i)
			rotate(stacks, 1, operations);
	}
}

void	turk_sort(int **stacks, short *operations)
{
	int	i;
	int candidate;
	int *moves;

	moves = (int *) malloc(2 * sizeof(int));
	push_b(stacks, operations);
	push_b(stacks, operations);
	if (stacks[1][1] < stacks[1][2])
		swap(stacks, 1, operations);
	while (stacks[0][0])
	{
		i = 0;
		moves[0] = stacks[0][0];
		moves[1] = stacks[1][0];
		candidate = 0;
		while (i++ < stacks[0][0])
		{
			candidate = calculations(stacks, i);
			if ((candidate >= 0 && candidate < moves[1])
				|| (candidate < 0 && ((-1) * candidate) < moves[1]))
			{
				moves[0] = i - 1;
				moves[1] = candidate;
			}
		}
		sorting(stacks, moves, operations);
	}
	while (stacks[1][0])
		push_a(stacks, operations);
	print_stack(stacks[0]);
	free(moves);
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