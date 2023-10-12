/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovotny <rnovotny@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 20:38:50 by rnovotny          #+#    #+#             */
/*   Updated: 2023/10/12 17:38:40 by rnovotny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>

int		main(int argc, char **argv);
int		check_input(int length, char **input);
void	process_stack(int argc, char **argv);
void	sort_stacks(int **stacks, unsigned short *operations);
long	ft_atoi(const char *nptr);

void	swap(int **stacks, int to_swap, unsigned short *operations);
void	push_a(int **stacks, unsigned short *operations);
void	push_b(int **stacks, unsigned short *operations);
void	rotate(int **stacks, int to_rotate, unsigned short *operations);
void	reverse_rotate(int **stacks, int to_rotate, unsigned short *operations);

void	assign_score(int **stacks, int position);
void	calculate_score(int **stacks, int a, int b);
int		find_min_max(int *stack, int min_or_max);
int		find_min_index(int **stacks);
int		find_offset(int **stacks);

void	special_cases(int **stacks, unsigned short *operations);
void	turk_sort(int **stacks, unsigned short *operations);
void	move(int **stacks, unsigned short *operations);

void	print_stacks(int **stacks);

void	two(int **stacks, unsigned short *operations);
void	three(int **stacks, unsigned short *operations);
void	four(int **stacks, unsigned short *operations);
void	five(int **stacks, unsigned short *operations);
void	five_too(int **stacks, unsigned short *operations);

void	read_operations(unsigned short *operations);
void	optimise_operations(unsigned short *operations);
int		operation_sums(unsigned short *operations, int i, int sum);
void	write_operation(short i);

#endif