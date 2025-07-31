/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aphyo-ht <aphyo-ht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 20:34:20 by aphyo-ht          #+#    #+#             */
/*   Updated: 2025/07/24 07:24:54 by aphyo-ht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_str.h"
#include <stdlib.h>

int	get_length(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_strcpy(char *dest, char *str)
{
	while (*str)
	{
		*dest = *str;
		dest++;
		str++;
	}
	*dest = '\0';
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	int			i;
	int			size;
	char		*tmp;
	t_stock_str	*ptr;

	i = 0;
	ptr = malloc((ac + 1) * sizeof(t_stock_str));
	if (!ptr)
		return (0);
	while (i < ac)
	{
		size = get_length(av[i]);
		ptr[i].size = size;
		ptr[i].str = av[i];
		tmp = malloc(sizeof(char) * (size + 1));
		if (!tmp)
			return (0);
		ft_strcpy(tmp, av[i]);
		ptr[i].copy = tmp;
		i++;
	}
	ptr[i].str = 0;
	return (ptr);
}
/*
#include <stdio.h>

int	main(void)
{
	int					size;
	struct s_stock_str	*result;
	int					i;

	char				*strs[] = {"JIOJFIOSODILLKLikaoisdifasldfas", "world",
						"this", "is", "a", "test"};
	size = sizeof(strs) / sizeof(char *);
	result = ft_strs_to_tab(size, strs);
	i = 0;
	// ft_show_tab(result);
	while (result[i].str)
	{
		printf("Pointer %p \n", result);
		printf("str : %s\n", result[i].str);
		printf("copy : %s\n", result[i].copy);
		printf("str : %i\n", result[i].size);
		printf("-------------------------\n");
		i++;
		printf("Index is now %i", i);
	}
	// Free the allocated memory
	for (int i = 0; i < size; i++)
	{
		free(result[i].copy);
	}
	free(result);
	return (0);
}
*/
