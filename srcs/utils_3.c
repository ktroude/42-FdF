/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktroude <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 14:54:07 by ktroude           #+#    #+#             */
/*   Updated: 2022/12/12 15:00:06 by ktroude          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

t_map	init_map(char *str)
{
	t_map	map;
	int		i;

	i = 0;
	map.h = get_array_size(str);
	map.l = get_line_size(str);
	map.array = malloc(sizeof(int *) * map.h);
	if (!map.array)
		print("Error: malloc failed\n", 1);
	while (i < map.h)
		map.array[i++] = malloc(sizeof(int) * map.l);
	return (map);
}

int	get_line_size(char *str)
{
	int	i;
	int	n;
	int	ret;

	i = 0;
	ret = 0;
	n = get_new_line_length(str);
	while (i < n)
	{
		if (str[i] == ' ')
			i++;
		else if (str[i] != ' ')
		{
			if (i == 0 || str[i - 1] == ' ')
				ret ++;
			while (str[i] != ' ')
				i++;
		}
	}
	return (ret);
}

int	ft_strlcpy(char *dst, char *src, int dstsize)
{
	int	i;

	i = 0;
	if (dstsize > 0)
	{
		while (src[i] && i < dstsize - 1)
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = 0;
	}
	while (src[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		i1;
	int		i2;
	char	*str;

	i1 = ft_strlen(s1);
	i2 = ft_strlen(s2);
	str = malloc(sizeof(char) * (i1 + i2 + 1));
	i1 = 0;
	i2 = 0;
	while (s1[i1])
	{
		str[i1] = s1[i1];
		i1++;
	}
	while (s2[i2])
		str[i1++] = s2[i2++];
	str[i1] = 0;
	if (s1)
		free(s1);
	return (str);
}

int	get_new_line_length(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	return (i);
}
