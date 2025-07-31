/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_params.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aphyo-ht <aphyo-ht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 22:31:37 by aphyo-ht          #+#    #+#             */
/*   Updated: 2025/07/19 19:14:32 by aphyo-ht         ###   ########.fr       */
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

	argv++;
	while (*argv)
	{
		count = ft_count_char(*argv);
		write(1, *argv, count);
		write(1, "\n", 1);
		argv++;
	}
	return (argc);
}
