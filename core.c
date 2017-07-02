/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkaminsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/21 18:05:35 by vkaminsk          #+#    #+#             */
/*   Updated: 2017/02/22 12:39:17 by vkaminsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./headers/filler.h"

void	check_dist(t_e *e, int p_y, int p_x)
{
	int		x;
	int		y;
	int		mean;

	y = 0;
	while (y < e->s_y)
	{
		x = 0;
		while (x < e->s_x)
		{
			if ((e->map[y][x] == e->op_t || e->map[y][x] == e->op_ts))
			{
				mean = abs(p_x - x) + abs(p_y - y);
				mean = (mean < 0) ? -mean : mean;
				if (mean < e->dist || e->dist < 0)
				{
					e->dist = mean;
					e->pos_y = p_y;
					e->pos_x = p_x;
				}
			}
			x++;
		}
		y++;
	}
}

int		can_put(t_e *e, int y, int x)
{
	int		i;
	int		j;
	t_put	put;

	put.count = 0;
	put.count_op = 0;
	i = 0;
	while (i < e->t_y)
	{
		j = 0;
		while (j < e->t_x)
		{
			if ((((y + i) >= e->s_y) || ((x + j) >= e->s_x)))
				return (0);
			if ((e->map[y + i][x + j] == e->my_t || e->map[y + i][x + j] ==
											e->my_ts) && e->token[i][j] == '*')
				put.count++;
			if ((e->map[y + i][x + j] == e->op_t || e->map[y + i][x + j] ==
											e->op_ts) && e->token[i][j] == '*')
				put.count_op++;
			j++;
		}
		i++;
	}
	return ((put.count == 1 && !put.count_op) ? 1 : 0);
}

void	put_token(int y, int x)
{
	ft_putnbr(y);
	ft_putchar(' ');
	ft_putnbr(x);
	ft_putchar('\n');
}

void	set_player(t_e *e)
{
	if (e->player == '1')
	{
		e->my_t = 'O';
		e->op_t = 'X';
		e->my_ts = 'o';
		e->op_ts = 'x';
	}
	else
	{
		e->my_t = 'X';
		e->op_t = 'O';
		e->my_ts = 'x';
		e->op_ts = 'o';
	}
}

void	core(t_e *e)
{
	int		x;
	int		y;

	y = 0;
	e->pos_y = 0;
	e->pos_x = 0;
	e->dist = -1;
	set_player(e);
	while (y < e->s_y)
	{
		x = 0;
		while (x < e->s_x)
		{
			if (can_put(e, y, x))
				check_dist(e, y, x);
			x++;
		}
		y++;
	}
	put_token(e->pos_y, e->pos_x);
}
