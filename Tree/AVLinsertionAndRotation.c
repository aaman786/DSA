#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int key;
    struct Node *left;
    struct Node *right;
    int height;
};

int getHeight(struct Node *n)
{
    if (n == NULL)
        return 0;
    return n->height;
}

int max(int a, int b)
{
    return (a > b) ? a : b;
}

struct Node *createNode(int key)
{
    struct Node *node = (struct Node *)malloc(sizeof(struct Node));
    node->key = key;
    node->left = NULL;
    node->right = NULL;
    node->height = 1;

    return (node);
}

int getBalanceFactor(struct Node *n)
{
    if (n == NULL)
        return 0;

    return getHeight(n->right) - getHeight(n->left);
}

struct Node *rightRotate(struct Node *y)
{
    struct Node *x = y->left;
    struct Node *T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = max(getHeight(y->right), getHeight(y->left)) + 1;
    x->height = max(getHeight(x->right), getHeight(x->left)) + 1;

    return x;
}

struct Node *leftRotate(struct Node *x)
{
    struct Node *y = x->right;
    struct Node *T2 = y->left;

    y->left = x;
    x->right = T2;

    y->height = max(getHeight(y->right), getHeight(y->left)) + 1;
    x->height = max(getHeight(x->right), getHeight(x->left)) + 1;

    return y;
}

struct Node *insertion(struct Node *node, int key)
{
    if (node == NULL)
    {
        return createNode(key);
    }

    if (key < node->key)
    {
        node->left = insertion(node->left, key);
        return node;
    }
    else if (key > node->key)
    {
        node->right = insertion(node->right, key);
        return node;
    }
    else
    {
        return node;
    }

    node->height = max(getHeight(node->left), getHeight(node->right)) + 1;
    int bf = getBalanceFactor(node);

    // LL case
    if (bf > 1 && key < node->left->key)
    {
        return rightRotate(node);
    }

    // RR case
    if (bf < -1 && key > node->right->key)
    {
        return leftRotate(node);
    }

    // LR case
    if (bf > 1 && key > node->left->key)
    {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    // RL case
    if (bf < -1 && key < node->right->key)
    {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

void preorderTraversal(struct Node *p)
{
    if (p != NULL)
    {
        printf("%d ", p->key);
        preorderTraversal(p->left);
        preorderTraversal(p->right);
    }
}

int main(int argc, char const *argv[])
{
    struct Node *root = NULL;

    root = insertion(root, 2);
    root = insertion(root, 1);
    root = insertion(root, 7);
    root = insertion(root, 4);
    root = insertion(root, 5);
    root = insertion(root, 3);
    root = insertion(root, 8);

    preorderTraversal(root);

    return 0;
}
