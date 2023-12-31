/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgirardi <mgirardi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 17:19:28 by michele           #+#    #+#             */
/*   Updated: 2023/04/29 21:02:40 by mgirardi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d_bonus.h"

void	ft_error(char *str)
{
	printf("%s\n", str);
	exit(0);
}

void	ft_giga_error(char *str, t_ncul *data)
{
	printf("%s\n", str);
	ft_free_map(data->map);
	ft_free_map(data->instr);
	exit(0);
}

int	ft_check_cols(char **map)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	j = 0;
	count = 0;
	while (map[i])
	{
		while (map[i][j])
			j++;
		if (j > count)
			count = j;
		j = 0;
		i++;
	}
	return (count);
}

int	ft_check_rows(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		i++;
	return (i);
}

void	ft_check_map_border(t_ncul *data)
{
	data->map_w = ft_check_cols(data->map);
	data->map_h = ft_check_rows(data->map);
	check_sup_border(data);
	check_inf_border(data);
	check_left_border(data);
	check_right_border(data);
}
