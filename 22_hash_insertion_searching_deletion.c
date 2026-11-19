Algorithm:
SEARCH(key):
1. Compute index = hash(key)
2. While the slot is not empty: if slot = key, return "Found"; else probe the next index
3. If the loop ends without a match, return "Not Found"

DELETE(key):
1. Locate the key using the SEARCH procedure
2. If found, mark the slot as deleted (tombstone)
3. Else, print "Key not found"
Program:
/* Practical 22: Insertion, Searching, Deletion in Hash Table (CO3) */
#include <stdio.h>
#define SIZE 10
int hashTable[SIZE];
int isOccupied[SIZE] = {0};
int hashFunction(int key) { return key % SIZE; }
 
void insert(int key) {
    int index = hashFunction(key), original = index;
    while (isOccupied[index]) {
        index = (index + 1) % SIZE;
        if (index == original) { printf("Hash Table Full!\n"); return; }
    }
    hashTable[index] = key;
    isOccupied[index] = 1;
    printf("%d inserted at index %d\n", key, index);
}
int search(int key) {
    int index = hashFunction(key), original = index;
    while (isOccupied[index]) {
        if (hashTable[index] == key) return index;
        index = (index + 1) % SIZE;
        if (index == original) break;
    }
    return -1;
}
void deleteKey(int key) {
    int index = search(key);
    if (index == -1) { printf("%d not found!\n", key); return; }
    isOccupied[index] = 0;
    printf("%d deleted from index %d\n", key, index);
}
void display() {
    printf("\nHash Table:\n");
    for (int i = 0; i < SIZE; i++) {
        if (isOccupied[i]) printf("Index %d: %d\n", i, hashTable[i]);
        else printf("Index %d: empty\n", i);
    }
}
int main() {
    int choice, key;
    do {
        printf("\n******** HASH TABLE MENU ********\n1. Insert\n2. Search\n3. Delete\n4. Display\n5. Exit\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: printf("Enter key: "); scanf("%d", &key); insert(key); break;
            case 2: printf("Enter key to search: "); scanf("%d", &key);
                    { int idx = search(key);
                      if (idx != -1) printf("%d found at index %d\n", key, idx);
                      else printf("%d not found.\n", key); }
                    break;
            case 3: printf("Enter key to delete: "); scanf("%d", &key); deleteKey(key); break;
            case 4: display(); break;
            case 5: printf("Program Terminated.\n"); break;
            default: printf("Invalid Choice!\n");
        }
    } while (choice != 5);
    return 0;
}
