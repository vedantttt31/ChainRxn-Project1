#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


void simple_hash(char *input, char *output) {
    unsigned int hash = 0;
    for (int i = 0; input[i] != '\0'; i++) {
        hash += input[i];
        hash = hash * 31 + input[i];
    }
    sprintf(output, "%u", hash);
}


typedef struct Block {
    int index;
    char timestamp[100];
    char data[256];
    char previousHash[256];
    char hash[256];
    struct Block* next;
} Block;


void get_timestamp(char *buffer) {
    time_t now = time(NULL);
    struct tm *t = localtime(&now);
    strftime(buffer, 100, "%Y-%m-%d %H:%M:%S", t);
}


Block* create_block(int index, char *data, char *previousHash) {
    Block* newBlock = (Block*)malloc(sizeof(Block));
    newBlock->index = index;
    strcpy(newBlock->data, data);
    strcpy(newBlock->previousHash, previousHash);
    get_timestamp(newBlock->timestamp);

    // Create a string from block contents to generate hash
    char toHash[1024];
    sprintf(toHash, "%d%s%s%s", index, newBlock->timestamp, data, previousHash);
    simple_hash(toHash, newBlock->hash);

    newBlock->next = NULL;
    return newBlock;
}

// Add a block to the blockchain
void add_block(Block **head, char *data) {
    if (*head == NULL) {
        *head = create_block(0, data, "0"); // Genesis block
    } else {
        Block *current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = create_block(current->index + 1, data, current->hash);
    }
}

// Print all blocks in the blockchain
void print_chain(Block *head) {
    Block *current = head;
    while (current != NULL) {
        printf("Block #%d\n", current->index);
        printf("Timestamp: %s\n", current->timestamp);
        printf("Data: %s\n", current->data);
        printf("Previous Hash: %s\n", current->previousHash);
        printf("Hash: %s\n", current->hash);
        printf("-----------------------------\n");
        current = current->next;
    }
}

// Free the blockchain
void free_chain(Block *head) {
    while (head != NULL) {
        Block* temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    Block* blockchain = NULL;

    add_block(&blockchain, "Genesis Block");
    add_block(&blockchain, "Alice pays Bob 10 BTC");
    add_block(&blockchain, "Bob pays Charlie 5 BTC");

    print_chain(blockchain);
    free_chain(blockchain);

    return 0;
}
