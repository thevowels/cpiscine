/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq_header_mapzapper.h                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aphyo-ht <aphyo-ht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 15:27:53 by sasakuya          #+#    #+#             */
/*   Updated: 2025/07/30 10:29:18 by aphyo-ht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSQ_HEADER_MAPZAPPER_H
# define BSQ_HEADER_MAPZAPPER_H

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_bsq
{
	char	**map;
	char	empty;
	char	obstacle;
	char	full;
	int		size;
	int		rows;
	int		cols;
	int		r;
	int		c;
	int		map_error;
}			t_bsq;

typedef struct s_parse_args
{
	int		read_size;
	int		total;
	int		i;
	int		j;
}			t_parse_args;

void		ft_init_struct(t_bsq *z);
void		ft_putstr(char *str);
void		ft_free_map(t_bsq *z);
int			ft_read_file(char *file, char *data);
void		ft_parse_map(char *data, t_bsq *z);
void		ft_mark_the_square(t_bsq *z);
void		ft_mapzapper(t_bsq *z);
void		ft_parse_map(char *data, t_bsq *z);
void		ft_parse_header(char *data, t_bsq *z, int *i);
void		ft_alloc_map(t_bsq *z);
void		ft_fill_map(char *data, t_bsq *z, int i);
void		ft_find_biggest_square(t_bsq *z, int *max, int *by, int *bx);
void		ft_draw_square(t_bsq *z, int max, int by, int bx);
void		ft_execute(char *data, t_bsq *z);
void		ft_stdin_decision(char *inp1, char *inp2, t_bsq *z);
void		map_fromstdin(t_bsq *z, char *data);
int			ft_possible_square(t_bsq *z);
int			ft_isnb(char c);
int			ft_str_clen(char *str, char c);
void		ft_fill_line(char *data, t_bsq *z, int r, int c);
int			ft_is_cok(char c, t_bsq *z);
int			ft_check_line(char *data, t_bsq *z);
int			is_header_ok(char *str);
void		ft_parse_header(char *data, t_bsq *z, int *i);
int			ft_atoi(char *str);
void		ft_strcpy(char *dest, char *src);

#endif
