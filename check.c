#include "rush01.h"
#include <stdio.h>

void	fill_row(int *row, int grid[4][4], int i)
{
	int	j;

	j = 0;
	while (j < 4)
	{
		row[j] = grid[i][j];
		j++;
	}
}

void	fill_col(int *col, int grid[4][4], int i)
{
	int	j;

	j = 0;
	while (j < 4)
	{
		col[j] = grid[j][i];
		j++;
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

int	check_visibility(int grid[4][4], int constraints[16])
{
	int	i;
	int	row[4];
	int	col[4];
	int	reversed_row[4];
	int	reversed_col[4];

	i = 0;
	while (i < 4)
	{
		fill_row(row, grid, i);
		fill_col(col, grid, i);
		reverse_array(row, reversed_row);
		reverse_array(col, reversed_col);

		int left = count_visible(row);
		int right = count_visible(reversed_row);
		int top = count_visible(col);
		int bottom = count_visible(reversed_col);

		// 🔥 Enhanced debug printing
		printf("Row %d -> Left: %d (Expected: %d), Right: %d (Expected: %d)\n",
			i, left, constraints[8 + i], right, constraints[12 + i]);

		printf("Col %d -> Top: %d (Expected: %d), Bottom: %d (Expected: %d)\n",
			i, top, constraints[i], bottom, constraints[4 + i]);

		if (left != constraints[8 + i] || right != constraints[12 + i]
			|| top != constraints[i] || bottom != constraints[4 + i])
			return (0);

		i++;
	}
	return (1);
}



