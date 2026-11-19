Algorithm:
INSERT(VALUE, PRIORITY):
1. Start
2. Create a new node storing VALUE and PRIORITY
3. If list is empty or new PRIORITY is higher than the head node's, insert the new node at the front
4. Else, traverse the list to find the correct position by priority, and insert the node there
5. Stop
DELETE():
1. Start
2. If list is empty, print "Queue Underflow" and exit
3. Remove the front node (highest priority) and update the head pointer
4. Return the removed value
5. Stop
Program:
/* Practical 7: Priority Queue using Linked List (CO2) */
#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    int priority;
    struct Node *next;
}; 
struct Node *front = NULL;
 
/* Insert according to priority (smaller number = higher priority) */
void enqueue()
{
    struct Node *newNode = (struct Node *) malloc(sizeof(struct Node));
    struct Node *temp;
 
    printf("Enter Data : ");
    scanf("%d", &newNode->data);
 
    printf("Enter Priority (Smaller Number = Higher Priority): ");
    scanf("%d", &newNode->priority);
    newNode->next = NULL;
 
    /* Queue Empty */
    if (front == NULL)
    {
        front = newNode;
    }
    /* Insert at beginning */
    else if (newNode->priority < front->priority)
    {
        newNode->next = front;
        front = newNode;
    }
    else
    {
        temp = front;
 
        while (temp->next != NULL &&
               temp->next->priority <= newNode->priority)
        {
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }
 
    printf("Element inserted successfully.\n");
}
 
/* Delete highest priority element */
void dequeue()
{
    struct Node *temp;
 
    if (front == NULL)
    {
        printf("Priority Queue Underflow!\n");
        return;
    }
 
    temp = front;
    printf("Deleted Element = %d\n", temp->data);
 
    front = front->next;
    free(temp);
}
 
void display()
{
    struct Node *temp = front;
 
    if (front == NULL)
    {
        printf("Priority Queue is Empty.\n");
        return;
    }
 
    printf("\nData\tPriority\n");
    printf("------------------\n");
 
    while (temp != NULL)
    {
        printf("%d\t%d\n", temp->data, temp->priority);
        temp = temp->next;
    }
}
 
int main()
{
    int choice;
 
    do
    {
        printf("\n****** PRIORITY QUEUE MENU ******");
        printf("\n1. Insert");
        printf("\n2. Delete");
        printf("\n3. Display");
        printf("\n4. Exit");
        printf("\nEnter Choice : ");
        scanf("%d", &choice);
 
        switch (choice)
        {
        case 1:
            enqueue();
            break;
        case 2:
            dequeue();
            break;
        case 3:
            display();
            break;
        case 4:
            printf("Program Terminated.\n");
            break;
        default:
            printf("Invalid Choice!\n");
        }
    } while (choice != 4);
 
    return 0;
}
