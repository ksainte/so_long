/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paste.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksainte <ksainte@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 11:12:11 by ksainte           #+#    #+#             */
/*   Updated: 2024/05/31 12:39:02 by ksainte          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../so_long.h"


void ft_paste_walls(t_program *program, t_map *map)
{
	size_t x;
    size_t y;
	
	program->sprite_position.x = 0;
	program->sprite_position.y = 0;
	program->sprite = ft_new_sprite(program->mlx, "block.xpm");
    x = 0;
    while(x < map->row)
    {
     y = 0;
     while(y < map->row_size)
     {
         if(map->tab[x][y] == '1')
		 {
			mlx_put_image_to_window(program->mlx, program->window.reference,
			program->sprite.reference, program->sprite_position.x, program->sprite_position.y);
		 }
		program->sprite_position.x += 64;//avance de 1 dans l axe des x
		program->sprite_position.y = program->sprite_position.y;//reste sur l axe des y
		 y++;
     }
	 program->sprite_position.y +=64;//descends de 1 dans l axe des y
	 program->sprite_position.x = 0;//repars a 1 dans l axe des x
	 x++;
    }
}

void ft_paste_cltbs(t_program *program, t_map *map)
{
	size_t x;
    size_t y;
	
	program->sprite_position.x = 0;
	program->sprite_position.y = 0;
	program->sprite = ft_new_sprite(program->mlx, "enemy_01.xpm");
    x = 0;
    while(x < map->row)
    {
     y = 0;
     while(y < map->row_size)
     {
         if(map->tab[x][y] == 'C')
		 {
			mlx_put_image_to_window(program->mlx, program->window.reference,
			program->sprite.reference, program->sprite_position.x, program->sprite_position.y);
		 }
		program->sprite_position.x += 64;//avance de 1 dans l axe des x
		program->sprite_position.y = program->sprite_position.y;//reste sur l axe des y
		 y++;
     }
	 program->sprite_position.y +=64;//descends de 1 dans l axe des y
	 program->sprite_position.x = 0;//repars a 1 dans l axe des x
	 x++;
    }
}
void ft_paste_exit(t_program *program, t_map *map)
{
	size_t x;
    size_t y;
	
	program->sprite_position.x = 0;
	program->sprite_position.y = 0;
	program->sprite = ft_new_sprite(program->mlx, "door_01.xpm");
    x = 0;
    while(x < map->row)
    {
     y = 0;
     while(y < map->row_size)
     {
         if(map->tab[x][y] == 'E')
		 {
			mlx_put_image_to_window(program->mlx, program->window.reference,
			program->sprite.reference, program->sprite_position.x, program->sprite_position.y);
		 }
		program->sprite_position.x += 64;//avance de 1 dans l axe des x
		program->sprite_position.y = program->sprite_position.y;//reste sur l axe des y
		 y++;
     }
	 program->sprite_position.y +=64;//descends de 1 dans l axe des y
	 program->sprite_position.x = 0;//repars a 1 dans l axe des x
	 x++;
    }
}
void ft_paste_start(t_program *program, t_map *map)
{
	size_t x;
    size_t y;
	
	program->sprite_position.x = 0;
	program->sprite_position.y = 0;
	program->sprite = ft_new_sprite(program->mlx, "effect_w.xpm");
    x = 0;
    while(x < map->row)
    {
     y = 0;
     while(y < map->row_size)
     {
         if(map->tab[x][y] == 'P')
		 {
			mlx_put_image_to_window(program->mlx, program->window.reference,
			program->sprite.reference, program->sprite_position.x, program->sprite_position.y);
		 }
		program->sprite_position.x += 64;//avance de 1 dans l axe des x
		program->sprite_position.y = program->sprite_position.y;//reste sur l axe des y
		 y++;
     }
	 program->sprite_position.y +=64;//descends de 1 dans l axe des y
	 program->sprite_position.x = 0;//repars a 1 dans l axe des x
	 x++;
    }
}
void ft_paste_bg(t_program *program, t_map *map)
{
	size_t x;
    size_t y;
	
	program->sprite_position.x = 0;
	program->sprite_position.y = 0;
	program->sprite = ft_new_sprite(program->mlx, "Background.xpm");
    x = 0;
    while(x < map->row)
    {
     y = 0;
     while(y < map->row_size)
     {
		mlx_put_image_to_window(program->mlx, program->window.reference,
		program->sprite.reference, program->sprite_position.x, program->sprite_position.y);
		program->sprite_position.x += 64;//avance de 1 dans l axe des x
		program->sprite_position.y = program->sprite_position.y;//reste sur l axe des y
		 y++;
     }
	 program->sprite_position.y +=64;//descends de 1 dans l axe des y
	 program->sprite_position.x = 0;//repars a 1 dans l axe des x
	 x++;
    }
}