/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nosterme <nosterme@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 13:40:15 by nosterme          #+#    #+#             */
/*   Updated: 2022/02/28 21:03:07 by nosterme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	eat(t_sophie *sophie)
{
	pthread_mutex_lock(&sophie->protect_eat_m);
	sophie->last_eat = get_time();
	sophie->deadline = sophie->last_eat + sophie->state->time_to_die;
	print_message(sophie, EAT);
	pthread_mutex_unlock(&sophie->protect_eat_m);
	waiting(get_time() + sophie->state->time_to_eat);
	sophie->count_eat++;
}
