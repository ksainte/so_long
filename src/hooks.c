#include "../so_long.h"


void ft_update_counter(int x, int y, t_program *program)
{
		if(program->map->tab[x][y] == 'C')
		{
			program->map->tab[x][y] = '2';
			program->map->counter_cltb--;
		}
		if(program->map->counter_cltb == 0)
			 program->map->has_exit = 0;
}

int	ft_exit(int key, int x, int y, t_program *program)
{

	if (key == 124 && program->map->tab[x][y + 1] == 'E' && program->map->has_exit == 0) //go to right
		{
			program->sprite_position.x += program->sprite.size.x;
			// program->input_position.y += 1;
			exit(1);
		}
	else if (key == 123 && program->map->tab[x][y - 1] == 'E' && program->map->has_exit == 0) //go to left
		{
			program->sprite_position.x -= program->sprite.size.x;
			// program->input_position.y -= 1;
				exit(1);
		}
	else if (key == 125 && program->map->tab[x + 1][y] == 'E' && program->map->has_exit == 0)//go down
		{
			program->sprite_position.y += program->sprite.size.y;
			// program->input_position.x += 1;
				exit(1);
		}	
	else if (key == 126 && program->map->tab[x - 1][y] == 'E' && program->map->has_exit == 0)//go up
		{
			program->sprite_position.y -= program->sprite.size.y;
			// program->input_position.x -= 1;
				exit(1);
		}
	return (0);
}

/* Any functon that you hook with the key event must be like this:
* Recibing an int for the code of the key pressed
* and a void pointer in case you need to recibe someting */
int	ft_input(int key, void *param)
{
	t_program *program = (t_program *)param;//ou int x, creation de variable
	t_image img;

	img.reference_bgd = mlx_xpm_file_to_image(program->mlx, "Background.xpm", &img.size.x, &img.size.y);
	mlx_put_image_to_window(program->mlx, program->window.reference,
		img.reference_bgd, program->sprite_position.x, program->sprite_position.y);
	
	int x;
    int y;

	// x = program->input_position.x;//ligne
	// y = program->input_position.y;//colonne
	y = program->sprite_position.x / 64;//ligne
	x = program->sprite_position.y / 64;//colonne
	printf("current x is -> %d\n", x);
	printf("current y is -> %d\n", y);
	if (key == 124 && program->map->tab[x][y + 1] != '1' && !ft_exit(key, x, y, program) && program->map->tab[x][y + 1] != 'E') //go to right
		{
			program->sprite_position.x += program->sprite.size.x;
			// program->input_position.y += 1;
			ft_update_counter(x, y, program);
			mlx_put_image_to_window(program->mlx, program->window.reference,
			img.reference_bgd, program->sprite_position.x, program->sprite_position.y);
			//change le sprite reference en fonction de la direction pour avoir l effet qu il bouge

		}
	else if (key == 123 && program->map->tab[x][y - 1] != '1' && !ft_exit(key, x, y, program) && program->map->tab[x][y - 1] != 'E') //go to left
		{
			program->sprite_position.x -= program->sprite.size.x;
			// program->input_position.y -= 1;
			ft_update_counter(x, y, program);
			mlx_put_image_to_window(program->mlx, program->window.reference,
			img.reference_bgd, program->sprite_position.x, program->sprite_position.y);
		}
	else if (key == 125 && program->map->tab[x + 1][y] != '1'&& !ft_exit(key, x, y, program) && program->map->tab[x + 1][y] != 'E')//go down
		{
			program->sprite_position.y += program->sprite.size.y;
			// program->input_position.x += 1;
			ft_update_counter(x, y, program);
			mlx_put_image_to_window(program->mlx, program->window.reference,
			img.reference_bgd, program->sprite_position.x, program->sprite_position.y);
		}	
	else if (key == 126 && program->map->tab[x - 1][y] != '1' && !ft_exit(key, x, y, program) && program->map->tab[x - 1][y] != 'E')//go up
		{
			program->sprite_position.y -= program->sprite.size.y;
			// program->input_position.x -= 1;
			ft_update_counter(x, y, program);
			mlx_put_image_to_window(program->mlx, program->window.reference,
			img.reference_bgd, program->sprite_position.x, program->sprite_position.y);
		}
	// change color based on keys R, G and B.
	else if (key == 53)
	{
		mlx_clear_window(program->mlx, program->window.reference);
		exit(1);
	}
	// mlx function that puts an image into a window at a given position
	// (the position 0,0 is the upper-left corner)
	mlx_put_image_to_window(program->mlx, program->window.reference,
		program->sprite.reference, program->sprite_position.x, program->sprite_position.y);
	// printf("Key pressed -> %d\n", key);
	// program->map->counter_cltb--;
	printf("counter is -> %d\n", program->map->counter_cltb);
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