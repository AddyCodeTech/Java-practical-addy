Algorithm:
PUSH(STACK, TOP, VALUE):
1. Start
2. If TOP = MAX-1, print "Stack Overflow" and exit
3. Increment TOP by 1
4. Set STACK[TOP] = VALUE
5. Stop
POP(STACK, TOP):
1. Start
2. If TOP = -1, print "Stack Underflow" and exit
3. VALUE = STACK[TOP]
4. Decrement TOP by 1
5. Return VALUE
6. Stop
DISPLAY(STACK, TOP):
1. Start
2. If TOP = -1, print "Stack is Empty" and exit
3. For i = TOP down to 0, print STACK[i]
4. Stop
  
Program:
/* Practical 1: Stack using Array - Push, Pop, Display (CO1) */
#include <stdio.h>
#define MAX 5
 
int arr[MAX];
int top = -1;
void push()
{
    int value;
    if (top == MAX - 1)
    {
        printf("Stack Overflow!\n");
        return;
    }
 
    printf("Enter element to push: ");
    scanf("%d", &value);
 
    top++;
    arr[top] = value;
 
    printf("%d inserted successfully.\n", value);
}
void pop()
{
    if (top == -1)
    {
        printf("Stack Underflow!\n");
        return;
    }
 
    printf("%d deleted successfully.\n", arr[top]);
    top--;
}
 
void display()
{
    int i;
 
    if (top == -1)
    {
        printf("Stack is Empty.\n");
        return;
    }
 
    printf("\nStack Elements are:\n");
    for (i = top; i >= 0; i--)
        printf("%d\n", arr[i]);
}
 
int main()
{
    int choice;
 
    do
    {
        printf("\n******** STACK MENU ********");
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
