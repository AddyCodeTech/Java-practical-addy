Algorithm:
FACTORIAL_ITERATIVE(n):
1. Set result = 1
2. For i = 1 to n: result = result * i
3. Return result
4. Stop
Program:
/* Practical 24: Analyze Non-Recursive Algorithm Mathematically & Implement in C (CO4)
 * Example: Factorial using Iteration
 * The loop runs n times, each iteration doing O(1) work => T(n) = O(n)
 */
#include <stdio.h>
long long factorial(int n) {
    long long result = 1;
    for (int i = 2; i <= n; i++)          /* Loop runs (n-1) times : O(n) */
        result *= i;                        /* O(1) work per iteration */
    return result;
}
int main() {
    int n;
    printf("Enter a number: ");
    scanf("%d", &n);
    printf("Factorial of %d = %lld\n", n, factorial(n));
    printf("\nMathematical Analysis:\n");
    printf("Loop runs from i = 2 to n, i.e. (n-1) times.\n");
    printf("Each iteration performs a constant amount of work O(1).\n");
    printf("Total Time Complexity: T(n) = (n-1) * O(1) = O(n)\n");
    printf("Space Complexity     : O(1)  (no extra space, only loop variables)\n");
    return 0;
}
