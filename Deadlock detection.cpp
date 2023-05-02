#include <stdio.h>
#include <stdbool.h>

#define NUM_PROCESSES 3
#define NUM_RESOURCES 3

int max_matrix[NUM_PROCESSES][NUM_RESOURCES] = {{3, 6, 8}, {4, 3, 3}, {3, 4, 4}};
int allocation_matrix[NUM_PROCESSES][NUM_RESOURCES] = {{3, 3, 3}, {2, 0, 3}, {1, 2, 4}};
int available_resources[NUM_RESOURCES] = {1, 2, 0};
bool finished[NUM_PROCESSES] = {false};

bool is_safe() {
    int work[NUM_RESOURCES];
    for (int i = 0; i < NUM_RESOURCES; i++) {
        work[i] = available_resources[i];
    }

    bool can_finish = true;
    while (can_finish) {
        can_finish = false;
        for (int i = 0; i < NUM_PROCESSES; i++) {
            if (!finished[i]) {
                bool can_allocate = true;
                for (int j = 0; j < NUM_RESOURCES; j++) {
                    if (max_matrix[i][j] - allocation_matrix[i][j] > work[j]) {
                        can_allocate = false;
                        break;
                    }
                }
                if (can_allocate) {
                    for (int j = 0; j < NUM_RESOURCES; j++) {
                        work[j] += allocation_matrix[i][j];
                    }
                    finished[i] = true;
                    can_finish = true;
                }
            }
        }
    }

    for (int i = 0; i < NUM_PROCESSES; i++) {
        if (!finished[i]) {
            return false;
        }
    }

    return true;
}

int main() {
    bool deadlock_detected = true;
    while (deadlock_detected) {
        deadlock_detected = false;
        for (int i = 0; i < NUM_PROCESSES; i++) {
            bool can_allocate = true;
            for (int j = 0; j < NUM_RESOURCES; j++) {
                if (max_matrix[i][j] - allocation_matrix[i][j] > available_resources[j]) {
                    can_allocate = false;
                    break;
                }
            }
            if (can_allocate && !finished[i]) {
                for (int j = 0; j < NUM_RESOURCES; j++) {
                    available_resources[j] += allocation_matrix[i][j];
                }
                finished[i] = true;
                deadlock_detected = false;
            }
        }
    }

    bool is_system_safe = is_safe();

    if (!is_system_safe) {
        printf("Deadlock detected.\n");

        printf("Deadlocked processes: ");
        for (int i = 0; i < NUM_PROCESSES; i++) {
            if (!finished[i]) {
                printf("P%d ", i + 1);
            }
        }
        printf("\n");
    } else {
        printf("No deadlock detected.\n");
    }

    return 0;
}
