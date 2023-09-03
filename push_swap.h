/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovotny <rnovotny@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 20:38:50 by rnovotny          #+#    #+#             */
/*   Updated: 2023/09/03 22:18:32 by rnovotny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>

int		main(int argc, char **argv);
int		check_input(int length, char **input);
void	process_stack(int argc, char **argv);
void	sort_stacks(int *stack_a, int *stack_b, short *operations);
long	ft_atoi(const char *nptr);

void	swap(int *stack_a, int *stack_b, int to_swap, short *operations);
void	push_a(int *stack_a, int *stack_b, short *operations);
void	push_b(int *stack_a, int *stack_b, short *operations);
void	rotate(int *stack_a, int *stack_b, int to_rotate, short *operations);
void	reverse_rotate(int *stack_a, int *stack_b, int to_rotate, short *operations);

int		calculations(int *stack_a, int *stack_b, int number);
void	sort(int *stack_a, int * stack_b, short *operations);
void	slow_sort(int *stack_a, int * stack_b, short *operations);
void	special_cases(int *stack_a, int *stack_b, short *operations);

void	two(int *stack_a, int *stack_b, short *operations);
void	three(int *stack_a, int *stack_b, short *operations);
void	four(int *stack_a, int *stack_b, short *operations);
void	five(int *stack_a, int *stack_b, short *operations);
void	five_too(int *stack_a, int *stack_b, short *operations);

void	read_operations(short *operations);
void	optimise_operations(short *operations);
int		operation_sums(short *operations, int i, int sum);
void	write_operation(short i);

#endif