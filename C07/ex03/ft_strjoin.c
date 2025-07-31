/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aphyo-ht <aphyo-ht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 07:23:22 by aphyo-ht          #+#    #+#             */
/*   Updated: 2025/07/24 02:48:44 by aphyo-ht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_char_counts(int size, char **strs, char *sep)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	count = 0;
	while (i < size)
	{
		j = 0;
		while (strs[i][j])
		{
			count++;
			j++;
		}
		j = 0;
		if (i++ < size)
		{
			while (sep[j])
			{
				count++;
				j++;
			}
		}
	}
	return (count);
}

void	ft_strcat(char *dest, char *src)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (dest[i])
		i++;
	while (src[j])
	{
		dest[i + j] = src[j];
		j++;
	}
	dest[i + j] = '\0';
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		i;
	int		count;
	char	*result;

	i = 0;
	count = ft_char_counts(size, strs, sep);
	result = malloc((count + 1) * sizeof(char));
	result[0] = '\0';
	count = 0;
	while (i < size)
	{
		ft_strcat(result, strs[i]);
		if (i < size - 1)
		{
			ft_strcat(result, sep);
		}
		i++;
	}
	return (result);
}
/*
#include <stdio.h>

int	main(void)
{
	char	*strs[] = {"ABC", "Second 1", "Another string", "End here!"};
	char	sep[] = ", ";
	char	*result;

	result = ft_strjoin(4,strs,sep);
	printf("Result : %s\n", result);
	free(result);
}
*/
