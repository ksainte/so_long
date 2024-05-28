#include "../so_long.h"

/* Returns an image of <width> x <height> black pixels. */
t_image ft_new_image(void* mlx, int width, int height)
{
	t_image img;

	/* mlx function that creates and returns a pointer
	to an image of the given width and height */
	img.reference = mlx_new_image(mlx, width, height);
	img.size.x = width;
	img.size.x = height;

	img.pixels = mlx_get_data_addr(img.reference, &img.bits_per_pixel, &img.line_size, &img.endian);

	return (img);
}
/* Returns an image with the sprite found in <path> */
t_image ft_new_sprite(void *mlx, char *path)
{
	t_image img;
	
	/* mlx function that creates an image that contains the xmp file found in the given path.
	* It also saves the width and height of the image in the pointers passed as parameters */
	img.reference = mlx_xpm_file_to_image(mlx, path, &img.size.x, &img.size.y);
	//And then having a function that creates the image and fills the variables
	img.pixels  = mlx_get_data_addr(img.reference, &img.bits_per_pixel, &img.line_size, &img.endian);
	return (img);
}
t_image ft_bgd_sprite(void *mlx, char *path)
{
	t_image img;
	
	/* mlx function that creates an image that contains the xmp file found in the given path.
	* It also saves the width and height of the image in the pointers passed as parameters */
	img.reference_bgd = mlx_xpm_file_to_image(mlx, path, &img.size.x, &img.size.y);
	//And then having a function that creates the image and fills the variables
	img.pixels  = mlx_get_data_addr(img.reference_bgd, &img.bits_per_pixel, &img.line_size, &img.endian);
	return (img);
}
