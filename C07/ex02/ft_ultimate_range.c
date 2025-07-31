/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aphyo-ht <aphyo-ht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 06:41:43 by aphyo-ht          #+#    #+#             */
/*   Updated: 2025/07/31 20:37:26 by aphyo-ht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	i;
	int	*arr;

	i = 0;
	if (min >= max)
		return (NULL);
	arr = (int *)malloc((max - min) * sizeof(int));
	if (!arr)
		return (NULL);
	while (min < max)
	{
		arr[i] = min;
		min++;
		i++;
	}
	return (arr);
}

/*
	I literally copy pasted the function below.
*/

int	ft_ultimate_range(int **range, int min, int max)
{
	*range = ft_range(min, max);
	if (*range == 0)
	{
		return (0);
	}
	return (max - min);
}

/*
int	ft_ultimate_range(int **range, int min, int max)
{
	int	*ptr;
	int	i;

	i = 0;
	if (min >= max)
	{
		*range = NULL;
		return (0);
	}
	while (min < max)
	{
		ptr = malloc(sizeof(int));
		*ptr = min;
		*range = ptr;
		min++;
		range++;
		i++;
	}
	return (i);
}
*/

/*

Don't run this main this main is for the commented out function
#include <stdio.h>

int	main(void)
{
	int	**range;
	int	i;
	int	j;

	range = malloc(sizeof(int *) * 17);
	i = 0;
	j = ft_ultimate_range(range,4, 20);
	while(i < j)
	{
		printf("Point : %i.\n", *range[i]);
		i++;
	}
	i = 0;
	while( i < j)
	{
		free(range[i]);
		i++;
	}
	free(range);
	return (0);
}
	*/
