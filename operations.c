/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovotny <rnovotny@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 21:11:42 by rnovotny          #+#    #+#             */
/*   Updated: 2023/08/28 16:33:47 by rnovotny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	swap(int *stack_a, int *stack_b, int size_a, int to_swap)	// TODO: you cannot pass size_a only, as you do not know size_B - maybe pass just the max value? or just the bigger value? or an array with both numbers in it?
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
	if (to_swap == 0)
		write(1, "sa", 2);
	if (to_swap == 1)
		write(1, "sb", 2);
	if (to_swap == -1)
		write(1, "ss", 2);
	return (size_a);
}

int	push(int *stack_a, int *stack_b, int size_a, int push_to)
{
	int	i;

	if (push_to == 0)
	{
		i = 0;
		while (i++ < size_a)
			stack_a[i] = stack_a[i - 1];
		stack_a[0] = stack_b[0];
		while (i-- > 0)
			stack_b[i] = stack_b[i + 1];
	}
	if (push_to == 1)
	{
		i = 0;
		while (i++ < size_a)
			stack_b[i] = stack_b[i - 1];
		stack_b[0] = stack_a[0];
		while (i-- > 0)
			stack_a[i] = stack_a[i + 1];
	}
	if (push_to == 0)
		write(1, "pa", 2);
	if (push_to == 1)
		write(1, "pb", 2);
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
