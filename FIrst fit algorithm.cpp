#include <stdio.h>

#define MAX_PARTITIONS 6
#define MAX_PROCESSES 5

int partitions[MAX_PARTITIONS] = {300, 600, 350, 200, 750, 125};
int processes[MAX_PROCESSES] = {115, 500, 358, 200, 375};
int allocation[MAX_PROCESSES] = {-1, -1, -1, -1, -1};

void firstFit(int partitions[], int m, int processes[], int n) {
    int i, j;
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            if (partitions[j] >= processes[i]) {
                allocation[i] = j;
                partitions[j] -= processes[i];
                break;
            }
        }
    }
}

void printAllocation() {
    printf("\nProcess No.\tProcess Size\tPartition No.\n");
    for (int i = 0; i < MAX_PROCESSES; i++) {
        printf(" %d \t\t %d \t\t", i+1, processes[i]);
        if (allocation[i] != -1)
            printf("%d\n", allocation[i]+1);
        else
            printf("Not Allocated\n");
    }
}

int main() {
    firstFit(partitions, MAX_PARTITIONS, processes, MAX_PROCESSES);
    printAllocation();
    return 0;
}
