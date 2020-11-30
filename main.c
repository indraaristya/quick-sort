#include <stdio.h>
#include <stdlib.h>

int main()
{
    int arr[] = {10, 7, 8, 9, 1, 5, 5, 0, -2};
    int n = sizeof(arr)/sizeof(arr[0]);
    printf("Unsorted array: \n");
    printArray(arr, n);
    quickSort(arr, 0, n-1);
    printf("Sorted array: \n");
    printArray(arr, n);
    return 0;
}

int doPartition(int numbers[], int left, int right) {
    int pivot = numbers[right]; //pilih isi array paling kanan sebagai pivot
    int leftPointer = left - 1; //initiate pointer paling kiri dengan nilai left - 1

    for (int current=left;current<=right - 1; current++) { //lakukan looping jika posisi pointer saat ini masih dalam jangkauan (tidak lebih dari index paling kanan)
        if (numbers[current] < pivot) { //jika nilai pointer saat ini lebih kecil daripada pivot
            leftPointer++;
            int temp = numbers[leftPointer];
            numbers[leftPointer] = numbers[current]; //tukar isi array paling kiri dengan isi array ke-pointer saat ini
            numbers[current] = temp;
        }
    }
    int temp = numbers[leftPointer+1];
    numbers[leftPointer+1] = numbers[right]; //tukar isi array pivot dengan left pointer + 1
    numbers[right] = temp;

    return leftPointer + 1; //return value index partisi berikutnya
}

void quickSort(int arr[], int start, int end) {
    if (start < end) {
        int partIndex = doPartition(arr, start, end);
        quickSort(arr, start, partIndex - 1);
        quickSort(arr, partIndex + 1, end);
    }
}

void printArray(int arr[], int size) {
    for (int i=0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
