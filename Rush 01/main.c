/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aphyo-ht <aphyo-ht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 15:58:54 by aphyo-ht          #+#    #+#             */
/*   Updated: 2025/07/20 23:33:14 by aphyo-ht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

// #include <stdio.h>
int		ft_allocate(int size, int **grid);
void	cheat_row(int flag, int row, int size, int **grid);
void	cheat_col(int flag, int col, int size, int **grid);
void	cheat_point(int row, int col, int size, int **grid);
void	ft_setcontrol(int size, int **grid, int **control);
int		check_arg(char *arg, int *rules);
int		backtrack(int size, int **grid, int **control, int *rules);

void	ft_putint(int i)
{
	char	c;

	c = i + '0';
	write(1, &c, 1);
}

int	submain(int size, int **grid, int **control, int *rules)
{
	int	i;
	int	j;
	int	gg;

	i = 0;
	j = 0;
	gg = backtrack(size, grid, control, rules);
	if (!gg)
	{
		write(1, "Error\n", 6);
	}
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			ft_putint(grid[i][j]);
			if (j < size - 1)
				write(1, " ", 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	int	size;
	int	*grid[9];
	int	*control[9];
	int	rules[36];

	if (argc != 2)
		return (0);
	size = check_arg(argv[1], rules);
	if (size == 0)
		return (0);
	if (!ft_allocate(size, grid) || !ft_allocate(size, control))
		return (0);
	submain(size, grid, control, rules);
}
// printf("The size is %d \n", size);
