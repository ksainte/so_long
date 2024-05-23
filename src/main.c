/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksainte <ksainte@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 13:41:40 by ksainte           #+#    #+#             */
/*   Updated: 2024/05/23 15:00:35 by ksainte          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../so_long.h"

static	void	check_arg(int ac, char *str)
{
	if (ac < 2 || str == NULL)
	{
		ft_printf("Erreur\nCarte manquante : ./so_long <map>\n");
		exit(EXIT_FAILURE);
	}
	else if (ac > 2)
	{
		ft_printf("Erreur\nTrop d'arguments : ./so_long <map>\n");
		exit(EXIT_FAILURE);
	}
	while (*str != '.' && *str != '\0')
		str++;
	if (ft_strncmp(".ber", str, 4) != 0 || ft_strlen(str) != 4)
	{
		ft_printf("Erreur\nExtension du fichier carte non valide : <map>.ber");
		exit(EXIT_FAILURE);
	}
	return ;
}
void	mdup(char *arg, t_map *data)
{
	char	*path;
	int		fd;

	path = ft_strjoin("./maps/", arg);
	if (!path)
		exit(EXIT_FAILURE);
	fd = open(path, O_RDONLY);
	free(path);
	if (fd == -1)
		exit_err(errno);
	data->map = minfo(arg, fd);
	printf_tab(data->map);
}

int	main(int ac, char **av)
{
	int		check;
	t_map	data;
	t_hook	disp;

	check_arg(ac, av[1]);
	mdup(av[1], &data);
}
