/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alboudje <alboudje@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 20:45:18 by alboudje          #+#    #+#             */
/*   Updated: 2022/12/18 21:07:48 by alboudje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

t_map	*open_map(char *path)
{
	int		map_fd;
	char	**map;

	map_fd = open(path, O_RDONLY);
	return (NULL);
}
