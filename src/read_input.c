/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rengelbr <rengelbr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 07:23:10 by rengelbr          #+#    #+#             */
/*   Updated: 2019/09/10 14:25:16 by rengelbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	This file contains functions that read from standard output the data needed
**	to build the "ant farm". Depending on the input, these functions will call
**	functions from other files to complete the game.
*/

#include "../libft/libft.h"
#include "../includes/colony.h"

#include <stdio.h>

// Checking whether it is a command. By identifying if input has ##
int		is_command(char *line)
{
	if (ft_strnequ(line, "##", 2))
		return (1);
	return (0);
}

// Checking whether input is a room. By checking if wordcount is three.
int		is_room(char *line)
{
	if (ft_wordcount(line, ' ') == 3)
		return (1);
	return (0);
}

// Checking whether if there is a - between numbers. **Could cause negative ants to think it's a link
int		is_link(char *line)
{
	char *str;

	str = line;
	while (*str)
	{
		if (*str == '-')
			return (1);
printf("not link so far\n");
		str++;
	}
	return (0);
}



char	*get_room_name(char *line)
{
	char *retRoomName;
	char** roomName;

	retRoomName = NULL;
	while (get_next_line(0, &line))
	{
		if (ft_wordcount(line, ' ') == 3)
		{
			roomName = ft_strsplit(line, ' ');
			retRoomName = roomName[0];
		}
		printf("%s\n", retRoomName);
	}
	return (retRoomName);
}

t_log		*read_input(char **line)
{
	t_log	*data;
	int start;
	int end;
	int i;
	int j;
	int k;

	data = (t_log*)malloc(sizeof(t_log));
	start = 0;
	end = 0;
	i = 1;
	j = -1;
	k = -1;
	get_next_line(0, line);
	data->ant_amnt = ft_atoi(*line);
printf("ant amnt = %d\n", data->ant_amnt);
	while (get_next_line(0, line))
	{
printf("loop starting\n");
		if (ft_strequ(*line, "##start"))
			start = 1;
		else if (ft_strequ(*line, "##end"))
			end = 1;
		else if (is_room(*line))
		{
			if (start == 1)
			{
				data->start_line = i;
printf("start_line = %d\n", data->start_line);
				start = 0;
			}
			else if (end == 1)
			{
				data->end_line = i;
printf("end_line = %d\n", data->end_line);
				end = 0;
			}
			data->rooms[++j] = malloc(sizeof(char*) * ft_strlen(*line));
			data->rooms[j] = *line;
printf("room = %s\n", data->rooms[j]);
		}
		else if (is_link(*line))
		{
printf("gonna try assign now\n");
			data->links[++k] = malloc(sizeof(char*) * ft_strlen(*line));
			data->links[k] = *line;
printf("links = %s\n", data->links[k]);
		}
		i++;
	}
	return (data);
}

// int		read_input(char **line)
// {
// 	char **rooms;
// 	char **links;
// 	int start;
// 	int end;
// 	int ants_amnt;
// 	int i;
// 	int j;

// 	rooms = (char**)malloc(sizeof(char*) * 256);
// 	links = (char**)malloc(sizeof(char*) * 256);
// 	start = 0;
// 	end = 0;
// 	i = 0;
// 	j = 0;
// 	get_next_line(0, line);
// 	ants_amnt = ft_atoi(*line);
// 	while (get_next_line(0, line))
// 	{
// 		if (is_command(*line))
// 		{
// 			if (ft_strequ(*line, "##start"))
// 				start = 1;
// 			else if (ft_strequ(*line, "##end"))
// 				end = 1;
// 		}
// 		else if (is_room(*line))
// 			rooms[i] = *line;
// 		else if (is_link(*line))
// 			links[j] = *line;
// 	}
// 	return (0);
// }

// t_room	*room_populate(char **line)
// {
// 	t_room	*room;

// 	if (!(t_room*)malloc(sizeof(t_room)))
// 		return (NULL);

// }
