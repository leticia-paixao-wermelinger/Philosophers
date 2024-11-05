<img src="./cover-philosophers.png"/>

# 🤔 Philosophers 🤔

This project is a reproduction of the famous Dining Philosophers problem, focusing on Operating System synchronization. It uses threads and mutexes to manage concurrent programming effectively.

## 🍽️ The Dining Philosophers Problem
N philosophers are sitting at a table;<br /><br />
There is one fork 🍴 for each Philosopher at the table;<br /><br />
All the philosophers can do is eat, think, and sleep, in that order;<br /><br />
Philosophers can NOT interact 💬 with each other;<br /><br />
There is a time ⌛ for the Philosophers to eat 🥘 and sleep 😴;<br /><br />
There is a time ⌛ a Philo can go without food (time_to_die). 😵 If they do not eat in that time, they die;<br /><br />
🪦 A Philosopher must avoid dying at all costs;<br /><br />
If a Philosopher dies, the program must finish;<br /><br />
A Philo can only eat if he is holding two forks; 🍴🍴<br /><br />
There must be NO deadlocks (each Philo takes a fork and wait for the other to be free);<br /><br />
There must be NO starvation (one philosopher never eats).

## Usage 
```
make run
```
(Check the arguments set inside the Makefile)

## The program takes the following arguments:
number_of_philosophers + time_to_die + time_to_eat + time_to_sleep + [number_of_times_each_philosopher_must_eat]

- number_of_philosophers: The number of philosophers and also the number of forks.
- time_to_die (in milliseconds): If a philosopher didn’t start eating time_to_die milliseconds since the beginning of their last meal or the beginning of the simulation, they die.
- time_to_eat (in milliseconds): The time it takes for a philosopher to eat. (During that time, they will need to hold two forks.)
- time_to_sleep (in milliseconds): The time a philosopher will spend sleeping.
- number_of_times_each_philosopher_must_eat (optional argument): If all philosophers have eaten at least number_of_times_each_philosopher_must_eat times, the simulation stops. If not specified, the simulation stops when a philosopher dies.
