/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   message.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nosterme <nosterme@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 13:19:47 by nosterme          #+#    #+#             */
/*   Updated: 2022/02/28 15:42:21 by nosterme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static char	*get_message(int type)
{
	if (type == FORK)
		return ("has taken a fork");
	else if (type == EAT)
		return ("is eating");
	else if (type == SLEEP)
		return ("is sleeping");
	else if (type == THINK)
		return ("is thinking");
	else if (type == DIE)
		return ("died");
	return (0);
}

void	print_message(t_sophie *sophie, int type)
{
	pthread_mutex_lock(&sophie->state->write_m);
	if (!sophie->state->done)
	{
		if (type == DIE)
			sophie->state->done = 1;
		printf("%10llu %d %s\n", get_time() - sophie->state->start, \
			sophie->position + 1, get_message(type));
	}
	pthread_mutex_unlock(&sophie->state->write_m);
}
