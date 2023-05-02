#include <stdio.h>

#define MAX_PAGE_FRAMES 10

int num_page_frames = 3;

int page_frames[MAX_PAGE_FRAMES];
int page_faults = 0;

void print_page_frames() {
    printf("[ ");
    for (int i = 0; i < num_page_frames; i++) {
        if (page_frames[i] == -1) {
            printf("- ");
        } else {
            printf("%d ", page_frames[i]);
        }
    }
    printf("]\n");
}

int is_page_in_frames(int page) {
    for (int i = 0; i < num_page_frames; i++) {
        if (page_frames[i] == page) {
            return 1;
        }
    }
    return 0;
}
int get_least_recently_used_page() {
    int lru_page_index = 0;
    int lru_page_time = page_frames[0];
    for (int i = 1; i < num_page_frames; i++) {
        if (page_frames[i] < lru_page_time) {
            lru_page_index = i;
            lru_page_time = page_frames[i];
        }
    }
    return lru_page_index;
}

int main() {
    
    for (int i = 0; i < MAX_PAGE_FRAMES; i++) {
        page_frames[i] = -1;
    }

    int page_reference_sequence[] = {1,2,3,2,1,5,2,1,6,2,5,6,3,1,3,6,1,2,4,3};
    int num_pages = sizeof(page_reference_sequence) / sizeof(int);

    for (int i = 0; i < num_pages; i++) {
        int page = page_reference_sequence[i];

        if (is_page_in_frames(page)) {
            printf("Page %d is already in frames: ", page);
            print_page_frames();
        } else {
            printf("Page %d is not in frames, replacing least recently used page: ", page);
            int lru_page_index = get_least_recently_used_page();
            page_frames[lru_page_index] = page;
            page_faults++;
            print_page_frames();
        }
    }

    printf("Total number of page faults: %d\n", page_faults);

    return 0;
}

