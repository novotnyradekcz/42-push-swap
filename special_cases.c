/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   special_cases.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovotny <rnovotny@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 19:03:16 by rnovotny          #+#    #+#             */
/*   Updated: 2023/10/16 15:42:31 by rnovotny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	two(int **stacks, int *operations)
{
	if (stacks[0][1] < stacks[0][2])
		return ;
	swap(stacks, 0, operations);
	return ;
}

void	three(int **stacks, int *operations)
{
	if (stacks[0][1] < stacks[0][2])
	{
		if (stacks[0][2] < stacks[0][3])
			return ;
		if (stacks[0][1] > stacks[0][3])
			reverse_rotate(stacks, 0, operations);
		else
		{
			swap(stacks, 0, operations);
			rotate(stacks, 0, operations);
		}
	}
	else if (stacks[0][1] < stacks[0][3])
		swap(stacks, 0, operations);
	else if (stacks[0][2] < stacks[0][3])
		rotate(stacks, 0, operations);
	else
	{
		rotate(stacks, 0, operations);
		swap(stacks, 0, operations);
	}
	return ;
}

void	four(int **stacks, int *operations)
{
	push_b(stacks, operations);
	three(stacks, operations);
	if (stacks[1][1] < stacks[0][1])
		push_a(stacks, operations);
	else if (stacks[1][1] < stacks[0][2])
	{
		rotate(stacks, 0, operations);
		push_a(stacks, operations);
		reverse_rotate(stacks, 0, operations);
	}
	else if (stacks[1][1] < stacks[0][3])
	{
		reverse_rotate(stacks, 0, operations);
		push_a(stacks, operations);
		rotate(stacks, 0, operations);
		rotate(stacks, 0, operations);
	}
	else
	{
		push_a(stacks, operations);
		rotate(stacks, 0, operations);
	}
	return ;
}

void	five(int **stacks, int *operations)
{
	push_b(stacks, operations);
	four(stacks, operations);
	if (stacks[1][1] < stacks[0][1])
		push_a(stacks, operations);
	else if (stacks[1][1] < stacks[0][2])
	{
		rotate(stacks, 0, operations);
		push_a(stacks, operations);
		reverse_rotate(stacks, 0, operations);
	}
	else if (stacks[1][1] < stacks[0][3])
	{
		rotate(stacks, 0, operations);
		rotate(stacks, 0, operations);
		push_a(stacks, operations);
		reverse_rotate(stacks, 0, operations);
		reverse_rotate(stacks, 0, operations);
	}
	else
		five_too(stacks, operations);
	return ;
}

void	five_too(int **stacks, int *operations)
{
	if (stacks[1][1] < stacks[0][4])
	{
		reverse_rotate(stacks, 0, operations);
		push_a(stacks, operations);
		rotate(stacks, 0, operations);
		rotate(stacks, 0, operations);
	}
	else
	{
		push_a(stacks, operations);
		rotate(stacks, 0, operations);
	}
	return ;
}