/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovotny <rnovotny@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 20:38:50 by rnovotny          #+#    #+#             */
/*   Updated: 2023/09/01 19:08:49 by rnovotny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>

int		main(int argc, char **argv);
int		check_input(int length, char **input);
void	process_stack(int argc, char **argv);
void	sort_stacks(int *stack_a, int *stack_b);
long	ft_atoi(const char *nptr);

void	swap(int *stack_a, int *stack_b, int to_swap);
void	push_a(int *stack_a, int *stack_b);
void	push_b(int *stack_a, int *stack_b);
void	rotate(int *stack_a, int *stack_b, int to_rotate);
void	reverse_rotate(int *stack_a, int *stack_b, int to_rotate);

int		operations(int *stack_a, int *stack_b, int number);
void	special_cases(int *stack_a, int *stack_b);

void	two(int *stack_a, int *stack_b);
void	three(int *stack_a, int *stack_b);
void	four(int *stack_a, int *stack_b);
void	five(int *stack_a, int *stack_b);
void	five_too(int *stack_a, int *stack_b);

#endif