/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aphyo-ht <aphyo-ht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 00:08:32 by aphyo-ht          #+#    #+#             */
/*   Updated: 2025/07/13 00:43:54 by aphyo-ht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <strings.h>

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size);

/*
int	main(void)
{
	char			src[] = "this is source which is longer than the 20 .";
	char			dest[30] = "dest";
	unsigned int	x;

	x = ft_strlcpy(dest, src, 20);
	printf("updated : %s \nLength : %d", dest, x);
	return (0);
}*/

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	i;

	i = 0;
	while (src[i] && i < size)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (i);
}
