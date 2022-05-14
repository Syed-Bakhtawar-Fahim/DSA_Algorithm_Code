#include <stdio.h>
#include <stdlib.h>


struct Node 
{
	int key;
	struct Node * left;
	struct Node * right;
	
};


struct Node * getNewNode(int value)
{
	struct Node * newNode = (struct Node *)malloc(sizeof(struct Node));
	newNode->key = value;
	newNode->left = NULL;
	newNode->right = NULL;
	return newNode;
}

struct Node * insert(struct Node * root, int value)
{
	if(root == NULL)
		return getNewNode(value);
	if(root->key < value)
		root->right = insert(root->right, value);
	if(root->key > value)
		root->left = insert(root->left, value);
		
	return root;
}


void preOrder(struct Node * root)
{
	if(root != NULL)
	{
		printf("%d ", root->key);
		preOrder(root->left);
		preOrder(root->right);
	}
}

void inOrder(struct Node * root)
{
	if(root != NULL)
	{
		inOrder(root->left);
		printf("%d ", root->key);
		inOrder(root->right);
	}
}

void postOrder(struct Node * root)
{
	if(root != NULL)
	{
		postOrder(root->left);
		postOrder(root->right);
		printf("%d ", root->key);
	}
}


int getRightMin(struct Node * root)
{
    struct Node * temp = root;
    while(temp->left != NULL)
    {
        temp = temp->left;
        return temp->key;
    }
   
}

struct Node * deleteNode(struct Node * root, int value)
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
           struct Node * temp = root->right;
           free(root);
           return temp;
       }
       else if(root->right == NULL)
       {
           struct Node * temp = root->left;
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

void mirror(struct Node * root)
{
    if(root == NULL)
        return;
    else
        mirror(root->left);
        mirror(root->right);
        
        struct Node * temp;
        temp = root->left;
        root->left = root->right;
        root->right = temp;
}

int main()
{
	
	struct Node * root = NULL;
	
	root = insert(root, 100);
	root = insert(root, 50);
	root = insert(root, 200);
	root = insert(root, 10);
	root = insert(root, 60);
	root = insert(root, 150);
	root = insert(root, 300);	
	
	
	
	printf("This is PreOrder: \n");
	preOrder(root);
	printf("\n");
	printf("\n");
	
	printf("This is inOrder: \n");
	inOrder(root);
	printf("\n");
	printf("\n");
	
	printf("This is postOrder: \n");
	postOrder(root);
	printf("\n");
	printf("\n");
	
	
	printf("After deleteing 300, the new tree is(inORder)\n");
	root = deleteNode(root, 300);
	inOrder(root);
	printf("\n");
	printf("\n");
	
	
	printf("Mirror Tree is: \n");
	mirror(root);
	inOrder(root);
	return 0;
}