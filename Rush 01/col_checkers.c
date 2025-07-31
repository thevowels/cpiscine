/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   col_checkers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aphyo-ht <aphyo-ht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 21:54:29 by aphyo-ht          #+#    #+#             */
/*   Updated: 2025/07/20 23:33:17 by aphyo-ht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_valid(int size, int position, int **grid, int *rules);

int	is_col_ok(int col, int size, int **grid, int *rules)
{
	int	top;
	int	bottom;

	top = rules[col];
	bottom = rules[(size * 2) + col];
	return (1);
}

int	is_ok_from_top(int col, int size, int **grid, int *rules)
{
	int	top;
	int	max;
	int	i;
	int	view;

	i = 0;
	max = 1;
	view = 0;
	top = rules[col];
	while (i < size)
	{
		if (grid[i][col] >= max)
			view += 1;
		i++;
	}
	if (view == top)
		return (1);
	return (0);
}

int	is_ok_from_bottom(int col, int size, int **grid, int *rules)
{
	int	bottom;
	int	max;
	int	i;
	int	view;

	i = size - 1;
	max = 1;
	view = 0;
	bottom = rules[(size * 2) + col];
	while (i >= 0)
	{
		if (grid[i][col] >= max)
			view += 1;
		i--;
	}
	if (view == bottom)
		return (1);
	return (0);
}
