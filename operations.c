/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovotny <rnovotny@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 21:11:42 by rnovotny          #+#    #+#             */
/*   Updated: 2023/08/29 17:11:02 by rnovotny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(int *stack_a, int *stack_b, int to_swap)
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
		write(1, "sa\n", 3);
	if (to_swap == 1)
		write(1, "sb\n", 3);
	if (to_swap == -1)
		write(1, "ss\n", 3);
}

void	push_a(int *stack_a, int *stack_b)
{
	int i;

	i = 0;
	while (++i < stack_a[0])
		stack_a[i + 1] = stack_a[i];
	stack_a[1] = stack_b[1];
	i = 0;
	while (++i < stack_b[0])
		stack_b[i] = stack_b[i + 1];
	stack_a[0]++;
	stack_b[0]--;
	write(1, "pa\n", 3);
}

void	push_b(int *stack_a, int *stack_b)
{
	int	i;

	i = 0;
	while (++i < stack_b[0])
		stack_b[i + 1] = stack_b[i];
	stack_b[1] = stack_a[1];
	i = 0;
	while (++i < stack_a[0])
		stack_a[i] = stack_a[i + 1];
	stack_b[0]++;
	stack_a[0]--;
	write(1, "pb\n", 3);
}

void	rotate(int *stack_a, int *stack_b, int to_rotate)
{
	int	i;
	int	tmp;

	if (to_rotate == 0 || to_rotate == -1)
	{
		tmp = stack_a[1];
		i = 0;
		while (++i < stack_a[0])
			stack_a[i] = stack_a[i + 1];
		stack_a[i] = tmp;
	}
	if (to_rotate == 1 || to_rotate == -1)
	{
		tmp = stack_b[1];
		i = 0;
		while (++i < stack_b[0])
			stack_b[i] = stack_b[i + 1];
		stack_b[i] = tmp;
	}
	if (to_rotate == 0)
		write(1, "ra\n", 3);
	if (to_rotate == 1)
		write(1, "rb\n", 3);
	if (to_rotate == -1)
		write(1, "rr\n", 3);
}

void	reverse_rotate(int *stack_a, int *stack_b, int to_rotate)
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
		write(1, "rra\n", 4);
	if (to_rotate == 1)
		write(1, "rrb\n", 4);
	if (to_rotate == -1)
		write(1, "rrr\n", 4);
}
