Sure! Below is a `README.md` file that includes a visual explanation of the dining philosophers problem using HTML and CSS for styling. This explanation is designed to be clear and engaging for a newly entered CS student.

---

# Dining Philosophers Problem

## Introduction
The Dining Philosophers Problem is a classic synchronization problem in computer science that illustrates the challenges of resource sharing and process coordination. 

Imagine five philosophers sitting around a circular table. Each philosopher needs two forks (one from their left and one from their right) to eat spaghetti. However, there are only five forks available, one between each pair of philosophers.

## Visual Explanation

```html
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <style>
        body {
            font-family: Arial, sans-serif;
            background-color: #f8f9fa;
            color: #333;
            display: flex;
            justify-content: center;
            align-items: center;
            height: 100vh;
            flex-direction: column;
        }
        h1 {
            color: #007bff;
        }
        .circle {
            position: relative;
            width: 300px;
            height: 300px;
            border: 2px solid #007bff;
            border-radius: 50%;
            margin-top: 20px;
        }
        .philosopher {
            position: absolute;
            width: 60px;
            height: 60px;
            border-radius: 50%;
            background-color: #007bff;
            color: white;
            display: flex;
            justify-content: center;
            align-items: center;
            text-align: center;
        }
        .philosopher:nth-child(1) { top: -30px; left: 120px; }
        .philosopher:nth-child(2) { top: 50px; right: -30px; }
        .philosopher:nth-child(3) { bottom: 50px; right: -30px; }
        .philosopher:nth-child(4) { bottom: -30px; left: 120px; }
        .philosopher:nth-child(5) { top: 50px; left: -30px; }
        .fork {
            position: absolute;
            width: 10px;
            height: 60px;
            background-color: #28a745;
        }
        .fork:nth-child(6) { top: 0; left: 145px; }
        .fork:nth-child(7) { top: 70px; right: 0; transform: rotate(72deg); }
        .fork:nth-child(8) { bottom: 70px; right: 0; transform: rotate(144deg); }
        .fork:nth-child(9) { bottom: 0; left: 145px; transform: rotate(216deg); }
        .fork:nth-child(10) { top: 70px; left: 0; transform: rotate(288deg); }
        .description {
            max-width: 600px;
            text-align: center;
            margin: 20px;
        }
        .code-block {
            background-color: #e9ecef;
            padding: 10px;
            border-radius: 5px;
            text-align: left;
        }
    </style>
    <title>Dining Philosophers Problem</title>
</head>
<body>
    <h1>Dining Philosophers Problem</h1>
    <div class="circle">
        <div class="philosopher">P1</div>
        <div class="philosopher">P2</div>
        <div class="philosopher">P3</div>
        <div class="philosopher">P4</div>
        <div class="philosopher">P5</div>
        <div class="fork"></div>
        <div class="fork"></div>
        <div class="fork"></div>
        <div class="fork"></div>
        <div class="fork"></div>
    </div>
    <div class="description">
        <p>In this problem, each philosopher alternates between thinking and eating. To eat, a philosopher needs both the fork on their left and the fork on their right. However, they can only pick up one fork at a time.</p>
        <p>To avoid deadlock, we introduce a rule: A philosopher only attempts to pick up forks if their hunger percentage is more than 50%. If they cannot pick up both forks, they put down any fork they have picked up and continue thinking.</p>
    </div>
    <div class="code-block">
        <p><strong>Philosopher State Transitions:</strong></p>
        <ul>
            <li><code>THINKING</code> (initial state)</li>
            <li><code>HUNGRY</code> (wants to eat)</li>
            <li><code>EATING</code> (has both forks)</li>
        </ul>
    </div>
</body>
</html>
```

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

---
