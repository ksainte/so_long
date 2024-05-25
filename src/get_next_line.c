/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksainte <ksainte@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 14:46:50 by ksainte           #+#    #+#             */
/*   Updated: 2024/05/25 16:26:39 by ksainte          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>
#include "../so_long.h"

char	*get_str(char *test, char *buff, char *str)
{
	size_t	i;

	i = 0;
	while (test[i] != '\0' && test[i] != '\n')
		i++;
	//tu sais que le dernier i sera soit sur n soit sur 0
	//si len de 10(i apres i++), ton dernier el est tab[9], puisque tab[10] est NULL et il sort du while
	if (test[i] == '\0')
		str = (char *)malloc(sizeof(char) * (i + 1));
	else if (test[i] == '\n' || i == 0)
		str = (char *)malloc(sizeof(char) * (i + 2));
	if (str == NULL)
		return (NULL);
	//donc si ton tab[10] est un \n par exemple, ton i sera de 10, ton dernier el est tab[9]
	//il va copier les el avant n, donc de 0 a 9 dans memcpy, de tab[0] a tab[9]
	str = ft_memcpy(str, test, i);
	if (test[i] == '\n')
	{
		str[i] = test[i];
		str[i + 1] = '\0';//on boucle le str avec un 0
		ft_memcpy(&buff[0], &test[i + 1], ft_strlen1(test) - i - 1);//on reprend apd de tab[11] pr len - i - 1, donc si len = 20, i = 10 car tab[10] = n,on veut copier el de tab[11] a tab[19], tab[20] etant NULL, on envoie a memcpy 20 - 10 - 1= 9 elements, cp de 0 a 8 avec memcpy 
		ft_bzero(&buff[ft_strlen1(test) - i - 1], BUFFER_SIZE - (ft_strlen1(test) - i - 1));//apd du buff[20 - 10 - 1] donc buff[9], buff[0] a buff[8] etant fill, on paste 0 apd de buff[9], 42 - (20 - 10 - 1) = 42 - 9 = 33, donc 33 zeros a la geule, 9 char etant fill, de 0 a  8, 9 + 33 = 42 el
	}
	// if (test[i] == '\n')
	// {
	// 	str[i] = '\0';
	// 	// str[i + 1] = '\0';//on boucle le str avec un 0
	// 	ft_memcpy(&buff[0], &test[i + 1], ft_strlen1(test) - i - 1);//on reprend apd de tab[11] pr len - i - 1, donc si len = 20, i = 10 car tab[10] = n,on veut copier el de tab[11] a tab[19], tab[20] etant NULL, on envoie a memcpy 20 - 10 - 1= 9 elements, cp de 0 a 8 avec memcpy 
	// 	ft_bzero(&buff[ft_strlen1(test) - i - 1], BUFFER_SIZE - (ft_strlen1(test) - i - 1));//apd du buff[20 - 10 - 1] donc buff[9], buff[0] a buff[8] etant fill, on paste 0 apd de buff[9], 42 - (20 - 10 - 1) = 42 - 9 = 33, donc 33 zeros a la geule, 9 char etant fill, de 0 a  8, 9 + 33 = 42 el
	// }
	else
		str[i] = '\0';
	return (str);
}

void	*ft_bzero(void *s, size_t n)
{
	char	*str;
	size_t	i;

	i = 0;
	str = (char *)s;
	while (i < n)
	{
		str[i] = '\0';
		i++;
	}
	return (str);
}

char	*ft_read_str(int fd, char *buff, char *test)
{
	int		nb_bytes_to_read;
	char	*first_line;
	char	*str;

	nb_bytes_to_read = -1;
	while (!ft_n_present(buff, '\n') && nb_bytes_to_read != 0)
	{
		nb_bytes_to_read = read(fd, buff, BUFFER_SIZE);
		if (nb_bytes_to_read == -1)
		{
			ft_bzero(buff, BUFFER_SIZE);
			free(test);
			return (0);
		}
		buff[nb_bytes_to_read] = '\0';
		if (nb_bytes_to_read != 0)
			test = ft_strjoin1(test, buff);
	}
	str = "salut";
	first_line = get_str(test, buff, str);
	free(test);
	return (first_line);
}

char	*get_next_line(int fd)
{
	static char	buff[BUFFER_SIZE + 1];
	char		*line;
	char		*test;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	test = (char *)malloc(sizeof(char));
	if (test == NULL)
		return (NULL);
	*test = 0;
	if (*buff != 0)
		test = ft_strjoin1(test, buff);
	line = ft_read_str(fd, buff, test);
	if (line == NULL)
		return (NULL);
	if (*line == '\0')
	{
		free(line);
		return (NULL);
	}
	return (line);
}
// int main()
// {
//     int fd;
//     char    *line;
//     int i;

//     fd = open("test.txt", O_RDONLY);
//     i = 0;
//     while (i < 10)
//     {
//         line = get_next_line(fd);
//         printf("%s",line);
//         i++;
//     }
//     close(fd);
//     return (0);
// }

/*

--------------\n
-------------'\0' str[ft_strlen(left_str) + ft_strlen(buff)] = '\0';

ou 
               i
--------------\n  i + 1
str------------'\0' 

strlen :len de test est de 10 qui s arrete a '\0'
sur i = 5 il y a un '\n' avec strlen_n
donc si i = '\n'
je copy paste a partir de i + 1, cpy to dst = 10 - 5 - 1 = 4 elements

--------------------------------------------'\0' o bytes left 

avant -----------\n ----------'\0' fd
apres \n new str ------- '\0' fd

 */