#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define BLOCK_SIZE 8192
#define BLOCK_PTR_SIZE 4
#define NUM_DIRECT_BLOCKS 12

int main() {
    int num_blocks, max_file_size, i, j, k, l, m;
    int single_ptr_blocks, double_ptr_blocks, triple_ptr_blocks;
    int single_ptrs_per_block, double_ptrs_per_block, triple_ptrs_per_block;
    int num_ptrs_per_block, num_blocks_needed;
    int inode_size, num_inodes_per_block, num_data_blocks;
    int num_inodes, max_file_size_in_blocks;

    // calculate the number of blocks in the file system
    num_blocks = 0;
    for (i = 0; i < NUM_DIRECT_BLOCKS; i++) {
        num_blocks++;
    }
    single_ptr_blocks = ceil((float)BLOCK_SIZE / BLOCK_PTR_SIZE);
    num_blocks += single_ptr_blocks;
    double_ptr_blocks = pow(single_ptr_blocks, 2);
    num_blocks += double_ptr_blocks;
    triple_ptr_blocks = pow(single_ptr_blocks, 3);
    num_blocks += triple_ptr_blocks;

    // calculate the maximum file size in bytes
    max_file_size = (NUM_DIRECT_BLOCKS + single_ptr_blocks + double_ptr_blocks * single_ptr_blocks + triple_ptr_blocks * single_ptr_blocks * single_ptr_blocks) * BLOCK_SIZE;

    printf("Maximum file size: %d bytes\n", max_file_size);

    // calculate the maximum file size in blocks
    single_ptrs_per_block = BLOCK_SIZE / BLOCK_PTR_SIZE;
    double_ptrs_per_block = pow(single_ptrs_per_block, 2);
    triple_ptrs_per_block = pow(single_ptrs_per_block, 3);

    num_ptrs_per_block = NUM_DIRECT_BLOCKS + single_ptrs_per_block + double_ptrs_per_block + triple_ptrs_per_block;
    num_blocks_needed = ceil((float)num_ptrs_per_block / (BLOCK_SIZE / BLOCK_PTR_SIZE));

    inode_size = num_ptrs_per_block * BLOCK_PTR_SIZE;
    num_inodes_per_block = BLOCK_SIZE / inode_size;
    num_data_blocks = num_blocks - ceil((float)num_inodes / num_inodes_per_block);

    num_inodes = num_data_blocks / num_ptrs_per_block;
    max_file_size_in_blocks = num_ptrs_per_block * num_inodes;

    printf("Maximum file size: %d blocks\n", max_file_size_in_blocks);

    return 0;
}
