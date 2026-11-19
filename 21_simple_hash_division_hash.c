Algorithm:
INSERT(key):
1. Compute index = key % TABLE_SIZE
2. If the slot at index is empty, place key there
3. Else, probe the next slot using linear probing: index = (index + 1) % TABLE_SIZE, and repeat until an empty slot is found
4. Stop
Program:
/* Practical 21: Simple Hash Table using Division Hash Function (CO3) */
#include <stdio.h>
#define SIZE 10
int hashTable[SIZE];
int isOccupied[SIZE] = {0};
 
int hashFunction(int key) { return key % SIZE; }
 
void insert(int key) {
    int index = hashFunction(key);
    int original = index;
    while (isOccupied[index]) {
        index = (index + 1) % SIZE;
        if (index == original) { printf("Hash Table Full!\n"); return; }
    }
    hashTable[index] = key;
    isOccupied[index] = 1;
    printf("%d inserted at index %d\n", key, index);
}
void display() {
    printf("\nHash Table:\n");
    for (int i = 0; i < SIZE; i++) {
        if (isOccupied[i]) printf("Index %d: %d\n", i, hashTable[i]);
        else printf("Index %d: empty\n", i);
    }
}
int main() {
    int n, key;
    printf("Enter number of elements to insert: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &key);
        insert(key);
    }
    display();
    return 0;
}
