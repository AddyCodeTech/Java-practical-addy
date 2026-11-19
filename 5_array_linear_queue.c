Algorithm:
INSERT/ENQUEUE(VALUE):
1. Start
2. If REAR = MAX-1, print "Queue Overflow" and exit
3. If FRONT = -1, set FRONT = 0
4. Increment REAR by 1
5. Set QUEUE[REAR] = VALUE
6. Stop
DELETE/DEQUEUE():
1. Start
2. If FRONT = -1 or FRONT > REAR, print "Queue Underflow" and exit
3. VALUE = QUEUE[FRONT]
4. Increment FRONT by 1
5. Return VALUE
6. Stop
Program:
/* Practical 5: Linear Queue using Array (CO1) */
#include <stdio.h>
#define MAX 5
int queue[MAX];
int front = -1, rear = -1;
void enqueue()
{
    int value;
 
    if (rear == MAX - 1)
    {
        printf("Queue Overflow!\n");
        return;
    }
    printf("Enter element: ");
    scanf("%d", &value);
 
    if (front == -1)
        front = 0;
 
    rear++;
    queue[rear] = value;
    printf("%d inserted successfully.\n", value);
}
void dequeue()
{
    if (front == -1)
    {
        printf("Queue Underflow!\n");
        return;
    }
    printf("%d deleted successfully.\n", queue[front]);
    if (front == rear)
    {
        front = rear = -1;
    }
    else
    {
        front++;
    }
}
 
void display()
{
    int i;
 
    if (front == -1)
    {
        printf("Queue is Empty.\n");
        return;
    }
    printf("\nQueue Elements are:\n");
    for (i = front; i <= rear; i++)
        printf("%d ", queue[i]);
    printf("\n");
}
int main()
{
    int choice;
 
    do
    {
        printf("\n******** LINEAR QUEUE MENU ********");
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
