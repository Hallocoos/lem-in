/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rengelbr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 11:28:51 by hde-vos           #+#    #+#             */
/*   Updated: 2020/05/18 16:21:46 by rengelbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/colony.h"

t_links *find_least_visited(t_links *room_links)
{
	t_links *next_link;
	t_links *ret_link;

	ret_link = room_links;
	if (ret_link && ret_link->next)
	{
		next_link = ret_link->next;
		while (next_link)
		{
			if (ret_link->room->visited > next_link->room->visited)
				ret_link = next_link;
			if (next_link->next)
				next_link = next_link->next;
			else
				return (ret_link);
		}
	}
	return (ret_link);
}

void algo(t_log *node_array)
{
	t_room 	*current_room;
	t_room 	*previous_room;
	t_links *temp_links;

	current_room = node_array->rooms[node_array->start_index];

	ft_putstr("Name: ");
	ft_putstr(current_room->name);
	ft_putstr("; Type: ");
	ft_putnbr(current_room->room_type);
	ft_putstr("\n");
	while (current_room->room_type != 1 && current_room->room_links->room)
	{
		previous_room = current_room;
		// ft_putstr("previous_room Name: ");
		// ft_putstr(previous_room->name);
		// ft_putstr("; previous_room Type: ");
		// ft_putnbr(previous_room->room_type);
		// ft_putstr("\n");
		// ft_putstr("asdf\n");
		current_room = find_least_visited(current_room->room_links)->room;
		current_room->visited++;
		ft_putstr("Name: ");



		ft_putstr(current_room->name);



		// ft_putstr(" ");
		// ft_putstr(current_room->y);
		ft_putstr("; Type: ");
		ft_putnbr(current_room->room_type);
		ft_putstr("\n");

		// ft_putstr("zxcv\n");
		if (!current_room->room_links && current_room->room_type != 1)
		{
			free_room(current_room);
			if (previous_room->room_links->next)
				temp_links = previous_room->room_links->next;
			free(previous_room->room_links);
			previous_room->room_links = temp_links;

			current_room = node_array->rooms[node_array->start_index];

			ft_putstr("Name: ");
			ft_putstr(current_room->name);
			ft_putstr("; Type: ");
			ft_putnbr(current_room->room_type);
			ft_putstr("\n");
		}
	}
}
