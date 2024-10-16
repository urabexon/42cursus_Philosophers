/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hurabe <hurabe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 22:02:06 by hurabe            #+#    #+#             */
/*   Updated: 2024/10/16 22:08:55 by hurabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	is_number(char *str)
{
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	if (*str == '-' || *str == '+')
		str++;
	if (!*str)
		return (0);
	while (*str)
	{
		if (!(*str >= '0' && *str <= '9'))
			return (0);
		str++;
	}
	return (1);
}

int	validate(int argc, char **argv)
{
	int	err_flg;

	err_flg = 0;
	if (argc != 5 && argc != 6)
		err_flg = error_msg("Invalid argument\n");
	else
	{
		if (!is_number(argv[1]) || ft_atoi(argv[1]) <= 0)
			err_flg = error_msg("Invalid philosophers number\n");
		if (!is_number(argv[2]) || ft_atoi(argv[2]) < 0)
			err_flg = error_msg("Invalid time to die\n");
		if (!is_number(argv[3]) || ft_atoi(argv[3]) < 0)
			err_flg = error_msg("Invalid time to eat\n");
		if (!is_number(argv[4]) || ft_atoi(argv[4]) < 0)
			err_flg = error_msg("Invalid time to sleep\n");
		if (argc == 6 && (!is_number(argv[5]) || ft_atoi(argv[5]) <= 0))
			err_flg = error_msg("Invalid number of times to eat\n");
	}
	if (err_flg)
		return (0);
	return (1);
}
