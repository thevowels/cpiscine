/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq_main_mapzapper.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aphyo-ht <aphyo-ht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 14:02:05 by sasakuya          #+#    #+#             */
/*   Updated: 2025/07/30 10:43:59 by aphyo-ht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq_header_mapzapper.h"

void	ft_parse_map(char *data, t_bsq *z)
{
	int	i;

	i = 0;
	ft_parse_header(data, z, &i);
	if (z->map_error)
		return ;
	ft_alloc_map(z);
	ft_fill_map(data, z, i);
}

void	ft_mapzapper(t_bsq *z)
{
	int	i;

	i = 0;
	while (i < z->rows)
	{
		ft_putstr(z->map[i]);
		ft_putstr("\n");
		i++;
	}
}

int	main(int argc, char *argv[])
{
	int		i;
	char	*data;
	t_bsq	z;

	data = malloc(88888889);
	i = 1;
	ft_init_struct(&z);
	if (argc == 1)
		map_fromstdin(&z, data);
	while (i < argc)
	{
		if (!ft_read_file(argv[i], data) || !data)
			ft_putstr("map error\n");
		else
			ft_execute(data, &z);
		if (i < argc - 1)
			ft_putstr("\n");
		z.map_error = 0;
		i++;
	}
	free(data);
	return (0);
}
