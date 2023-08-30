/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovotny <rnovotny@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 20:38:50 by rnovotny          #+#    #+#             */
/*   Updated: 2023/08/30 16:56:45 by rnovotny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>

int 	main(int argc, char **argv);
int 	check_input(int length, char **input);
void	process_stack(int argc, char **argv);
void	sort_stacks(int *stack_a, int *stack_b, int size);
long	ft_atoi(const char *nptr);

void	swap(int *stack_a, int *stack_b, int to_swap);
void	push_a(int *stack_a, int *stack_b);
void	push_b(int *stack_a, int *stack_b);
void	rotate(int *stack_a, int *stack_b, int to_rotate);
void	reverse_rotate(int *stack_a, int *stack_b, int to_rotate);

#endif