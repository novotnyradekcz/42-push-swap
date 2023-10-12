/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovotny <rnovotny@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 21:11:42 by rnovotny          #+#    #+#             */
/*   Updated: 2023/10/12 13:44:52 by rnovotny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// #include <stdio.h>

void	swap(int **stacks, int to_swap, unsigned short *operations)
{
	int	tmp;

	if (to_swap == 0 || to_swap == -1)
	{
		tmp = stacks[0][1];
		stacks[0][1] = stacks[0][2];
		stacks[0][2] = tmp;
	}
	if (to_swap == 1 || to_swap == -1)
	{
		tmp = stacks[1][1];
		stacks[1][1] = stacks[1][2];
		stacks[1][2] = tmp;
	}
	if (to_swap == 0)
		operations[operations[0] + 1] = 1;
	if (to_swap == 1)
		operations[operations[0] + 1] = 2;
	if (to_swap == -1)
		operations[operations[0] + 1] = 4;
	operations[0]++;
}

void	push_a(int **stacks, unsigned short *operations)
{
	int	i;

	i = stacks[0][0] + 1;
	while (i-- > 1)
		stacks[0][i + 1] = stacks[0][i];
	stacks[0][1] = stacks[1][1];
	i = 0;
	while (++i < stacks[1][0])
		stacks[1][i] = stacks[1][i + 1];
	stacks[0][0]++;
	stacks[1][0]--;
	operations[operations[0] + 1] = 8;
	operations[0]++;
}

void	push_b(int **stacks, unsigned short *operations)
{
	int	i;

	i = stacks[1][0] + 1;
	while (i-- > 1)
		stacks[1][i + 1] = stacks[1][i];
	stacks[1][1] = stacks[0][1];
	i = 0;
	while (++i < stacks[0][0])
		stacks[0][i] = stacks[0][i + 1];
	stacks[1][0]++;
	stacks[0][0]--;
	operations[operations[0] + 1] = 16;
	operations[0]++;
}

void	rotate(int **stacks, int to_rotate, unsigned short *operations)
{
	int	i;
	int	tmp;

	i = 0;
	if (to_rotate == 0 || to_rotate == -1)
	{
		tmp = stacks[0][1];
		while (++i < stacks[0][0])
			stacks[0][i] = stacks[0][i + 1];
		stacks[0][i] = tmp;
	}
	i = 0;
	if (to_rotate == 1 || to_rotate == -1)
	{
		tmp = stacks[1][1];
		while (++i < stacks[1][0])
			stacks[1][i] = stacks[1][i + 1];
		stacks[1][i] = tmp;
	}
	if (to_rotate == 0)
		operations[operations[0] + 1] = 32;
	if (to_rotate == 1)
		operations[operations[0] + 1] = 64;
	if (to_rotate == -1)
		operations[operations[0] + 1] = 128;
	operations[0]++;
}

void	reverse_rotate(int **stacks, int to_rotate, unsigned short *operations)
{
	int	i;
	int	tmp;

	if (to_rotate == 0 || to_rotate == -1)
	{
		tmp = stacks[0][stacks[0][0]];
		i = stacks[0][0];
		while (--i > 0)
			stacks[0][i + 1] = stacks[0][i];
		stacks[0][1] = tmp;
	}
	if (to_rotate == 1 || to_rotate == -1)
	{
		tmp = stacks[1][stacks[1][0]];
		i = stacks[1][0];
		while (--i > 0)
			stacks[1][i + 1] = stacks[1][i];
		stacks[1][1] = tmp;
	}
	if (to_rotate == 0)
		operations[operations[0] + 1] = 256;
	if (to_rotate == 1)
		operations[operations[0] + 1] = 512;
	if (to_rotate == -1)
		operations[operations[0] + 1] = 1024;
	operations[0]++;
}

// void	print_stacks(int stacks[2][21])
// {
// 	int	i;

// 	i = -1;
// 	while (i++ < stacks[0][0])
// 		printf("%d ", stacks[0][i]);
// 	printf("\n");
// 	i = -1;
// 	while (i++ < stacks[1][0])
// 		printf("%d ", stacks[1][i]);
// 	printf("\n");
// }

// int	main(void)
// {
// 	short	operations[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
// 	int	stacks[2][21] =
// 	{
// 		{9, 1, 17, 27, 13, 14, 5, 16, 11, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, 
// 		{11, 9, 8, 6, 4, 2, 20, 19, 18, 12, 15, 10, 1, 1, 1, 1, 1, 1, 1, 1, 1}
// 	};
// 	push_b(stacks, operations);
// 	// push_b(stacks, operations);
// 	// push_b(stacks, operations);
// 	// push_b(stacks, operations);
// 	// push_b(stacks, operations);
// 	print_stacks(stacks);
// }