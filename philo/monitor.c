/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hurabe <hurabe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 22:01:53 by hurabe            #+#    #+#             */
/*   Updated: 2024/10/18 20:08:29 by hurabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	monitor(t_data *data)
{
	int	i;

	if (data->must_eat == 0)
		return ;
	start_delay(data->start_time);
	while (1)
	{
		i = 0;
		while (i < data->philos_num)
		{
			if (check_anyone_dead(data, i))
				return ;
			i++;
		}
		if (everyone_is_full(data))
			return ;
		usleep(300);
	}
}
