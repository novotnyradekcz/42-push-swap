/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovotny <rnovotny@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 10:59:33 by rnovotny          #+#    #+#             */
/*   Updated: 2023/10/15 00:20:37 by rnovotny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>

int		main(int argc, char **argv);
int		process_input(int argc, char **argv);
int		read_moves(int **stacks, char *instruction);
int		append(char *s1, char *s2);
void	free_all(int **stacks, char *instruction);

int		initial_checks(int argc, char **argv);
int		check_input(int length, char **input);
int		check_duplicates(int length, char**input);

#endif