/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nosterme <nosterme@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 10:21:20 by nosterme          #+#    #+#             */
/*   Updated: 2022/02/28 18:27:11 by nosterme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>

/*
 * Macros
 */

# define FORK 0
# define EAT 1
# define SLEEP 2
# define THINK 3
# define DIE 4

/*
 * Structs
 */

typedef struct s_state	t_state;

typedef struct s_sophie
{
	int					position;
	unsigned long long	last_eat;
	unsigned long long	deadline;
	int					lfork;
	int					rfork;
	int					count_eat;
	int					done;
	t_state				*state;
	pthread_mutex_t		protect_eat_m;
}						t_sophie;

struct s_state
{
	int					amount;
	unsigned long long	time_to_die;
	unsigned long long	time_to_eat;
	unsigned long long	time_to_sleep;
	int					must_eat;
	unsigned long long	start;
	int					done;
	t_sophie			*sophies;
	pthread_mutex_t		*forks_m;
	pthread_mutex_t		write_m;
	pthread_mutex_t		sophie_died_m;
};

/*
 * Functions
 */

int						init(t_state *state, int argc, char **argv);
void					*routine(void *sophie_v);
void					print_message(t_sophie *sophie, int type);
void					take_forks(t_sophie *sophie);
void					eat(t_sophie *sophie);
void					drop_forks(t_sophie *sophie);

/*
 * Exit
 */

int						usage_error(void);
int						clear_state(t_state *state);
int						exit_error(char *str);

/*
 * Utils
 */

int						ft_strlen(const char *s);
int						ft_atoi(const char *nptr);
int						ft_isdigit(int c);
unsigned long long		get_time(void);
void					waiting(unsigned long long limit);

#endif