#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node *createNode(int data)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));

    ptr->data = data;
    ptr->left = NULL;
    ptr->right = NULL;

    return ptr;
}

void inorderTraversal(struct Node *root)
{
    if (root != NULL)
    {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}

// for checking BST or not.
int checkingBST(struct Node *root)
{
    if (root != NULL)
    {
        static struct Node *prevNode;
        if (!checkingBST(root->left))
        {
            return 0;
        }
        if (prevNode != NULL && root->data <= prevNode->data)
        {
            return 0;
        }
        prevNode = root;
        return checkingBST(root->right);
    }
    else
    {
        return 1;
    }
}

void iterativeSearchInBST(struct Node *root, int val)
{
    while (root != NULL)
    {
        if (root->data == val)
        {
            printf("We get the value.\n");
            return;
        }
        else if (val < root->data)
        {
            root = root->left;
        }
        else if (val > root->data)
        {
            root = root->right;
        }
    }
}

int main(int argc, char const *argv[])
{
    struct Node *root, *a, *b, *c, *d;

    root = createNode(7);
    a = createNode(4);
    root->left = a;
    b = createNode(11);
    root->right = b;

    c = createNode(2);
    a->left = c;
    d = createNode(5);
    a->right = d;

    printf("Inorder Traversal in tree: ");
    inorderTraversal(root); // if this is in ascending order then tree is BST.

    printf("\n");

    if (checkingBST(root) == 1)
    {
        printf("This tree is a BST!\n");
    }
    else
    {
        printf("This tree is not BST.\n");
    }

    iterativeSearchInBST(root, 14);

    return 0;
}