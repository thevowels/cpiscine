/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aphyo-ht <aphyo-ht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 07:07:03 by aphyo-ht          #+#    #+#             */
/*   Updated: 2025/07/11 03:12:37 by aphyo-ht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	ft_check_swap(int *a, int *b)
{
	char	c;

	if (*a > *b)
	{
		ft_swap(a, b);
	}
}

void	ft_sort_int_tab(int *tab, int size)
{
	int	max;
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size - 1)
		{
			ft_check_swap(tab + j, tab + j + 1);
			j++;
		}
		i++;
	}
}
