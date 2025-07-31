/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq_parse_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aphyo-ht <aphyo-ht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 07:05:05 by aphyo-ht          #+#    #+#             */
/*   Updated: 2025/07/30 10:28:21 by aphyo-ht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq_header_mapzapper.h"

int	is_header_ok(char *str)
{
	if (str[0] == str[1] || str[0] == str[2] || str[1] == str[2])
		return (0);
	if (str[3] != '\n')
		return (0);
	return (1);
}

// Cannnot be void. We've to go back to main and says map error
// we can't exit the program

void	ft_parse_header(char *data, t_bsq *z, int *i)
{
	while (data[*i] >= '0' && data[*i] <= '9')
	{
		z->rows = (z->rows * 10) + (data[*i] - '0');
		(*i)++;
	}
	if (*i == 0 || z->rows == 0 || !is_header_ok(data + *i))
	{
		z->map_error = 1;
		return ;
	}
	z->empty = data[*i];
	z->obstacle = data[(*i) + 1];
	z->full = data[(*i) + 2];
	(*i) += 4;
	z->cols = ft_str_clen(data + *i, '\n');
}

int	ft_atoi(char *str)
{
	int	val;

	val = 0;
	while (ft_isnb(*str))
	{
		val = (val * 10) + (int)(*str - '0');
		str++;
	}
	return (val);
}

void	ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (*(src + i))
	{
		*(dest + i) = *(src + i);
		i++;
	}
	return ;
}
