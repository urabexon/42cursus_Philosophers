/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hurabe <hurabe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 22:01:46 by hurabe            #+#    #+#             */
/*   Updated: 2024/10/16 22:37:04 by hurabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	init_philos(t_data *data)
{
	return (0);
}

static int	init_mutex(t_data *data)
{
	return (0);
}

static int	allcate_data(t_data *data)
{
	return (0);
}

int	init_data(t_data *data, int argc, char **argv)
{
	data->philos_num = ft_atoi(argv[1]);
	data->time_to_die = ft_atoi(argv[2]);
	data->time_to_eat = ft_atoi(argv[3]);
	data->time_to_sleep = ft_atoi(argv[4]);
	data->must_eat = -1;
	if (argc == 6)
		data->must_eat = ft_atoi(argv[5]);
	data->finished = false;
	data->dead = false;
	data->start_time = get_current_time() + (data->philos_num * 20);
	if (allcate_data(data))
		return (1);
	if (init_mutex(data))
		return (error_free("NULL", data));
	if (init_philos(data))
	{
		pthread_mutex_destroy(&data->dead_lock);
		pthread_mutex_destroy(&data->eat_lock);
		pthread_mutex_destroy(&data->write_lock);
		return (error_free("NULL", data));
	}
	return (0);
}
