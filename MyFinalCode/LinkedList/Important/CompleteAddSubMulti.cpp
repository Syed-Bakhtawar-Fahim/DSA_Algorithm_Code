#include <stdio.h>
#include <stdlib.h>

// Linked list Node
struct Node
{
    int data;
    struct Node *next;
};

struct Node *newNode(int data)
{
    struct Node *new_node =
        (struct Node *)malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

void push(struct Node **head_ref, int new_data)
{
   
    struct Node *new_node = newNode(new_data);

    // link the old list off the new Node
    new_node->next = (*head_ref);

    // move the head to point to the new Node
    (*head_ref) = new_node;
}

// Function to reverse the linked list and return
// its length
int reverse(struct Node **head_ref)
{
    struct Node *prev = NULL;
    struct Node *current = *head_ref;
    struct Node *next;
    int len = 0;
    while (current != NULL)
    {
        len++;
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *head_ref = prev;
    return len;
}

// Function to make an empty linked list of
// given size
struct Node *make_empty_list(int size)
{
    struct Node *head = NULL;
    while (size--)
        push(&head, 0);
    return head;
}

Node *addTwoLists(struct Node *first, struct Node *second)
{
    // res is head node of the resultant list
    Node *res = NULL;
    Node *temp, *prev = NULL;
    int carry = 0, sum;

    // while both lists exist
    while (first != NULL || second != NULL)
    {
        
        sum = carry + (first ? first->data : 0) + (second ? second->data : 0);
        // update carry for next calculation
        carry = (sum >= 10) ? 1 : 0;
        // update sum if it is greater than 10
        sum = sum % 10;
        // Create a new node with sum as data
        temp = newNode(sum);
        // if this is the first node then set it as head of the resultant list
        if (res == NULL)
            res = temp;
        // If this is not the first node then connect it to the rest.
        else
            prev->next = temp;

        // Set prev for next insertion
        prev = temp;

        // Move first and second pointers to next nodes
        if (first)
            first = first->next;
        if (second)
            second = second->next;
    }
    if (carry > 0)
        temp->next = newNode(carry);
    // return head of the resultant list
    return res;
}

Node* subtractLinkedListHelper(Node* l1, Node* l2, bool& borrow)
{
    if (l1 == NULL && l2 == NULL && borrow == 0)
        return NULL;
 
    Node* previous
        = subtractLinkedListHelper(
            l1 ? l1->next : NULL,
            l2 ? l2->next : NULL, borrow);
 
    int d1 = l1->data;
    int d2 = l2->data;
    int sub = 0;
 
    /* if you have given the value to next digit then
       reduce the d1 by 1 */
    if (borrow) {
        d1--;
        borrow = false;
    }
 
    /* If d1 < d2, then borrow the number from previous digit.
       Add 10 to d1 and set borrow = true; */
    if (d1 < d2) {
        borrow = true;
        d1 = d1 + 10;
    }
 
    /* subtract the digits */
    sub = d1 - d2;
 
    /* Create a Node with sub value */
    Node* current = newNode(sub);
 
    /* Set the Next pointer as Previous */
    current->next = previous;
 
    return current;
}
 
 /* A utility function to get length
 of linked list */
int getLength(Node* Node)
{
    int size = 0;
    while (Node != NULL) {
        Node = Node->next;
        size++;
    }
    return size;
}
 
/* A Utility that padds zeros in front of the
   Node, with the given diff */
Node* paddZeros(Node* sNode, int diff)
{
    if (sNode == NULL)
        return NULL;
 
    Node* zHead = newNode(0);
    diff--;
    Node* temp = zHead;
    while (diff--) {
        temp->next = newNode(0);
        temp = temp->next;
    }
    temp->next = sNode;
    return zHead;
}
/* This API subtracts two linked lists and returns the
   linked list which shall  have the subtracted result. */
Node* subtractLinkedList(Node* l1, Node* l2)
{
    // Base Case.
    if (l1 == NULL && l2 == NULL)
        return NULL;
 
    // In either of the case, get the lengths of both
    // Linked list.
    int len1 = getLength(l1);
    int len2 = getLength(l2);
 
    Node *lNode = NULL, *sNode = NULL;
 
    Node* temp1 = l1;
    Node* temp2 = l2;
 
    // If lengths differ, calculate the smaller Node
    // and padd zeros for smaller Node and ensure both
    // larger Node and smaller Node has equal length.
    if (len1 != len2) {
        lNode = len1 > len2 ? l1 : l2;
        sNode = len1 > len2 ? l2 : l1;
        sNode = paddZeros(sNode, abs(len1 - len2));
    }
 
    else {
        // If both list lengths are equal, then calculate
        // the larger and smaller list. If 5-6-7 & 5-6-8
        // are linked list, then walk through linked list
        // at last Node as 7 < 8, larger Node is 5-6-8
        // and smaller Node is 5-6-7.
        while (l1 && l2) {
            if (l1->data != l2->data) {
                lNode = l1->data > l2->data ? temp1 : temp2;
                sNode = l1->data > l2->data ? temp2 : temp1;
                break;
            }
            l1 = l1->next;
            l2 = l2->next;
        }
    }
      // If both lNode and sNode still have NULL value,
      // then this means that the  value of both of the given linked lists
      // is the same and hence we can directly return a node with value 0.
    if(lNode==NULL&&sNode==NULL)
    {
      return newNode(0);
    }
    // After calculating larger and smaller Node, call
    // subtractLinkedListHelper which returns the subtracted
    // linked list.
    bool borrow = false;
    return subtractLinkedListHelper(lNode, sNode, borrow);
}
 


// Multiply contents of two linked lists => store
// in another list and return its head
struct Node *multiplyTwoLists(struct Node *first,
                              struct Node *second)
{
    // reverse the lists to multiply from end
    // m and n lengths of linked lists to make
    // and empty list
    int m = reverse(&first), n = reverse(&second);

    // make a list that will contain the result
    // of multiplication.
    // m+n+1 can be max size of the list
    struct Node *result = make_empty_list(m + n + 1);

    // pointers for traverse linked lists and also
    // to reverse them after
    struct Node *second_ptr = second,
                *result_ptr1 = result, *result_ptr2, *first_ptr;

    // multiply each Node of second list with first
    while (second_ptr)
    {

        int carry = 0;

        // each time we start from the next of Node
        // from which we started last time
        result_ptr2 = result_ptr1;

        first_ptr = first;

        while (first_ptr)
        {

            // multiply a first list's digit with a
            // current second list's digit
            int mul = first_ptr->data * second_ptr->data + carry;

            // Assign the product to corresponding Node
            // of result
            result_ptr2->data += mul % 10;

            // now resultant Node itself can have more
            // than 1 digit
            carry = mul / 10 + result_ptr2->data / 10;
            result_ptr2->data = result_ptr2->data % 10;

            first_ptr = first_ptr->next;
            result_ptr2 = result_ptr2->next;
        }

        // if carry is remaining from last multiplication
        if (carry > 0)
        {
            result_ptr2->data += carry;
        }

        result_ptr1 = result_ptr1->next;
        second_ptr = second_ptr->next;
    }

    // reverse the result_list as it was populated
    // from last Node
    reverse(&result);
    reverse(&first);
    reverse(&second);

    // remove if there are zeros at starting
    while (result->data == 0)
    {
        struct Node *temp = result;
        result = result->next;
        free(temp);
    }

    // Return head of multiplication list
    return result;
}

// A utility function to print a linked list
void printList(struct Node *Node)
{
    while (Node != NULL)
    {
        printf("%d", Node->data);
        if (Node->next)
            printf("->");
        Node = Node->next;
    }
    printf("\n");
}

// Driver program to test above function
int main(void)
{
    struct Node *first = NULL;
    struct Node *second = NULL;

    // create first list 9->9->9->4->6->9
    push(&first, 9);
    push(&first, 9);
    push(&first, 9);
    push(&first, 4);
    push(&first, 6);
    push(&first, 9);
    printf("First List is: ");
    printList(first);

    // create second list 9->9->8->4->9
    push(&second, 9);
    push(&second, 9);
    push(&second, 8);
    push(&second, 4);
    push(&second, 9);
    printf("Second List is: ");
    printList(second);

    // Multiply the two lists and see result
    struct Node *result = multiplyTwoLists(first, second);
    printf("Multiplication Resultant Linked list is: ");
    printList(result);

    struct Node *res = addTwoLists(first, second);
    printf("Addition Resultant Linked list is: ");
    printList(res);

    // Node* head1 = newNode(1);
    // head1->next = newNode(0);
    // head1->next->next = newNode(0);
 
    // Node* head2 = newNode(1);
 
    Node* resultSub = subtractLinkedList(first, second);
    printf("Subtraction Resultant Linked list is: ");
    printList(resultSub);

    return 0;
}