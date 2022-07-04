#include <stdio.h>

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

int insert(int *ar, int uSize, int tSize, int index)
{
    if (index >= tSize)
    {
        printf("The index provided is out of range, the size of array is %d.\n", tSize);
    }

    for (int i = index; i < uSize; i++)
    {
        ar[i] = ar[i + 1];
    }

    printf("The deletion is sucessful... \n");

    return uSize - 1;
}

int main(int argc, char const *argv[])
{
    int arr[10] = {2, 4, 6, 7, 8, 9, 10};
    int size = 10, uSize = 7;

    // old array
    printf("Displaying the old array~~~ \n");
    display(arr, uSize);

    // operation of deletion
    printf("\n");
    printf("Performing deletion on the initial array\n");
    int deleteAtindex = 4;                           // input of index of element user want to delete
    uSize = insert(arr, uSize, size, deleteAtindex); // after the deletion is performed the initial size will decrease so we to store the new one.

    // New array
    printf("\n");
    printf("Displaying the array after the deletion~~~~ \n");
    display(arr, uSize);

    return 0;
}