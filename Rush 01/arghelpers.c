/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arghelpers.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aphyo-ht <aphyo-ht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 20:28:53 by aphyo-ht          #+#    #+#             */
/*   Updated: 2025/07/20 22:00:28 by aphyo-ht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	bad_vals(int size, int *rules);

int	check_arg(char *arg, int *rules)
{
	int	i;
	int	size;

	i = 0;
	size = 0;
	while (*arg)
	{
		if (*arg <= 32)
			arg++;
		else if (*arg >= '1' && *arg <= '9')
		{
			size += 1;
			rules[i] = *arg - '0';
			i++;
			arg++;
		}
		else
			return (0);
	}
	if (bad_vals(size, rules))
		return (0);
	return (size / 4);
}

int	bad_vals(int size, int *rules)
{
	int	i;

	i = 0;
	if (size % (size / 4) != 0)
		return (1);
	while (i < size)
	{
		if (rules[i] > size / 4)
			return (1);
		i++;
	}
	return (0);
}
