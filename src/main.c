/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksainte <ksainte@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 13:41:40 by ksainte           #+#    #+#             */
/*   Updated: 2024/05/27 12:45:04 by ksainte          ###   ########.fr       */
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

int ft_is_rectangular(char **tab){
	
	size_t len_first;
	int i;

	len_first = ft_strlen(tab[0]);
	i = 0;
	while(tab[i]){
		if(len_first == ft_strlen(tab[i])){
			printf("\ni is :%d\n",i);
            printf("len is : %zu\n",ft_strlen(tab[i]));
            printf("%s",tab[i]);
			i++;
		}
		else{
			printf("\nis not rectangular");
			return(0);
		}
	}
	return(1);
}

int ft_has_walls(char **tab, int row_size){
	
	int x;
	int y;
	
	x = 0;
	// printf("\n row_size is %d", row_size);
	int len = ft_strlen(tab[0]);
	while(tab[x])
	{
		if(tab[x][0] == '1' && tab[x][len - 1] == '1')
			x++;
		else
			return(0);
	}
	y = 0;
	while(tab[0][y])
	{
		if(tab[0][y] == '1')
			y++;
		else
			return(0);
	}
	y = 0;
	while(tab[row_size - 1][y])
	{
		if(tab[row_size - 1][y] == '1')
			y++;
		else
			return(0);
	}
	return(1);
}

int ft_is_legit(char **tab){
	
	int x;
	int y;
	int counter_cltb = 0;
	int counter_exit = 0;
	int counter_pos = 0;

	x = 0;
	while(tab[x])
	{
		y = 0;
		while(tab[x][y])
		{
			if (tab[x][y] != '0' && tab[x][y] != '1' && tab[x][y] != 'E' && tab[x][y] != 'C' && tab[x][y] != 'P')
				return(0);
			if (tab[x][y] == 'E')
			{
				counter_exit++;
				if(counter_exit > 1)
					return(0);
			}
			if (tab[x][y] == 'C')
				counter_cltb++;
			if (tab[x][y] == 'P')
			{	
				counter_pos++;
				if(counter_pos > 1)
					return(0);
			}
			y++;
		}
	x++;
	}
	if(counter_exit == 0 || counter_cltb == 0 || counter_pos == 0)
			return(0);
	return(1);
}

void ft_valid_map(char **tab, int row_size){
	
	if (ft_is_rectangular(tab))
		printf("\n is rectangular ok");
	if (ft_has_walls(tab, row_size))
		printf("\n has walls ok");
	if (ft_is_legit(tab))
		printf("\n has valid char ok");
	else
		printf("\nmap not ok");
}

int ft_n_in_line(char *str)
{
	
	int i;

	i = 0;
	while(str[i])
	{
		if(str[i] == '\n')
			return(1);
		i++;
	}
	return(0);
	
}
void	free_table(char **buffer)
{
	int	i;

	i = -1;
	while (buffer[++i] != NULL)
		free(buffer[i]);
	free(buffer);
}

// int	main(int argc, char **argv)
int	main()
{
	int		fd;
	// char *path;
	size_t 	row_size;
	// size_t 	tot_size;
	// // size_t column_size;
	char *line;
	// char *line2;
	char **tab;

	// check_arg(argc, argv);
	// path = ft_strjoin("./maps/", argv[1]);
	// printf("path is %s", path);
	
    fd = open("test.txt", O_RDONLY);
    row_size = 0;
	line = (char *)malloc(sizeof(char*));
    while (line != NULL)
    {
		if (line)
			free(line);
        line = get_next_line(fd);
        // printf("line is %s",line);
		if (line == 0 || *line == '\n')
		{
			// printf("line is %s\n",line);
			break;
		}
        row_size++;
    }
	while(line != 0){
		// printf("Enters here\n");
		//prochain \n
		free(line);
		line = get_next_line(fd);
		// printf("yooooo %s|\n", line);
		if (line && line[0] != '\n')
		{
			printf("exit\n");
			free(line);
			return(1);
		}
	}
	free(line);
	// system("leaks -q -fullContent $(ps -o pid= -p $PPID)");
	int z = 0;
	z = close(fd);
	
	printf("\nfinal is %zu\n\n", row_size);
	
	tab = calloc(row_size + 1, sizeof(char*));
	// tab = (char**)malloc(row_size + 1 * sizeof(char*));
	fd = open("test.txt", O_RDONLY);
	size_t i = 0;
	// row_size = 6;
	char *tmp;
	while (i < row_size)
	{
		tab[i] = get_next_line(fd);
		tmp = tab[i];
		tab[i] = ft_strtrim(tab[i], "\n");
		tab[i] = ft_strtrim_end(tab[i], " ");
		free(tmp);
		printf("%s", tab[i]);
		i++;
	}
	tab[i] = NULL;
	close(fd);
	// system("leaks -q -fullContent $(ps -o pid= -p $PPID)");
	ft_valid_map(tab, row_size);
	free_table(tab);
	// system("leaks -q -fullContent $(ps -o pid= -p $PPID)");
}