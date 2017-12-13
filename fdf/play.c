/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omeyer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/28 08:48:24 by omeyer            #+#    #+#             */
/*   Updated: 2017/07/02 18:17:47 by omeyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		key_event(int key_pressed)
{
	if (key_pressed == 53)
		exit(0);
	return (0);
}

void	d_point(void *mlx, void *win, t_node **head, int colour)
{
	t_node	*temp;

	temp = *head;
	while (temp != NULL)
	{
		mlx_pixel_put(mlx, win, (int)temp->data.x, (int)temp->data.y, colour);
		temp = temp->next;
	}
}

void	connecter(void *mlx, void *win, t_node *p0, t_node *p1)
{
	t_vector	vec;
	t_move		step;
	double		crawl;
	int			i;

	if ((vec.d.x = (p1->data.x - p0->data.x))
			> (vec.d.y = (p1->data.y - p0->data.y)))
		crawl = fabs(vec.d.x);
	else
		crawl = fabs(vec.d.y);
	vec.mv.x = vec.d.x / crawl;
	vec.mv.y = vec.d.y / crawl;
	step.x = p0->data.x;
	step.y = p0->data.y;
	i = 0;
	while (i < crawl)
	{
		step.x = step.x + vec.mv.x;
		step.y = step.y + vec.mv.y;
		mlx_pixel_put(mlx, win, (int)step.x, (int)step.y, 0x00FFFF00);
		i++;
	}
}

void	dh_line(void *mlx, void *win, t_node **head, int max_x)
{
	t_node	*p0;
	t_node	*p1;
	int		j;

	p0 = *head;
	p1 = p0->next;
	j = 1;
	while (p1 != NULL)
	{
		connecter(mlx, win, p0, p1);
		if (p1->next != NULL)
		{
			p0 = p0->next;
			p1 = p1->next;
		}
		if (j == max_x - 1)
		{
			p0 = p0->next;
			p1 = p1->next;
			j = 0;
		}
		j++;
	}
}

void	dv_line(void *mlx, void *win, t_node **head, int max_x)
{
	t_node		*p0;
	t_node		*p1;
	t_point		pnt;

	p0 = *head;
	p1 = *head;
	pnt.z = 0;
	while (pnt.z < (list_len(head) / max_x) - 1)
	{
		pnt.y = 0;
		while (pnt.y < max_x)
		{
			pnt.x = 0;
			while (pnt.x < max_x)
			{
				p1 = p1->next;
				pnt.x++;
			}
			connecter(mlx, win, p0, p1);
			p0 = p0->next;
			p1 = p0;
			pnt.y++;
		}
		pnt.z++;
	}
}
