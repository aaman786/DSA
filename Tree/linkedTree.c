#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int Data;
    struct Node *left;
    struct Node *right;
};

struct Node *generateNode(int data)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));

    ptr->Data = data;
    ptr->left = NULL;
    ptr->right = NULL;
    return ptr;
}

int main(int argc, char const *argv[])
{
    struct Node *a;
    struct Node *b;
    struct Node *c;

    a = generateNode(2);
    a->left = b;
    a->right = c;
    b = generateNode(4);
    c = generateNode(6);

    return 0;
}
