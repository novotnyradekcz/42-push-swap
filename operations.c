/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovotny <rnovotny@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 21:11:42 by rnovotny          #+#    #+#             */
/*   Updated: 2023/09/03 17:08:39 by rnovotny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(int *stack_a, int *stack_b, int to_swap, short *operations)
{
	int	tmp;

	if (to_swap == 0 || to_swap == -1)
	{
		tmp = stack_a[1];
		stack_a[1] = stack_a[2];
		stack_a[2] = tmp;
	}
	if (to_swap == 1 || to_swap == -1)
	{
		tmp = stack_b[1];
		stack_b[1] = stack_b[2];
		stack_b[2] = tmp;
	}
	if (to_swap == 0)
		operations[operations[0] + 1] = 1;
	if (to_swap == 1)
		operations[operations[0] + 1] = 2;
	if (to_swap == -1)
		operations[operations[0] + 1] = 4;
	operations[0]++;
}

void	push_a(int *stack_a, int *stack_b, short *operations)
{
	int	i;

	i = stack_a[0] + 1;
	while (i-- > 1)
		stack_a[i + 1] = stack_a[i];
	stack_a[1] = stack_b[1];
	i = 0;
	while (++i < stack_b[0])
		stack_b[i] = stack_b[i + 1];
	stack_a[0]++;
	stack_b[0]--;
	operations[operations[0] + 1] = 8;
	operations[0]++;
}

void	push_b(int *stack_a, int *stack_b, short *operations)
{
	int	i;

	i = stack_b[0] + 1;
	while (i-- > 1)
		stack_b[i + 1] = stack_b[i];
	stack_b[1] = stack_a[1];
	i = 0;
	while (++i < stack_a[0])
		stack_a[i] = stack_a[i + 1];
	stack_b[0]++;
	stack_a[0]--;
	operations[operations[0] + 1] = 16;
	operations[0]++;
}

void	rotate(int *stack_a, int *stack_b, int to_rotate, short *operations)
{
	int	i;
	int	tmp;

	i = 0;
	if (to_rotate == 0 || to_rotate == -1)
	{
		tmp = stack_a[1];
		while (++i < stack_a[0])
			stack_a[i] = stack_a[i + 1];
		stack_a[i] = tmp;
	}
	if (to_rotate == 1 || to_rotate == -1)
	{
		tmp = stack_b[1];
		while (++i < stack_b[0])
			stack_b[i] = stack_b[i + 1];
		stack_b[i] = tmp;
	}
	if (to_rotate == 0)
		operations[operations[0] + 1] = 32;
	if (to_rotate == 1)
		operations[operations[0] + 1] = 64;
	if (to_rotate == -1)
		operations[operations[0] + 1] = 128;
	operations[0]++;
}

void	reverse_rotate(int *stack_a, int *stack_b, int to_rotate, short *operations)
{
	int	i;
	int	tmp;

	if (to_rotate == 0 || to_rotate == -1)
	{
		tmp = stack_a[stack_a[0]];
		i = stack_a[0];
		while (--i > 0)
			stack_a[i + 1] = stack_a[i];
		stack_a[1] = tmp;
	}
	if (to_rotate == 1 || to_rotate == -1)
	{
		tmp = stack_b[stack_b[0]];
		i = stack_b[0];
		while (--i > 0)
			stack_b[i + 1] = stack_b[i];
		stack_b[1] = tmp;
	}
	if (to_rotate == 0)
		operations[operations[0] + 1] = 256;
	if (to_rotate == 1)
		operations[operations[0] + 1] = 512;
	if (to_rotate == -1)
		operations[operations[0] + 1] = 1024;
	operations[0]++;
}
