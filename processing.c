/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovotny <rnovotny@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 17:16:51 by rnovotny          #+#    #+#             */
/*   Updated: 2023/11/10 12:34:57 by rnovotny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

long	ft_atoi(const char *nptr)
{
	int		i;
	int		neg;
	long	res;

	neg = 1;
	res = 0;
	i = 0;
	while ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == 32)
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			neg = -neg;
		i++;
	}
	while (nptr[i] >= 48 && nptr[i] <= 57)
	{
		res = res * 10 + (nptr[i] - 48);
		i++;
	}
	return (neg * res);
}

int	append(char *s1, char s2)
{
	int	i;

	i = 0;
	while (s1[i] != '\0')
		i++;
	if ((i == 0 && s2 != 'p' && s2 != 'r' && s2 != 's')
		|| (i == 1 && s1[0] == 'p' && s2 != 'a' && s2 != 'b')
		|| (i == 1 && s1[0] == 'r' && s2 != 'a' && s2 != 'b' && s2 != 'r')
		|| (i == 1 && s1[0] == 's' && s2 != 'a' && s2 != 'b' && s2 != 's')
		|| (i == 2 && s1[0] == 'p')
		|| (i == 2 && s1[0] == 'r' && (s1[1] == 'a' || s1[1] == 'b'))
		|| (i == 2 && s1[0] == 'r' && s1[1] == 'r'
			&& s2 != 'a' && s2 != 'b' && s2 != 'r')
		|| (i == 2 && s1[0] == 's')
		|| (i == 3))
		return (1);
	while (s1[i] != '\0')
		i++;
	s1[i] = s2;
	s1[i + 1] = '\0';
	return (0);
}

int	read_moves(int **stacks, char *instruction)
{
	int		check;
	char	buffer;

	check = 1;
	while (check > 0)
	{
		check = read(0, &buffer, 1);
		if (buffer == '\n' && check == 0)
			return (0);
		if (check <= 0)
			return (1);
		if (buffer == '\n')
		{
			execute(stacks, instruction);
			instruction[0] = '\0';
			continue ;
		}
		if (append(instruction, buffer))
		{
			while (check == 1)
				check = read(0, &buffer, 1);
			return (1);
		}
	}
	return (0);
}

int	**allocate_stacks(int size)
{
	int	**stacks;

	stacks = (int **) malloc(2 * sizeof(int *));
	if (!stacks)
		return (0);
	stacks[0] = (int *) malloc(size * sizeof(int));
	stacks[1] = (int *) malloc(size * sizeof(int));
	if (stacks[0] && stacks[1])
	{
		stacks[0][0] = size - 1;
		stacks[1][0] = 0;
	}
	return (stacks);
}

int	process_input(int argc, char **argv)
{
	int		i;
	int		**stacks;
	char	*line;

	stacks = allocate_stacks(argc);
	line = (char *)malloc(4 * sizeof(char));
	if (!stacks[0] || !stacks[1] || !line)
	{
		free_all(stacks, line);
		return (1);
	}
	i = 0;
	while (++i < argc)
		stacks[0][i] = ft_atoi(argv[i]);
	line[0] = '\0';
	if (read_moves(stacks, line))
	{
		free_all(stacks, line);
		return (1);
	}
	check_result(stacks);
	free_all(stacks, line);
	return (0);
}
