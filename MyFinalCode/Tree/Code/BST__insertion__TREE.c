#include<stdio.h>
#include<stdlib.h>

struct node
{
    int key;
    struct node *left;
    struct node *right;
};

//return a new node with the given value
struct node *getNode(int val)
{
    struct node *newNode;

    newNode = malloc(sizeof(struct node));

    newNode->key   = val;
    newNode->left  = NULL;
    newNode->right = NULL;

    return newNode;
}

//inserts nodes in the binary search tree
struct node *insertNode(struct node *root, int val)
{
     if(root == NULL)
         return getNode(val);

     if(root->key < val)
         root->right = insertNode(root->right,val);

     if(root->key > val)
         root->left = insertNode(root->left,val);

     return root;
}

void preOrder(struct node * root)
{
    if(root != NULL)
    {
        printf("%d ", root->key);
        preOrder(root->left);
        preOrder(root->right);
    }
}

// inOrder
void inOrder(struct node * root)
{
    if(root != NULL)
    {
        inOrder(root->left);
        printf("%d ", root->key);
        inOrder(root->right);
    }
}

// postOrder
void postOrder(struct node * root)
{
    if(root != NULL)
    {
        postOrder(root->left);
        postOrder(root->right);
        printf("%d ", root->key);
    }
}

int getRightMin(struct node * root)
{
    struct node * temp = root;
    while(temp->left != NULL) 
    {
        temp = temp->left;
        return temp->key;
    }
}

struct node * deleteNode(struct node * root, int value)
{
    if(root == NULL)
    {
        return NULL;
    }
    if(root->key > value)
    {
        root->left = deleteNode(root->left, value);
    }
    else if(root->key < value)
    {
        root->right = deleteNode(root->right, value);
    }
    else
    {
       if(root->left == NULL && root->right == NULL)
       {
           free(root);
           return NULL;
       }
       else if(root->left == NULL)
       {
           struct node * temp = root->right;
           free(root);
           return temp;
       }
       else if(root->right == NULL)
       {
           struct node * temp = root->left;
           free(root);
           return temp;
       }
       else
       {
           int rightMin = getRightMin(root->right);
           root->key = rightMin;
           root->right = deleteNode(root->right, rightMin);
       }
    }
    return root;
}

int main()
{
   struct node *root = NULL;

   root = insertNode(root,100);
   root = insertNode(root, 50);
   root = insertNode(root, 200);
   root = insertNode(root, 10);
   root = insertNode(root, 60);
   root = insertNode(root, 150);
   root = insertNode(root, 300);
    

   printf("This is Pre Order: \n");
   preOrder(root);
   printf("\n");
   printf("\n");
   
   printf("This is InOrder: \n");
   inOrder(root);
   printf("\n");
   printf("\n");

    printf("This is Post Order: \n");
   postOrder(root);
   printf("\n");
   printf("\n");
   
   // After Deletion
    root = deleteNode(root, 300);
    printf("After deletion of 300, the new tree :\n");
    inOrder(root);
    printf("\n");
    printf("\n");
    
    root = deleteNode(root, 100);
    printf("After deletion of 100, the new tree :\n");
    inOrder(root);

   return 0;
}