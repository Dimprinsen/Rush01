#ifndef RUSH01_H
# define RUSH01_H

# include <stdlib.h>
# include <unistd.h>

void	ft_putstr(char *str);
int		ft_strlen(char *str);
int		ft_atoi(char *str);
int		validate_input(char *str, int *constraints);
void	print_grid(int grid[4][4]);
int		solve_puzzle(int grid[4][4], int constraints[16], int row, int col);
int		is_valid(int grid[4][4], int row, int col, int num);
int		check_visibility(int grid[4][4], int constraints[16]);
int		count_visible(int *line);

#endif
