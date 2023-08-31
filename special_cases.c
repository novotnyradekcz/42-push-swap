/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   special_cases.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovotny <rnovotny@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 19:03:16 by rnovotny          #+#    #+#             */
/*   Updated: 2023/08/31 19:46:31 by rnovotny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	two(int *stack_a, int *stack_b)
{
	if (stack_a[1] > stack_a[2])
		return ;
	rotate(stack_a, stack_b, 0);
	return ;
}

void	three(int *stack_a, int *stack_b)
{
	if (stack_a[1] < stack_a[2])
	{
		if (stack_a[2] < stack_a[3])
			return ;
		if (stack_a[1] > stack_a[3])
			reverse_rotate(stack_a, stack_b, 0);
		else
		{
			rotate(stack_a, stack_b, 0);
			swap(stack_a, stack_b, 0);
			reverse_rotate(stack_a, stack_b, 0);
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
