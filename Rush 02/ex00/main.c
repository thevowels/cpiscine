/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aphyo-ht <aphyo-ht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 20:12:08 by aphyo-ht          #+#    #+#             */
/*   Updated: 2025/07/27 23:41:04 by aphyo-ht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lib.h"
#include "ft_struct.h"

int	is_find_valid(char *str)
{
	while (*str)
	{
		if (*str < '0' || *str > '9')
		{
			ft_putstr("Error\n");
			return (0);
		}
		str++;
	}
	return (1);
}

/*
	validate the arguments
*/
int	checkargs(int argc, char **argv, char **filename)
{
	if (argc == 2)
	{
		*filename = ft_strdup(DEFAULT_DICT);
		return (1);
	}
	else if (argc == 3)
	{
		*filename = ft_strdup(argv[1]);
		return (1);
	}
	ft_putstr("There is not enough arguments\n");
	return (filename - filename);
}

/*
	ft_getline
	return the line, increment the buffer
*/

char	*ft_getline(char *buffer, int *skip)
{
	int		i;
	char	*line;

	i = 0;
	while (buffer[i] != '\n' && buffer[i] != '\0')
	{
		i++;
	}
	// ft_putstr("I = ");
	// ft_putnbr(i);
	// ft_putchar('\n');
	*skip = i;
	// ft_putstr("Skip = ");
	// ft_putnbr(*skip);
	// ft_putchar('\n');
	line = malloc(i + 1);
	ft_strncpy(line, buffer, i + 1);
	return (line);
}

/*
	get key and value from the line
	and pass it to the dictionary
*/
// int	ft_parseline(char *buffer, int stop)
// {
// }

/*
	transverse through the buffer
	read each line and fill the dict

*/

int ft_add_val(char *key, char *value, t_dict * dict)
{
	if(ft_strlen(key) == 1)
	{
		dict->primitives[*key - '0'] = value;
	}
	else if(ft_strlen(key) == 2)
	{
		if(key[0] == '1' && key[1] == '0')
			dict->tens[0] = value;
		else if(key[0] == '1')
		{
			dict->edges[key[1] - '0'] = value;
		}
		else
		{
			dict->tens[key[0] - '0'] = value;
		}
	}
	else if(ft_strlen(key) == 3)
	{
		dict->hundred = value;
	}
	else if(ft_strlen(key)-1 >=3 && ft_strlen(key) -1 % 3 == 0 )
	{
		dict->lions[ft_strlen(key)/3] = value;
	}
	return (0);
}

int ft_filldict(char * buffer,int count , t_dict *dict)
{
	int i = 0;
	char *key;
	char *value;

	while(buffer[i] != ' ')
	{
		i++;
	}
	key = ft_strdupn(buffer,i);
	while(buffer[i] != ':')
		i++;
	i++;
	while(ft_isspaces(buffer[i]))
		i++;
	value = ft_strdupc(&buffer[i], '\n');

	ft_putstr("Key is : ");
	ft_putstr(key);
	ft_putchar('\n');
	ft_putstr("Value is : ");
	ft_putstr(value);
	ft_putchar('\n');
	ft_add_val(key,value,dict);
	return (count);
}

int	ft_process_buffer(char *buffer, t_dict *dict)
{
	int	i;

	i = 0;
	while (*buffer)
	{
		i = 0;
		while (buffer[i] != '\n' && buffer[i] != '\0')
			i++;
		if (i != 0)
			ft_filldict(buffer, i, dict);
		buffer += i + 1;
	}
	dict->edges[0] = "asdf";
	return (1);
}

/*
	ft_free
	free all the pointers appropirately
*/
void	ft_free(t_dict *dict, char *buffer)
{
	if (*(dict->edges))
		free(dict->edges);
	free(buffer);
	// Free all elements inside dict
}
/*
	ft_construct
	construct the dict
	1. count the chars on the file
	2. create malloc with count + 1
	3. read the file into the buffer . add '\0' at the end
*/
int	ft_construct(char *filename, t_dict *dict)
{
	char	*buffer;
	int		file;
	int		char_count;

	// t_dict	dict;
	char_count = ft_checksize(filename);
	if (char_count == -1)
		return (-1);
	buffer = malloc(char_count + 1);
	file = open(filename, O_RDONLY);
	if (file == -1)
	{
		ft_putstr("Dict Error\n");
		return (-1);
	}
	if (read(file, buffer, char_count) == -1)
	{
		ft_putstr("Dict Error\n");
		return (-1);
	}
	buffer[char_count] = '\0';
	ft_process_buffer(buffer, dict);
	// ft_putstr(buffer);
	ft_free(dict, buffer);
	close(file);
	return (1);
}

/*
	Init function
*/
int	main(int argc, char **argv)
{
	char	**filename;
	char	*check;
	t_dict	dict;

	filename = malloc(sizeof(char *));
	// TODO: Important || process the right one only if the left one is false
	// I think second check is not working here.
	// I'll fix later.
	if (!checkargs(argc, argv, filename) || !is_find_valid(argv[argc - 1]))
	{
		free(*filename);
		free(filename);
		return (-1);
	}
	check = argv[argc - 1];
	if (ft_construct(*filename, &dict) == -1)
	{
		free(*filename);
		free(filename);
		return (-1);
	}
	ft_putstr(check);
	free(*filename);
	free(filename);
	return (0);
}
