#include <stdio.h>

#define NUM_PROCESSES 4
#define NUM_RESOURCES 3

int main() {
    int claim[NUM_PROCESSES][NUM_RESOURCES] = {{3, 2, 2}, {6, 1, 3}, {3, 1, 4}, {4, 2, 2}};
    int allocation[NUM_PROCESSES][NUM_RESOURCES] = {{1, 0, 0}, {6, 1, 2}, {2, 1, 1}, {0, 0, 2}};
    int available[NUM_RESOURCES] = {9, 3, 6};
    int work[NUM_RESOURCES];
    int finish[NUM_PROCESSES] = {0};
    int safeSequence[NUM_PROCESSES];
    int numSafe = 0;

    
    for (int i = 0; i < NUM_RESOURCES; i++) {
        work[i] = available[i];
    }

    
    while (numSafe < NUM_PROCESSES) {
        int found = 0;

        for (int i = 0; i < NUM_PROCESSES; i++) {
            if (!finish[i]) {
                int j;
                for (j = 0; j < NUM_RESOURCES; j++) {
                    if (claim[i][j] - allocation[i][j] > work[j]) {
                        break;
                    }
                }

                if (j == NUM_RESOURCES) {
                    
                    for (j = 0; j < NUM_RESOURCES; j++) {
                        work[j] += allocation[i][j];
                    }

                    
                    finish[i] = 1;
                    safeSequence[numSafe] = i;
                    numSafe++;

                    found = 1;
                }
            }
        }

        if (!found) {
            
            printf("Unsafe state\n");
            return 0;
        }
    }

    
    printf("Safe state, safe sequence: ");
    for (int i = 0; i < NUM_PROCESSES; i++) {
        printf("%d ", safeSequence[i]);
    }
    printf("\n");

    return 0;
}
