/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkaminsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/04 15:20:47 by vkaminsk          #+#    #+#             */
/*   Updated: 2017/01/17 17:42:29 by vkaminsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_list_push_back_gnl(t_gnl **begin_list, int fd)
{
	t_gnl *temp_list;
	t_gnl *new_node;

	new_node = (t_gnl*)malloc(sizeof(t_gnl));
	new_node->str = NULL;
	new_node->fd = fd;
	new_node->next = NULL;
	temp_list = *begin_list;
	if (temp_list)
	{
		while (temp_list->next != NULL)
		{
			temp_list = temp_list->next;
		}
		temp_list->next = new_node;
	}
	else
	{
		*begin_list = new_node;
	}
}

static int	ft_check_str(char **str, char **line)
{
	char	*tmp;

	tmp = ft_strchr(*str, '\n');
	if (tmp)
	{
		*line = ft_strsub(*str, 0, tmp - *str);
		ft_memmove(*str, tmp + 1, ft_strlen(tmp));
		tmp = NULL;
		return (1);
	}
	return (0);
}

static int	ft_read(int fd, char **str, char **line)
{
	char	buf[BUFF_SIZE + 1];
	long	ret;
	char	*tmp;

	while ((ret = read(fd, buf, BUFF_SIZE)))
	{
		if (ret == -1)
			return (-1);
		buf[ret] = '\0';
		tmp = NULL;
		if (*str)
		{
			tmp = ft_strdup(*str);
			ft_memdel((void **)str);
			*str = ft_strjoin(tmp, buf);
			ft_memdel((void **)&tmp);
		}
		else
			*str = ft_strdup(buf);
		if (ft_check_str(str, line))
			return (1);
	}
	return (0);
}

static int	get_middle(t_gnl *tmp, int *str, t_gnl **input, char **line)
{
	int		result;

	if (!tmp && str[1])
	{
		ft_list_push_back_gnl(input, str[0]);
		tmp = *input;
		while (tmp->next)
			tmp = tmp->next;
		tmp->str = NULL;
	}
	result = ft_read(str[0], &tmp->str, line);
	if (result != 0)
		return (result);
	if (tmp->str == NULL || tmp->str[0] == '\0')
		return (0);
	*line = tmp->str;
	tmp->str = NULL;
	return (1);
}

int			get_next_line(int const fd, char **line)
{
	static t_gnl	*input;
	t_gnl			*tmp;
	int				str[2];

	str[0] = fd;
	str[1] = 1;
	if (!line || fd < 0)
		return (-1);
	tmp = input;
	while (tmp)
	{
		if (tmp->fd == fd && str[1])
		{
			str[1] = 0;
			if (tmp->str && ft_check_str(&tmp->str, line))
				return (1);
		}
		else if (str[1])
			tmp = tmp->next;
		else
			break ;
	}
	return (get_middle(tmp, str, &input, line));
}
