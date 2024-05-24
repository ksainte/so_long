/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksainte <ksainte@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 13:41:40 by ksainte           #+#    #+#             */
/*   Updated: 2024/05/24 16:19:31 by ksainte          ###   ########.fr       */
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

// int	main(int argc, char **argv)
int	main()
{
	int		fd;
	// char *path;
	size_t 	row_size;
	// size_t column_size;
	char *line;
	char **tab;

	// check_arg(argc, argv);
	// path = ft_strjoin("./maps/", argv[1]);
	// printf("path is %s", path);
    fd = open("test.txt", O_RDONLY);
    row_size = 0;
	line = "hey";
    while (line)
    {
        line = get_next_line(fd);
        printf("line is %s",line);
		if (line == 0 || *line == '\n')
			break;
        row_size++;
    }
    close(fd);
	//on doit parse les infos ds un double tableau
	printf("final is %zu\n", row_size);
	tab = calloc(row_size + 1, sizeof(char*));
	fd = open("test.txt", O_RDONLY);
	size_t i = 0;
	while (i < row_size)
	{
		tab[i] = get_next_line(fd);
		i++;
	}
	tab[i] = NULL;
	fd = open("test.txt", O_RDONLY);
	char *str;
	str = get_next_line(fd);
	for (i = 0; i < row_size; i++) {
		printf("%s\n", tab[i]);
    }

}
		// 	fd = open("test.txt", O_RDONLY);
		// size_t a = 0;
		// char *str;
		// str = get_next_line(fd);
		// while(str[a] != '\0')
		// {
		// 	printf("%c",str[a]);
		// 	a++;
		// }
		// for (i = 0; i < row_size; i++) {
		// 	for (size_t k = 0; k < a; k++) {
		// 		printf("%c\n", tab[i][k]);
		// 	}
    	// }