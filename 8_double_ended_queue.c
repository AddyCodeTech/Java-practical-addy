Algorithm:
1. Start
2. insertFront(VALUE): If deque is full, print "Overflow"; else move front pointer backward and insert VALUE
3. insertRear(VALUE): If deque is full, print "Overflow"; else advance rear pointer and insert VALUE
4. deleteFront(): If deque is empty, print "Underflow"; else remove element at front and advance front pointer
5. deleteRear(): If deque is empty, print "Underflow"; else remove element at rear and decrement rear pointer
6. display(): Print all elements from front to rear
7. Stop
Program:
/* Practical 8: Double Ended Queue (Deque) using Array (CO2) */
#include <stdio.h>
#define MAX 5
int arr[MAX];
int front = -1, rear = -1;
 
int isFull()
{
    return (rear == MAX - 1);
}
 
int isEmpty()
{
    return (front == -1);
}
 
/* Insert at Front */
void insertFront()
{
    int value;
 
    if (front == 0)
    {
        printf("Insertion at Front Not Possible!\n");
        return;
    }
 
    printf("Enter element: ");
    scanf("%d", &value);
 
    if (isEmpty())
    {
        front = rear = 0;
    }
    else
    {
        front--;
    }
 
    arr[front] = value;
 
    printf("%d inserted at Front.\n", value);
}
 
/* Insert at Rear */
void insertRear()
{
    int value;
 
    if (isFull())
    {
        printf("Deque Overflow!\n");
        return;
    }
 
    printf("Enter element: ");
    scanf("%d", &value);
 
    if (isEmpty())
    {
        front = rear = 0;
    }
    else
    {
        rear++;
    }
 
    arr[rear] = value;
 
    printf("%d inserted at Rear.\n", value);
}
 
/* Delete from Front */
void deleteFront()
{
    if (isEmpty())
    {
        printf("Deque Underflow!\n");
        return;
    }
 
    printf("%d deleted from Front.\n", arr[front]);
 
    if (front == rear)
    {
        front = rear = -1;
    }
    else
    {
        front++;
    }
}
 
/* Delete from Rear */
void deleteRear()
{
    if (isEmpty())
    {
        printf("Deque Underflow!\n");
        return;
    }
 
    printf("%d deleted from Rear.\n", arr[rear]);
 
    if (front == rear)
    {
        front = rear = -1;
    }
    else
    {
        rear--;
    }
}
 
void display()
{
    int i;
 
    if (isEmpty())
    {
        printf("Deque is Empty.\n");
        return;
    }
 
    printf("\nDeque Elements are:\n");
    for (i = front; i <= rear; i++)
        printf("%d ", arr[i]);
    printf("\n");
}
 
int main()
{
    int choice;
 
    do
    {
        printf("\n******** DEQUE MENU ********");
        printf("\n1. Insert Front");
        printf("\n2. Insert Rear");
        printf("\n3. Delete Front");
        printf("\n4. Delete Rear");
        printf("\n5. Display");
        printf("\n6. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
 
        switch (choice)
        {
        case 1:
            insertFront();
            break;
        case 2:
            insertRear();
            break;
        case 3:
            deleteFront();
            break;
        case 4:
            deleteRear();
            break;
        case 5:
            display();
            break;
        case 6:
            printf("Program Terminated.\n");
            break;
        default:
            printf("Invalid Choice!\n");
        }
    } while (choice != 6);
 
    return 0;
}
