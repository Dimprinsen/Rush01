/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thtinner <thtinner@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 19:06:43 by thtinner          #+#    #+#             */
/*   Updated: 2025/03/02 21:09:12 by thtinner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef RUSH_H
# define RUSH_H

# include <stdlib.h>
# include <unistd.h>

typedef struct s_visibility
{
	int	row[4];
	int	col[4];
	int	rev_row[4];
	int	rev_col[4];
	int	left;
	int	right;
	int	top;
	int	bottom;
}	t_visibility;

void	ft_putchar(char c);
void	ft_putstr(char *str);
int		ft_strlen(char *str);
int		ft_atoi(char *str);
int		validate_input(char *str, int *constraints);
void	print_grid(int grid[4][4]);
int		solve_grid(int grid[4][4], int constraints[16], int row, int col);
int		is_valid(int grid[4][4], int row, int col, int num);
int		check_constraints(int grid[4][4], int constraints[16]);
int		count_visible(int *line);
int		final_check(int grid[4][4], int constraints[16]);

#endif
