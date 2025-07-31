/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lib.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aphyo-ht <aphyo-ht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 20:15:02 by aphyo-ht          #+#    #+#             */
/*   Updated: 2025/07/27 22:57:50 by aphyo-ht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LIB_H

# define FT_LIB_H

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

# define DEFAULT_DICT "numbers.dict"

// Strings
int		ft_count_until(char *str, char c);
void	ft_putstr(char *str);
int		ft_strlen(char *str);
char	*ft_strdup(char *src);
char	*ft_strdupn(char *src, int n);
char	*ft_strdupc(char *src, char c);
char	*ft_strncpy(char *dest, char *src, unsigned int n);
void	ft_putnbr(int nb);

// chars
void	ft_putchar(char c);
int		ft_isspaces(char c);
int		ft_isprintable(char c);
int		ft_isdigit(char c);

// file operations
int		ft_checksize(char *filename);

#endif
