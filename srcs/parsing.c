/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktroude <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 14:45:26 by ktroude           #+#    #+#             */
/*   Updated: 2022/12/12 14:50:47 by ktroude          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

t_map	parsing(int argc, char **argv)
{
	int		fd;
	char	*str;
	t_map	map;

	fd = check_arg(argv, argc);
	if (fd < 0)
		exit(1);
	str = map_to_str(fd);
	if (str == NULL)
		exit(1);
	map = str_to_struct(str);
	if (map.array == NULL)
		print("Error: parsing\n", 1);
	return (map);
}

int	check_arg(char **argv, int argc)
{
	int	fd;

	if (argc != 2)
		print("Error: wrong argument\n", 1);
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		print("Error: can't open ", 0);
		print(argv[1], 0);
		print("\n", 1);
	}
	return (fd);
}

// open file, get the map and put it in a str
char	*map_to_str(int fd)
{
	char	*str;
	char	buf[2];
	int		ret;

	str = malloc(sizeof(char));
	str[0] = 0;
	ret = 1;
	while (ret)
	{
		ret = read(fd, buf, 1);
		buf[1] = 0;
		if (ret == -1)
			print("Error: read failed\n", 1);
		str = ft_strjoin(str, buf);
	}
	return (str);
}

t_map	str_to_struct(char *str)
{
	t_map	map;
	int		j;
	int		k;

	j = 0;
	k = 0;
	map = init_map(str);
	printf("OK\n");
	map = get_data(str, map, j);
	return (map);
}

t_map	get_data(char *str, t_map map, int j)
{
	int	k;
	int	i;

	i = 0;
	k = 0;
	while (str[i])
	{
		map.array[j][k++] = ft_atoi(&str[i]);
		if (k == map.l)
		{
			k = 0;
			j++;
		}
		if (j == map.h)
			break ;
		while (str[i] && str[i] != ' ' && str[i] != '\n')
			i++;
		while (str[i] == ' ' || str[i] == '\n')
			i++;
	}
	return (map);
}
