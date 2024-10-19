/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hurabe <hurabe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 22:01:49 by hurabe            #+#    #+#             */
/*   Updated: 2024/10/19 23:10:20 by hurabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philosophers(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->philos_num)
	{
		if (pthread_create(&data->philos[i].philo, NULL, &routine, \
			&data->philos[i]) != 0)
		{
			while (--i >= 0)
				pthread_detach(data->philos[i].philo);
			error_free("pthread_join error\n", data);
			return ;
		}
		i++;
	}
	monitor(data);
	i = 0;
	while (i < data->philos_num)
	{
		if (pthread_join(data->philos[i].philo, NULL) != 0)
			error_msg("pthread_join error\n");
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (!validate(argc, argv))
		return (EXIT_FAILURE);
	if (init_data(&data, argc, argv))
		return (EXIT_FAILURE);
	philosophers(&data);
	destroy_all(&data);
	return (EXIT_SUCCESS);
}
