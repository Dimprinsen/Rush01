/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thtinner <thtinner@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 17:49:42 by thtinner          #+#    #+#             */
/*   Updated: 2025/03/02 21:08:44 by thtinner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "rush.h"

int	is_valid(int grid[4][4], int row, int col, int nbr)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (grid[row][i] == nbr || grid[i][col] == nbr)
			return (0);
		i++;
	}
	return (1);
}

void	next_cell(int *row, int *col)
{
	if (*col == 3)
	{
		*row += 1;
		*col = 0;
	}
	else
		*col += 1;
}

int	final_check(int grid[4][4], int constraints[16])
{
	if (check_constraints(grid, constraints))
	{
		print_grid(grid);
		return (1);
	}
	return (0);
}

void	print_grid(int grid[4][4])
{
	int		row;
	int		col;
	char	c;

	row = 0;
	while (row < 4)
	{
		col = 0;
		while (col < 4)
		{
			c = grid[row][col] + '0';
			ft_putchar(c);
			if (col < 3)
				ft_putchar(' ');
			col++;
		}
		ft_putchar('\n');
		row++;
	}
}

int	solve_grid(int grid[4][4], int constraints[16], int row, int col)
{
	int	nbr;
	int	next_row;
	int	next_col;

	if (row == 4)
		return (final_check(grid, constraints));
	next_row = row;
	next_col = col;
	next_cell(&next_row, &next_col);
	nbr = 1;
	while (nbr <= 4)
	{
		if (is_valid(grid, row, col, nbr))
		{
			grid[row][col] = nbr;
			if (solve_grid(grid, constraints, next_row, next_col))
				return (1);
			grid[row][col] = 0;
		}
		nbr++;
	}
	return (0);
}
