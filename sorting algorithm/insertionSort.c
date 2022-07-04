#include <stdio.h>

void insertionSort(int *ar, int s)
{
    int key, j;

    for (int i = 1; i < s - 1; i++)
    {
        key = ar[i];
        j = i - 1;

        while (j >= 0 && ar[j] > key)
        {
            ar[j + 1] = ar[j];
            j--;
        }
        ar[j + 1] = key;
    }

    for (int i = 0; i < s; i++)
    {
        printf("%d ", ar[i]);
    }
}

int main(int argc, char const *argv[])
{
    int arr[] = {12, 65, 7, 23, 9};

    int size = 5;

    insertionSort(arr, size);

    return 0;
}
