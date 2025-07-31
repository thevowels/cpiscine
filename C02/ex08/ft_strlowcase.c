/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlowcase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aphyo-ht <aphyo-ht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 22:54:18 by aphyo-ht          #+#    #+#             */
/*   Updated: 2025/07/11 01:18:27 by aphyo-ht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_strlowcase(char *str);
/*
int	main(void)
{
	char	str[] = "to THE LOwERCase";

	printf("input: %s \n", str);
	printf("output: %s \n", ft_strlowcase(str));
	return (0);
}*/

char	*ft_strlowcase(char *str)
{
	char	*tmp;

	tmp = str;
	while (*tmp != '\0')
	{
		if (*tmp >= 'A' && *tmp <= 'Z')
		{
			*tmp += 32;
		}
		tmp++;
	}
	return (str);
}
