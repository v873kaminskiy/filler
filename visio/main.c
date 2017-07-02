/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkaminsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/22 11:31:04 by vkaminsk          #+#    #+#             */
/*   Updated: 2017/02/22 11:31:05 by vkaminsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include <stdio.h>

void	ft_map(char *tmp)
{
	int		i;

	i = 0;
	while (tmp[i])
	{
		if (tmp[i] == 'X')
			printf("\e[35;7m%c\e[0m", tmp[i]);
		else if (tmp[i] == 'x')
			printf("\e[35;5m%c\e[0m", tmp[i]);
		else if (tmp[i] == 'O')
			printf("\e[33;7m%c\e[0m", tmp[i]);
		else if (tmp[i] == 'o')
			printf("\e[33;5m%c\e[0m", tmp[i]);
		else
			printf("%c", tmp[i]);
		i++;
	}
	printf("\n");
}

int		main(int argc, char **argv)
{
	char	*tmp;

	while (get_next_line(0, &tmp) > 0)
	{
		if (ft_isdigit(tmp[0]))
			ft_map(tmp);
		else
			printf("%s\n", tmp);
	}
	return (0);
}
