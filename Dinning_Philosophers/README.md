# Dining Philosophers Problem

## Introduction
The Dining Philosophers Problem is a classic synchronization problem in computer science that illustrates the challenges of resource sharing and process coordination.

Imagine five philosophers sitting around a circular table. Each philosopher needs two forks (one from their left and one from their right) to eat spaghetti. However, there are only five forks available, one between each pair of philosophers.

## Visual Explanation
![Dining Philosophers Diagram](dining_philosophers.png)

In this problem, each philosopher alternates between thinking and eating. To eat, a philosopher needs both the fork on their left and the fork on their right. However, they can only pick up one fork at a time.

To avoid deadlock, we introduce a rule: A philosopher only attempts to pick up forks if their hunger percentage is more than 50%. If they cannot pick up both forks, they put down any fork they have picked up and continue thinking.

## Explanation of Code

The provided program simulates the dining philosophers problem using threads and semaphores:

1. **Initialization**: 
    - The number of philosophers (N) is taken as input.
    - Arrays and semaphores are initialized.

2. **Philosopher Behavior**:
    - Each philosopher is a thread that thinks, checks its hunger level, and tries to eat if hungry.

3. **Fork Management**:
    - `take_fork(int phnum)`: Philosopher attempts to pick up forks.
    - `put_fork(int phnum)`: Philosopher puts down forks after eating.
    - `test(int phnum)`: Checks if a philosopher can eat.

## Running the Program

1. **Compile**:
    ```sh
    gcc -pthread dining_philosophers.c -o dining_philosophers
    ```

2. **Execute**:
    ```sh
    ./dining_philosophers
    ```

3. **Input the number of philosophers**: 
    - Enter an odd number to avoid deadlock.

## Conclusion

The dining philosophers problem is a fundamental example of concurrent programming and resource sharing. By visualizing the problem and implementing it with semaphores, we can better understand the challenges and solutions in process synchronization.
