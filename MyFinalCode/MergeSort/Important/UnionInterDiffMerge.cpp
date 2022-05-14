#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
};

void push(struct Node **head_ref, int new_data)
{

    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));

    new_node->data = new_data;

    new_node->next = (*head_ref);

    (*head_ref) = new_node;
}

void FrontBackSplit(struct Node *source,
                    struct Node **frontRef,
                    struct Node **backRef)
{
    struct Node *fast;
    struct Node *slow;
    if (source == NULL || source->next == NULL)
    {

        *frontRef = source;
        *backRef = NULL;
    }
    else
    {
        slow = source;
        fast = source->next;

        while (fast != NULL)
        {
            fast = fast->next;
            if (fast != NULL)
            {
                slow = slow->next;
                fast = fast->next;
            }
        }

        *frontRef = source;
        *backRef = slow->next;
        slow->next = NULL;
    }
}

struct Node *SortedMerge(struct Node *a,
                         struct Node *b)
{
    struct Node *result = NULL;

    if (a == NULL)
        return (b);
    else if (b == NULL)
        return (a);

    if (a->data <= b->data)
    {
        result = a;
        result->next = SortedMerge(a->next, b);
    }
    else
    {
        result = b;
        result->next = SortedMerge(a, b->next);
    }
    return (result);
}

void mergeSort(struct Node **headRef)
{
    struct Node *head = *headRef;
    struct Node *a, *b;

    if ((head == NULL) || (head->next == NULL))
        return;

    FrontBackSplit(head, &a, &b);

    mergeSort(&a);
    mergeSort(&b);

    *headRef = SortedMerge(a, b);
}

struct Node *getUnion(struct Node *head1,
                      struct Node *head2)
{
    struct Node *result = NULL;
    struct Node *t1 = head1, *t2 = head2;

    while (t1 != NULL && t2 != NULL)
    {

        if (t1->data < t2->data)
        {
            push(&result, t1->data);
            t1 = t1->next;
        }

        else if (t1->data > t2->data)
        {
            push(&result, t2->data);
            t2 = t2->next;
        }

        else
        {
            push(&result, t2->data);
            t1 = t1->next;
            t2 = t2->next;
        }
    }

    while (t1 != NULL)
    {
        push(&result, t1->data);
        t1 = t1->next;
    }
    while (t2 != NULL)
    {
        push(&result, t2->data);
        t2 = t2->next;
    }

    return result;
}

struct Node *getIntersection(struct Node *head1,
                             struct Node *head2)
{
    struct Node *result = NULL;
    struct Node *t1 = head1, *t2 = head2;

    while (t1 != NULL && t2 != NULL)
    {

        if (t1->data < t2->data)
            t1 = t1->next;

        else if (t1->data > t2->data)
            t2 = t2->next;

        else
        {

            push(&result, t2->data);

            t1 = t1->next;
            t2 = t2->next;
        }
    }

    return result;
}

struct Node *aDiffernceB(struct Node *head1,
                         struct Node *head2)
{
    struct Node *result = NULL;
    struct Node *t1 = head1, *t2 = head2;

    while (t1 != NULL && t2 != NULL)
    {

        if(t1->data == t2->data)
            t1 = t1->next; 
            t2 = t2->next;

        if(t1->data < t2->data)
            push(&result, t1->data);
            t1 = t1->next;
        
        t2 = t2->next;
    
    }

    while (t1 != NULL)
    {
        push(&result, t1->data);
        t1 = t1->next;
    }

    return result;
}

void printList(struct Node *node)
{
    while (node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
}

void mergeArrays(int arr1[], int arr2[], int n1,
                 int n2, int arr3[])
{
    int i = 0, j = 0, k = 0;

    while (i < n1 && j < n2)
    {

        if (arr1[i] < arr2[j])
            arr3[k++] = arr1[i++];
        else
            arr3[k++] = arr2[j++];
    }

    while (i < n1)
        arr3[k++] = arr1[i++];

    while (j < n2)
        arr3[k++] = arr2[j++];
}

int main()
{

    struct Node *head1 = NULL;
    struct Node *head2 = NULL;
    struct Node *intersection_list = NULL;
    struct Node *union_list = NULL;
    struct Node *difference_list = NULL;

    /*create a linked list 11->10->15->4->20 */
    push(&head1, 20);
    push(&head1, 4);
    push(&head1, 15);
    push(&head1, 10);
    push(&head1, 11);

    /*create a linked list 8->4->2->10 */
    push(&head2, 10);
    push(&head2, 2);
    push(&head2, 4);
    push(&head2, 8);

    /* Sort the above created Linked List */
    mergeSort(&head1);
    mergeSort(&head2);

    intersection_list = getIntersection(head1, head2);
    union_list = getUnion(head1, head2);
    difference_list = aDiffernceB(head1, head2);

    printf("First list is \n");
    printList(head1);

    printf("\nSecond list is \n");
    printList(head2);

    printf("\nIntersection list is \n");
    printList(intersection_list);

    printf("\nUnion list is \n");
    printList(union_list);

    printf("\nDifference List is \n");
    printList(difference_list);

    int arr1[] = {1, 3, 5, 7};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);

    int arr2[] = {2, 4, 6, 8};
    int n2 = sizeof(arr2) / sizeof(arr2[0]);

    int arr3[n1 + n2];
    mergeArrays(arr1, arr2, n1, n2, arr3);

    cout << "\nArray after merging" << endl;
    for (int i = 0; i < n1 + n2; i++)
        cout << arr3[i] << " ";

    return 0;
}