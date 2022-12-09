#include "fdf.h"	


// init the mini graphic lib value's to display a screen
t_mlx   init_mlx(t_mlx mlx)
{
	mlx.vars.mlx = mlx_init();
	mlx.vars.win = mlx_new_window(mlx.vars.mlx, 1920, 1080, "FDF");
	mlx.img.img = mlx_new_image(mlx.vars.mlx, 1920, 1080);
	mlx.img.addr = mlx_get_data_addr(mlx.img.img, &mlx.img.bits_per_pixel, &mlx.img.line_length, &mlx.img.endian);
    return mlx;
}

// set up a loop and check if an event happend and respond to it
t_mlx   loop_and_hooks(t_mlx mlx)
{
	mlx_hook(mlx.vars.win, 2, 1L<<0, ft_close, &mlx.vars);
	mlx_hook(mlx.vars.win, 17, 1L<<0, ft_close_x, &mlx.vars);
	mlx_loop(mlx.vars.mlx);
    return mlx;
}

void    free_mlx(t_mlx mlx)
{
	free(mlx.vars.mlx);
	free(mlx.vars.win);
	free(mlx.img.img);
	free(mlx.img.addr);
}

int	ft_close(int keycode, t_vars *vars)
{
	if (keycode == 53)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		exit(0);
	}
	return (0);
}

int	ft_close_x(t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	exit(0);
	return (0);
}