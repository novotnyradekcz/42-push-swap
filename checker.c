/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovotny <rnovotny@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 10:58:11 by rnovotny          #+#    #+#             */
/*   Updated: 2023/11/10 12:16:24 by rnovotny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	free_all(int **stacks, char *instruction)
{
	if (stacks[0])
		free(stacks[0]);
	if (stacks[1])
		free(stacks[1]);
	if (stacks)
		free(stacks);
	if (instruction)
		free(instruction);
}

void	execute(int **stacks, char *instruction)
{
	if (instruction[0] == 'p' && instruction[1] == 'a')
		push_a(stacks);
	if (instruction[0] == 'p' && instruction[1] == 'b')
		push_b(stacks);
	if (instruction[0] == 's' && instruction[1] == 'a')
		swap(stacks, 0);
	if (instruction[0] == 's' && instruction[1] == 'b')
		swap(stacks, 1);
	if (instruction[0] == 's' && instruction[1] == 's')
		swap(stacks, -1);
	if (instruction[0] == 'r' && instruction[1] == 'a')
		rotate(stacks, 0);
	if (instruction[0] == 'r' && instruction[1] == 'b')
		rotate(stacks, 1);
	if (instruction[0] == 'r' && instruction[1] == 'r' && !instruction[2])
		rotate(stacks, -1);
	if (instruction[0] == 'r' && instruction[2] == 'a')
		reverse_rotate(stacks, 0);
	if (instruction[0] == 'r' && instruction[2] == 'b')
		reverse_rotate(stacks, 1);
	if (instruction[0] == 'r' && instruction[2] == 'r')
		reverse_rotate(stacks, -1);
}

int	main(int argc, char **argv)
{
	if (argc < 2)
		return (0);
	if (initial_checks(argc, argv))
	{
		write(2, "Error\n", 6);
		return (1);
	}
	if (process_input(argc, argv))
	{
		write(2, "Error\n", 6);
		return (1);
	}
	return (0);
}

// load stack form arguments
// and perform the same initial steps as in the push_swap program
// but
// stop before starting the sorting
// at that point start reading the stdin
// and manipulating the stack based on the instructions
// (Error if instruction input is wrong)
// when stdin is finished, check if stack is ordered