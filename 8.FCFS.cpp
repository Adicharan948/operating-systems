#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int n = 5;  
    int track_pos[] = {55, 58, 60, 70, 18};
    int head_pos = 50;
    int total_head_movement = 0;  
    
    
    for (int i = 0; i < n; i++) {
        total_head_movement += abs(track_pos[i] - head_pos);
        head_pos = track_pos[i];
    }
    
    
    float avg_head_movement = (float)total_head_movement / n;
    
    
    printf("Total head movement: %d\n", total_head_movement);
    printf("Average head movement: %f\n", avg_head_movement);
    
    return 0;
}
