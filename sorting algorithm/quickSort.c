#include <stdio.h>

int partition(int *ar, int low, int high)
{
    int pivot = ar[low];
    int i = low + 1;
    int j = high;
    int temp;

    do
    {
        while (ar[i] <= pivot)
        {
            i++;
        }
        while (ar[j] > pivot)
        {
            j--;
        }
        if (i <= j)
        {
            temp = ar[i];
            ar[i] = ar[j];
            ar[j] = temp;
        }
    } while (i < j);

    temp = ar[low];
    ar[low] = ar[j];
    ar[j] = temp;

    return j;
}

void quickSort(int *ar, int low, int high)
{
    int partitionIndex;

    if (low < high)
    {

        partitionIndex = partition(ar, low, high); // returns index of pivot after partition

        quickSort(ar, low, partitionIndex - 1);  // sort left subarray.
        quickSort(ar, partitionIndex + 1, high); // sort right subarray.
    }
}

void traversalOfarray(int *ar, int s)
{
    int i = 0;
    while (i < s)
    {
        printf("%d ", ar[i]);
        i++;
    }
}

int main(int argc, char const *argv[])
{
    int arr[] = {9, 4, 4, 8, 7, 5, 6};
    int size = 7;

    quickSort(arr, 0, size - 1);

    traversalOfarray(arr, size);

    return 0;
}
