/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq_mapzapper_subroutines.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aphyo-ht <aphyo-ht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 14:33:02 by sasakuya          #+#    #+#             */
/*   Updated: 2025/07/30 09:15:13 by aphyo-ht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq_header_mapzapper.h"

void	ft_init_struct(t_bsq *z)
{
	z->map = NULL;
	z->rows = 0;
	z->cols = 0;
	z->r = 0;
	z->c = 0;
	z->size = 0;
	z->obstacle = 0;
	z->empty = 0;
	z->full = 0;
	z->map_error = 0;
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}

void	ft_free_map(t_bsq *z)
{
	int	i;

	i = 0;
	if (z->map != NULL)
	{
		while (i < z->rows)
		{
			if (z->map[i] != NULL)
			{
				free(z->map[i]);
				z->map[i] = NULL;
			}
			i++;
		}
		free(z->map);
	}
	ft_init_struct(z);
}
