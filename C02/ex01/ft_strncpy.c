/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aphyo-ht <aphyo-ht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 17:36:20 by aphyo-ht          #+#    #+#             */
/*   Updated: 2025/07/11 01:25:26 by aphyo-ht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (src[i] != '\0' && i < n)
	{
		*(dest + i) = *(src + i);
		i++;
	}
	while (i < n)
	{
		*(dest + i) = '\0';
		i++;
	}
	return (dest);
}
/*
int	main(void)
{
	char	dest[20];
	char	*str;
	char	*result;
	int		i;

	str = "abcd this is src";
	result = ft_strncpy(dest, str, 8);
	i = 0;
	while (i < 20)
	{
		if (dest[i] == '\0')
		{
			write(1, "*", 1);
		}
		else
		{
			write(1, &dest[i], 1);
		}
		i++;
	}
}
	*/
