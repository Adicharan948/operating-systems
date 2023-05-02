#include <stdio.h>

int main()
{
    int n = 4; // number of processes
    int burst_time[] = {6, 8, 7, 3}; // CPU burst time for each process
    
    int waiting_time[n], turnaround_time[n];
    int total_waiting_time = 0, total_turnaround_time = 0;
    
    // Sort processes by burst time in ascending order using Selection Sort
    for (int i = 0; i < n - 1; i++) {
        int min_index = i;
        for (int j = i + 1; j < n; j++) {
            if (burst_time[j] < burst_time[min_index]) {
                min_index = j;
            }
        }
        int temp = burst_time[i];
        burst_time[i] = burst_time[min_index];
        burst_time[min_index] = temp;
    }
    
    // Calculate waiting time and turnaround time for each process
    waiting_time[0] = 0;
    for (int i = 1; i < n; i++) {
        waiting_time[i] = waiting_time[i-1] + burst_time[i-1];
    }
    for (int i = 0; i < n; i++) {
        turnaround_time[i] = waiting_time[i] + burst_time[i];
        total_waiting_time += waiting_time[i];
        total_turnaround_time += turnaround_time[i];
    }
    
    // Print results
    printf("Process\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++) {
        printf("P%d\t%d\t\t%d\t\t%d\n", i+1, burst_time[i], waiting_time[i], turnaround_time[i]);
    }
    float avg_waiting_time = (float) total_waiting_time / n;
    float avg_turnaround_time = (float) total_turnaround_time / n;
    printf("Average Waiting Time: %.2f\n", avg_waiting_time);
    printf("Average Turnaround Time: %.2f\n", avg_turnaround_time);
    
    return 0;
}
