/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovotny <rnovotny@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 20:39:52 by rnovotny          #+#    #+#             */
/*   Updated: 2023/08/29 13:30:55 by rnovotny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	sort_stacks(int *stack_a, int *stack_b, int size)
{
	int	i;
	int	size_a;
	
	while(size_a > 0)
	{
		
	}
}

void	process_stack(int argc, char **argv)
{
	int	*stack_a;
	int	*stack_b;
	int	i;
	// TODO: idea - merge stack_a and b into one array of arrays stack[][]
	stack_a = (int *) malloc(sizeof(int) * (argc));	// leave one extra sport for size
	stack_b = (int *) malloc(sizeof(int) * (argc));	// stack_a[0] and stack_b[0] is current size of stack 
	i = 0;
	while (i++ < argc - 1)
		stack_a[i - 1] = ft_atoi(argv[i]);
	sort_stacks(stack_a, stack_b, i);
}

int check_input(int length, char **input)
{
	int i;
	int j;

	i = 1;
	while (i < length - 1)
	{
		j = 0;
		if (input[i][j] > '9' || input[i][j] < '0')
		{
			if (input[i][j] != '-' && input[i][j] != '+')
				return (1);
		}
		while (input[i][j])
		{
			if (input[i][j] > '9' || input[i][j] < '0')
				return (1);
			j++;
		}
		if (j > 10)
			return (1);
		i++;
	}
	return (0);
}

int main(int argc, char **argv)
{
	int	i;
	
	if (check_input(argc, argv))
		eturn (1);
	i = 1;
	while (i < argc)
	{
		if (ft_atoi(argv[i]) < -2147483648 || ft_atoi(argv[i]) > 2147483647)
			return (1);
	}
	process_stack(argc, argv);
	return (0);
}