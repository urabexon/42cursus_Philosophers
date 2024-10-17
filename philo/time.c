/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hurabe <hurabe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 22:02:02 by hurabe            #+#    #+#             */
/*   Updated: 2024/10/17 23:20:34 by hurabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	start_delay(time_t start_time)
{
	while (1)
	{
		if (get_current_time() >= start_time)
			break ;
		usleep(10);
	}
}

time_t	get_current_time(void)
{
	struct timeval	time;
	time_t			milliseconds;

	if (gettimeofday(&time, NULL) == -1)
	{
		error_msg("gettimeofday error\n");
		return (-1);
	}
	milliseconds = (time.tv_sec * 1000) + (time.tv_usec / 1000);
	return (milliseconds);
}

int	my_sleep(size_t milliseconds)
{
	size_t	start;

	start = get_current_time();
	while ((get_current_time() - start) < milliseconds)
		usleep(100);
	return (0);
}
