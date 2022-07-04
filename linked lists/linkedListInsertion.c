#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void linkedListTraversal(struct Node *ptr)
{
    while (ptr != NULL)
    {
        printf("The Element: %d \n", ptr->data);
        ptr = ptr->next;
    }
}

// Insert at begining Method.
struct Node *insertAtBegning(struct Node *head, int newElement)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = newElement;
    ptr->next = head;

    return ptr;
}

// Insert at Index Method
struct Node *insertAtIndex(struct Node *head, int newElment, int index)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    struct Node *p = head;

    int i = 0;
    while (i != index - 1)
    {
        p = p->next;
        i++;
    }

    ptr->data = newElment;
    ptr->next = p->next;
    p->next = ptr;

    return head;
}

// Insert at the End
struct Node *insertAtEnd(struct Node *head, int newElement)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    struct Node *p = head;

    while (p->next != NULL)
    {
        p = p->next;
    }

    ptr->data = newElement;
    ptr->next = NULL;
    p->next = ptr;

    return head;
}

// Insert at Node
void insertAfterNode(struct Node *prevNode, int newElement)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = newElement;

    ptr->next = prevNode->next;
    prevNode->next = ptr;
}

int main(int argc, char const *argv[])
{
    struct Node *head;
    struct Node *second;
    struct Node *third;
    struct Node *fourth;

    // Allocation of memory
    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));
    fourth = (struct Node *)malloc(sizeof(struct Node));

    // Assigning values with the perspectives.
    head->data = 2;
    head->next = second;

    second->data = 4;
    second->next = third;

    third->data = 6;
    third->next = fourth;

    fourth->data = 8;
    fourth->next = NULL;

    // insert at the begining
    // head = insertAtBegning(head, 0);

    /*  // insert at Index
     head = insertAtIndex(head, 11, 2);
    */

    /*  //insert at the end
     head = insertAtEnd(head, 55);
    */

    // insert at node
    // insertAfterNode(second, 11);

    // For displayng he elements
    linkedListTraversal(head);

    return 0;
}
