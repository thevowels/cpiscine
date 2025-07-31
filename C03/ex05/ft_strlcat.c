/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aphyo-ht <aphyo-ht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 01:12:12 by aphyo-ht          #+#    #+#             */
/*   Updated: 2025/07/16 16:21:52 by aphyo-ht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	srclength;
	unsigned int	destlength;
	int				i;

	i = 0;
	destlength = 0;
	srclength = 0;
	while (dest[destlength])
		destlength++;
	if (destlength == size)
		return (destlength + size);
	while (src[srclength])
		srclength++;
	while (src[i] && (destlength + i) < size)
	{
		dest[destlength + i] = src[i];
		i++;
	}
	dest[destlength + i] = '\0';
	return (destlength + srclength);
}
