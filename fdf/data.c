/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omeyer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/02 10:41:34 by omeyer            #+#    #+#             */
/*   Updated: 2017/07/02 15:46:23 by omeyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

void	push_back(t_point data, int n, t_node **head)
{
	t_node	*temp1;
	t_node	*temp2;
	int		i;

	temp1 = (t_node*)malloc(sizeof(t_node));
	temp1->data = data;
	temp1->next = NULL;
	if (n == 1)
	{
		temp1->next = *head;
		*head = temp1;
		return;
	}
	temp2 = *head;
	i = 0;
	while (i < n - 2)
	{
		temp2 = temp2->next;
		i++;
	}
	temp1->next = temp2->next;
	temp2->next = temp1;
}

int		list_len(t_node **head)
{
	int		i;
	t_node	*temp;

	i = 0;
	temp = *head;
	while (temp != NULL)
	{
		i++;
		temp = temp->next;
	}
	return (i);
}

int		file_handler(char *filename, t_node **head)
{
	int		fd;
	int		max_x;

	max_x = 0;
	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		ft_putstr(filename);
		ft_putstr("  does not exist. Please insert a valid filname\n");
		return (-1);
	}
	max_x = get_data(head, fd, max_x);
	if (fd == -1)
	{
		ft_putstr(filename);
		ft_putstr(" did not close correctly\n");
		return (-1);
	}
	return (max_x);
}

int		get_data(t_node **head, int fd, int max_x)
{
	char		*line;
	char		**split_line;
	t_point		temp_pnt;
	int			cnt;
	int			flag;

	flag = 0;
	cnt = 1;
	temp_pnt.y = 0;
	while (get_next_line(fd, &line) == 1)
	{
		split_line = ft_strsplit(line, ' ');
		temp_pnt.x = 0;
		while (split_line[(int)temp_pnt.x])
		{
			temp_pnt.z = (double)ft_atoi(split_line[(int)temp_pnt.x]);
			push_back(temp_pnt, cnt, &(*head));
			cnt++;
			temp_pnt.x++;
		}
		(flag++ == 0 ? max_x = (int const)temp_pnt.x : 0);
		temp_pnt.y++;
		free(line);
	}
	return (max_x);
}
