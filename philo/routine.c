/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hurabe <hurabe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 22:01:59 by hurabe            #+#    #+#             */
/*   Updated: 2024/10/19 23:20:55 by hurabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	lonely_philo(t_philo *philo)
{
	
}

void	thinking(t_philo *philo)
{
	
}

void	sleeping(t_data *philo)
{
	
}

void	eating(t_philo *philo)
{
	
}

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->data->must_eat == 0)
		return (NULL);
	start_delay(philo->data->start_time);
	if (philo->data->philos_num == 1)
	{
		lonely_philo(philo);
		return (NULL);
	}
	if (philo->id % 2 == 0)
		standby(philo);
	while (everyone_is_alive(philo->data))
	{
		if (check_finish(philo->data))
			break ;
		eating(philo);
		sleeping(philo);
		thinking(philo);
	}
	return (NULL);
}
