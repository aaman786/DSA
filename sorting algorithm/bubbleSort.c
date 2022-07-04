#include <stdio.h>

void traversal(int ar[], int s)
{

    int i = 0;
    while (i < s)
    {
        printf("%d ", ar[i]);
        i++;
    }
    printf("\n");
}

void bubbleSort(int *ar, int s)
{
    int a = 0;

    for (int i = 0; i < s; i++)
    {
        a = 1;
        printf("Working on pass number: %d.\n", i + 1);

        for (int j = 0; j < s - i - 1; j++)
        {
            if (ar[j] > ar[j + 1])
            {
                int temp = ar[j];
                ar[j] = ar[j + 1];
                ar[j + 1] = temp;
                a = 0;
            }
        }

        if (a)
        {
            // printf("The array is already sorted.\n");
            return;
        }
    }
}

int main(int argc, char const *argv[])
{
    // int arr[] = {12, 54, 65, 7, 23, 9};
    // int arr[] = {12, 14, 21, 54, 60};

    int s = sizeof(arr) / sizeof(arr[0]);
    printf("The size of array: %d.\n", s);

    printf("The array before bubble sort.\n");
    traversal(arr, s);

    bubbleSort(arr, s);

    printf("The array after bubble sort.\n");
    traversal(arr, s);

    return 0;
}
