/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   files.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aphyo-ht <aphyo-ht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 23:54:54 by aphyo-ht          #+#    #+#             */
/*   Updated: 2025/07/27 17:07:49 by aphyo-ht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lib.h"

/*
	count the number of characters on the file
*/
int	ft_checksize(char *filename)
{
	int		count;
	int		file;
	char	buffer[1024];
	int		tmp;

	file = open(filename, O_RDONLY);
	if (file == -1)
		return (-1);
	count = 0;
	while (1)
	{
		tmp = read(file, buffer, 1024);
		if (tmp == -1)
		{
			ft_putstr("Dict Error\n");
			close(file);
			return (-1);
		}
		else if (tmp < 1024)
		{
			count += tmp;
			break ;
		}
		count += tmp;
	}
	close(file);
	return (count);
}
