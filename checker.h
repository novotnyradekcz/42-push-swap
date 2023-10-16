/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovotny <rnovotny@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 10:59:33 by rnovotny          #+#    #+#             */
/*   Updated: 2023/10/16 15:06:06 by rnovotny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>

int		main(int argc, char **argv);
void	execute(int **stacks, char *instruction);
void	free_all(int **stacks, char *instruction);

int		process_input(int argc, char **argv);
int		**allocate_stacks(int size);
int		read_moves(int **stacks, char *instruction);
int		append(char *s1, char s2);
long	ft_atoi(const char *nptr);

int		initial_checks(int argc, char **argv);
int		check_input(int length, char **input);
int		check_duplicates(int length, char**input);
void	check_result(int **stacks);

void	swap(int **stacks, int to_swap);
void	push_a(int **stacks);
void	push_b(int **stacks);
void	rotate(int **stacks, int to_rotate);
void	reverse_rotate(int **stacks, int to_rotate);

#endif