Algorithm:
1. Start; initialize an empty stack
2. Scan the postfix expression from left to right:
   a. If the character is an operand, push it onto the stack
   b. If the character is an operator, pop two operands (op2 then op1), compute op1 OPERATOR op2, and push the result
3. After the scan, pop the final value from the stack — this is the result of the expression
4. Display the result
5. Stop
Program:
/* Practical 3: Evaluate a Postfix Expression using Stack (CO2) */
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#define MAX 100
int stack[MAX];
int top = -1;
void push(int value)
{
    stack[++top] = value;
}
int pop()
{
    return stack[top--];
} 
/* Perform arithmetic operation */
int calculate(int a, int b, char op)
{
    switch (op)
    {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': return a / b;
        case '^': return (int) pow(a, b);
        default:  return 0;
    }
}
int main()
{
    char postfix[MAX];
    int i, operand1, operand2, result;
 
    printf("Enter Postfix Expression: ");
    scanf("%s", postfix);
 
    for (i = 0; postfix[i] != '\0'; i++)
    {
        char ch = postfix[i];
 
        if (isdigit(ch))
        {
            push(ch - '0');
        }
        else
        {
            operand2 = pop();
            operand1 = pop();
 
            result = calculate(operand1, operand2, ch);
 
            push(result);
        }
    }
 
    printf("Result = %d\n", pop());
 
    return 0;
}
