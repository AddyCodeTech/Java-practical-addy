Algorithm:
PUSH(VALUE):
1. Start
2. Create a new node and store VALUE in it
3. Set new node's next pointer to the current TOP
4. Set TOP = new node
5. Stop
POP():
1. Start
2. If TOP = NULL, print "Stack Underflow" and exit
3. temp = TOP
4. TOP = TOP->next
5. VALUE = temp->data; free/delete temp
6. Return VALUE
7. Stop
Program:
/* Practical 4: Stack using Linked List (CO2) */
#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};
struct Node *top = NULL;
void push()
{
    int value;
    struct Node *newNode;
    printf("Enter element: ");
    scanf("%d", &value);
    newNode = (struct Node *) malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = top;
    top = newNode;
    printf("%d inserted successfully.\n", value);
}
void pop()
{
    struct Node *temp;
    if (top == NULL)
    {
        printf("Stack Underflow!\n");
        return;
    }
    temp = top;
    printf("%d deleted successfully.\n", temp->data);
 
    top = top->next;
    free(temp);
}
void display()
{
    struct Node *temp = top;
    if (top == NULL)
    {
        printf("Stack is Empty.\n");
        return;
    }
 
    printf("\nStack Elements are:\n");
    while (temp != NULL)
    {
        printf("%d\n", temp->data);
        temp = temp->next;
    }
}
 
int main()
{
    int choice;
 
    do
    {
        printf("\n******** STACK USING LINKED LIST ********");
        printf("\n1. Push");
        printf("\n2. Pop");
        printf("\n3. Display");
        printf("\n4. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            push();
            break;
        case 2:
            pop();
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
