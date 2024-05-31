#include "../so_long.h"

/* Returns an image with the sprite found in <path> */
t_image ft_new_sprite(void *mlx, char *path)
{
	t_image img;//declaration de la struct t_image
	
	/* mlx function that creates an image that contains the xmp file found in the given path.
	* It also saves the width and height of the image in the pointers passed as parameters */

	//reference est une variable (de type) pointeur sur void
	// &/pointeur qui pointe sur structure mlx_img_list_s qui definie l image/sprite en question
	img.reference = mlx_xpm_file_to_image(mlx, path, &img.size.x, &img.size.y);
	//And then having a function that creates the image and fills the variables
	img.pixels  = mlx_get_data_addr(img.reference, &img.bits_per_pixel, &img.line_size, &img.endian);
	return (img);
}
