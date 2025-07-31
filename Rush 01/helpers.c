/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aphyo-ht <aphyo-ht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 15:59:25 by aphyo-ht          #+#    #+#             */
/*   Updated: 2025/07/20 19:55:08 by aphyo-ht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_allocate(int size, int **grid)
{
	int	i;
	int	j;

	i = 0;
	while (i < 9)
	{
		grid[i] = (int *)malloc(9 * 4);
		if (grid[i] == NULL)
			return (0);
		i++;
	}
	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			grid[i][j] = 0;
			j++;
		}
		i++;
	}
	return (1);
}

void	cheat_row(int flag, int row, int size, int **grid)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (flag)
		{
			grid[row][i] = i + 1;
		}
		else
		{
			grid[row][i] = size - i;
		}
		i++;
	}
}

void	cheat_col(int flag, int col, int size, int **grid)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (flag)
		{
			grid[i][col] = i + 1;
		}
		else
		{
			grid[i][col] = size - i;
		}
		i++;
	}
}

void	cheat_point(int row, int col, int size, int **grid)
{
	grid[row][col] = size;
}

void	ft_setcontrol(int size, int **grid, int **control)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			if (grid[i][j] != 0)
				control[i][j] = 1;
			j++;
		}
		i++;
	}
}
