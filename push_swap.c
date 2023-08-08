/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovotny <rnovotny@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 20:39:52 by rnovotny          #+#    #+#             */
/*   Updated: 2023/07/18 20:13:52 by rnovotny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int check_input(int length, char **input)
{
    int i;
    int j;

    i = 0;
    while (i < length - 1)
    {
        j = 0;
        if (input[i][j] > '9' || input[i][j] < '0')
        {
            if (input[i][j] != '-' && input[i][j] != '+')
                return (1);
        }
        while (input[i][j])
        {
            if (input[i][j] > '9' || input[i][j] < '0')
                return (1);
            j++;
        }
        i++;
    }
    return (0);
}

int main(int argc, char **argv)
{
    if (check_input(argc, argv))
        return (1);
    return (0);
}