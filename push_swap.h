/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovotny <rnovotny@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 20:38:50 by rnovotny          #+#    #+#             */
/*   Updated: 2023/10/16 15:42:31 by rnovotny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>

int		main(int argc, char **argv);
int		check_input(int length, char **input);
int		check_duplicates(int length, char**input);
void	process_stack(int argc, char **argv);
void	sort_stacks(int **stacks, int *operations);

void	swap(int **stacks, int to_swap, int *operations);
void	push_a(int **stacks, int *operations);
void	push_b(int **stacks, int *operations);
void	rotate(int **stacks, int to_rotate, int *operations);
void	reverse_rotate(int **stacks, int to_rotate, int *operations);

int		find_min_index(int **stacks);
int		find_min_max(int *stack, int min_or_max);
int		find_offset(int **stacks);
long	ft_atoi(const char *nptr);

void	do_sort(int **stacks, int *operations);
void	start_sort(int **stacks, int *operations);
void	assign_score(int **stacks, int position);
void	calculate_score(int **stacks, int a, int b);
void	calculate_score_rrr(int **stacks, int a, int b);

void	move_rr(int **stacks, int *operations);
void	move_rrr(int **stacks, int *operations);
void	move_ra_rb(int **stacks, int *operations);
void	special_cases(int **stacks, int *operations);

void	two(int **stacks, int *operations);
void	three(int **stacks, int *operations);
void	four(int **stacks, int *operations);
void	five(int **stacks, int *operations);
void	five_too(int **stacks, int *operations);

void	read_operations(int *operations);
void	optimise_operations(int *operations);
int		operation_sums(int *operations, int i, int sum);
void	write_operation(short i);

#endif