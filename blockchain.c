#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// TODO: Implement a simple hash function or use a real one
void simple_hash(char *input, char *output) {
    // Simulate a hash by processing the input string
}

// Block structure
typedef struct Block {
    int index;
    char timestamp[100];
    char data[256];
    char previousHash[256];
    char hash[256];
    struct Block* next;
} Block;

// TODO: Fill this to get current time in string format
void get_timestamp(char *buffer) {
    // Fill buffer with current date-time
}

// TODO: Implement logic to create a new block
Block* create_block(int index, char *data, char *previousHash) {
    Block* newBlock = (Block*)malloc(sizeof(Block));
    
    // Fill the block fields (index, data, timestamp, previousHash)
    
    // Create a string from block data to hash
    
    // Call simple_hash on the string and store in block->hash

    newBlock->next = NULL;
    return newBlock;
}

// TODO: Implement logic to add a block to the chain
void add_block(Block **head, char *data) {
    // Traverse to the last block
    // Get index and previousHash
    // Call create_block and link the new block
}

// TODO: Print all blocks in the blockchain
void print_chain(Block *head) {
    // Traverse the chain and print block details
}

int main() {
    Block* blockchain = NULL;

    // TODO: Add a few blocks with sample data
    // add_block(&blockchain, "Genesis Block");
    // add_block(&blockchain, "Sample transaction");

    // TODO: Print the chain
    // print_chain(blockchain);

    // TODO: Free the chain
    return 0;
}
