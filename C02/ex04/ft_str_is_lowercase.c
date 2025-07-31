/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_lowercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aphyo-ht <aphyo-ht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 20:45:15 by aphyo-ht          #+#    #+#             */
/*   Updated: 2025/07/11 01:23:23 by aphyo-ht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>

int	ft_str_is_lowercase(char *str);

/*
int	main(void)
{
	char	*str;

	str = "asdfasdf\0IAMUPPERCASE";
	printf("Output: %i \n", ft_str_is_lowercase(str));
}
*/

int	ft_str_is_lowercase(char *str)
{
	char	*tmp;

	tmp = str;
	while (*tmp != '\0')
	{
		if (*tmp < 'a' || *tmp > 'z')
			return (0);
		tmp++;
	}
	return (1);
}
