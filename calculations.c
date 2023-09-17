/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculations.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovotny <rnovotny@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 15:15:17 by rnovotny          #+#    #+#             */
/*   Updated: 2023/09/17 21:47:00 by rnovotny         ###   ########.fr       */
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

void	slow_sort(int *stack_a, int * stack_b, short *operations)
{
	int	i;
	int	smallest;
	int	sindex;
	
	i = 1;
	smallest = stack_a[1];
	while (i++ < stack_a[0])
	{
		if (stack_a[i] < smallest)
		{
			smallest = stack_a[i];
			sindex = i;
		}
	}
	if (sindex < stack_a[0] / 2)
	{
		while (stack_a[1] != smallest)
			rotate(stack_a, stack_b, 0, operations);
	}
	else
	{
		while (stack_a[1] != smallest)
			reverse_rotate(stack_a, stack_b, 0, operations);
	}
	push_b(stack_a, stack_b, operations);
	return ;
}

void	sort(int *stack_a, int * stack_b, short *operations)
{
	while (stack_a[0] > 0)
		slow_sort(stack_a, stack_b, operations);
	while (stack_b[0] > 0)
		push_a(stack_a, stack_b, operations);
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
	printf("%d %d\n", front, back);
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
		print_stack(stack_b);
		while (i++ < moves[1])
			rotate(stack_a, stack_b, 1, operations);
		print_stack(stack_b);
		push_b(stack_a, stack_b, operations);
		print_stack(stack_b);
		i = find_max(stack_b);
		while (stack_b[1] != i)
			reverse_rotate(stack_a, stack_b, 1, operations);
		print_stack(stack_b);
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
		printf("\n%d\n", moves[1]);
		sorting(stack_a, stack_b, moves, operations);
	}
	// i = 0;
	// candidate = -2147483648;
	// while (i++ < stack_b[0])
	// {
	// 	if (stack_b[i] > candidate)
	// 		candidate = stack_b[i];
	// }
	// while (stack_b[1] != candidate)
	// 	rotate(stack_a, stack_b, 1, operations);
	while (stack_b[0])
		push_a(stack_a, stack_b, operations);
	i = 0;
	while (i++ < operations[0])
		printf("%d\n", operations[i]);
	i = 0;
	while (i++ < stack_a[0])
		printf("%d ", stack_a[i]);
	printf("\n");
	free(moves);
}