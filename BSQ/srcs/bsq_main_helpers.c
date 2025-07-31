/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq_main_helpers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aphyo-ht <aphyo-ht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 10:33:47 by aphyo-ht          #+#    #+#             */
/*   Updated: 2025/07/30 10:43:57 by aphyo-ht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq_header_mapzapper.h"

void	map_fromstdin(t_bsq *z, char *data)
{
	int	line_count;
	int	buffer_point;
	int	x;

	x = 0;
	buffer_point = 0;
	buffer_point += read(0, data, 88888888);
	line_count = ft_atoi(data);
	while (ft_isnb(data[x]))
	{
		if (ft_isnb(data[x]))
			x++;
	}
	if (!is_header_ok(data + x))
	{
		ft_putstr("map error\n");
		free(data);
		exit(EXIT_FAILURE);
	}
	while (line_count > 0)
	{
		buffer_point += read(0, data + buffer_point, 88888888 - buffer_point);
		line_count--;
	}
	ft_execute(data, z);
}

int	ft_possible_square(t_bsq *z)
{
	int	y;
	int	x;

	y = 0;
	while (y < z->size)
	{
		x = 0;
		while (x < z->size)
		{
			if (z->r + y >= z->rows || z->c + x >= z->cols)
				return (0);
			if (z->map[z->r + y][z->c + x] == z->obstacle)
				return (0);
			x++;
		}
		y++;
	}
	return (1);
}

void	ft_mark_the_square(t_bsq *z)
{
	int	max;
	int	by;
	int	bx;

	max = 0;
	by = 0;
	bx = 0;
	ft_find_biggest_square(z, &max, &by, &bx);
	ft_draw_square(z, max, by, bx);
}
