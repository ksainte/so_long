#include "../so_long.h"

/* Any functon that you hook with the key event must be like this:
* Recibing an int for the code of the key pressed
* and a void pointer in case you need to recibe someting */
int	ft_input(int key, void *param)
{
	t_program *program = (t_program *)param;
	// t_map *map = (t_map *)param;

	// mlx function that clears the window
	// mlx_clear_window(program->mlx, program->window.reference);

	program->sprite2 = ft_bgd_sprite(program->mlx, "Background.xpm");
	mlx_put_image_to_window(program->mlx, program->window.reference,
		program->sprite2.reference_bgd, program->sprite_position.x, program->sprite_position.y);


	// program->sprite_position.x = map->starting_y * 64;
    // program->sprite_position.y = map->starting_x * 64;

	int x;
    int y;

	x = program->map->starting_x;//ligne
	y = program->map->starting_y;//colonne
	printf("x is %d\n", x);
	printf("y is %d\n", y);
	// map->tab[x][y + 1] != '1'

	if (key == 124) //go to right
		program->sprite_position.x += program->sprite.size.x;
	else if (key == 123) //go to left
		program->sprite_position.x -= program->sprite.size.x;
	else if (key == 125)//go down
		program->sprite_position.y += program->sprite.size.y;
	else if (key == 126)//go up
		program->sprite_position.y -= program->sprite.size.y;
	// change color based on keys R, G and B.
	else if (key == 15)
		turn_img_to_color(&program->sprite, new_color(255,0,0,0));
	else if (key == 5)
		turn_img_to_color(&program->sprite, new_color(0,255,0,0));
	else if (key == 11)
		turn_img_to_color(&program->sprite, new_color(0,0,255,0));

	// mlx function that puts an image into a window at a given position
	// (the position 0,0 is the upper-left corner)
	mlx_put_image_to_window(program->mlx, program->window.reference,
		program->sprite.reference, program->sprite_position.x, program->sprite_position.y);
	// print the key pressed so you know the number of each key
	printf("Key pressed -> %d\n", key);
	return (0);
}

int	ft_update (void *param)
{
	t_program	*program = (t_program *)param;
	// a static that saves how many frames have passed
	static int	frame;

	// add a frame and every x frames change the position by 1 pixel
	// so it looks like its animated
	frame++;
	if (frame == ANIMATION_FRAMES)
		program->sprite_position.y += 1;
	// every x*2 frames go back that pixel to loop the animation
	else if (frame >= ANIMATION_FRAMES * 2)
	{
		program->sprite_position.y -= 1;
		frame = 0;
	}
	mlx_put_image_to_window(program->mlx, program->window.reference,
		program->sprite.reference, program->sprite_position.x, program->sprite_position.y);

	return (0);
}