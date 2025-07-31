/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_uppercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aphyo-ht <aphyo-ht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 21:02:52 by aphyo-ht          #+#    #+#             */
/*   Updated: 2025/07/11 01:22:47 by aphyo-ht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_str_is_uppercase(char *str);

/*
int	main(void)
{
	char	*str;

	str = "ASDFASDF";
	printf("Output : %i \n", ft_str_is_uppercase(str));
}*/

int	ft_str_is_uppercase(char *str)
{
	char	*tmp;

	tmp = str;
	while (*tmp != '\0')
	{
		if (*tmp < 'A' || *tmp > 'Z')
			return (0);
		tmp++;
	}
	return (1);
}
