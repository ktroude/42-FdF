/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktroude <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 14:42:09 by ktroude           #+#    #+#             */
/*   Updated: 2022/12/12 14:42:39 by ktroude          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	main(int argc, char **argv)
{
	t_map	map;
	t_mlx	mlx;

	map = parsing(argc, argv);
	mlx = init_mlx();
	// coding algo
	mlx = loop_and_hooks(mlx);
	free_mlx(mlx);
}
