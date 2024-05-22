/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksainte <ksainte@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 13:41:40 by ksainte           #+#    #+#             */
/*   Updated: 2024/05/22 14:14:27 by ksainte          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../so_long.h"

int main()
{
	t_program program;
	// mlx function that initialize the mlx and returns a pointer to it.
	program.mlx = mlx_init();
	// Open a window (window.c whitin this project)
	program.window = ft_new_window(program.mlx, 1980, 1080, "Hello world!");

	// Create a new image/sprite (image.c)
	program.sprite = ft_new_sprite(program.mlx, "block.xpm");
	program.sprite_position.x = 0;
	program.sprite_position.y = 0;
	// mlx function that draws an image into a window at the given position
	mlx_put_image_to_window(program.mlx, program.window.reference,
		program.sprite.reference, program.sprite_position.x, program.sprite_position.y);
	// hook the input() (hooks.c) function to the the key pressed event
	mlx_key_hook(program.window.reference, *ft_input, &program);
	// hook a function to the loop (it would be called each frame)
	mlx_loop_hook(program.mlx, *ft_update, &program);

	mlx_loop(program.mlx);
}
