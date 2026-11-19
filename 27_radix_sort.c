Algorithm:
1. Find the maximum number in the array to determine the number of digits, d
2. For each digit position (units, tens, hundreds, ...):
   a. Perform a stable Counting Sort of the array based on the current digit
3. Repeat step 2 for all d digit positions
4. The array is now sorted
5. Stop
Program:
/* Practical 27: Radix Sort (CO5) */
#include <stdio.h>
int getMax(int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++) if (arr[i] > max) max = arr[i];
    return max;
}
void countSortByDigit(int arr[], int n, int exp) {
    int output[n], count[10] = {0};
    for (int i = 0; i < n; i++) count[(arr[i] / exp) % 10]++;
    for (int i = 1; i < 10; i++) count[i] += count[i - 1];
    for (int i = n - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }
    for (int i = 0; i < n; i++) arr[i] = output[i];
}
void radixSort(int arr[], int n) {
    int max = getMax(arr, n);
    for (int exp = 1; max / exp > 0; exp *= 10) countSortByDigit(arr, n, exp);
}
int main() {
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter elements (positive integers): ");
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
    radixSort(arr, n);
    printf("Sorted array: ");
    for (int i = 0; i < n; i++) printf("%d ", arr[i]);
    printf("\n");
    return 0;
}
