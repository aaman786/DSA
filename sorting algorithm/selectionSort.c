#include <stdio.h>

void selectionSort(int *ar, int s)
{
    int j;

    for (int i = 0; i < s - 1; i++)
    {
        j = i + 1;
        while (j < s)
        {
            if (ar[i] > ar[j])
            {
                int temp;
                temp = ar[i];
                ar[i] = ar[j];
                ar[j] = temp;
            }
            j++;
        }
    }

    for (int i = 0; i < s; i++)
    {
        printf("%d ", ar[i]);
    }
}

int main(int argc, char const *argv[])
{
    int arr[] = {8, 0, 7, 1, 3, 2};

    selectionSort(arr, 6);

    return 0;
}