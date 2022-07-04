#include <stdio.h>
#include <stdlib.h>

struct Node
{
    struct Node *prev;
    int data;
    struct Node *next;
};

void traversal(struct Node *head)
{
    while (head != NULL)
    {
        printf("Element: %d\n", head->data);
        head = head->next;
    }
}

// insertion at begining
struct Node *insertionAtBegining(struct Node *head, int newElement)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = newElement;

    struct Node *p = head;

    p->prev = ptr;
    ptr->next = p;
    ptr->prev = NULL;

    head = ptr;

    return head;
}

// insertion after node -> "It does not return anything as itt deals with the address"
void insertionAfterNode(struct Node *prevNode, int newElement)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = newElement;

    ptr->next = prevNode->next;
    prevNode->next = ptr;
    ptr->prev = prevNode;
}

// insertion at index
struct Node *insertionAtIndex(struct Node *head, int index, int newElement)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = newElement;

    struct Node *p = head;

    int i = 0;
    while (i < index - 1)
    {
        p = p->next;
        i++;
    }

    ptr->next = p->next;
    p->next = ptr;
    ptr->prev = p;

    return head;
}

int main(int argc, char const *argv[])
{
    struct Node *first = (struct Node *)malloc(sizeof(struct Node));
    struct Node *second = (struct Node *)malloc(sizeof(struct Node));
    struct Node *third = (struct Node *)malloc(sizeof(struct Node));
    struct Node *fourth = (struct Node *)malloc(sizeof(struct Node));

    first->prev = NULL;
    first->data = 2;
    first->next = second;

    second->prev = first;
    second->data = 4;
    second->next = third;

    third->prev = second;
    third->data = 6;
    third->next = fourth;

    fourth->prev = third;
    fourth->data = 8;
    fourth->next = NULL;

    // insertion at begining
    // first = insertionAtBegining(first, 0);

    // insertion after node
    // insertionAfterNode(third, 0);

    // insertion at index
    first = insertionAtIndex(first, 4, 71);

    traversal(first);

    return 0;
}
