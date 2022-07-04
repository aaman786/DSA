#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void traversal(struct Node *ptr)
{
    while (ptr != NULL)
    {
        printf("The Element: %d \n", ptr->data);
        ptr = ptr->next;
    }
}

// deletion at begining method
struct Node *deletionAtBegining(struct Node *head)
{
    struct Node *temp = head;
    head = head->next;
    free(temp);

    return head;
}

// deletion at index
struct Node *deletionAtIndex(struct Node *head, int index)
{
    struct Node *ptr = head;
    struct Node *temp = head->next;

    int i = 0;
    while (i != index - 1)
    {
        ptr = ptr->next;
        temp = temp->next;
        // printf("%d \n", ptr->data);
        i++;
    }

    ptr->next = temp->next;
    free(temp);

    return head;
}

// Deletion at last
struct Node *deletionAtLast(struct Node *head)
{
    struct Node *ptr = head;
    struct Node *temp = head->next;

    while (temp->next != NULL)
    {

        ptr = ptr->next;
        temp = temp->next;
    }
    ptr->next = NULL;
    free(temp);

    return head;
}

void deletionByValue(struct Node *head, int value)
{
    struct Node *ptr = head;
    struct Node *temp = head->next;

    while (temp->data != value && temp->next != NULL)
    {
        ptr = ptr->next;
        temp = temp->next;
    }

    if (temp->data == value)
    {
        ptr->next = temp->next;
        free(temp);
    }

    return head;
}

int main(int argc, char const *argv[])
{
    struct Node *first;
    struct Node *second;
    struct Node *third;
    struct Node *fourth;

    // Allocation of the memory.
    first = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));
    fourth = (struct Node *)malloc(sizeof(struct Node));

    first->data = 2;
    first->next = second;

    second->data = 4;
    second->next = third;

    third->data = 6;
    third->next = fourth;

    fourth->data = 8;
    fourth->next = NULL;

    // deletion at begining
    // first = deletionAtBegining(first);

    // deletion at index
    //  deletionAtIndex(first, 2);

    // deletion at last
    // first = deletionAtLast(first);

    // deletion by the value
    // first = deletionAtLast(first,6);

    traversal(first);

    return 0;
}
