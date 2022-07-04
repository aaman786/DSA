#include <stdio.h>
#include <stdbool.h>

void display(int *ar, int s)
{
    int i = 0;
    while (i < s)
    {
        printf("%d ", *(ar + i));
        i++;
    }
    printf("\n");
}

int linearSearch(int *ar, int size, int element)
{
    int i = 0;
    while (i < size)
    {
        if (ar[i] == element)
        {
            printf("The linear search is sucessful! \n");
            return i;
        }
        i++;
    }
    printf("The element is not present in array.\n");
    return 0;
}

void bubbleSorting(int *ar, int size)
{
    bool isSorted = false;
    int temp;

    for (int i = 0; i < size; i++)
    {
        isSorted = true;
        printf("The pass no. is %d\n", i + 1);
        for (int j = 0; j < size - i - 1; j++)
        {
            // printf("The comparison: %d > %d \n", ar[j], ar[j + 1]);
            if (ar[j] > ar[j + 1])
            {
                isSorted = false;
                temp = ar[j];
                ar[j] = ar[j + 1];
                ar[j + 1] = temp;
            }
        }
        if (isSorted)
        {
            printf("The given array is already sorted.\n");
            return;
        }
    }
}

int binarySearch(int *ar, int high, int low, int element)
{

    int mid;
    if (high >= low)
    {
        mid = (low + high) / 2;
        if (element == ar[mid])
        {

            return mid;
        }
        else if (element > ar[mid])
        {

            return binarySearch(ar, high, mid + 1, element);
        }
        else
        {

            return binarySearch(ar, mid - 1, low, element);
        }
    }
    printf("The number is not present in the array. \n");
    return -1;
}

int main(int argc, char const *argv[])
{
    /*   code for linear search
      {
          // unsorted array for the binary search
          int arr[] = {1, 6, 2, 9, 10, 3, 15, 71, 4, 50};
          int sizeofarr = sizeof(arr) / sizeof(arr[0]);

          // Linear Search operation
          int num = 44; // an element by user for the search
          int receivedIndexOfElement = linearSearch(arr, sizeofarr, num);

          if (receivedIndexOfElement != 0) // function returns 0 if the element is not present in the array.
          {
              printf("The index number is: %d \n", receivedIndexOfElement);
          }
      }
   */

    // Code for the binay search
    int arr[] = {
        1,
        2,
        6,
        9,
        10,
        12,
        15, 18, 20, 25, 44, 47, 52, 61, 67};
    int sizeofarr = sizeof(arr) / sizeof(arr[0]);

    // int arr[] = {1, 6, 2, 9, 10, 3, 15, 71, 4, 50};
    // sorting before binary search
    // printf("Array after the sorting oeration...\n");
    // bubbleSorting(arr, sizeofarr);

    // Binary search operation
    int binarySearchResult = binarySearch(arr, sizeofarr - 1, 0, 21);
    if (binarySearchResult != -1)
    {
        printf("The index of element you want to find is: %d", binarySearchResult);
    }

    return 0;
}
