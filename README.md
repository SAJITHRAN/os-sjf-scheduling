# SJF CPU Scheduling (Non-Preemptive)

This project implements the **Shortest Job First (SJF) Non-Preemptive CPU Scheduling algorithm** in C as part of an Operating Systems assignment.

## Description

Shortest Job First (SJF) scheduling selects the process with the **smallest burst time** from the set of processes that have already arrived.
In the **Non-Preemptive version**, once a process starts executing, it continues until it finishes.

The program calculates:

* Waiting Time (WT)
* Turnaround Time (TAT)
* Average Waiting Time
* Average Turnaround Time

## Input Format

```
n
PID ArrivalTime BurstTime
```

Example:

```
5
P1 0 4
P2 1 3
P3 2 1
P4 3 2
P5 4 6
```

## Output

The program prints:

* Waiting Time for each process
* Turnaround Time for each process
* Average Waiting Time
* Average Turnaround Time

Example Output:

```
Waiting Time:
P1 0
P2 6
P3 2
P4 2
P5 6

Turnaround Time:
P1 4
P2 9
P3 3
P4 4
P5 12

Average Waiting Time: 3.20
Average Turnaround Time: 6.40
```

## Language Used

C Programming

## Author

Sajithran
Operating Systems Assignment
