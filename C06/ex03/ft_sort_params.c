/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aphyo-ht <aphyo-ht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 22:47:55 by aphyo-ht          #+#    #+#             */
/*   Updated: 2025/07/19 19:14:14 by aphyo-ht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	compare(char *str1, char *str2)
{
	while (*str1 && *str2)
	{
		if (*str1 != *str2)
			return (*str1 - *str2);
		str1++;
		str2++;
	}
	return (*str1 - *str2);
}

void	swap(char **str1, char **str2)
{
	char	*tmp;

	tmp = *str1;
	*str1 = *str2;
	*str2 = tmp;
}

void	sort_words(int length, char **words)
{
	int	i;
	int	max;

	while (length)
	{
		max = 0;
		i = 1;
		while (i <= length)
		{
			if (compare(words[i], words[max]) < 0)
				max = i;
			i++;
		}
		swap(&words[length], &words[max]);
		length--;
	}
}

int	main(int argc, char **argv)
{
	if (argc > 1)
	{
		argv++;
		argc -= 2;
		sort_words(argc, argv);
		while (argc >= 0)
		{
			while (*argv[argc])
			{
				write(1, argv[argc], 1);
				argc[argv]++;
			}
			write(1, "\n", 1);
			argc--;
		}
	}
	return (0);
}
