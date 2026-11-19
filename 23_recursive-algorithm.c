Algorithm:
FACTORIAL(n):
1. If n = 0, return 1 (base case)
2. Else, return n * FACTORIAL(n-1)
3. Stop
Program:
/* Practical 23: Analyze Recursive Algorithm Mathematically & Implement in C (CO4)
 * Example: Factorial using Recursion
 * Recurrence Relation: T(n) = T(n-1) + O(1), T(0) = O(1)
 * Solving by back-substitution: T(n) = O(n)
 */
#include <stdio.h>
long long factorial(int n) {
    if (n == 0 || n == 1) return 1;      /* Base case: O(1) */
    return n * factorial(n - 1);          /* Recursive case: T(n-1) + O(1) */
}
int main() {
    int n;
    printf("Enter a number: ");
    scanf("%d", &n);
    printf("Factorial of %d = %lld\n", n, factorial(n));
    printf("\nMathematical Analysis:\n");
    printf("Recurrence Relation : T(n) = T(n-1) + c\n");
    printf("Base Condition      : T(0) = c\n");
    printf("Solving by substitution:\n");
    printf("T(n) = T(n-1) + c\n");
    printf("     = T(n-2) + 2c\n");
    printf("     = ... = T(0) + nc = O(n)\n");
    printf("Time Complexity  : O(n)\n");
    printf("Space Complexity : O(n)  (recursion call stack)\n");
    return 0;
}
