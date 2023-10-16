/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moving.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovotny <rnovotny@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 20:57:26 by rnovotny          #+#    #+#             */
/*   Updated: 2023/10/16 15:42:31 by rnovotny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	special_cases(int **stacks, int *operations)
{
	if (stacks[0][0] == 1)
		return ;
	if (stacks[0][0] == 2)
		two(stacks, operations);
	else if (stacks[0][0] == 3)
		three(stacks, operations);
	else if (stacks[0][0] == 4)
		four(stacks, operations);
	else
		five(stacks, operations);
}

void	move_rr(int **stacks, int *operations)
{
	int	i;
	int	a;
	int	b;

	i = 0;
	a = stacks[3][0];
	b = stacks[4][0];
	if (a < b)
	{
		while (++i < a)
			rotate(stacks, -1, operations);
		while (i++ < b)
			rotate(stacks, 1, operations);
	}
	else
	{
		while (++i < b)
			rotate(stacks, -1, operations);
		while (i++ < a)
			rotate(stacks, 0, operations);
	}
}

void	move_rrr(int **stacks, int *operations)
{
	int	i;
	int	a;
	int	b;

	i = 0;
	a = stacks[0][0] - stacks[3][0] + 2;
	b = stacks[1][0] - stacks[4][0] + 2;
	if (a < b)
	{
		while (++i < a)
			reverse_rotate(stacks, -1, operations);
		while (i++ < b)
			reverse_rotate(stacks, 1, operations);
	}
	else
	{
		while (++i < b)
			reverse_rotate(stacks, -1, operations);
		while (i++ < a)
			reverse_rotate(stacks, 0, operations);
	}
}

void	move_ra_rb(int **stacks, int *operations)
{
	int	i;
	int	a;
	int	b;

	i = 0;
	if (stacks[4][stacks[3][0]] == 4)
	{
		a = stacks[3][0];
		b = stacks[1][0] - stacks[4][0] + 2;
		while (++i < a)
			rotate(stacks, 0, operations);
		i = 0;
		while (++i < b)
			reverse_rotate(stacks, 1, operations);
	}
	if (stacks[4][stacks[3][0]] == 8)
	{
		a = stacks[0][0] - stacks[3][0] + 2;
		b = stacks[4][0];
		while (++i < a)
			reverse_rotate(stacks, 0, operations);
		i = 0;
		while (++i < b)
			rotate(stacks, 1, operations);
	}
}