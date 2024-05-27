/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksainte <ksainte@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 15:58:19 by ksainte           #+#    #+#             */
/*   Updated: 2024/05/27 18:40:20 by ksainte          ###   ########.fr       */
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
// int ft_has_valid_path(char **tab)
// {
	
// 	return(1)
// }


void ft_valid_map(t_map *map)
{
	
	if (ft_is_rectangular(map) && ft_has_walls(map) && ft_char_is_legit(map))
	{
		printf("\n map is ok");
	}
	else
	{
		printf("\nmap is not ok");
		ft_error();
	}
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
    int   i;

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

// int	main(int argc, char **argv)
int	main()
{
    static t_map   map;
	// char *path;


	// check_arg(argc, argv);
	// path = ft_strjoin("./maps/", argv[1]);
    ft_row_number(&map);
	printf("\nthere is %d rows\n\n", map.row);
    ft_fill_tab(&map);
	ft_valid_map(&map);
	free_table(map.tab);
	system("leaks -q -fullContent $(ps -o pid= -p $PPID)");
}

//-fsanitize=address
//CC = gcc -g -g3