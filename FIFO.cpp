#include <stdio.h>

int main()
 {
    int frames, pages, i, j, page_faults = 0, next_frame = 0;
    printf("Enter the number of page frames: ");
    scanf("%d", &frames);
    int page_frames[frames], page_ref_seq[100];
    printf("Enter the page reference sequence (terminate with -1): ");
    for (i = 0; i < 100; i++) {
        scanf("%d", &pages);
        if (pages == -1)
            break;
        page_ref_seq[i] = pages;
    }
    int ref_seq_length = i;
    
    for (i = 0; i < frames; i++)
        page_frames[i] = -1;
    printf("Page Reference Sequence\tPage Frames\tPage Faults\n");
    for (i = 0; i < ref_seq_length; i++) {
        int page_found = 0;
        
        for (j = 0; j < frames; j++) {
            if (page_frames[j] == page_ref_seq[i]) {
                page_found = 1;
                break;
            }
        }
        
        if (!page_found) {
            page_faults++;
            page_frames[next_frame] = page_ref_seq[i];
            next_frame = (next_frame + 1) % frames;
        }
        
        printf("%d\t\t\t", page_ref_seq[i]);
        for (j = 0; j < frames; j++) {
            if (page_frames[j] != -1)
                printf("%d ", page_frames[j]);
            else
                printf("- ");
        }
        printf("\t\t%d\n", page_faults);
    }
    printf("Total page faults: %d\n", page_faults);
    return 0;
}
