/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovotny <rnovotny@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 20:38:50 by rnovotny          #+#    #+#             */
/*   Updated: 2023/10/11 18:16:25 by rnovotny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>

int		main(int argc, char **argv);
int		check_input(int length, char **input);
void	process_stack(int argc, char **argv);
void	sort_stacks(int **stacks, short *operations);
long	ft_atoi(const char *nptr);

void	swap(int **stacks, int to_swap, short *operations);
void	push_a(int **stacks, short *operations);
void	push_b(int **stacks, short *operations);
void	rotate(int **stacks, int to_rotate, short *operations);
void	reverse_rotate(int **stacks, int to_rotate, short *operations);

int		calculations(int **stacks, int number);
int		find_min_max(int *stack, int min_or_max);
int		find_min_index(int *stack);
void	sort(int **stacks, short *operations);
void	slow_sort(int **stacks, short *operations);
void	special_cases(int **stacks, short *operations);
void	sorting(int **stacks, int *moves, short *operations);
void	turk_sort(int **stacks, short *operations);
void	move(int **stacks, short *operations);
void	assign_score(int **stacks, int position);
void	calculate_score(int **stacks, int a, int b);
int		find_offset(int **stacks);

void	print_stack(int *stack);

void	two(int **stacks, short *operations);
void	three(int **stacks, short *operations);
void	four(int **stacks, short *operations);
void	five(int **stacks, short *operations);
void	five_too(int **stacks, short *operations);

void	read_operations(short *operations);
void	optimise_operations(short *operations);
int		operation_sums(short *operations, int i, int sum);
void	write_operation(short i);
void	optimise_rr(short *operations);
void	shift(short *operations, int i, int j);

#endif