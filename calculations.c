/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculations.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovotny <rnovotny@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 15:15:17 by rnovotny          #+#    #+#             */
/*   Updated: 2023/08/31 19:50:45 by rnovotny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	special_cases(int *stack_a, int *stack_b)
{
	if (stack_a[0] == 1)
		return ;
	if (stack_a[0] == 2)
	{
		two(stack_a, stack_b);
		return ;
	}
	if (stack_a[0] == 3)
	{
		three(stack_a, stack_b);
		return ;
	}
}

int	operations(int *stack_a, int *stack_b, int number)
{
	int	i;
	int	front;
	int	back;

	i = 1;
	while (stack_b[i] > stack_a[number])
		i++;
	front = i - 1;
	i = stack_a[0];
	while (stack_b[i] < stack_a[number])
		i--;
	back = i + 1;
	if (front < back)
		return (front);
	else
		return (back);
}
