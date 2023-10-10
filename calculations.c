/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculations.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovotny <rnovotny@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 15:15:17 by rnovotny          #+#    #+#             */
/*   Updated: 2023/10/10 23:04:34 by rnovotny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#include <stdio.h>

void	special_cases(int *stack_a, int *stack_b, short *operations)
{
	if (stack_a[0] == 1)
		return ;
	if (stack_a[0] == 2)
		two(stack_a, stack_b, operations);
	else if (stack_a[0] == 3)
		three(stack_a, stack_b, operations);
	else if (stack_a[0] == 4)
		four(stack_a, stack_b, operations);
	else
		five(stack_a, stack_b, operations);
	return ;
}

int	calculations(int *stack_a, int *stack_b, int number)
{
	int	i;
	int	front;
	int	back;

	i = 1;
	while (i <= stack_b[0] && stack_b[i] > stack_a[number])
		i++;
	front = i - 1;
	back = stack_b[0] - front;
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

void	sorting(int *stack_a, int *stack_b, int *moves, short *operations)
{
	int i;
	
	if (moves[1] >= 0)
	{
		i = 0;
		while (i++ < moves[0])
			rotate(stack_a, stack_b, 0, operations);
		i = 0;
		while (i++ < moves[1])
			rotate(stack_a, stack_b, 1, operations);
		push_b(stack_a, stack_b, operations);
		i = find_max(stack_b);
		while (stack_b[1] != i)
			reverse_rotate(stack_a, stack_b, 1, operations);
	}
	if (moves[1] < 0)
	{
		i = 0;
		while (i++ < (stack_a[0] - moves[0] - 1))
			reverse_rotate(stack_a, stack_b, 0, operations);
		i = 0;
		while (i++ < (stack_b[0] + moves[1] - 1))
			reverse_rotate(stack_a, stack_b, 1, operations);
		push_b(stack_a, stack_b, operations);
		i = find_max(stack_b);
		while (stack_b[1] != i)
			rotate(stack_a, stack_b, 1, operations);
	}
}

void	turk_sort(int *stack_a, int *stack_b, short *operations)
{
	int	i;
	int candidate;
	int *moves;

	moves = (int *) malloc(2 * sizeof(int));
	push_b(stack_a, stack_b, operations);
	push_b(stack_a, stack_b, operations);
	if (stack_b[1] < stack_b[2])
		swap(stack_a, stack_b, 1, operations);
	while (stack_a[0])
	{
		i = 0;
		moves[0] = stack_a[0];
		moves[1] = stack_b[0];
		candidate = 0;
		while (i++ < stack_a[0])
		{
			candidate = calculations(stack_a, stack_b, i);
			if ((candidate >= 0 && candidate < moves[1])
				|| (candidate < 0 && ((-1) * candidate) < moves[1]))
			{
				moves[0] = i - 1;
				moves[1] = candidate;
			}
		}
		sorting(stack_a, stack_b, moves, operations);
	}
	while (stack_b[0])
		push_a(stack_a, stack_b, operations);
	print_stack(stack_a);
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
