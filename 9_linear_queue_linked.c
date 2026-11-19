Algorithm:
INSERT(VALUE):
1. Start
2. Create a new node with VALUE, next = NULL
3. If queue is empty, set FRONT = REAR = new node
4. Else, REAR->next = new node; REAR = new node
5. Stop
DELETE():
1. Start
2. If FRONT = NULL, print "Queue Underflow" and exit
3. temp = FRONT; FRONT = FRONT->next
4. If FRONT = NULL, set REAR = NULL
5. VALUE = temp->data; delete temp
6. Return VALUE
7. Stop
Program:
/* Practical 9: Linear Queue using Linked List (CO2) */
#include <stdio.h>
#include <stdlib.h>
 
struct Node
{
    int data;
    struct Node *next;
};
 
struct Node *front = NULL;
struct Node *rear = NULL;
 
void enqueue()
{
    int value;
    struct Node *newNode;
 
    printf("Enter element: ");
    scanf("%d", &value);
 
    newNode = (struct Node *) malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
 
    if (rear == NULL)
    {
        front = rear = newNode;
    }
    else
    {
        rear->next = newNode;
        rear = newNode;
    }
 
    printf("%d inserted successfully.\n", value);
}
 
void dequeue()
{
    struct Node *temp;
 
    if (front == NULL)
    {
        printf("Queue Underflow!\n");
        return;
    }
 
    temp = front;
    printf("%d deleted successfully.\n", temp->data);
 
    front = front->next;
    if (front == NULL)
        rear = NULL;
 
    free(temp);
}
 
void display()
{
    struct Node *temp = front;
 
    if (front == NULL)
    {
        printf("Queue is Empty.\n");
        return;
    }
 
    printf("\nQueue Elements are:\n");
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}
 
int main()
{
    int choice;
 
    do
    {
        printf("\n******** LINEAR QUEUE USING LINKED LIST ********");
        printf("\n1. Enqueue");
        printf("\n2. Dequeue");
        printf("\n3. Display");
        printf("\n4. Exit");
        printf("\nEnter your choice: ");
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
