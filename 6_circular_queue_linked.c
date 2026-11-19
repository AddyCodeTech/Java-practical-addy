Algorithm:
INSERT(VALUE):
1. Start
2. Create a new node and store VALUE in it
3. If queue is empty, set FRONT = REAR = new node, and new node->next = new node
4. Else, new node->next = FRONT; REAR->next = new node; REAR = new node
5. Stop
DELETE():
1. Start
2. If queue is empty, print "Queue Underflow" and exit
3. If FRONT = REAR (only one node), delete it and set FRONT = REAR = NULL
4. Else, temp = FRONT; FRONT = FRONT->next; REAR->next = FRONT; delete temp
5. Stop
Program:
/* Practical 6: Circular Queue using Linked List (CO2) */
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
 
    if (front == NULL)
    {
        front = rear = newNode;
        rear->next = front;
    }
    else
    {
        rear->next = newNode;
        rear = newNode;
        rear->next = front;
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
    if (front == rear)
    {
        printf("%d deleted successfully.\n", front->data);
        free(front);
        front = rear = NULL;
    }
    else
    {
        temp = front;
        printf("%d deleted successfully.\n", temp->data);
 
        front = front->next;
        rear->next = front;
 
        free(temp);
    }
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
    do
    {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != front);
 
    printf("\n");
}
 
int main()
{
    int choice;
 
    do
    {
        printf("\n******** CIRCULAR QUEUE MENU ********");
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
