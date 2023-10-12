/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovotny <rnovotny@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 20:39:52 by rnovotny          #+#    #+#             */
/*   Updated: 2023/10/12 21:33:14 by rnovotny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_stacks(int **stacks, unsigned short *operations)
{
	int	i;
	
	i = 1;
	while (i < stacks[0][0])
	{
		if (stacks[0][i] > stacks[0][i + 1])
			break ;
		i++;
	}
	if (i == stacks[0][0])
		return ;
	if (stacks[0][0] < 6)
		special_cases(stacks, operations);
	else
		start_sort(stacks, operations);
}

void	process_stack(int argc, char **argv)
{
	int				**stacks;
	unsigned short	*operations;
	int				i;

	i = -1;
	stacks = (int **) malloc(5 * sizeof(int *));	// 0 - stack A, 1 - stack B, 2 - operation cost, 3 - position of number in B that needs to be on top, 4 - operations (1: rr, 2: rrr, 4: ra, rrb, 8: rra, rb)
	while (i++ < 4)
		stacks[i] = (int *) malloc(argc * sizeof(int));
	operations = (unsigned short *) malloc(65536 * sizeof(unsigned short));
	stacks[0][0] = argc - 1;
	stacks[1][0] = 0;
	operations[0] = 0;
	i = 0;
	while (i++ < argc - 1)
		stacks[0][i] = ft_atoi(argv[i]);
	sort_stacks(stacks, operations);
	read_operations(operations);	// post-optimisation
	i = -1;
	while (i++ < 4)
		free(stacks[i]);
	free(stacks);
	free(operations);
}

int	check_duplicates(int length, char **input)
{
	int	i;
	int	j;
	int	number;

	i = 0;
	while (++i < length)
	{
		number = ft_atoi(input[i]);
		j = i;
		while (++j < length)
		{
			if (number == ft_atoi(input[j]))
				return (1);
		}
	}
	return (0);
}

int	check_input(int length, char **input)
{
	int	i;
	int	j;

	i = 1;
	while (i < length)
	{
		j = 0;
		if (input[i][j] > '9' || input[i][j] < '0')
		{
			if (input[i][j] != '-' && input[i][j] != '+')
				return (1);
		}
		j++;
		while (input[i][j])
		{
			if (input[i][j] > '9' || input[i][j] < '0')
				return (1);
			j++;
		}
		if (j > 11)
			return (1);
		i++;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	int	i;

	if (argc < 2)
		return (1);
	if (check_input(argc, argv))
	{
		write(2, "Error\n", 6);
		return (1);
	}
	i = 0;
	while (++i < argc)
	{
		if (ft_atoi(argv[i]) < -2147483648 || ft_atoi(argv[i]) > 2147483647)
		{
			write(2, "Error\n", 6);
			return (1);
		}
	}
	if (check_duplicates(argc, argv))
	{
		write(2, "Error\n", 6);
		return (1);
	}
	process_stack(argc, argv);
	return (0);
}

// stacks[0][0] and stacks[1][0] is current size of stack 
// stacks[2][0] is the position of the largest number
// stacks[3][0] is position of the minimum of stacks[2]
// stacks[4][0] has the value from stacks[3] corresponding to stacks[3][0] (=stacks[3][stacks[3][0]])