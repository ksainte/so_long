/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksainte <ksainte@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 15:58:19 by ksainte           #+#    #+#             */
/*   Updated: 2024/05/31 13:45:20 by ksainte          ###   ########.fr       */
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

void ft_init_window(t_program *program, t_map *map)
{
	
	program->mlx = mlx_init();
	program->lenght = map->row_size * 64;
	program->height = map->row * 64;
	if(program->lenght > 2560 || program->height > 1440)
		ft_error();
	program->window = ft_new_window(program->mlx, program->lenght, program->height, "Hello world!");
	ft_paste_bg(program, map);
	ft_paste_walls(program, map);
	ft_paste_cltbs(program, map);
	ft_paste_exit(program, map);
	// ft_paste_start(program, map);
}

void ft_init_player(t_program *program, t_map *map)
{
	program->sprite = ft_new_sprite(program->mlx, "player_01.xpm");
    program->sprite_position.x = map->starting_y * 64;
    program->sprite_position.y = map->starting_x * 64;
	program->map = map;//assignation a un pointeur sur structure de type t_map, l'& d une structure t_map
	// printf("\n4 is %p", map);//adresse sur lequel le pointeur pointe
	// printf("\n5 is %p\n", &map);//adresse du pointeur lui meme
	// printf("6 is %p\n", program->map);//
	// printf("\nx og is %d\n", map->starting_x);
	// printf("y og is %d\n", map->starting_y);
	// program->input_position.x = map->starting_x;//ligne
	// program->input_position.y = map->starting_y;//colonne
    mlx_put_image_to_window(program->mlx, program->window.reference,
        program->sprite.reference, program->sprite_position.x, program->sprite_position.y);
	// mlx_key_hook(program->window.reference, *ft_input, program);
	mlx_hook(program->window.reference, 2,0,*ft_input, program);
}
// int ft_valid_path(t_map *map, int x, int y, int counter_cltb, int has_exit)
// {	

// 	if(has_exit == 0 && counter_cltb == 0)
// 		return(1);
// 	if(map->tmp[x][y] == 'E')
// 		has_exit = 0;
// 	if(map->tmp[x][y] == 'C')
// 		counter_cltb--;
// 	//valid paths on the way, if you can reach C and E through it youre good to go
// 	if(map->tmp[x][y] == '0' || map->tmp[x][y] == 'C' || map->tmp[x][y] == 'E' || map->tmp[x][y] == 'P')
// 	{
// 		map->tmp[x][y] = '2';
// 		ft_valid_path(map, x - 1, y, counter_cltb, has_exit);
// 		ft_valid_path(map, x + 1, y, counter_cltb, has_exit);
// 		ft_valid_path(map, x, y - 1, counter_cltb, has_exit);
// 		ft_valid_path(map, x, y + 1, counter_cltb, has_exit);  
// 	}
// 	return(0);
// }
// int ft_spawn(t_map *map)
// {
// 	int x;
// 	int y;
	
// 	x = 1;
// 	while(map->tab[x])
// 	{
// 		y = 1;
// 		while(map->tab[x][y])
// 		{
// 			if(map->tab[x][y] == '0' && ft_valid_path(map, x, y, map->counter_cltb, map->has_exit))
// 			{
// 				map->starting_x = x;
// 				map->starting_y = y;
// 				return(0);	
// 			}
// 			y++;
// 		}
// 		x++;
// 	}
// 	return(1);
// }

// void ft_init_enemy(t_program *program, t_map *map)
// {
// 	t_image img;

// 	img.reference_enmy = mlx_xpm_file_to_image(program->mlx,"player_01.xpm", &img.size.x, &img.size.y);
// 	// program->sprite = ft_new_sprite(program->mlx, "block.xpm");
// 	ft_init_tmp(map);
// 	ft_spawn(map);
//     program->enmy_sprite_position.x = map->starting_y * 64;
//     program->enmy_sprite_position.y = map->starting_x * 64;
// 	printf("\n%d\n", map->starting_x);
// 	printf("%d\n", map->starting_y);
// 	// mlx_put_image_to_window(program->mlx, program->window.reference,
// 	// 	img.reference_enmy, program->enmy_sprite_position.x, program->enmy_sprite_position.y);
// 	// mlx_key_hook(program->window.reference, *ft_input, program);
// 	// mlx_hook(program->window.reference, 2,0,*ft_input, program);
// }


// int	main(int argc, char **argv)
int	main()
{
    static t_map   map;
	t_program 	program;
	// char *path;
	
	// printf("\n6 is %p\n", &map);
	//envoie a un pointeur t_map *map, tu envoies l'& de la structure, le receptacle est une adresse(auto genere par)
	//la fonction qui va pointer sur ta structure, pour acceder aux valeurs de cette structure a partir du pointeur,
	//utilise une ->

	// check_arg(argc, argv);
	// path = ft_strjoin("./maps/", argv[1]);
    ft_row_number(&map);
	// printf("\nthere is %d rows\n\n", map.row);
    ft_fill_tab(&map);
	ft_valid_map(&map);
	ft_init_window(&program, &map);
	ft_init_player(&program, &map);
	// ft_init_enemy(&program, &map);
	mlx_loop(program.mlx);
	free_table(map.tab);
	free_table(map.tmp);
	system("leaks -q -fullContent $(ps -o pid= -p $PPID)");
}

//-fsanitize=address
//CC = gcc -g -g3