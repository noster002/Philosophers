/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nosterme <nosterme@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 13:48:11 by nosterme          #+#    #+#             */
/*   Updated: 2022/02/28 18:26:06 by nosterme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	take_forks(t_sophie *sophie)
{
	pthread_mutex_lock(&sophie->state->forks_m[sophie->lfork]);
	print_message(sophie, FORK);
	pthread_mutex_lock(&sophie->state->forks_m[sophie->rfork]);
	print_message(sophie, FORK);
}

void	drop_forks(t_sophie *sophie)
{
	print_message(sophie, SLEEP);
	pthread_mutex_unlock(&sophie->state->forks_m[sophie->lfork]);
	pthread_mutex_unlock(&sophie->state->forks_m[sophie->rfork]);
	waiting(get_time() + sophie->state->time_to_sleep);
}
