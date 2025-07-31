/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aphyo-ht <aphyo-ht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 04:05:13 by aphyo-ht          #+#    #+#             */
/*   Updated: 2025/07/17 06:53:59 by aphyo-ht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	checkbase(char *base)
{
	int		i;
	char	*tmp;

	i = 0;
	if (!(base[0] && base[1]))
		return (1);
	while (base[i])
	{
		if (base[i] == '-' || base[i] == '+')
			return (1);
		tmp = &base[i + 1];
		while (*tmp)
		{
			if (base[i] == *tmp)
			{
				return (1);
			}
			tmp++;
		}
		i++;
	}
	return (0);
}

void	printjob(long nbr, char *base, int baselength)
{
	if (nbr < 0)
	{
		write(1, "-", 1);
		printjob(-nbr, base, baselength);
	}
	else
	{
		if (nbr >= baselength)
		{
			printjob(nbr / baselength, base, baselength);
			write(1, &base[nbr % baselength], 1);
		}
		else
		{
			write(1, &base[nbr], 1);
		}
	}
}

void	ft_putnbr_base(int nbr, char *base)
{
	int	baselength;

	if (checkbase(base))
		return ;
	baselength = 0;
	while (base[baselength])
		baselength++;
	printjob(nbr, base, baselength);
}

/*
int	main(void)
{
	ft_putnbr_base(-2147483648, "01");
	return (0);
}
*/
