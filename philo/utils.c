/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nosterme <nosterme@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 10:18:38 by nosterme          #+#    #+#             */
/*   Updated: 2022/02/28 18:25:05 by nosterme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	ft_strlen(const char *s)
{
	int	count;

	count = 0;
	while (s[count] != 0)
		count++;
	return (count);
}

int	ft_atoi(const char *nptr)
{
	int	i;
	int	sign;
	int	count;

	count = 0;
	sign = 1;
	i = 0;
	while ((nptr[count] >= 7 && nptr[count] <= 13) || nptr[count] == ' ')
		count++;
	if (nptr[count] == '-')
		sign = -1;
	if (nptr[count] == '-' || nptr[count] == '+')
		count++;
	while (nptr[count] >= '0' && nptr[count] <= '9' && nptr[count])
	{
		i = i * 10 + (nptr[count] - '0');
		count++;
	}
	return (i * sign);
}

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

unsigned long long	get_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

void	waiting(unsigned long long limit)
{
	while (limit > get_time())
		usleep(500);
}
