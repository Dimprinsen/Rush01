/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thtinner <thtinner@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 18:47:35 by thtinner          #+#    #+#             */
/*   Updated: 2025/03/02 20:40:27 by thtinner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

void	fill(int *array, int grid[4][4], int index, int is_row)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (is_row)
			array[i] = grid[index][i];
		else
			array[i] = grid[i][index];
		i++;
	}
}

void	reverse_array(int *src, int *dest)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		dest[i] = src[3 - i];
		i++;
	}
}

int	count_visible(int *line)
{
	int	max_height;
	int	count;
	int	i;

	max_height = 0;
	count = 0;
	i = 0;
	while (i < 4)
	{
		if (line[i] > max_height)
		{
			max_height = line[i];
			count++;
		}
		i++;
	}
	return (count);
}

int	check_constraints(int grid[4][4], int constraints[16])
{
	int				i;
	t_visibility	vis;

	i = 0;
	while (i < 4)
	{
		fill(vis.row, grid, i, 1);
		fill(vis.col, grid, i, 0);
		reverse_array(vis.row, vis.rev_row);
		reverse_array(vis.col, vis.rev_col);
		vis.left = count_visible(vis.row);
		vis.right = count_visible(vis.rev_row);
		vis.top = count_visible(vis.col);
		vis.bottom = count_visible(vis.rev_col);
		if (vis.left != constraints[8 + i] || vis.right != constraints[12 + i]
			|| vis.top != constraints[i] || vis.bottom != constraints[4 + i])
			return (0);
		i++;
	}
	return (1);
}
