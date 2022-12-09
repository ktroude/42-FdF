#include "fdf.h"

int	main(int argc, char **argv)
{
	int		**map;
	t_mlx	mlx;

	if ((map = parsing(argc, argv)) == NULL)
		return (1);
	mlx = init_mlx(mlx);
	// coding algo
	mlx = loop_and_hooks(mlx);
	free_mlx(mlx);

}