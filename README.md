<h1 align="center">
	Philosophers
</h1>

<p align="center">
	<b><i>I never thought philosophy would be so deadly</i></b><br>
</p>

---

## About the project

> _Eat, Sleep, Spaghetti, repeat.
> This project is about learning how threads work by precisely timing a group of philosophers on
> when to pick up forks and eat spaghetti without dying from hunger._


## Usage

### Requirements

The function is written in C language and thus needs the **`cc` compiler** and some standard **C libraries** to run.

### Instructions

**1. Move to the Mandatory directory**

The codes are in the `philo` directory
```shell
cd philo
```

**1. Compiling the program**

To compile, go to the program path and run:

```shell
make
```

**2. Executing the program**

To execute the program, run:

```shell
./philo number_of_philosophers time_to_die time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]
```

For example
```shell
./philo 4 410 200 200
./philo 6 610 300 200 5
```

### Outputs

```terminal
./philo 4 410 200 200
<time> <number of philo> <action>
```
