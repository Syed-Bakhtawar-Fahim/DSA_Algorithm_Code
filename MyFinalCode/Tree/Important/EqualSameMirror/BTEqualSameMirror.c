#include <stdio.h>
#include <stdlib.h>
 

struct node
{
    int data;
    struct node* left;
    struct node* right;
};
 

struct node* newNode(int data)
{
    struct node* node = (struct node*)
                             malloc(sizeof(struct node));
    node->data  = data;
    node->left  = NULL;
    node->right = NULL;
 
    return(node);
}
 
/* Given two trees, return true if they are
 structurally identical */
int identicalTrees(struct node* a, struct node* b)
{
    /*1. both empty */
    if (a==NULL && b==NULL)
        return 1;
 
    /* 2. both non-empty -> compare them */
    if (a!=NULL && b!=NULL)
    {
        return
        (
            a->data == b->data &&
            identicalTrees(a->left, b->left) &&
            identicalTrees(a->right, b->right)
        );
    }
     
    /* 3. one empty, one not -> false */
    return 0;
}

int isSameStructure(struct node* a, struct node* b)
{
    // 1. both empty
    if (a == NULL && b == NULL)
        return 1;
    // 2. both non-empty -> compare them
    if (a != NULL && b != NULL) {
        return (isSameStructure(a->left, b->left)
                && isSameStructure(a->right, b->right));
    }
    // 3. one empty, one not -> false
    return 0;
}
int areMirror(struct node* a, struct node* b)
{
    /* Base case : Both empty */
    if (a==NULL && b==NULL)
        printf("Both are empty\n");
 
    // If only one is empty
    if (a==NULL || b == NULL)
        printf("One tree is empty\n");
 
    /* Both non-empty, compare them recursively
     Note that in recursive calls, we pass left
     of one tree and right of other tree */
    return  a->data == b->data &&
            areMirror(a->left, b->right) &&
            areMirror(a->right, b->left);
} 
 

/* Driver program to test identicalTrees function*/
int main()
{
    struct node *root1 = newNode(1);
    struct node *root2 = newNode(1);
    root1->left = newNode(2);
    root1->right = newNode(3);
    root1->left->left  = newNode(4);
    root1->left->right = newNode(5);
 
    root2->left = newNode(2);
    root2->right = newNode(3);
    root2->left->left = newNode(4); 
    root2->left->right = newNode(5);
 
    if(identicalTrees(root1, root2))
        printf("Both tree are identical\n");
    else
        printf("Trees are not identical\n");
 


    if (isSameStructure(root1, root2))
        printf("Both trees have same structure\n");
    else
        printf("Trees do not have same structure\n");
    
    if(areMirror(root1, root2))
        printf("Yes, both are mirror image of each other\n");
    else
        printf("No, they're not mirror image of each other\n");
    
    getchar();

  return 0;
}