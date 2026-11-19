Algorithm:
1. Start; initialize an empty stack and an empty postfix string
2. Scan the infix expression from left to right; for each character:
   a. If it is an operand, append it directly to the postfix string
   b. If it is '(', push it onto the stack
   c. If it is ')', pop from the stack and append to postfix until '(' is found; discard the '('
   d. If it is an operator, pop and append operators from the stack while the top has greater or equal precedence, then push the current operator
3. After the scan, pop any remaining operators from the stack and append them to postfix
4. Display the postfix expression
5. Stop
Program:
/* Practical 2: Infix to Postfix conversion using Stack (CO1) */
#include <stdio.h>
#include <string.h>
#include <ctype.h>
 
#define MAX 100
 
char stack[MAX];
int top = -1;
 
void push(char c)
{
    stack[++top] = c;
}
 
char pop()
{
    return stack[top--];
}
 
char peek()
{
    return stack[top];
}
int isEmpty()
{
    return top == -1;
}
/* Precedence of operators */
int precedence(char op)
{
    if (op == '^')
        return 3;
    else if (op == '*' || op == '/')
        return 2;
    else if (op == '+' || op == '-')
        return 1;
    else
        return 0;
}
/* Check whether character is an operator */
int isOperator(char ch)
{
    return (ch == '+' || ch == '-' || ch == '*' ||
            ch == '/' || ch == '^');
} 
void infixToPostfix(char infix[], char postfix[])
{
    int i, j = 0;
    char ch;
    for (i = 0; infix[i] != '\0'; i++)
    {
        ch = infix[i];
        /* Operand */
        if (isalnum(ch))
        {
            postfix[j++] = ch;
        }
        /* Left Parenthesis */
        else if (ch == '(')
        {
            push(ch);
        }
        /* Right Parenthesis */
        else if (ch == ')')
        {
            while (!isEmpty() && peek() != '(')
            {
                postfix[j++] = pop();
            }
            if (!isEmpty())
                pop(); /* Remove '(' */
        }
        /* Operator */
        else if (isOperator(ch))
        {
            while (!isEmpty() && precedence(peek()) >= precedence(ch))
            {
                postfix[j++] = pop();
            }
            push(ch);
        }
    }
    /* Pop remaining operators */
    while (!isEmpty())
    {
        postfix[j++] = pop();
    }
    postfix[j] = '\0';
}
int main()
{
    char infix[MAX], postfix[MAX];
 
    printf("Enter Infix Expression: ");
    scanf("%s", infix);
 
    infixToPostfix(infix, postfix);
 
    printf("Postfix Expression: %s\n", postfix);
    return 0;
}
