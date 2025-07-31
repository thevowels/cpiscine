/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aphyo-ht <aphyo-ht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 21:10:11 by aphyo-ht          #+#    #+#             */
/*   Updated: 2025/07/11 01:21:21 by aphyo-ht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_printable(char *str);

// int main(void)
// {
// 	char *str;
// 	str = "asdfa";
// 	printf("Output : %i ", ft_str_is_printable(str));
// }

int	ft_str_is_printable(char *str)
{
	char	*tmp;

	tmp = str;
	while (*tmp != '\0')
	{
		if (*tmp < 32 || *tmp > 126)
			return (0);
		tmp++;
	}
	return (1);
}
