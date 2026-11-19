Algorithm:
1. Find the maximum value in the array; create a count array of size (max+1), initialized to 0
2. For every element in the input array, increment count[element]
3. Transform count[] into cumulative counts: count[i] += count[i-1]
4. Build the output array: scanning the input from the end, place each element at position count[element]-1 in the output, then decrement count[element]
5. Copy the output array back to the original array
6. Stop
Program:
/* Practical 26: Counting Sort (CO5) */
#include <stdio.h>
void countingSort(int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++) if (arr[i] > max) max = arr[i];
    int count[max + 1];
    for (int i = 0; i <= max; i++) count[i] = 0;
    for (int i = 0; i < n; i++) count[arr[i]]++;
    for (int i = 1; i <= max; i++) count[i] += count[i - 1];
    int output[n];
    for (int i = n - 1; i >= 0; i--) {
        output[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    }
    for (int i = 0; i < n; i++) arr[i] = output[i];
}
int main() {
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter elements (positive integers): ");
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
    countingSort(arr, n);
    printf("Sorted array: ");
    for (int i = 0; i < n; i++) printf("%d ", arr[i]);
    printf("\n");
    return 0;
}
