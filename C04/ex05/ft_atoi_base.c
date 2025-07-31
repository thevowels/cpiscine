/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aphyo-ht <aphyo-ht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 02:31:47 by aphyo-ht          #+#    #+#             */
/*   Updated: 2025/07/17 17:39:03 by aphyo-ht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
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

int	get_position(char c, char *base)
{
	int	i;

	i = 0;
	while (base[i])
	{
		if (base[i] == c)
			return (i);
		i++;
	}
	return (-42);
}

int	power(int val, int pow, int *strl, char *str)
{
	int	result;

	result = 0;
	if (val != 42)
	{
		result = 1;
		while (pow >= 1)
		{
			result *= val;
			pow--;
		}
		return (result);
	}
	else
	{
		while (str[*strl + 1])
		{
			*strl += 1;
		}
		return (result);
	}
	return (42);
}

int	magic(char *str, char *base, int *bv, int *first)
{
	int	sign;
	int	i;

	i = 0;
	sign = 1;
	while (str[i])
	{
		if (str[i] == '-')
		{
			sign *= -1;
			i++;
		}
		else if (str[i] == '+' || str[i] <= 32)
			i++;
		else
			break ;
	}
	*first = i;
	while (base[*bv])
		*bv = *bv + 1;
	return (sign);
}

int	ft_atoi_base(char *str, char *base)
{
	int	basevalue;
	int	strlength;
	int	value;
	int	sign;
	int	first;

	value = 0;
	basevalue = 0;
	strlength = -1;
	sign = 1;
	first = 0;
	if (checkbase(base))
		return (0);
	sign = magic(str, base, &basevalue, &first);
	str += first;
	power(42, 24, &strlength, str);
	while (*str && get_position(*str, base) != -42)
	{
		value = value * basevalue + get_position(*str, base);
		strlength--;
		str++;
	}
	return (value * sign);
}

/*
#include <stdio.h>

int	main(void)
{

	// value += get_position(*str, base) * (power(basevalue, strlength,
	// 			&strlength, str));

	// ft_atoi_base("-2147483648", "01");
	printf("\nNumber: +-----123ABC | Base: 0123456789 (Decimal):\n");
	printf("%d\n\n", ft_atoi_base("  +-----123ABC", "0123456789"));
	printf("Number: 00001101 | Base: 01 (Binary):\n");
	printf("%d\n\n", ft_atoi_base("   00001101", "01"));
	printf("Number: FF | Base: 0123456789ABCDEF (Hexadecimal):\n");
	printf("%d\n\n", ft_atoi_base("FF", "0123456789ABCDEF"));
	printf("Number: pone | Base: poneyvif (Octal):\n");
	printf("%d\n\n", ft_atoi_base("pone", "poneyvif"));
	return (1);
}
*/
