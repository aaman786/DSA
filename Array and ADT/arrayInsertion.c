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

int insert(int *ar, int uSize, int tSize, int index, int num)
{
    if (uSize >= tSize)
    {
        printf("The array is already full.\n");
    }

    for (int i = uSize - 1; i >= index; i--)
    {
        ar[i + 1] = ar[i];
    }

    ar[index] = num;
    printf("The insertion is sucessful... \n");

    return uSize + 1;
}

int main(int argc, char const *argv[])

{
    int arr[10] = {2, 4, 6, 7, 8, 9, 10};
    int size = 10, uSize = 7;

    // old array
    printf("Displaying the old array~~~ \n");
    display(arr, uSize);

    // operation of insertion
    printf("\n");
    printf("Performing the Insertion on the initial array\n");
    int inputAtindex = 4, inutNum = 5;                       // input number from the user
    uSize = insert(arr, uSize, size, inputAtindex, inutNum); // after the insertion is performed the initial size will increase so we to store the new one.

    // New array
    printf("\n");
    printf("Displaying the array after the insertion~~~~ \n");
    display(arr, uSize);

    return 0;
}
