/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovotny <rnovotny@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 10:58:11 by rnovotny          #+#    #+#             */
/*   Updated: 2023/10/15 00:22:47 by rnovotny         ###   ########.fr       */
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

int	append(char *s1, char *s2)
{
	int	i;

	if (s2 != 'a' && s2 != 'b' && s2 != 'p' && s2 != 'r' && s2 != 's')
		return (1);
	i = 0;
	while (s1[i] != '\0')
		i++;
	s1[i] = *s2;
	s1[i + 1] = '\0';
	return (0);
}

void	execute(int **stacks, char *instruction)
{
	
}

int	read_moves(int **stacks, char *instruction)
{
	int		check;
	char	buffer;

	instruction[0] = '\0';
	check = 1;
	while (check > 0)
	{
		check = read(0, &buffer, 1);
		if (check == 0)
			return (0);
		if (check < 0)
			return (1);
		if (buffer == '\n')
		{
			execute(stacks, instruction);
			instruction[0] = '\0';
			continue ;
		}
		if (append(instruction, buffer))
			return (1)
	}
	return (0);
}	

int	process_input(int argc, char **argv)
{
	int		**stacks;
	char	*line;
	
	stacks = (int **) malloc(2 * sizeof(int *));	// 0 - stack A, 1 - stack B
	if (!stacks)
		return (1);
	stacks[0] = (int *) malloc(argc * sizeof(int));
	stacks[1] = (int *) malloc(argc * sizeof(int));
	line = (char *)malloc(4 * sizeof(char));
	if (!stacks[0] || stacks[1] || !line || read_moves(stacks, line))
	{
		
		free_all(stacks, line);
		return (1);
	}
	check_result(stacks);
	return (0);
}

int	main(int argc, char **argv)
{	
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