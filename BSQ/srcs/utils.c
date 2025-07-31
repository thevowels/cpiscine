/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aphyo-ht <aphyo-ht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 11:38:22 by aphyo-ht          #+#    #+#             */
/*   Updated: 2025/07/30 10:43:54 by aphyo-ht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq_header_mapzapper.h"

int	ft_read_file(char *file, char *data)
{
	int		fops;
	size_t	size;

	fops = open(file, O_RDONLY);
	if (fops < 0)
		return (0);
	size = read(fops, data, 88888888);
	if (size == 88888888)
	{
		data[0] = '\0';
	}
	if (size == 0)
		return (0);
	data[size] = '\0';
	close(fops);
	return (1);
}

int	ft_isnb(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

// Count the number of characters of str until given char c
int	ft_str_clen(char *str, char c)
{
	int	i;

	i = 0;
	while (*str && *str != c)
	{
		i++;
		str++;
	}
	return (i);
}

int	ft_is_cok(char c, t_bsq *z)
{
	if (c == z->empty || c == z->obstacle || c == z->full)
		return (1);
	return (0);
}

int	ft_check_line(char *data, t_bsq *z)
{
	int	c;

	c = 0;
	while (data[c] && data[c] != '\n')
	{
		if (!ft_is_cok(data[c], z))
		{
			z->map_error = 1;
			return (0);
		}
		c++;
	}
	return (c);
}
