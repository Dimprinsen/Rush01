#include "rush01.h"
#include <stdio.h>

int	is_valid(int grid[4][4], int row, int col, int num)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (grid[row][i] == num || grid[i][col] == num)
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

int solve_puzzle(int grid[4][4], int constraints[16], int row, int col)
{
    int num;
    int next_row;
    int next_col;

    // If we reach the last row, check if the solution is valid
    if (row == 4)
    {
        if (check_visibility(grid, constraints))
        {
            printf("Solution found!\n");
            print_grid(grid);  // Print the solved grid
            return 1;
        }
        return 0;
    }

    // Get the next row and column
    next_row = row;
    next_col = col;
    next_cell(&next_row, &next_col);

    // Try numbers 1 through 4
    for (num = 1; num <= 4; num++)
    {
        // Check if it's a valid number to place in the grid
        if (is_valid(grid, row, col, num))
        {
            grid[row][col] = num;

            // Print the current grid state after placing the number
            printf("Placed %d at [%d][%d]\n", num, row, col);
            print_grid(grid);

            // Recursively solve the next cell
            if (solve_puzzle(grid, constraints, next_row, next_col))
                return 1;

            // Backtrack: Reset the current cell
            grid[row][col] = 0;
            printf("Backtracking from [%d][%d]\n", row, col);
            print_grid(grid);
        }
    }

    return 0;  // Return false if no number can be placed in this cell
}

/*int solve_puzzle(int grid[4][4], int constraints[16], int row, int col)
{
    int num, next_row = row, next_col = col;

    // Base case: if we've filled all rows, check visibility
    if (row == 4) {
        if (check_visibility(grid, constraints)) {
            print_grid(grid);
            return 1;
        }
        return 0;
    }

    // Move to the next cell
    next_cell(&next_row, &next_col);

    // Try placing each number 1 to 4 in the current cell
    num = 1;
    while (num <= 4) {
        if (is_valid(grid, row, col, num)) {
            grid[row][col] = num;
            print_grid(grid);  // Debug print after placing a number
            if (solve_puzzle(grid, constraints, next_row, next_col)) return 1;
            grid[row][col] = 0;  // Backtrack
        }
        num++;
    }

    return 0;  // No valid number found
}
*/



