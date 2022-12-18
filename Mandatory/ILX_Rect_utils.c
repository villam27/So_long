/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ILX_Rect_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alboudje <alboudje@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 18:44:29 by alboudje          #+#    #+#             */
/*   Updated: 2022/12/18 18:46:29 by alboudje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ILX_Rect.h"

int	ilx_intersection_rect(t_ilx_rect *r1, t_ilx_rect *r2)
{
	if (r1->x < r2->x + r2->w && r2->x < r1->x + r1->w
		&& r1->y < r2->y + r2->h && r2->y < r1->y + r1->h)
		return (1);
	return (0);
}

int	ilx_vertical_align_rect(t_ilx_rect *r1, t_ilx_rect *r2)
{
	if (r1->y < r2->y + r2->h && r1->y + r1->h > r2->y)
		return (1);
	return (0);
}

int	ilx_horizont_align_rect(t_ilx_rect *r1, t_ilx_rect *r2)
{
	if (r1->x < r2->x + r2->w && r1->x + r1->w > r2->x)
		return (1);
	return (0);
}
