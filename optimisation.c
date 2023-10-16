/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimisation.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovotny <rnovotny@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 11:43:29 by rnovotny          #+#    #+#             */
/*   Updated: 2023/10/16 15:42:31 by rnovotny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	operation_sums(int *operations, int i, int sum)
{
	int	j;

	if (sum == 3)
		operations[i] = 4;
	if (sum == 96)
		operations[i] = 128;
	if (sum == 768)
		operations[i] = 1024;
	j = i;
	while (++j < operations[0])
		operations[j] = operations[j + 1];
	operations[0] -= 1;
	if (i > 1)
		i--;
	return (i);
}


void	optimise_operations(int *operations)
{
	int	i;
	int	j;
	int	sum;

	i = 1;
	while (i < operations[0])
	{
		sum = operations[i] + operations[i + 1];
		if (sum == 2 || sum == 4 || sum == 8 ||
			sum == 24 || sum == 288 || sum == 576)
		{
			j = i;
			while (++j < operations[0])
				operations[j - 1] = operations[j + 1];
			operations[0] -= 2;
			if (i > 1)
				i--;
		}
		else if (sum == 3 || sum == 96 || sum == 768)
			i = operation_sums(operations, i, sum);
		else
			i++;
	}
}

void	write_operation(short i)
{
	if (i == 1)
		write(1, "sa\n", 3);
	if (i == 2)
		write(1, "sb\n", 3);
	if (i == 4)
		write(1, "ss\n", 3);
	if (i == 8)
		write(1, "pa\n", 3);
	if (i == 16)
		write(1, "pb\n", 3);
	if (i == 32)
		write(1, "ra\n", 3);
	if (i == 64)
		write(1, "rb\n", 3);
	if (i == 128)
		write(1, "rr\n", 3);
	if (i == 256)
		write(1, "rra\n", 4);
	if (i == 512)
		write(1, "rrb\n", 4);
	if (i == 1024)
		write(1, "rrr\n", 4);
}

void	read_operations(int *operations)
{
	int	i;

	i = 0;
	optimise_operations(operations);
	while (i++ < operations[0])
		write_operation(operations[i]);
}
