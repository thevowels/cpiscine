/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aphyo-ht <aphyo-ht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 03:45:24 by aphyo-ht          #+#    #+#             */
/*   Updated: 2025/07/28 06:22:40 by aphyo-ht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

int	ft_isin(char c, char *charset)
{
	while (*charset)
	{
		if (c == *charset)
			return (1);
		charset++;
	}
	return (0);
}

int	count_words(char *str, char *charset)
{
	int	count;
	int	flag;

	count = 0;
	flag = 1;
	while (*str)
	{
		if (flag && !ft_isin(*str, charset))
		{
			count++;
			flag = 0;
		}
		else if (!flag && ft_isin(*str, charset))
		{
			flag = 1;
		}
		str++;
	}
	return (count);
}

char	*ft_get(char *str, int n)
{
	char	*word;
	int		i;

	i = 0;
	word = malloc(sizeof(char) * (n + 1));
	while (i < n)
	{
		word[i] = str[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

char	**ft_split(char *str, char *charset)
{
	char	**arr;
	int		wc;
	int		flag;
	int		j;

	flag = 1;
	arr = malloc(sizeof(char *) * (count_words(str, charset) + 1));
	if (!arr)
		return (NULL);
	wc = 0;
	while (*str)
	{
		if (flag && !ft_isin(*str, charset))
		{
			j = 0;
			while (!ft_isin(str[j], charset) && str[j])
				j++;
			arr[wc++] = ft_get(str, j);
			str += j;
		}
		else if (!flag && ft_isin(*str, charset))
			flag = 1;
		str++;
	}
	return (arr);
}
/*
#include <stdio.h>

int	main(void)
{
	char	str[] = "1.......22;::;:,,333.,.,..;:4444.,;asdfa...kkkk..last";
	char	charset[] = ",:;.";
	char	**char_arr;
	int		i;
	int		n;

	n = 0;
	i = count_words(str, charset);
	printf("Word count is : %d \n", i);
	char_arr = ft_split(str, charset);
	while(n < i)
	{
		printf("%s\n", char_arr[n]);
		free(char_arr[n]);
		n++;
	}
	free(char_arr);
	return (0);
}
*/
