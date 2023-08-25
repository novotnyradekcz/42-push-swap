/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovotny <rnovotny@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 20:38:50 by rnovotny          #+#    #+#             */
/*   Updated: 2023/08/25 21:32:42 by rnovotny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>

int	main(int argc, char **argv);
int	check_input(int length, char **input);

int	swap(int *stack_a, int *stack_b, int size_a, int to_swap);
int	push(int *stack_a, int *stack_b, int size_a, int push_to);
int	rotate(int *stack_a, int *stack_b, int size_a, int to_rotate);
int	reverse_rotate(int *stack_a, int *stack_b, int size_a, int to_rotate);

#endif