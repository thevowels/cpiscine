/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solvers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aphyo-ht <aphyo-ht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 19:37:58 by aphyo-ht          #+#    #+#             */
/*   Updated: 2025/07/20 23:34:08 by aphyo-ht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		check_point(int x, int size, int **grid, int *rules);
int		is_col_ok(int row, int size, int **grid, int *rules);
int		is_row_ok(int row, int size, int **grid, int *rules);
void	fill_grid(int value, int position, int size, int **grid);
void	undo_fill(int position, int size, int **grid);
int		is_valid(int size, int position, int **grid, int *rules);

int	check_matrix(int size, int **grid, int *rules)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (!(is_col_ok(0, size, grid, rules) && is_row_ok(i, size, grid,
					rules)))
			return (0);
		i++;
	}
	return (1);
}

int	need_to_fill(int size, int **grid)
{
	int	i;
	int	j;

	while (i < size)
	{
		while (j < size)
		{
			if (grid[i][j] == 0)
				return (1);
		}
	}
	return (0);
}

int	find_to_fill(int size, int **grid)
{
	int	i;
	int	j;

	while (i < size)
	{
		while (j < size)
		{
			if (grid[i][j] == 0)
				return ((i * size) + j);
		}
	}
	return (0);
}

int	backtrack(int size, int **grid, int **control, int *rules)
{
	int	position;
	int	i;

	i = 0;
	if (!need_to_fill(size, grid) && check_matrix(size, grid, rules))
	{
		return (1);
	}
	while (need_to_fill(size, grid))
	{
		position = find_to_fill(size, grid);
		while (i < size)
		{
			fill_grid(i, position, size, grid);
			if (is_valid(size, position, grid, rules))
			{
				if (backtrack(size, grid, control, rules))
					return (1);
			}
			undo_fill(position, size, grid);
			i++;
		}
	}
	return (0);
}

// int	check_point(int x, int size, int **grid, int *rules)
// {
// 	int	i;
// 	int	j;

// 	i = x / size;
// 	j = x % size;
// }
