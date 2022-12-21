/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ILX_Rects.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alboudje <alboudje@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 20:25:16 by alboudje          #+#    #+#             */
/*   Updated: 2022/12/21 20:41:06 by alboudje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ILX_Rect.h"

t_ilx_rect	**ilx_create_rects(int w, int h, int num)
{
	t_ilx_rect	**rects;
	int			i;

	i = 0;
	rects = malloc(sizeof(t_ilx_rect *) * (num + 1));
	if (!rects)
		return (NULL);
	while (i < num)
	{
		rects[i] = ilx_create_rect(-w, -h, w, h);
		if (!rects[i])
			return (ilx_free_rects(rects), NULL);
		i++;
	}
	rects[i] = NULL;
	return (rects);
}

void	ilx_free_rects(t_ilx_rect **rects)
{
	int	i;

	i = 0;
	while (rects[i])
	{
		free(rects[i]);
		i++;
	}
	free(rects);
}
