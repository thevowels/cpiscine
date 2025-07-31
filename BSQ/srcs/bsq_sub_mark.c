/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq_sub_mark.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aphyo-ht <aphyo-ht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 16:04:51 by sasakuya          #+#    #+#             */
/*   Updated: 2025/07/30 10:28:51 by aphyo-ht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq_header_mapzapper.h"

// char	*ft_read_stdin(void)
// {
// 	char			buf[4096];
// 	char			*data;
// 	char			*tmp;
// 	t_parse_args	args;

// 	data = malloc(1);
// 	data[0] = '\0';
// 	args.total = 0;
// 	args.read_size = 1;
// 	while (args.read_size > 0)
// 	{
// 		args.read_size = read(0, buf, 4096);
// 		tmp = malloc(args.total + args.read_size + 1);
// 		args.i = 0;
// 		while (args.i < args.total)
// 		{
// 			tmp[args.i] = data[args.i];
// 			args.i++;
// 		}
// 		args.j = 0;
// 		while (args.j < args.read_size)
// 		{
// 			tmp[args.total + args.j] = buf[args.j];
// 			args.j++;
// 		}
// 		tmp[args.total + args.read_size] = '\0';
// 		free(data);
// 		data = tmp;
// 		args.total += args.read_size;
// 	}
// 	return (data);
// }

void	ft_find_biggest_square(t_bsq *z, int *max, int *by, int *bx)
{
	z->r = 0;
	while (z->r < z->rows)
	{
		z->c = 0;
		while (z->c < z->cols)
		{
			z->size = 1;
			while (ft_possible_square(z))
				z->size++;
			if (z->size - 1 > *max)
			{
				*max = z->size - 1;
				*by = z->r;
				*bx = z->c;
			}
			z->c++;
		}
		z->r++;
	}
}

void	ft_draw_square(t_bsq *z, int max, int by, int bx)
{
	int	y;
	int	x;

	y = 0;
	while (y < max)
	{
		x = 0;
		while (x < max)
		{
			z->map[by + y][bx + x] = z->full;
			x++;
		}
		y++;
	}
}
