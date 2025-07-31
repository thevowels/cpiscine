/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq_sub_parse.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aphyo-ht <aphyo-ht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 15:25:13 by sasakuya          #+#    #+#             */
/*   Updated: 2025/07/30 10:27:44 by aphyo-ht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq_header_mapzapper.h"

void	ft_alloc_map(t_bsq *z)
{
	int	i;

	z->map = malloc(sizeof(char *) * z->rows);
	i = 0;
	while (i < z->rows)
	{
		z->map[i] = NULL;
		i++;
	}
}

void	ft_fill_line(char *data, t_bsq *z, int r, int c)
{
	int	k;

	k = 0;
	while (k < c)
	{
		z->map[r][k] = data[k];
		k++;
	}
	z->map[r][k] = '\0';
}

void	ft_fill_map(char *data, t_bsq *z, int i)
{
	int	r;
	int	c;

	r = 0;
	while (r < z->rows)
	{
		c = ft_check_line(data + i, z);
		if (z->cols != c || c == 0)
		{
			z->map_error = 1;
			return ;
		}
		z->map[r] = malloc(c + 1);
		ft_fill_line((data + i), z, r, c);
		i += c + 1;
		r++;
	}
	if (data[i] != '\0')
	{
		z->map_error = 1;
		return ;
	}
}

void	ft_execute(char *data, t_bsq *z)
{
	ft_init_struct(z);
	ft_parse_map(data, z);
	if (z->map_error)
	{
		ft_putstr("map error\n");
	}
	if (!z->map_error)
	{
		ft_mark_the_square(z);
		ft_mapzapper(z);
	}
	ft_free_map(z);
}
