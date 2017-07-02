/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   subfunc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkaminsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/22 10:45:00 by vkaminsk          #+#    #+#             */
/*   Updated: 2017/02/22 12:39:49 by vkaminsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./headers/filler.h"

int		abs(int i)
{
	if (i < 0)
		return (i);
	else
		return (-i);
}

int		str_find(char *tmp, char *find)
{
	while (*find != '\0' && *find == *tmp)
	{
		find++;
		tmp++;
	}
	if (*find == '\0')
		return (1);
	else
		return (0);
}
