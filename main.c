/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thtinner <thtinner@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 17:45:42 by thtinner          #+#    #+#             */
/*   Updated: 2025/03/02 18:58:36 by thtinner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "rush.h"

int	validate_input(char *str, int *input)
{
	int	i;
	int	j;

	if (ft_strlen(str) != 31)
		return (0);
	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] >= '1' && str[i] <= '4')
		{
			input[j++] = ft_atoi(&str[i]);
			if (j > 16)
				return (0);
		}
		else if (str[i] != ' ')
			return (0);
		i++;
	}
	return (j == 16);
}

int	main(int argc, char **argv)
{
	int	grid[4][4];
	int	input[16];

	if (argc != 2 || !validate_input(argv[1], input))
	{
		ft_putstr("Error\n");
		return (1);
	}
	if (!solve_grid(grid, input, 0, 0))
	{
		ft_putstr("Error\n");
		return (1);
	}
	if (solve_grid(grid, input, 0, 0))
		print_grid(grid);
	return (0);
}
