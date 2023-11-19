# Philosophers
42 School - Level03

A program to showcase the dining philosophers problem

## Rules

One or more philosophers sit at a round table.  
There is a large bowl of spaghetti in the middle of the table.  
+ The philosophers alternatively eat, think, or sleep.
+ There is one fork to the right of each philosopher. (as many forks as philosphers)
+ A philosopher takes their right and their left forks to eat, one in each hand.
+ When a philosopher has finished eating, they put their forks back on the table and start sleeping. Once awake, they start thinking again.
+ Every philosopher needs to eat and should never starve.
+ The simulation stops when a philosopher dies of starvation.

## Usage

`make` compiles the program.

#### Arguments
1. number_of_philosophers
2. time_to_die (in milliseconds)
3. time_to_eat (in milliseconds)
4. time_to_sleep (in milliseconds)
5. number_of_times_each_philosopher_must_eat (optional)

```
$ ./philo <nop> <tod> <toe> <tos> <notepme>
```
