Report: Process Scheduling Simulation (FCFS & SJF)

1. Introduction

The purpose of this project is to simulate process scheduling using two algorithms: First Come First Served (FCFS) and Shortest Job First (SJF). Process scheduling is a fundamental aspect of operating system design, where processes are scheduled to run on the CPU based on their attributes such as arrival time and burst time.

The simulation calculates key performance metrics for processes:

 • Turnaround Time (TAT): Total time taken from process arrival to completion.
 • Waiting Time (WT): Time spent by the process waiting in the ready queue.
 • Response Time (RT): Time from the process arrival to its first execution.

2. Process Structure

The program defines a Process structure to represent each process. It contains:

 • pid: Process ID.
 • arrival_time: Time when the process arrives in the system.
 • burst_time: CPU burst time required by the process.
 • turnaround_time: Time taken from process arrival to completion (calculated later).
 • waiting_time: Time spent waiting in the queue before execution (calculated later).
 • response_time: Time from process arrival to the first execution (same as waiting time in non-preemptive algorithms).

This structure is used to hold process-related data for further computations.

struct Process {
    int pid;
    int arrival_time;
    int burst_time;
    int turnaround_time;
    int waiting_time;
    int response_time;
};

3. FCFS Scheduling Algorithm

The First Come First Served (FCFS) algorithm schedules processes in the order of their arrival times. This is a non-preemptive algorithm, meaning once a process starts executing, it runs to completion.

Key Steps:

 • Sort processes by arrival time.
 • For each process, compute:
 • Turnaround Time (TAT): Finish time - Arrival time.
 • Waiting Time (WT): Turnaround Time - Burst Time.
 • Response Time (RT): The same as the waiting time for non-preemptive algorithms.

The function fcfs() implements this algorithm, iterating over the processes and calculating the required metrics.

4. SJF Scheduling Algorithm

The Shortest Job First (SJF) algorithm selects processes based on the shortest burst time. This is also a non-preemptive algorithm.

Key Steps:

 • Sort processes by burst time. If two processes have the same burst time, the one with the earlier arrival time is selected first.
 • Compute the same metrics: Turnaround Time, Waiting Time, and Response Time.
 • Once the shortest job is executed, the function moves to the next shortest job.

The function sjf() implements this algorithm, considering both burst time and arrival time when scheduling processes.

5. Main Function Workflow

The main() function acts as the driver for the entire simulation. It performs the following operations:

 • Reads the number of processes and their respective arrival times and burst times.
 • Initializes the Process array with user input.
 • Calls the FCFS and SJF scheduling functions.
 • Outputs the Gantt Chart, process metrics (PID, AT, BT, WT, TAT, RT), and average performance metrics for each scheduling algorithm.

6. Gantt Chart Representation

The Gantt Chart shows the order in which processes are executed. It is displayed for both FCFS and SJF scheduling algorithms. The chart visually represents the execution order of processes over time.

Example of FCFS Gantt chart:

Gantt Chart: | P1 |   P2   |   P3   |   P4   |

Example of SJF Gantt chart:

Gantt Chart: | P2 | P4 |   P1   |   P3   |

7. Performance Metrics

For each algorithm, the following metrics are calculated for each process:

 • Turnaround Time (TAT): Completion time - Arrival time.
 • Waiting Time (WT): Turnaround Time - Burst Time.
 • Response Time (RT): Time from process arrival to the first execution (same as WT for non-preemptive algorithms).

The program also computes the average waiting time, average turnaround time, and average response time for all processes and displays them after executing each algorithm.

8. Sample Input and Output

Sample Input:

Enter the number of processes: 4
Enter the arrival time and burst time for process 1: 0 8
Enter the arrival time and burst time for process 2: 1 4
Enter the arrival time and burst time for process 3: 2 9
Enter the arrival time and burst time for process 4: 3 5

Sample Output (FCFS):

=== First Come First Served (FCFS) ===
Gantt Chart: | P1 |   P2   |   P3   |   P4   |
PID     AT     BT     WT     TAT    RT
1       0      8      0      8      0
2       1      4      7      11     7
3       2      9      10     19     10
4       3      5      18     23     18

Average Waiting Time: 8.75
Average Turnaround Time: 15.25
Average Response Time: 8.75

Sample Output (SJF):

=== Shortest Job First (SJF) ===
Gantt Chart: | P2 | P4 |   P1   |   P3   |
PID     AT     BT     WT     TAT    RT
1       0      8      0      8      0
2       1      4      7      11     7
3       2      9      15     24     15
4       3      5      9      14     9

Average Waiting Time: 5.25
Average Turnaround Time: 11.75
Average Response Time: 5.25

