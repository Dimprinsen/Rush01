/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thtinner <thtinner@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 15:00:50 by thtinner          #+#    #+#             */
/*   Updated: 2025/03/01 23:32:26 by thtinner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putstr(char *str);
int		ft_atoi(char *str);

int	check_input(char *str, int *input)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= '1' && str[i] <= '4')
		{
			if (j >= 16)
				return (0);
			input[j] = str[i] - '0';
			j++;
		}
		else if (str[i] != ' ')
			return (0);
		i++;
	}
	return (j == 16);
}

#include <stdio.h>
int	main(int argc, char *argv[])
{
	int	grid[4][4];
	int	input[16];
	if (argc != 2 || !check_input(argv[1], input)) //Validate input
	{
		ft_putstr("Error\n");
		return (1);
	}
//	if (solve(grid, input, 0, 0)) //function to see if solution exists
//		print_grid (grid); //if solution found, print grid
//	else		
//		ft_pustr ("Error\n");
    	for (int i = 0; i < 16; i++) //loop to print input back;
    	{
        	printf("%d ", input[i]);
    	}
    	printf("\n");	
	return (0);
}
/*


	//A function for input parsing, validating etc
	//Loop through the string, extracting the numbers
	//Store in an array: Input/constraints[16]
	//Ensure 16 numbers between 1-4 are present, return 1 or 0 to main
	
	
	//Solver function:
	//Filling and checking if visibility conditions are met
	//Try placing 1 - 4 in first cell, (row first?)
	//Backtrack and reset to 0 if necessary
	//Further....


	//Visibility checking:
	//For each row and column,
	//check how many are visible from left/top
	//check how many are visible from right/bottom
	//Compare this with our input constraints



	//Grid Print:
	//Loop through grid and print each number
*/
