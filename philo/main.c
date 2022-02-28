/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nosterme <nosterme@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 10:34:42 by nosterme          #+#    #+#             */
/*   Updated: 2022/02/28 21:10:02 by nosterme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static int	input_is_invalid(int argc, char **argv)
{
	int	i;
	int	j;

	i = 0;
	if (argc < 5 || argc > 6)
		return (1);
	while (++i < argc)
	{
		j = -1;
		while (argv[i][++j])
		{
			if (!ft_isdigit(argv[i][j]))
				return (1);
		}
	}
	return (0);
}

static void	*eat_counter(void *state_v)
{
	t_state	*state;
	int		total;
	int		i;

	state = (t_state *)state_v;
	total = 0;
	i = 0;
	while (total < state->amount)
	{
		i %= state->amount;
		pthread_mutex_lock(&state->sophies[i].protect_eat_m);
		if (!state->sophies[i].done && \
			state->sophies[i].count_eat == state->must_eat)
		{
			state->sophies[i].done = 1;
			total++;
		}
		pthread_mutex_unlock(&state->sophies[i].protect_eat_m);
		i++;
		usleep(500);
	}
	pthread_mutex_unlock(&state->sophie_died_m);
	return ((void *)0);
}

static int	start_simulation(t_state *state)
{
	pthread_t	thread;
	void		*sophie;
	int			i;

	state->start = get_time();
	if (state->must_eat >= 0)
	{
		if (pthread_create(&thread, NULL, &eat_counter, state))
			return (1);
		pthread_detach(thread);
	}
	i = -1;
	while (++i < state->amount)
	{
		sophie = (void *)(&state->sophies[i]);
		if (pthread_create(&thread, NULL, &routine, sophie))
			return (1);
		pthread_detach(thread);
		usleep(100);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_state	state;

	if (input_is_invalid(argc, argv))
		return (usage_error());
	if (init(&state, argc, argv))
		return (clear_state(&state) && exit_error("init"));
	if (start_simulation(&state))
		return (clear_state(&state) && exit_error("start_simulation"));
	pthread_mutex_lock(&state.sophie_died_m);
	pthread_mutex_unlock(&state.sophie_died_m);
	clear_state(&state);
	return (0);
}
