#include <stdio.h>
#define SIZE 7

int hashTable[SIZE];

void initialize() {
	int i;
    for ( i = 0; i < SIZE; i++)
        hashTable[i] = -1;
}

void insert(int key) {
    int index = key % SIZE;
    int start = index;  
    int count = 0;

  
    while (hashTable[index] != -1 && count < SIZE) {
        index = (index + 1) % SIZE;
        count++;
    }

    if (count == SIZE) {
        printf("Hash Table is full! Cannot insert %d.\n", key);
        return;
    }

    hashTable[index] = key;
    printf("Inserted %d at index %d.\n", key, index);
}

void display() {
    printf("\nHash Table:\n");
    int i;
    for ( i = 0; i < SIZE; i++) {
        if (hashTable[i] != -1)
            printf("Slot %d: %d\n", i, hashTable[i]);
        else
            printf("Slot %d: Empty\n", i);
    }
}

int main() {
    initialize();

    int keys[] = {10, 20, 5, 15, 7, 3};
    int n = sizeof(keys) / sizeof(keys[0]);
int i;
    for ( i = 0; i < n; i++)
        insert(keys[i]);

    display();
    return 0;
}

