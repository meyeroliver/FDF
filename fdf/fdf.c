/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omeyer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/02 10:10:52 by omeyer            #+#    #+#             */
/*   Updated: 2017/07/02 17:17:12 by omeyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	fdf(char *filename)
{
	void	*mlx;
	void	*win;
	t_node	*head;
	int		max_x;

	head = NULL;
	max_x = file_handler(filename, &head);
	mlx = mlx_init();
	win = mlx_new_window(mlx, 1000, 1000, "FDF.C");
	cart_to_iso(&head);
	d_point(mlx, win, &head, 0x00FFFF00);
	dh_line(mlx, win, &head, max_x);
	dv_line(mlx, win, &head, max_x);
	mlx_key_hook(win, key_event, 0);
	mlx_loop(mlx);
}
