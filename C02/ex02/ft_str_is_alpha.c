/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aphyo-ht <aphyo-ht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 19:06:17 by aphyo-ht          #+#    #+#             */
/*   Updated: 2025/07/11 01:33:15 by aphyo-ht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_str_is_alpha(char *str);

/*
int	main(void)
{
	char	*str;
	int		c;

	str = "asdfasdf";
	c = ft_str_is_alpha(str);
	printf(" output: %i", c);
}*/

int	ft_str_is_alpha(char *str)
{
	char	*tmp;

	tmp = str;
	while (*tmp != '\0')
	{
		if (!((*tmp >= 'A' && *tmp <= 'Z') || (*tmp >= 'a' && *tmp <= 'z')))
		{
			return (0);
		}
		tmp++;
	}
	return (1);
}
