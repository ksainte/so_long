/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksainte <ksainte@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 13:37:29 by ksainte           #+#    #+#             */
/*   Updated: 2024/05/23 15:01:18 by ksainte          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "./Libft/libft.h"
#include "./gnl/get_next_line.h"
# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
#include <stdio.h>
# include <mlx.h>
# include <fcntl.h>
# include <errno.h>

// //I highly recommend using stack-allocated memory as much as possible, as it will make your life so much easier when you need to exit the program.
// typedef struct s_data
// {
// 	void		*mlx_ptr; // MLX pointer
// 	void		*win_ptr; // MLX window pointer
// 	void		*textures[5]; // MLX image pointers (on the stack)
// 	//t_map		*map; // Map pointer (contains map details - preferably kept on the stack)
// }	t_data;

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

/* all info needed for an image */
typedef struct	s_image {
	void		*reference;
	t_vector	size;
	char		*pixels;
	int			bits_per_pixel;
	int			line_size;
	int			endian;
}				t_image;
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

typedef struct	s_program {
	void		*mlx;
	t_window	window;
	t_image		sprite;
	t_vector	sprite_position;
	t_wall_img	wall_imgs;
	t_vector	img_size;
}				t_program;

typedef struct t_struct
{
	char	**map;
	char	path[1];
	int		isize[2];
	size_t	item;
	size_t	mpos[2];
	size_t	ppos[2];
}	t_map;

typedef struct t_struct1
{
	char	**map;
	int		dir[2];
	int		isize[2];
	int		move;
	size_t	item;
	size_t	ipos[2];
	size_t	ppos[2];
	void	*img;
	void	*mlx_p;
	void	*mlx_w;
}	t_hook;

t_window	ft_new_window(void *mlx, int widht, int height, char *name);
t_image		ft_new_sprite(void *mlx, char *path);
void	open_wallimgs_up(t_program *game);
void	open_wallimgs_down(t_program *game);


t_color		new_color(int r, int g, int b, int a);
void		turn_img_to_color(t_image *image, t_color color);

int			ft_input(int key, void *program);
int			ft_update (void *param);
#endif