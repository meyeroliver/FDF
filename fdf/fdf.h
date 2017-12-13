/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omeyer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/26 11:27:32 by omeyer            #+#    #+#             */
/*   Updated: 2017/07/02 17:50:25 by omeyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# define SCALE 10
# define X_SHIFT 600
# define Y_SHIFT 200

# include "libft/libft.h"
# include <math.h>
# include "mlx.h"

typedef struct		s_point
{
	double			x;
	double			y;
	double			z;
}					t_point;

typedef struct		s_node
{
	t_point			data;
	struct s_node	*next;
}					t_node;

typedef struct		s_delta
{
	double			x;
	double			y;
}					t_delta;

typedef struct		s_move
{
	double			x;
	double			y;
}					t_move;

typedef struct		s_vector
{
	t_move			mv;
	t_delta			d;
}					t_vector;

void				push_back(t_point data, int n, t_node **head);
int					list_len(t_node **head);
int					get_data();
int					file_handler(char *filename, t_node **head);
void				cart_to_iso(t_node **head);
int					key_event(int key_pressed);
void				d_point(void *mlx, void *win, t_node **head, int colour);
void				dh_line(void *mlx, void *win, t_node **head, int max_x);
void				dv_line(void *mlx, void *win, t_node **head, int max_x);
void				fdf(char *filename);

#endif
