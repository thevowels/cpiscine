/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aphyo-ht <aphyo-ht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 09:02:47 by aphyo-ht          #+#    #+#             */
/*   Updated: 2025/07/16 15:39:24 by aphyo-ht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	int				count;
	unsigned int	bn;

	count = 0;
	bn = 0;
	while (dest[count])
	{
		count++;
	}
	while (*src && bn < nb)
	{
		dest[bn + count] = *src;
		src++;
		bn++;
	}
	dest[bn + count] = '\0';
	return (dest);
}

// Logic error thougth the nb number of characters to be qual
// to the result of dest string intead of numer of chars to be copied.
