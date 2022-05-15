#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *link;
};

struct node * push(struct node *head, int val)
{
    struct node *newP = (struct node*)malloc(sizeof(struct node));
    newP->data = val;
    newP->link = head;
    head = newP;
    return head;
}

struct node *add(struct node *head1, struct node *head2)
{
    if (head1->data == 0)
        return head2;
    if (head2->data == 0)
        return head1;

    struct node *ptr1 = head1;
    struct node *ptr2 = head2;
    struct node *head3 = NULL;
    int carry = 0;
    // int sum = 0;
    int sum;

    while(ptr1 || ptr2)
    {
        sum = 0;
        if(ptr1)
            sum += ptr1->data;
        if(ptr2)
            sum += ptr2->data;
        sum += carry;
        carry = sum / 10;
        sum = sum % 10;

        head3 = push(head3, sum);

        if(ptr1)
            ptr1 = ptr1->link;
        if(ptr2)
            ptr2 = ptr2->link;
    }

    if(carry)
        head3 = push(head3, carry);
    return head3;

}

struct node * reverseLL(struct node * head)
{
    if(head == NULL)
        return head;
    struct node * current = NULL;
    struct node * next = head->link;
    head->link = NULL;

    while(next != NULL)
    {
        current = next;
        next = next->link;
        current->link = head;
        head = current;
    }
    return head;
}

struct node * add_note(struct node * head, int val)
{
    struct node * newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = val;
    newNode->link = NULL;

    newNode->link = head;
    head = newNode;
    return head;
}

struct node * createLL(struct node *head, int n)
{
    while(n != 0)
    {
        head = add_note(head, n%10);
        n = n/10;
    }
    return head;
}

void print(struct node * head)
{
    struct node * temp = head;
    if(head == NULL)
        printf("No Number\n");
    else
        while(temp->link != NULL)
        {
            printf("%d -> ", temp->data);
            temp = temp->link;

        }
        printf("%d ", temp->data);
}

void back2Num(struct node * head)
{
    struct node *temp = head;
    printf("\nResult\n");
    while (temp)
    {
        printf("%d ", temp->data);
        temp = temp->link;
    }
    return;
    
}

int main()
{
    int a, b;
    printf("Enter two Number: ");
    scanf("%d %d ", &a, &b);

    printf("\nLinked List Representation of first Number\n");
    struct node * head1 = NULL;
    head1 = createLL(head1, a);
    print(head1);

    struct node * head2 = NULL;
    printf("Linked List Representation of second Number\n");
    // struct node * head1 = NULL;
    head2 = createLL(head2, b);
    print(head2);

    head1 = reverseLL(head1);
    head2 = reverseLL(head2);

    printf("\nReversed Linked List: \n");
    print(head1);
    printf("\n");
    print(head2);

    struct node * head3 = NULL;
    head3 = add(head1, head2);
    printf("\nResultant Linked List is: \n");
    print(head3);

    back2Num(head3);

    return 0;

}


// long long multiplyTwoLists (struct Node* first, struct Node* second)
// {
//     long long N= 1000000007;
//     long long num1 = 0, num2 = 0;
//     while (first || second){
         
//         if(first){
//             num1 = ((num1)*10)%N + first->data;
//             first = first->next;
//         }
         
//         if(second)
//         {
//             num2 = ((num2)*10)%N + second->data;
//             second = second->next;
//         }
         
//     }
//     return ((num1%N)*(num2%N))%N;
// }