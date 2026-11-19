Algorithm:
1. Create n empty buckets
2. For every element in the input array, compute its bucket index based on its value range and insert it into the corresponding bucket
3. Sort each bucket individually (e.g., using Insertion Sort)
4. Concatenate all buckets in order to produce the sorted array
5. Stop
Program:
/* Practical 28: Bucket Sort (CO5) */
#include <stdio.h>
#define BUCKETS 10
void insertionSort(float arr[], int n) {
    for (int i = 1; i < n; i++) {
        float key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) { arr[j + 1] = arr[j]; j--; }
        arr[j + 1] = key;
    }
}
void bucketSort(float arr[], int n) {
    float buckets[BUCKETS][100];
    int bucketCount[BUCKETS] = {0};
    for (int i = 0; i < n; i++) {
        int idx = (int)(arr[i] * BUCKETS);
        if (idx >= BUCKETS) idx = BUCKETS - 1;
        buckets[idx][bucketCount[idx]++] = arr[i];
    }
    int k = 0;
    for (int i = 0; i < BUCKETS; i++) {
        insertionSort(buckets[i], bucketCount[i]);
        for (int j = 0; j < bucketCount[i]; j++) arr[k++] = buckets[i][j];
    }
}
int main() {
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    float arr[n];
    printf("Enter elements (between 0 and 1): ");
    for (int i = 0; i < n; i++) scanf("%f", &arr[i]);
    bucketSort(arr, n);
    printf("Sorted array: ");
    for (int i = 0; i < n; i++) printf("%.2f ", arr[i]);
    printf("\n");
    return 0;
}
