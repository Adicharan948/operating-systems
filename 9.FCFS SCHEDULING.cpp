#include <stdio.h>

struct Process {
    int pid;
    int burst_time;
    int waiting_time;
    int turnaround_time;
};

void fcfs(struct Process processes[], int n) {
    int i;
    float avg_waiting_time, avg_turnaround_time;
    int total_waiting_time = 0, total_turnaround_time = 0;
    int current_time = 0;

    for (i = 0; i < n; i++) {
        processes[i].waiting_time = current_time;
        current_time += processes[i].burst_time;
        processes[i].turnaround_time = current_time;
        total_waiting_time += processes[i].waiting_time;
        total_turnaround_time += processes[i].turnaround_time;
    }

    avg_waiting_time = (float)total_waiting_time / n;
    avg_turnaround_time = (float)total_turnaround_time / n;

    printf("Average Waiting Time = %.2f\n", avg_waiting_time);
    printf("Average Turnaround Time = %.2f\n", avg_turnaround_time);
}

int main() {
    struct Process processes[] = {{0, 2, 0, 0}, {1, 4, 0, 0}, {2, 8, 0, 0}};
    int n = sizeof(processes) / sizeof(processes[0]);

    fcfs(processes, n);

    return 0;
}
