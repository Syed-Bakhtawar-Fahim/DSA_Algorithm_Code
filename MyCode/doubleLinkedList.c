#include<stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
};
struct Node * Start,*tmp,*end;

void insert(){
    tmp=(struct Node*)malloc(sizeof(struct Node));
    int n;
    printf("Enter Number for list");
    scanf("%d",&n);
    tmp->data=n;
    tmp->prev=NULL;
    tmp->next=NULL;

    if(Start==NULL){
        Start=tmp;
    }

    else{
        struct Node *curr=Start;
        while(curr->next!=NULL){
            curr=curr->next;
        }
        curr->next=tmp;
        tmp->prev=curr;
        end=tmp;
        printf("%d",end->data);

    }
}
void display(){
    struct Node *p=Start;
    while(p!=NULL){
        printf("%d\n",p->data);
        p=p->next;
    }
}
void displayRev(){

    while(end!=Start){
        printf("%d\n",end->data);
        end=end->prev;
    }
    printf("%d",end->data);
}
void deleteElement(){
	int todelete;

	printf("Enter No. to delete");
	scanf("%d",&todelete);
	struct Node *currr,*pree=Start,*en=end;
	if(todelete==Start->data){
        Start=Start->next;
		currr->prev=NULL;
		free(pree);
	}
	if(todelete==end->data){

        end=end->prev;
        end->next=NULL;
        free(en);
	}
	else{
		currr=Start->next;
		pree=Start;
		while(currr->next!=NULL){
			if(todelete==currr->data){
				pree->next=currr->next;
                currr->next->prev=currr->prev;
				free(currr);
				break;
			}
		}
            currr=currr->next;
			pree=pree->next;
	}
}

void Search(){
    struct Node *p=Start;
    int num;
    printf("Enter No. to search : ");
    scanf("%d",&num);
    while(p!=NULL){
    if (num==p->data){
        printf("YES!");
        break;
    }
    p=p->next;
    }
}

void main()
{
    int  input, disp,search_num,another_num;
    printf("for insert press 2\nPress 1 to exit\n" );
    scanf("%d", &input);
    while (input == 2)
    {
            insert();
            printf("Press 1 to insert another node\nPress 0 to display the list and search press 6 to delete\n");
            scanf("%d", &disp);
            if (disp==0)
            {

                printf("Your linked list is:\n");
                displayRev();
                printf("\nDo you want to reverse the list? Press 3 if yes, 4 if no\n");
                scanf("%d",&search_num);

                if (search_num==3)
                {
                    display();
                }

               // if(search_num==6)
                //{
                  //  deleteElement();
                    //printf("The updated linked list is: ");
                    //display();
                //}

                else
                {
                Search();
                }
                break;
            }
            if (disp==1)
            {
                continue;
            }
            if (disp==6)
            {

                printf("Your list before deletion: \n");
                display();
               deleteElement();
               printf("\nThe updated linked list is: \n");
               display();
               printf("\nDo you want to delete another element? If yes, press 8: \n");
               scanf("%d",&another_num);
               if(another_num==8)
               {
                   deleteElement();
                   printf("The updated linked list is: \n");
                   display();
               }
               else
               {
                   break;
               }
            }

    }
}