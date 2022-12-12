/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktroude <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 14:51:11 by ktroude           #+#    #+#             */
/*   Updated: 2022/12/12 14:52:37 by ktroude          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	print(char *str, int i)
{
	while (*str)
		write(2, str++, 1);
	if (i)
		exit(i);
}

char	*add_char(char *s1, char*s2)
{
	int		i;
	char	*str;

	i = 0;
	if (!s1)
	{
		s1 = malloc(sizeof(char) * 2);
		s1[0] = s2[0];
		s1[1] = 0;
		return (s1);
	}
	str = malloc(sizeof(char) * (ft_strlen(s1) + 1));
	while (s1[i++])
		str[i] = s1[i];
	str[++i] = s2[0];
	str[++i] = 0;
	free(s1);
	return (str);
}

int	ft_strlen(char *str)
{
	int	i;

	if (! str)
		return (0);
	i = 0;
	while (*str++)
		i++;
	return (i);
}

int	ft_atoi(char *str)
{
	int	i;
	int	sign;
	int	result;

	i = 0;
	sign = 1;
	result = 0;
	while ((str[i] >= 9 && str[i] <= 13) || (str[i] == 32))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = sign * -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
		result = result * 10 + (str[i++] - 48);
	return (result * sign);
}
