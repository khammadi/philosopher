# Philosophers

A solution to the **Dining Philosophers** problem, developed as part of the 42 curriculum.

The project demonstrates thread synchronization, mutexes, process management, semaphores, and protection against race conditions and deadlocks.

## Project Structure

- `philo/` — mandatory implementation using threads and mutexes
- `philo_bonus/` — bonus implementation using processes and semaphores

## Requirements

- Clang or GCC
- Make
- POSIX-compatible operating system
- pthread support

## Compilation

### Mandatory version

```bash
cd philo
make
```

This creates the `philo` executable.

### Bonus version

```bash
cd philo_bonus
make
```

This creates the `philo_bonus` executable.

## Usage

```bash
./philo number_of_philosophers time_to_die time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]
```

### Arguments

| Argument | Description |
|---|---|
| `number_of_philosophers` | Number of philosophers and forks |
| `time_to_die` | Time in milliseconds before a philosopher dies without eating |
| `time_to_eat` | Time in milliseconds spent eating |
| `time_to_sleep` | Time in milliseconds spent sleeping |
| `number_of_times_each_philosopher_must_eat` | Optional number of meals required for each philosopher |

All time values are expressed in milliseconds.

## Examples

```bash
cd philo
./philo 5 800 200 200
```

```bash
cd philo
./philo 5 800 200 200 5
```

```bash
cd philo_bonus
./philo_bonus 5 800 200 200
```

## Simulation

During the simulation, philosophers repeatedly:

1. Take forks
2. Eat
3. Sleep
4. Think

The simulation ends when a philosopher dies or, when the optional meal-count argument is provided, when every philosopher has eaten the required number of times.

## Makefile Commands

The following commands are available in both `philo/` and `philo_bonus/`:

```bash
make
```

Compile the project.

```bash
make clean
```

Remove object files.

```bash
make fclean
```

Remove object files and the executable.

```bash
make re
```

Recompile the project from scratch.

## Concepts Used

- POSIX threads
- Mutexes
- Processes
- Semaphores
- Thread synchronization
- Process synchronization
- Timing and sleeping
- Deadlock avoidance
- Race-condition prevention
- Memory management

## Author

**khammadi**
