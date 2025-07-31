/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aphyo-ht <aphyo-ht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 22:27:28 by aphyo-ht          #+#    #+#             */
/*   Updated: 2025/07/20 23:33:31 by aphyo-ht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	fill_grid(int value, int position, int size, int **grid)
{
	int	row;
	int	col;

	row = position / size;
	col = position % size;
	grid[row][col] = value;
}

void	undo_fill(int position, int size, int **grid)
{
	int	row;
	int	col;

	row = position / size;
	col = position % size;
	grid[row][col] = 0;
}
