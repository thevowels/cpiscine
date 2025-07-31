/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aphyo-ht <aphyo-ht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 00:07:17 by aphyo-ht          #+#    #+#             */
/*   Updated: 2025/07/16 16:21:39 by aphyo-ht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (s1[i] && s2[i] && i < n)
	{
		if (s1[i] != s2[i])
			return (0);
		i++;
	}
	if (i < n && (s1[i] || s2[i]))
		return (0);
	return (1);
}

char	*ft_strstr(char *str, char *to_find)
{
	unsigned int	length;

	length = 0;
	if (!*to_find)
	{
		return (str);
	}
	while (to_find[length])
	{
		length++;
	}
	while (*str)
	{
		if (*str == *to_find && ft_strncmp(str, to_find, length))
		{
			return (str);
		}
		str++;
	}
	return (0);
}

// my previous was failing when finding the empty string,
//	instead of return the full str, its returning null.
