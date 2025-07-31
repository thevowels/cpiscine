/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aphyo-ht <aphyo-ht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 22:40:36 by aphyo-ht          #+#    #+#             */
/*   Updated: 2025/07/19 19:14:44 by aphyo-ht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_count_char(char *str)
{
	int	count;

	count = 0;
	while (*str)
	{
		count++;
		str++;
	}
	return (count);
}

int	main(int argc, char **argv)
{
	int	count;

	count = 0;
	argc--;
	while (argv[argc] && argc >= 1)
	{
		count = ft_count_char(argv[argc]);
		write(1, argv[argc], count);
		write(1, "\n", 1);
		argc--;
	}
	return (0);
}
