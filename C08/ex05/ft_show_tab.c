/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aphyo-ht <aphyo-ht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 04:20:05 by aphyo-ht          #+#    #+#             */
/*   Updated: 2025/07/24 07:23:48 by aphyo-ht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "ft_stock_str.h"

void	ft_putstr(char *str)
{
	while (*str)
	{
		write(1, str, 1);
		str++;
	}
	write(1, "\n", 1);
}

void	ft_putint(int i)
{
	char	c;

	while (i >= 10)
	{
		c = '0' + i % 10;
		write(1, &c, 1);
		i = i / 10;
	}
	c = '0' + i % 10;
	write(1, &c, 1);
	write(1, "\n", 1);
}

void	ft_show_tab(struct s_stock_str *par)
{
	int	i;

	i = 0;
	while (par[i].str)
	{
		ft_putstr(par[i].str);
		ft_putint(par[i].size);
		ft_putstr(par[i].copy);
		i++;
	}
}

/*
#include <stdio.h>

int	main(void)
{
	char				*strs[] = {"hello", "world", "this", "is", "a", "test"};
	int					size;
	struct s_stock_str	*result;

	size = sizeof(strs) / sizeof(char *);
	result = ft_strs_to_tab(size, strs);
	ft_show_tab(result);
	// Free the allocated memory
	for (int i = 0; i < size; i++)
	{
		free(result[i].copy);
	}
	free(result);
	return (0);
}
*/
