#include <stdio.h>

// for finding the maximum element of an array.
int max(int *ar, int s)
{
    int i, max = ar[0];

    for (i = 0; i < s - 1; i++)
    {
        if (max < ar[i + 1])
        {
            max = ar[i + 1];
        }
    }
    return max;
}

void traversal(int *ar, int size)
{
    int i = 0;
    while (i < size)
    {
        printf("%d ", ar[i]);
        i++;
    }
    printf("\n");
}

void countSortAlgorithm(int *ar, int size)
{

    int maxValOfArray;
    maxValOfArray = max(ar, size);

    // printf("The maximum number in array: %d.\n", maxValOfArray);

    int newArr[maxValOfArray + 1];

    int z = 0;
    // for removing prevalues in array and intializing with 0.
    while (z < (maxValOfArray + 1))
    {
        newArr[z] = 0;
        z++;
    }

    int val;
    for (z = 0; z < size; z++)
    {
        val = ar[z];
        newArr[val] = newArr[val] + 1;
    }

    int refillingArray = 0; // initial array ar
    for (z = 0; z < maxValOfArray + 1; z++)
    {
        if (newArr[z] != 0)
        {
            for (int j = 0; j < newArr[z]; j++)
            {
                ar[refillingArray] = z;
                refillingArray++;
            }
        }
    }
}

int main(int argc, char const *argv[])
{
    int arr[] = {3, 1, 9, 7, 1, 2, 4};
    int size = 7;

    printf("The array before count sort.\n");
    traversal(arr, size);

    countSortAlgorithm(arr, size);

    printf("The array after count sort.\n");
    traversal(arr, size);

    return 0;
}
