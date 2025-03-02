#include "rush01.h"
#include <stdio.h>

int	validate_input(char *str, int *constraints)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] >= '1' && str[i] <= '4')
		{
			constraints[j++] = ft_atoi(&str[i]);
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
	int	grid[4][4] = {{0}};
	int	constraints[16];

	if (argc != 2 || !validate_input(argv[1], constraints))
	{
		ft_putstr("Error\n");
		return (1);
	}
	printf("Input validation passed!\n");
	printf("Initial empty grid:\n");
    print_grid(grid);
	if (!solve_puzzle(grid, constraints, 0, 0))
    {
        printf("Solver failed\n");
        ft_putstr("Error\n");
        return (1);
    }
	if (solve_puzzle(grid, constraints, 0, 0))
		print_grid(grid);
	else
		ft_putstr("Error\n");
	return (0);
}

