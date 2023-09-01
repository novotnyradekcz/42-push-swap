/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   special_cases.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovotny <rnovotny@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 19:03:16 by rnovotny          #+#    #+#             */
/*   Updated: 2023/09/01 21:31:28 by rnovotny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	two(int *stack_a, int *stack_b)
{
	if (stack_a[1] < stack_a[2])
		return ;
	swap(stack_a, stack_b, 0);
	return ;
}

void	three(int *stack_a, int *stack_b)
{
	// printf("A: %d, %d, %d\n", stack_a[1], stack_a[2], stack_a[3]);
	if (stack_a[1] < stack_a[2])
	{
		if (stack_a[2] < stack_a[3])
			return ;
		if (stack_a[1] > stack_a[3])
			reverse_rotate(stack_a, stack_b, 0);
		else
		{
			swap(stack_a, stack_b, 0);
			rotate(stack_a, stack_b, 0);
		}
	}
	else if (stack_a[1] < stack_a[3])
		swap(stack_a, stack_b, 0);
	else if (stack_a[2] < stack_a[3])
		rotate(stack_a, stack_b, 0);
	else
	{
		rotate(stack_a, stack_b, 0);
		swap(stack_a, stack_b, 0);
	}
	return ;
}

void	four(int *stack_a, int *stack_b)
{
	push_b(stack_a, stack_b);
	three(stack_a, stack_b);
	if (stack_b[1] < stack_a[1])
		push_a(stack_a, stack_b);
	else if (stack_b[1] < stack_a[2])
	{
		rotate(stack_a, stack_b, 0);
		push_a(stack_a, stack_b);
		reverse_rotate(stack_a, stack_b, 0);
	}
	else if (stack_b[1] < stack_a[3])
	{
		reverse_rotate(stack_a, stack_b, 0);
		push_a(stack_a, stack_b);
		rotate(stack_a, stack_b, 0);
		rotate(stack_a, stack_b, 0);
	}
	else
	{
		push_a(stack_a, stack_b);
		rotate(stack_a, stack_b, 0);
	}
	return ;
}

void	five(int *stack_a, int *stack_b)
{
	push_b(stack_a, stack_b);
	four(stack_a, stack_b);
	if (stack_b[1] < stack_a[1])
		push_a(stack_a, stack_b);
	else if (stack_b[1] < stack_a[2])
	{
		rotate(stack_a, stack_b, 0);
		push_a(stack_a, stack_b);
		reverse_rotate(stack_a, stack_b, 0);
	}
	else if (stack_b[1] < stack_a[3])
	{
		rotate(stack_a, stack_b, 0);
		rotate(stack_a, stack_b, 0);
		push_a(stack_a, stack_b);
		reverse_rotate(stack_a, stack_b, 0);
		reverse_rotate(stack_a, stack_b, 0);
	}
	else
		five_too(stack_a, stack_b);
	return ;
}

void	five_too(int *stack_a, int *stack_b)
{
	if (stack_b[1] < stack_a[4])
	{
		reverse_rotate(stack_a, stack_b, 0);
		push_a(stack_a, stack_b);
		rotate(stack_a, stack_b, 0);
		rotate(stack_a, stack_b, 0);
	}
	else
	{
		push_a(stack_a, stack_b);
		rotate(stack_a, stack_b, 0);
	}
	return ;
}