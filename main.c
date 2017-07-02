/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkaminsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/21 14:42:54 by vkaminsk          #+#    #+#             */
/*   Updated: 2017/02/22 12:39:28 by vkaminsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./headers/filler.h"

char	player_find(char *tmp)
{
	while (!ft_isdigit(*tmp))
		tmp++;
	return (*tmp);
}

void	size_find(char *tmp, int *y, int *x)
{
	int		i;
	char	*str;

	i = 1;
	while (!ft_isdigit(*tmp))
		tmp++;
	while (ft_isdigit(*(tmp + i++)))
		;
	str = ft_strsub(tmp, 0, i - 1);
	while (--i)
		tmp++;
	*y = ft_atoi(str);
	free(str);
	while (!ft_isdigit(*tmp))
		tmp++;
	while (ft_isdigit(*(tmp + i)))
		i++;
	str = ft_strsub(tmp, 0, i);
	*x = ft_atoi(str);
	free(str);
}

char	**map_find(char **tmp, int fd, int y, int x)
{
	char	**map;
	int		i;

	map = malloc(sizeof(char*) * y);
	i = 0;
	while (i < y)
	{
		map[i++] = ft_strsub(*tmp, 4, x);
		free(*tmp);
		get_next_line(fd, tmp);
	}
	return (map);
}

char	**token_find(char **tmp, t_e *e, int fd)
{
	char	**token;
	int		i;

	token = malloc(sizeof(char*) * e->t_y);
	i = 0;
	while (i < e->t_y)
	{
		token[i++] = ft_strsub(*tmp, 0, e->t_x);
		free(*tmp);
		if (i < e->t_y)
			get_next_line(fd, tmp);
	}
	return (token);
}

int		main(void)
{
	t_e		e;
	char	*tmp;
	int		fd;

	fd = 0;
	while (get_next_line(fd, &tmp) > 0)
	{
		if (ft_strstr(tmp, "players/filler") && ft_strstr(tmp, "exec"))
			e.player = player_find(tmp);
		else if (str_find(tmp, "Plateau"))
			size_find(tmp, &e.s_y, &e.s_x);
		else if (ft_isdigit(tmp[0]))
			e.map = map_find(&tmp, fd, e.s_y, e.s_x);
		if (str_find(tmp, "Piece"))
		{
			size_find(tmp, &e.t_y, &e.t_x);
			get_next_line(fd, &tmp);
			e.token = token_find(&tmp, &e, fd);
			core(&e);
		}
	}
	return (0);
}
