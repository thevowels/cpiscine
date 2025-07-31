/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strupcase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aphyo-ht <aphyo-ht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 22:20:59 by aphyo-ht          #+#    #+#             */
/*   Updated: 2025/07/11 01:19:05 by aphyo-ht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_strupcase(char *str);

// int	main(void)
// {
// 	char	str[] = "to uppe ^&*()09876543 UpperCase";

// 	str[1] = 'x';
// 	printf("input: %s\n", str);
// 	printf("output: %s\n", ft_strupcase(str));
// }
char	*ft_strupcase(char *str)
{
	char	*tmp;

	tmp = str;
	while (*tmp != '\0')
	{
		if (*tmp >= 'a' && *tmp <= 'z')
			*tmp = *tmp - 32;
		tmp++;
	}
	return (str);
}
