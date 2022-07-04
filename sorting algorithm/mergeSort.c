#include <stdio.h>

void merge(int *ar, int mid, int low, int high)
{
    int i, j, k, tempArray[20];
    i = low;
    j = mid + 1;
    k = low;

    while (i <= mid && j <= high)
    {
        if (ar[i] < ar[j])
        {
            tempArray[k] = ar[i];
            i++;
            k++;
        }
        else
        {
            tempArray[k] = ar[j];
            j++;
            k++;
        }
    }

    while (i <= mid)
    {
        tempArray[k] = ar[i];
        i++;
        k++;
    }
    while (j <= high)
    {
        tempArray[k] = ar[j];
        j++;
        k++;
    }

    for (int i = low; i <= high; i++)
    {
        ar[i] = tempArray[i];
    }
}

void mergeSort(int *ar, int low, int high)
{
    int mid;

    if (low < high)
    {
        mid = (low + high) / 2;
        mergeSort(ar, low, mid);
        mergeSort(ar, mid + 1, high);
        merge(ar, mid, low, high);
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
    int arr[] = {7, 9, 18, 19, 22, 1, 6, 9, 11};
    int size = 9;

    mergeSort(arr, 0, size - 1);

    // traversal
    traversalOfarray(arr, size);
    return 0;
}