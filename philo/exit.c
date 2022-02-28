/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nosterme <nosterme@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 10:42:48 by nosterme          #+#    #+#             */
/*   Updated: 2022/02/28 16:02:19 by nosterme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	usage_error(void)
{
	write(2, "Usage: ", 7);
	write(2, "./philo ", 8);
	write(2, "'number_of_philosophers' ", 25);
	write(2, "'time_to_die' (in ms) ", 22);
	write(2, "'time_to_eat' (in ms) ", 22);
	write(2, "'time_to_sleep' (in ms) ", 24);
	write(2, "['number_of_times_each_philosopher_must_eat']\n", 46);
	return (1);
}

int	clear_state(t_state *state)
{
	int	i;

	if (state->forks_m)
	{
		i = -1;
		while (++i < state->amount)
			pthread_mutex_destroy(&state->forks_m[i]);
		free(state->forks_m);
	}
	if (state->sophies)
	{
		i = -1;
		while (++i < state->amount)
			pthread_mutex_destroy(&state->sophies[i].protect_eat_m);
		free(state->sophies);
	}
	pthread_mutex_destroy(&state->write_m);
	pthread_mutex_destroy(&state->sophie_died_m);
	return (1);
}

int	exit_error(char *str)
{
	write(2, "Error in function ", 18);
	write(2, str, ft_strlen(str));
	return (1);
}
