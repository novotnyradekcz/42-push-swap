/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checking.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovotny <rnovotny@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 16:50:58 by rnovotny          #+#    #+#             */
/*   Updated: 2023/10/15 00:23:09 by rnovotny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_result(int **stacks)
{
	
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

int	initial_checks(int argc, char **argv)
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
	return (0);
}