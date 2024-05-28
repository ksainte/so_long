/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksainte <ksainte@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 15:58:19 by ksainte           #+#    #+#             */
/*   Updated: 2024/05/28 19:38:27 by ksainte          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include"../so_long.h"

// static	void	check_arg(int ac, char **argv)
// {
// 	if (ac < 2 || argv[1] == NULL)
// 	{
// 		ft_printf("Erreur\nCarte manquante : ./so_long <map>\n");
// 		exit(EXIT_FAILURE);
// 	}
// 	return ;
// }


static	void ft_has_valid_path(t_map *map, int x, int y)
{
	
	if(map->tmp[x][y] == 'E')
		map->has_exit = 1;
	if(map->tmp[x][y] == 'C')
		map->has_all_cltb--;
	//valid paths on the way, if you can reach C and E through it youre good to go
	if(map->tmp[x][y] == '0' || map->tmp[x][y] == 'C' || map->tmp[x][y] == 'E' || map->tmp[x][y] == 'P')
	{
		map->tmp[x][y] = '2';
		ft_has_valid_path(map, x - 1, y);
		ft_has_valid_path(map, x + 1, y);
		ft_has_valid_path(map, x, y - 1);
		ft_has_valid_path(map, x, y + 1);  
	}
}
void ft_init_tmp(t_map *map)
{
	int x;

	x = 0;
	map->tmp = ft_calloc(map->row + 1, sizeof(char*));
	while(map->tab[x])
	{
			map->tmp[x] = ft_strdup(map->tab[x]);
			x++;
	}
	map->tmp[x]= NULL;
}

void ft_valid_map(t_map *map)
{
	
	if (ft_is_rectangular(map) && ft_has_walls(map) && ft_char_is_legit(map))
	{
		printf("\nmap is ok");
	}
	else
	{
		printf("\nmap is not ok");
		ft_error();
	}
	map->has_all_cltb = map->counter_cltb;
	ft_init_tmp(map);
	ft_has_valid_path(map, map->starting_x, map->starting_y);
	if(map->has_exit == 1 && map->has_all_cltb == 0)
		printf("\nmap has valid path");
	else
		printf("\npath is invalid");
}

void ft_row_number(t_map *map)
{
    
    map->fd = open("test.txt", O_RDONLY);
	map->line = (char *)malloc(sizeof(char*));
    while (map->line != NULL)
    {
		if (map->line)
			free(map->line);
        map->line = get_next_line(map->fd);
		if (map->line == 0 || *map->line == '\n')
			break;
        map->row++;
    }
	while(map->line != 0){
		free(map->line);
		map->line = get_next_line(map->fd);
		if (map->line && map->line[0] != '\n')
		{
			printf("exit\n");
			free(map->line);
			ft_error();
		}
	}
	free(map->line);
    map->return_value = close(map->fd);
    if(map->return_value == -1)
        printf("Error\n");
}

void ft_fill_tab(t_map *map)
{
    char *tmp;
	char *tmp1;
    size_t   i;

    i = 0;
	map->tab = calloc(map->row + 1, sizeof(char*));
	map->fd = open("test.txt", O_RDONLY);
	while (i < map->row)
	{
		map->tab[i] = get_next_line(map->fd);
		tmp = map->tab[i];
		map->tab[i] = ft_strtrim(map->tab[i], "\n");
		tmp1 = map->tab[i];
		map->tab[i] = ft_strtrim_end(map->tab[i], " ");
		free(tmp);
		free(tmp1);
		// printf("%s", map->tab[i]);
		i++;
	}
	map->tab[i] = NULL;
	map->return_value = close(map->fd);
    if(map->return_value == -1)
        printf("Error\n");
}

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

void ft_init_window(t_program *program, t_map *map)
{
	
	program->mlx = mlx_init();
	program->lenght = map->row_size * 64;
	program->height = map->row * 64;
	if(program->lenght > 2560 || program->height > 1440)
		ft_error();
	program->window = ft_new_window(program->mlx, program->lenght, program->height, "Hello world!");
	ft_paste_walls(program, map);
	ft_paste_cltbs(program, map);
	ft_paste_exit(program, map);
	ft_paste_start(program, map);
}

// int	main(int argc, char **argv)
int	main()
{
    static t_map   map;
	t_program 	program;
	// char *path;


	// check_arg(argc, argv);
	// path = ft_strjoin("./maps/", argv[1]);
    ft_row_number(&map);
	// printf("\nthere is %d rows\n\n", map.row);
    ft_fill_tab(&map);
	ft_valid_map(&map);
	ft_init_window(&program, &map);
	mlx_loop(program.mlx);
	free_table(map.tab);
	free_table(map.tmp);
	system("leaks -q -fullContent $(ps -o pid= -p $PPID)");
}

//-fsanitize=address
//CC = gcc -g -g3