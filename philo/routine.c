/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nosterme <nosterme@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 14:41:50 by nosterme          #+#    #+#             */
/*   Updated: 2022/02/28 18:21:24 by nosterme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static void	*clock_handler(void *sophie_v)
{
	t_sophie	*sophie;

	sophie = (t_sophie *)sophie_v;
	while (1)
	{
		pthread_mutex_lock(&sophie->protect_eat_m);
		if (get_time() > sophie->deadline)
		{
			print_message(sophie, DIE);
			pthread_mutex_unlock(&sophie->protect_eat_m);
			pthread_mutex_unlock(&sophie->state->sophie_died_m);
			return ((void *)0);
		}
		pthread_mutex_unlock(&sophie->protect_eat_m);
		usleep(500);
	}
	return ((void *)0);
}

void	*routine(void *sophie_v)
{
	t_sophie	*sophie;
	pthread_t	time;

	sophie = (t_sophie *)sophie_v;
	sophie->last_eat = get_time();
	sophie->deadline = sophie->last_eat + sophie->state->time_to_die;
	if (pthread_create(&time, NULL, &clock_handler, sophie_v))
		return ((void *)1);
	pthread_detach(time);
	print_message(sophie, THINK);
	while (1)
	{
		take_forks(sophie);
		eat(sophie);
		drop_forks(sophie);
		print_message(sophie, THINK);
	}
	return ((void *)0);
}
