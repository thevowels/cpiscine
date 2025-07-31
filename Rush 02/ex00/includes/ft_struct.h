/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_struct.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aphyo-ht <aphyo-ht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 20:18:15 by aphyo-ht          #+#    #+#             */
/*   Updated: 2025/07/27 23:07:03 by aphyo-ht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STRUCT_H

# define FT_STRUCT_H

typedef struct s_single
{
	char	*key;
	char	*value;
}			t_single;


typedef struct s_dict
{
	char	*primitives[10];
	char	*edges[9];
	char	*tens[9];
	char	*hundred;
	char	*lions[30];
}			t_dict;

#endif
