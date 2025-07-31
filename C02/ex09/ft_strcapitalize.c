/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aphyo-ht <aphyo-ht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 00:48:57 by aphyo-ht          #+#    #+#             */
/*   Updated: 2025/07/13 00:41:58 by aphyo-ht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_strcapitalize(char *str);

int	ft_chr_is_alpha(char *str)
{
	if (!((*str >= 'A' && *str <= 'Z') || (*str >= 'a' && *str <= 'z')))
	{
		return (0);
	}
	return (1);
}

void	ft_chr_to_upper(char *str)
{
	if (*str >= 'a' && *str <= 'z')
	{
		*str -= 32;
	}
}

void	ft_strlowcase(char *str)
{
	while (*str)
	{
		if (*str >= 'A' && *str <= 'Z')
		{
			*str += 32;
		}
		str++;
	}
}

// int	main(void)
// {
// 	char	str[] = "1 hi, how are you? 42words forty-two; fifty+and+one";

// 	printf("Before: %s \n", str);
// 	ft_strcapitalize(str);
// 	printf("After: %s \n", str);
// }

char	*ft_strcapitalize(char *str)
{
	int	i;

	i = 0;
	ft_strlowcase(str);
	ft_chr_to_upper(&str[i]);
	i++;
	while (str[i])
	{
		if (!(ft_chr_is_alpha(&str[i - 1])
				|| (str[i - 1] >= '0' && str[i - 1] <= '9'))
			&& ft_chr_is_alpha(&str[i]))
		{
			ft_chr_to_upper(&str[i]);
		}
		i++;
	}
	return (str);
}
