/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovotny <rnovotny@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 08:33:23 by rnovotny          #+#    #+#             */
/*   Updated: 2023/10/16 14:54:39 by rnovotny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	swap(int **stacks, int to_swap)
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
}

void	push_a(int **stacks)
{
	int	i;

	if (!stacks[1][0])
		return ;
	i = stacks[0][0] + 1;
	while (i-- > 1)
		stacks[0][i + 1] = stacks[0][i];
	stacks[0][1] = stacks[1][1];
	i = 0;
	while (++i < stacks[1][0])
		stacks[1][i] = stacks[1][i + 1];
	stacks[0][0]++;
	stacks[1][0]--;
}

void	push_b(int **stacks)
{
	int	i;

	if (!stacks[0][0])
		return ;
	i = stacks[1][0] + 1;
	while (i-- > 1)
		stacks[1][i + 1] = stacks[1][i];
	stacks[1][1] = stacks[0][1];
	i = 0;
	while (++i < stacks[0][0])
		stacks[0][i] = stacks[0][i + 1];
	stacks[1][0]++;
	stacks[0][0]--;
}

void	rotate(int **stacks, int to_rotate)
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
}

void	reverse_rotate(int **stacks, int to_rotate)
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
}
