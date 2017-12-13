/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cart_to_iso.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omeyer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/02 10:16:25 by omeyer            #+#    #+#             */
/*   Updated: 2017/07/02 14:53:24 by omeyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	cart_to_iso(t_node **head)
{
	t_node	*temp;
	t_point	pnt;

	temp = *head;
	while (temp != NULL)
	{
		pnt.x = temp->data.x;
		pnt.y = temp->data.y;
		temp->data.x = (X_SHIFT + temp->data.x * SCALE)
			- ((Y_SHIFT + pnt.y * SCALE));
		temp->data.y = ((Y_SHIFT + temp->data.y * SCALE)
				+ (X_SHIFT + pnt.x * SCALE)) / 2;
		if (temp->data.z >= 0)
			temp->data.y = temp->data.y - (temp->data.z * SCALE);
		else
			temp->data.y = temp->data.y + (temp->data.z * SCALE);
		temp = temp->next;
	}
}
