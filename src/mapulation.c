/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rengelbr <rengelbr@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 13:34:57 by rengelbr          #+#    #+#             */
/*   Updated: 2019/09/20 10:16:17 by rengelbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/colony.h"
#include "../libft/libft.h"
#include <stdio.h>
//finds every link in all_links that references name, returns it in 2d array
char	**get_linked_rooms(t_str name, t_str *all_links)
{
	unsigned int	name_len;
	unsigned int	i;
	unsigned int	j;
	char			**connected;

	name_len = ft_strlen(name);
	i = 0;
	j = 0;
	connected = (char**)malloc(sizeof(char*) * ft_two_d_arrsize(all_links));
	while (all_links[i])
	{
		if (ft_strnstr(all_links[i], name, ft_strlen(all_links[i])))
		{
			connected[j] = ft_strdup(all_links[i]);
			j++;
		}
		i++;
	}
	return (connected);
}

// void	add_room_links(t_room *maze)
int		get_coordinate(t_str room, char type)
{
	int		i;
	int		j;
	int		x_y;
	char	**coordinates;

	i = 0;
	j = 0;
	x_y = 0;
	coordinates = ft_strsplit(room, ' ');
	if (type == 'x')
		x_y = ft_atoi(coordinates[1]);
	else if (type == 'y')
		x_y = ft_atoi(coordinates[2]);
	return (x_y);
}

void	add_room(t_room **maze, t_str room, unsigned int type)
{
	t_room *new_room;

	new_room = malloc(sizeof(t_room));
	new_room->room_type = type;
	new_room->name = get_room_name(room);
	new_room->x = get_coordinate(room, 'x');
	new_room->y = get_coordinate(room, 'y');
	new_room->visited = 0;
	new_room->next = *maze;
	*maze = new_room;
}

t_room	*new_maze(t_str room, unsigned int type)
{
	t_room	*maze;

	maze = malloc(sizeof(t_room));
	maze->room_type = type;
	maze->name = get_room_name(room);
	maze->x = get_coordinate(room, 'x');
	maze->y = get_coordinate(room, 'y');
	maze->visited = 0;
	maze->next = NULL;
	return (maze);
}

//Returns name of room linked to r_name from string link
char *get_linked_name(t_str r_name, t_str link)
{
	t_str *arr_names;

	arr_names = ft_strsplit(link, '-');
	if (ft_strequ(r_name, arr_names[0]))
		return (arr_names[1]);
	if (ft_strequ(r_name, arr_names[1]))
		return (arr_names[0]);
	return (NULL);
}

void	link_rooms(t_room *maze, t_str *links)
{
	t_room	temp;
	t_str	*cur_lnks;
	int		i;

	i = 0;
	cur_lnks = NULL;
	while (maze)
	{
		cur_lnks = get_linked_rooms(maze->name, links);
		maze->room_links = malloc(sizeof(t_room*) * ft_two_d_arrsize(cur_lnks));
		temp = *maze;
		while (!ft_strequ(temp.name, )
	}
}

t_room	*init_rooms(t_log *data)
{
	t_room *maze;
	int i;
	char **cur_links;
	char *room_name;

	maze = NULL;
	i = 0;
	cur_links = (char**)malloc(sizeof(sizeof(char*)));
	room_name = get_room_name(data->rooms[i]);
	cur_links = get_linked_rooms(room_name, data->links);
	while (data->rooms[i])
	{
		if (!maze)
		{
			if (i == data->start_index)
				maze = new_maze(data->rooms[i], 0);
			else if (i == data->end_index)
				maze = new_maze(data->rooms[i], 1);
			else
				maze = new_maze(data->rooms[i], 2);
		}
		else
		{
			if (i == data->start_index)
				add_room(&maze, data->rooms[i], 0);
			else if (i == data->end_index)
				add_room(&maze, data->rooms[i], 1);
			else
				add_room(&maze, data->rooms[i], 2);
		}
		i++;
	}
	return (maze);
}
