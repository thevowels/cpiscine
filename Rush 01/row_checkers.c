/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   row_checkers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aphyo-ht <aphyo-ht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 21:20:10 by aphyo-ht          #+#    #+#             */
/*   Updated: 2025/07/20 22:03:47 by aphyo-ht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_row_ok(int row, int size, int **grid, int *rules)
{
	int	left;
	int	right;
	int	max;
	int	i;

	i = 0;
	max = 1;
	left = rules[(size * 3) + row];
	right = rules[(size * 4) + row];
	while (i < size)
	{
	}
	return (1);
}

int	is_ok_from_left(int row, int size, int **grid, int *rules)
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
	if (view == left)
		return (1);
	return (0);
}

int	is_ok_from_right(int row, int size, int **grid, int *rules)
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
