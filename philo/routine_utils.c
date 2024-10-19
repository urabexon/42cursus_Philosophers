/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hurabe <hurabe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 22:01:57 by hurabe            #+#    #+#             */
/*   Updated: 2024/10/19 23:03:47 by hurabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_msg(t_philo *philo, t_status status, int current_time)
{
	int	timestamp;

	timestamp = current_time - philo->data->start_time;
	pthread_mutex_lock(&philo->data->write_lock);
	if (everyone_is_alive(philo->data))
	{
		if (status == DIED)
			printf("%d %d died\n", timestamp, philo->id);
		else if (status == EATING)
			printf("%d %d is eating\n", timestamp, philo->id);
		else if (status == SLEEPING)
			printf("%d %d is sleeping\n", timestamp, philo->id);
		else if (status == THINKING)
			printf("%d %d has taken a fork\n", timestamp, philo->id);
	}
	pthread_mutex_unlock(&philo->data->write_lock);
}

void	standby(t_philo *philo)
{
	
}


void	get_forks(t_philo *philo)
{
	
}

void	return_forks(t_philo *philo)
{
	if (philo->id % 2 == 0)
	{
		pthread_mutex_unlock(philo->right_fork);
		pthread_mutex_unlock(philo->left_fork);
	}
	else
	{
		pthread_mutex_unlock(philo->left_fork);
		pthread_mutex_unlock(philo->right_fork);
	}
}
