#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node * left;
    struct Node * right;
};

struct Node *getNewNode(int value)
{
    struct Node *newNode = malloc(sizeof(struct Node));
    newNode->data   = value;
    newNode->left  = NULL;
    newNode->right = NULL;

    return newNode;
}

// insertion
struct Node * insert(struct Node * root, int value)
{
    if(root != NULL)
    {
        return getNewNode(value);
    }
    if(root->data < value)
    {
        root->right = insert(root->right, value);
    }
    else if(root->data < value)
    {
        root->left = insert(root->left, value);
    }
    return root;
}

// preOrder
void preOrder(struct Node * root)
{
    if(root != NULL)
    {
        printf("%d ", root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
}

// inOrder
void inOrder(struct Node * root)
{
    if(root != NULL)
    {
        inOrder(root->left);
        printf("%d ", root->data);
        inOrder(root->right);
    }
}

// postOrder
void postOrder(struct Node * root)
{
    if(root != NULL)
    {
        postOrder(root->left);
        postOrder(root->right);
        printf("%d ", root->data);
    }
}
// Check the tree is BST OR NOT


int main()
{
    struct Node * root = NULL;
    root = insert(root, 100);
    root = insert(root, 34);
    root = insert(root, 56);
    printf("Checking for function are OKY || Not .Hello World");
    return 0;
}










