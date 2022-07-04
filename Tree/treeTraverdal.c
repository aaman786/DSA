/*
 There are three types of travesal in the tree.
 1. Preorder traversal :- root ----> left subtree ----> right subtree.
 2. Postorder traversal :- left subtree ----> right subtree ----> root.
 3. Inorder traversal :- left subtree ----> root ----> right subtree.
  */

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

// preorder traversal
void preorderTraversal(struct Node *p)
{
    if (p != NULL)
    {
        printf("%d ", p->data);
        preorderTraversal(p->left);
        preorderTraversal(p->right);
    }
}

// postorder traversal
void postorderTraversal(struct Node *p)
{
    if (p != NULL)
    {
        postorderTraversal(p->left);
        postorderTraversal(p->right);
        printf("%d ", p->data);
    }
}

// inorder traversal
void inorderTraversal(struct Node *p)
{
    if (p != NULL)
    {
        inorderTraversal(p->left);
        printf("hii");
        printf("%d ", p->data);
        inorderTraversal(p->right);
    }
}

int main(int argc, char const *argv[])
{
    struct Node *root = createNode(7);
    struct Node *a = createNode(2);
    struct Node *b = createNode(1);
    root->left = a;
    root->right = b;
    struct Node *c = createNode(0);
    struct Node *d = createNode(4);
    a->left = c;
    a->right = d;

    printf("The preorder traversal in tree is: ");
    preorderTraversal(root);
    printf("\n");

    printf("The postorder traversal in tree is: ");
    postorderTraversal(root);
    printf("\n");

    printf("The inorder traversal in tree is: ");
    inorderTraversal(root);

    return 0;
}
