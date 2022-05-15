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
void findPreSuc(struct Node* root, struct Node* pre,struct Node* suc, int key)
{
    // Base case
    if (root == NULL)  return ;
 
    // If key is present at root
    if (root->key == key)
    {
        // the maximum value in left subtree is predecessor
        if (root->left != NULL)
        {
            struct Node* tmp = root->left;
            while (tmp->right)
                tmp = tmp->right;
            pre = tmp ;
        }
 
        // the minimum value in right subtree is successor
        if (root->right != NULL)
        {
            struct Node* tmp = root->right ;
            while (tmp->left)
                tmp = tmp->left ;
            suc = tmp ;
        }
        return ;
    }
 
    // If key is smaller than root's key, go to left subtree
    if (root->key > key)
    {
        suc = root ;
        findPreSuc(root->left, pre, suc, key) ;
    }
    else // go to right subtree
    {
        pre = root ;
        findPreSuc(root->right, pre, suc, key) ;
    }
}

// Height Function
int maxDepth(struct Node* root)
{
    if (root == NULL)
        return -1;
    else {
        /* compute the depth of each subtree */
        int lDepth = maxDepth(root->left);
        int rDepth = maxDepth(root->right);
 
        /* use the larger one */
        if (lDepth > rDepth)
            return (lDepth + 1);
        else
            return (rDepth + 1);
    }
}

int main()
{
	
	struct Node * root = NULL;
    
    struct Node* pre = NULL;
    struct Node* suc = NULL;
    int key = 65;
	
	
// 	root = insert(root, 100);
// 	root = insert(root, 50);
// 	root = insert(root, 200);
// 	root = insert(root, 10);
// 	root = insert(root, 60);
// 	root = insert(root, 150);
// 	root = insert(root, 300);
	
	root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);
		
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
	
	
	printf("After deleteing 300, the new tree is (inORder)\n");
	root = deleteNode(root, 300);
	inOrder(root);
	printf("\n");
	printf("\n");
	
	
	printf("Mirror Tree is: \n");
	mirror(root);
	inOrder(root);
	printf("\n");
	printf("\n");

    printf("Height of tree is %d", maxDepth(root));
    printf("\n");
	printf("\n");

  
	findPreSuc(root, pre, suc, key);
    	if(pre != NULL)
	        printf("Predecessor is: ", pre->key);
	   else
	   {
	       printf("No Predecessor\n");
	   }
	   if(suc != NULL)
	        printf("Succesor is: ", suc->key);
	   else
	   {
	       printf("No Succesor\n");
	   }
	   
	//    inOrder(root);
	
	
	

	return 0;
}