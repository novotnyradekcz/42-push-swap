/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   special_cases.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovotny <rnovotny@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 19:03:16 by rnovotny          #+#    #+#             */
/*   Updated: 2023/09/03 17:15:22 by rnovotny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	two(int *stack_a, int *stack_b, short *operations)
{
	if (stack_a[1] < stack_a[2])
		return ;
	swap(stack_a, stack_b, 0, operations);
	return ;
}

void	three(int *stack_a, int *stack_b, short *operations)
{
	if (stack_a[1] < stack_a[2])
	{
		if (stack_a[2] < stack_a[3])
			return ;
		if (stack_a[1] > stack_a[3])
			reverse_rotate(stack_a, stack_b, 0, operations);
		else
		{
			swap(stack_a, stack_b, 0, operations);
			rotate(stack_a, stack_b, 0, operations);
		}
	}
	else if (stack_a[1] < stack_a[3])
		swap(stack_a, stack_b, 0, operations);
	else if (stack_a[2] < stack_a[3])
		rotate(stack_a, stack_b, 0, operations);
	else
	{
		rotate(stack_a, stack_b, 0, operations);
		swap(stack_a, stack_b, 0, operations);
	}
	return ;
}

void	four(int *stack_a, int *stack_b, short *operations)
{
	push_b(stack_a, stack_b, operations);
	three(stack_a, stack_b, operations);
	if (stack_b[1] < stack_a[1])
		push_a(stack_a, stack_b, operations);
	else if (stack_b[1] < stack_a[2])
	{
		rotate(stack_a, stack_b, 0, operations);
		push_a(stack_a, stack_b, operations);
		reverse_rotate(stack_a, stack_b, 0, operations);
	}
	else if (stack_b[1] < stack_a[3])
	{
		reverse_rotate(stack_a, stack_b, 0, operations);
		push_a(stack_a, stack_b, operations);
		rotate(stack_a, stack_b, 0, operations);
		rotate(stack_a, stack_b, 0, operations);
	}
	else
	{
		push_a(stack_a, stack_b, operations);
		rotate(stack_a, stack_b, 0, operations);
	}
	return ;
}

void	five(int *stack_a, int *stack_b, short *operations)
{
	push_b(stack_a, stack_b, operations);
	four(stack_a, stack_b, operations);
	if (stack_b[1] < stack_a[1])
		push_a(stack_a, stack_b, operations);
	else if (stack_b[1] < stack_a[2])
	{
		rotate(stack_a, stack_b, 0, operations);
		push_a(stack_a, stack_b, operations);
		reverse_rotate(stack_a, stack_b, 0, operations);
	}
	else if (stack_b[1] < stack_a[3])
	{
		rotate(stack_a, stack_b, 0, operations);
		rotate(stack_a, stack_b, 0, operations);
		push_a(stack_a, stack_b, operations);
		reverse_rotate(stack_a, stack_b, 0, operations);
		reverse_rotate(stack_a, stack_b, 0, operations);
	}
	else
		five_too(stack_a, stack_b, operations);
	return ;
}

void	five_too(int *stack_a, int *stack_b, short *operations)
{
	if (stack_b[1] < stack_a[4])
	{
		reverse_rotate(stack_a, stack_b, 0, operations);
		push_a(stack_a, stack_b, operations);
		rotate(stack_a, stack_b, 0, operations);
		rotate(stack_a, stack_b, 0, operations);
	}
	else
	{
		push_a(stack_a, stack_b, operations);
		rotate(stack_a, stack_b, 0, operations);
	}
	return ;
}