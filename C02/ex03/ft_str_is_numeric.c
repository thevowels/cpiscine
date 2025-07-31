/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_numeric.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aphyo-ht <aphyo-ht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 20:37:11 by aphyo-ht          #+#    #+#             */
/*   Updated: 2025/07/11 01:24:09 by aphyo-ht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>

int	ft_str_is_numeric(char *str);

/*
int	main(void)
{
	char	*str;

	str = "1234560789";
	printf("Output: %i", ft_str_is_numeric(str));
}*/

int	ft_str_is_numeric(char *str)
{
	char	*tmp;

	tmp = str;
	while (*tmp != '\0')
	{
		if (*tmp < '0' || *tmp > '9')
		{
			return (0);
		}
		tmp++;
	}
	return (1);
}
