#include "../so_long.h"

int ft_close ()
{
	exit(0);
}

t_window	ft_new_window(void *mlx, int widht, int height, char *name)
{
	t_window	window;

	/* Returning a void pointer that is a reference to the opened window with a given size and name */
	window.reference = mlx_new_window(mlx, widht, height, name);
	window.size.x = widht;
	window.size.y = height;

	// Now we 'hook' the function ft_close() to the closing window event
	mlx_hook(window.reference, 17, 0, ft_close, 0);

	return (window);
}


