/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksainte <ksainte@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 13:41:40 by ksainte           #+#    #+#             */
/*   Updated: 2024/05/24 21:30:35 by ksainte          ###   ########.fr       */
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
			// printf("\ni is :%d\n",i);
            // printf("len is : %zu\n",ft_strlen(tab[i]));
            // printf("%s",tab[i]);
			i++;
		}
		else{
			//  printf("\nlen is : %zu",ft_strlen(tab[i]));
				return(0);
			}
	}
	return(1);
}

void ft_valid_tab(char **tab){
	
	if (ft_is_rectangular(tab))
		printf("\nok");
	else
		printf("\nnot ok");
}
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
        printf("\nline is %s",line);
		if (line == 0)
			break;
        row_size++;
    }
    close(fd);
	//on doit parse les infos ds un double tableau
	printf("\nfinal is %zu\n\n", row_size);
	tab = calloc(row_size + 1, sizeof(char*));
	fd = open("test.txt", O_RDONLY);
	size_t i = 0;
	while (i < row_size)
	{
		tab[i] = get_next_line(fd);
		i++;
	}
	tab[i] = NULL;
	close(fd);
	i = 0;
	while (tab[i])
	{
		// printf("\ni is :%zu\n",i);
		printf("%s\n",tab[i]);
		i++;
	}
	ft_valid_tab(tab);

}