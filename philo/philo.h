/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hurabe <hurabe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 20:05:25 by hurabe            #+#    #+#             */
/*   Updated: 2024/10/17 23:47:22 by hurabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include <pthread.h>
# include <stdbool.h>
# include <limits.h>

// enum
typedef enum e_status
{
	GOT_FORK = 0,
	EATING = 1,
	SLEEPING = 2,
	THINKING = 3,
	DIED = 4
}			t_status;

// struct
typedef struct s_data
{
	t_philo				*philos;
	int					philos_num;
	time_t				time_to_die;
	time_t				time_to_eat;
	time_t				time_to_sleep;
	int					must_eat;
	bool				finished;
	time_t				start_time;
	bool				dead;
	pthread_mutex_t		*forks;
	pthread_mutex_t		eat_lock;
	pthread_mutex_t		write_lock;
	pthread_mutex_t		dead_lock;
}						t_data;

typedef struct s_philo
{
	pthread_t		philo;
	int				id;
	time_t			last_eat;
	int				eat_count;
	pthread_mutex_t	*right_fork;
	pthread_mutex_t	*left_fork;
	t_data			*data;
}					t_philo;

// validate
int		validate(int argc, char **argv);

// init_data
int		init_data(t_data *data, int argc, char **argv);

// time
void	start_delay(time_t start_time);
time_t	get_current_time(void);
int		my_sleep(size_t milliseconds);

// utils
int		ft_atoi(const char *str);
int		error_free(char *msg, t_data *data);
int		error_msg(char *s);
void	*free_data(t_data *data);
int		destroy_all(t_data *data);

#endif