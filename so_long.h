/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksainte <ksainte@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 13:37:29 by ksainte           #+#    #+#             */
/*   Updated: 2024/05/30 14:42:10 by ksainte          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "./Libft/libft.h"
#include "./get_next_line.h"
# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
#include <stdio.h>
# include <mlx.h>
# include <fcntl.h>
# include <errno.h>
# include <string.h>

// //I highly recommend using stack-allocated memory as much as possible, as it will make your life so much easier when you need to exit the program.
// typedef struct s_data
// {
// 	void		*mlx_ptr; // MLX pointer
// 	void		*win_ptr; // MLX window pointer
// 	void		*textures[5]; // MLX image pointers (on the stack)
// 	//t_map		*map; // Map pointer (contains map details - preferably kept on the stack)
// }	t_data;

# define LENGTH 400
# define HEIGHT 100

# ifndef ANIMATION_FRAMES
#  define ANIMATION_FRAMES 10
# endif

/* vector with an x and y */
typedef struct	s_vector
{
	int	x;
	int	y;
}				t_vector;

/* A pointer to the window and its size */
typedef struct	s_window {
	void		*reference;
	t_vector	size;
}				t_window;

/* The 4 values that define a color */
typedef struct s_color {
	int	r;
	int g;
	int b;
	int a;
}	t_color;

/* All posible wall images */
typedef struct s_wall_img
{
	void	*block;
	void	*up_left;
	void	*up;
	void	*up_right;
	void	*right;
	void	*down_right;
	void	*down;
	void	*down_left;
	void	*left;
}	t_wall_img;

/* all info needed for an image */
typedef struct	s_image {
	void		*reference;
	void		*reference_bgd;
	t_vector	size;
	char		*pixels;
	int			bits_per_pixel;
	int			line_size;
	int			endian;
}				t_image;

typedef struct t_struct
{
	char	**tab;
	char	**tmp;
	char 	*line;
	size_t 	row;
	int		fd;
	int		return_value;
	size_t	row_size;
	int 	counter_cltb;
	int 	counter_exit;
	int 	counter_pos;
	int		starting_x;
	int		starting_y;
	int		has_exit;
	int		has_all_cltb;
}	t_map;

typedef struct	s_program {
	void		*mlx;
	t_window	window;
	t_image		sprite;
	t_image		sprite2;//la structure(&?)
	t_map		*map;//un pointeur sur une struct de type t_map
	t_vector	sprite_position;
	t_wall_img	wall_imgs;
	t_vector	img_size;
	size_t		lenght;
	size_t		height;
}				t_program;


t_window	ft_new_window(void *mlx, int widht, int height, char *name);
t_image		ft_new_sprite(void *mlx, char *path);
void		open_wallimgs_up(t_program *game);
void		open_wallimgs_down(t_program *game);
char		*ft_strtrim_end(char const *s1, char const *set);
int 		ft_is_rectangular(t_map *map);
int 		ft_has_walls(t_map *map);
int 		char_check(char c, t_map *map);
int 		ft_char_is_legit(t_map *map);
int 		ft_n_in_line(char *str);
void		free_table(char **buffer);
void		ft_error(void);
t_image ft_bgd_sprite(void *mlx, char *path);


t_color		new_color(int r, int g, int b, int a);
void		turn_img_to_color(t_image *image, t_color color);

int			ft_input(int key, void *program);
int			ft_update (void *param);
#endif