/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aphyo-ht <aphyo-ht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 23:03:58 by aphyo-ht          #+#    #+#             */
/*   Updated: 2025/07/20 23:34:28 by aphyo-ht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_pos_ok_from_left(int row, int size, int **grid, int *rules)
{
	int	left;
	int	max;
	int	i;
	int	view;

	i = 0;
	max = 1;
	view = 0;
	left = rules[(size * 3) + row];
	while (i < size)
	{
		if (grid[row][i] >= max)
			view += 1;
		i++;
	}
	if (view < left)
		return (1);
	return (0);
}

int	is_pos_ok_from_right(int row, int size, int **grid, int *rules)
{
	int	right;
	int	max;
	int	i;
	int	view;

	i = size - 1;
	max = 1;
	view = 0;
	right = rules[(size * 4) + row];
	while (i >= 0)
	{
		if (grid[row][i] >= max)
			view += 1;
		i--;
	}
	if (view == right)
		return (1);
	return (0);
}

int	is_pos_ok_from_top(int col, int size, int **grid, int *rules)
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
	if (view < top)
		return (1);
	return (0);
}

int	is_pos_ok_from_bottom(int col, int size, int **grid, int *rules)
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
	if (view < bottom)
		return (1);
	return (0);
}

int	is_valid(int size, int position, int **grid, int *rules)
{
	int	row;
	int	col;

	row = position / size;
	col = position % size;
	if (!is_pos_ok_from_left(row, size, grid, rules))
		return (0);
	if (!is_pos_ok_from_right(row, size, grid, rules))
		return (0);
	if (!is_pos_ok_from_bottom(col, size, grid, rules))
		return (0);
	if (!is_pos_ok_from_top(col, size, grid, rules))
		return (0);
	return (1);
}
