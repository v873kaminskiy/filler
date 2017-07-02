/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkaminsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/21 15:06:26 by vkaminsk          #+#    #+#             */
/*   Updated: 2017/02/22 12:39:59 by vkaminsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_FILLER_H
# define FILLER_FILLER_H
# include "../libft/libft.h"

typedef struct	s_e
{
	char		**map;
	int			s_x;
	int			s_y;
	int			pos_x;
	int			pos_y;
	int			dist;
	char		player;
	char		**token;
	int			t_x;
	int			t_y;
	char		my_t;
	char		op_t;
	char		my_ts;
	char		op_ts;

}				t_e;

typedef struct	s_put
{
	int			count;
	int			count_op;
}				t_put;

int				can_put(t_e *e, int x, int y);
void			core(t_e *e);
int				abs(int i);
int				str_find(char *tmp, char *find);
#endif
