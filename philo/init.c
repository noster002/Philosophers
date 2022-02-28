/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nosterme <nosterme@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 10:45:37 by nosterme          #+#    #+#             */
/*   Updated: 2022/02/28 15:39:45 by nosterme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static int	init_mutexes(t_state *state)
{
	int	i;

	pthread_mutex_init(&state->write_m, NULL);
	pthread_mutex_init(&state->sophie_died_m, NULL);
	pthread_mutex_lock(&state->sophie_died_m);
	state->forks_m = \
			(pthread_mutex_t *)malloc(sizeof(*state->forks_m) * state->amount);
	if (state->forks_m == NULL)
		return (1);
	i = -1;
	while (++i < state->amount)
		pthread_mutex_init(&state->forks_m[i], NULL);
	return (0);
}

static void	init_sophies(t_state *state)
{
	int	i;

	i = -1;
	while (++i < state->amount)
	{
		state->sophies[i].position = i;
		state->sophies[i].lfork = i;
		state->sophies[i].rfork = (i + 1) % state->amount;
		state->sophies[i].count_eat = 0;
		state->sophies[i].done = 0;
		state->sophies[i].state = state;
		pthread_mutex_init(&state->sophies[i].protect_eat_m, NULL);
	}
}

int	init(t_state *state, int argc, char **argv)
{
	state->amount = ft_atoi(argv[1]);
	state->time_to_die = ft_atoi(argv[2]);
	state->time_to_eat = ft_atoi(argv[3]);
	state->time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		state->must_eat = ft_atoi(argv[5]);
	else
		state->must_eat = -1;
	state->done = 0;
	state->sophies = NULL;
	state->forks_m = NULL;
	state->sophies = \
			(t_sophie *)malloc(sizeof(*state->sophies) * state->amount);
	if (state->sophies == NULL)
		return (1);
	init_sophies(state);
	return (init_mutexes(state));
}
