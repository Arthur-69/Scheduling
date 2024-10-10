#include <stdio.h>
#include <stdlib.h>

struct Process {
    int pid;
    int arrival_time;
    int burst_time;
    int turnaround_time;
    int waiting_time;
    int response_time;
};

void fcfs(struct Process proc[], int n) {
    int total_wt = 0, total_tat = 0, total_rt = 0;
    int current_time = 0;

    printf("\n=== First Come First Served (FCFS) ===\n");
    printf("Gantt Chart: ");
    
    for (int i = 0; i < n; i++) {
        if (current_time < proc[i].arrival_time) {
            current_time = proc[i].arrival_time; 
        }

        proc[i].response_time = current_time - proc[i].arrival_time;
        proc[i].waiting_time = proc[i].response_time;
        proc[i].turnaround_time = proc[i].waiting_time + proc[i].burst_time;
        current_time += proc[i].burst_time;

        printf("| P%d ", proc[i].pid);

        total_wt += proc[i].waiting_time;
        total_tat += proc[i].turnaround_time;
        total_rt += proc[i].response_time;
    }
    printf("|\n\n");
    
    printf("PID     AT     BT     WT     TAT    RT\n");
    for (int i = 0; i < n; i++) {
        printf("%d       %d      %d      %d      %d      %d\n", 
            proc[i].pid, proc[i].arrival_time, proc[i].burst_time,
            proc[i].waiting_time, proc[i].turnaround_time, proc[i].response_time);
    }

    printf("\nAverage Waiting Time: %.2f\n", (float)total_wt / n);
    printf("Average Turnaround Time: %.2f\n", (float)total_tat / n);
    printf("Average Response Time: %.2f\n", (float)total_rt / n);
}

void sjf(struct Process proc[], int n) {
    int total_wt = 0, total_tat = 0, total_rt = 0;
    int current_time = 0;
    int completed = 0;
    int is_completed[n]; 
    for (int i = 0; i < n; i++) is_completed[i] = 0;

    printf("\n=== Shortest Job First (SJF) ===\n");
    printf("Gantt Chart: ");

    while (completed != n) {
        int idx = -1;
        int min_bt = 10000; 

        for (int i = 0; i < n; i++) {
            if (proc[i].arrival_time <= current_time && is_completed[i] == 0) {
                if (proc[i].burst_time < min_bt) {
                    min_bt = proc[i].burst_time;
                    idx = i;
                } else if (proc[i].burst_time == min_bt) {
                    if (proc[i].arrival_time < proc[idx].arrival_time) {
                        idx = i;
                    }
                }
            }
        }

        if (idx != -1) {
            proc[idx].response_time = current_time - proc[idx].arrival_time;
            proc[idx].waiting_time = proc[idx].response_time;
            proc[idx].turnaround_time = proc[idx].waiting_time + proc[idx].burst_time;
            current_time += proc[idx].burst_time;
            is_completed[idx] = 1;
            completed++;

            printf("| P%d ", proc[idx].pid);

            total_wt += proc[idx].waiting_time;
            total_tat += proc[idx].turnaround_time;
            total_rt += proc[idx].response_time;
        } else {
            current_time++;
        }
    }
    printf("|\n\n");

    printf("PID     AT     BT     WT     TAT    RT\n");
    for (int i = 0; i < n; i++) {
        printf("%d       %d      %d      %d      %d      %d\n", 
            proc[i].pid, proc[i].arrival_time, proc[i].burst_time,
            proc[i].waiting_time, proc[i].turnaround_time, proc[i].response_time);
    }

    printf("\nAverage Waiting Time: %.2f\n", (float)total_wt / n);
    printf("Average Turnaround Time: %.2f\n", (float)total_tat / n);
    printf("Average Response Time: %.2f\n", (float)total_rt / n);
}

int main() {
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    struct Process proc[n];

    for (int i = 0; i < n; i++) {
        printf("Enter the arrival time and burst time for process %d: ", i + 1);
        proc[i].pid = i + 1;
        scanf("%d %d", &proc[i].arrival_time, &proc[i].burst_time);
    }

    fcfs(proc, n);
    sjf(proc, n);

    return 0;
}

