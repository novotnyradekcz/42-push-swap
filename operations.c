/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovotny <rnovotny@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 21:11:42 by rnovotny          #+#    #+#             */
/*   Updated: 2023/08/25 21:41:55 by rnovotny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	swap(int *stack_a, int *stack_b, int size_a, int to_swap)
{
	int	tmp;
	
	if (to_swap == 0 || to_swap == -1)
	{
		tmp = stack_a[0];
		stack_a[0] = stack_a[1];
		stack_a[1] = tmp;
	}
	if (to_swap == 1 || to_swap == -1)
	{
		tmp = stack_b[0];
		stack_b[0] = stack_b[1];
		stack_b[1] = tmp;
	}
	return (size_a);
}

int	push(int *stack_a, int *stack_b, int size_a, int push_to)
{
	return (size_a);
}

int	rotate(int *stack_a, int *stack_b, int size_a, int to_rotate)
{
	return (size_a);
}

int	reverse_rotate(int *stack_a, int *stack_b, int size_a, int to_rotate)
{
	return (size_a);
}
